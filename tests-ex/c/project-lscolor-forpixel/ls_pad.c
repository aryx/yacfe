/* `dir', `vdir' and `ls' directory listing programs for GNU.
   Copyright (C) 85, 88, 90, 91, 95, 1996 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation,
   Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */

/* If the macro MULTI_COL is defined,
   the multi-column format is the default regardless
   of the type of output device.
   This is for the `dir' program.

   If the macro LONG_FORMAT is defined,
   the long format is the default regardless of the
   type of output device.
   This is for the `vdir' program.

   If neither is defined,
   the output format depends on whether the output
   device is a terminal.
   This is for the `ls' program. */

/* Written by Richard Stallman and David MacKenzie.  */

/* Color support by Peter Anvin <Peter.Anvin@linux.org> and Dennis
   Flaherty <dennisf@denix.elk.miles.com> based on original patches by
   Greg Lee <lee@uhunix.uhcc.hawaii.edu>.  */

#ifdef _AIX
 #pragma alloca
#endif

#include <config.h>
#include <sys/types.h>

#include <termios.h>
#ifdef GWINSZ_IN_SYS_IOCTL
# include <sys/ioctl.h>
#endif

#include <stdio.h>
#include <grp.h>
#include <pwd.h>
#include <getopt.h>

#if HAVE_LIMITS_H
/* limits.h must come before system.h because limits.h on some systems
   undefs PATH_MAX, whereas system.h includes pathmax.h which sets
   PATH_MAX.  */
# include <limits.h>
#endif

#include "system.h"
#include <fnmatch.h>

#include "obstack.h"
#include "ls.h"
#include "error.h"
#include "argmatch.h"
#include "xstrtol.h"

#define obstack_chunk_alloc xmalloc
#define obstack_chunk_free free

#ifndef INT_MAX
# define INT_MAX 2147483647
#endif

/* Return an int indicating the result of comparing two longs. */
#if (INT_MAX <= 65535)
# define longdiff(a, b) ((a) < (b) ? -1 : (a) > (b) ? 1 : 0)
#else
# define longdiff(a, b) ((a) - (b))
#endif

/* The maximum number of digits required to print an inode number
   in an unsigned format.  */
#ifndef INODE_DIGITS
# define INODE_DIGITS 7
#endif

enum filetype
  {
    symbolic_link,
    directory,
    arg_directory,		/* Directory given as command line arg. */
    normal			/* All others. */
  };

struct fileinfo
  {
    /* The file name. */
    char *name;

    struct stat stat;

    /* For symbolic link, name of the file linked to, otherwise zero. */
    char *linkname;

    /* For symbolic link and long listing, st_mode of file linked to, otherwise
       zero. */
    unsigned int linkmode;

    /* For symbolic link and color printing, 1 if linked-to file
       exits, otherwise 0.  */
    int linkok;

    enum filetype filetype;
  };

#define LEN_STR_PAIR(s) sizeof (s) - 1, s

/* Null is a valid character in a color indicator (think about Epson
   printers, for example) so we have to use a length/buffer string
   type.  */

struct bin_str
  {
    unsigned int len;		/* Number of bytes */
    char *string;		/* Pointer to the same */
  };

#ifndef STDC_HEADERS
char *ctime ();
time_t time ();
void free ();
#endif

void mode_string ();

char *stpcpy ();
char *xstrdup ();
char *getgroup ();
char *getuser ();
char *xmalloc ();
char *xrealloc ();
void invalid_arg ();

static char *make_link_path __P ((const char *path, const char *linkname));
static int compare_atime __P ((const struct fileinfo *file1,
			       const struct fileinfo *file2));
static int rev_cmp_atime __P ((const struct fileinfo *file2,
			       const struct fileinfo *file1));
static int compare_ctime __P ((const struct fileinfo *file1,
			       const struct fileinfo *file2));
static int rev_cmp_ctime __P ((const struct fileinfo *file2,
			       const struct fileinfo *file1));
static int compare_mtime __P ((const struct fileinfo *file1,
			       const struct fileinfo *file2));
static int rev_cmp_mtime __P ((const struct fileinfo *file2,
			       const struct fileinfo *file1));
static int compare_size __P ((const struct fileinfo *file1,
			      const struct fileinfo *file2));
static int rev_cmp_size __P ((const struct fileinfo *file2,
			      const struct fileinfo *file1));
static int compare_name __P ((const struct fileinfo *file1,
			      const struct fileinfo *file2));
static int rev_cmp_name __P ((const struct fileinfo *file2,
			      const struct fileinfo *file1));
static int compare_extension __P ((const struct fileinfo *file1,
				   const struct fileinfo *file2));
static int rev_cmp_extension __P ((const struct fileinfo *file2,
				   const struct fileinfo *file1));
static int decode_switches __P ((int argc, char **argv));
static int file_interesting __P ((const struct dirent *next));
static int gobble_file __P ((const char *name, int explicit_arg,
			     const char *dirname));
static int is_not_dot_or_dotdot __P ((const char *name));
static void print_color_indicator __P ((const char *name, unsigned int mode,
					int linkok));
static void put_indicator __P ((const struct bin_str *ind));
static int length_of_file_name_and_frills __P ((const struct fileinfo *f));
static void add_ignore_pattern __P ((const char *pattern));
static void attach __P ((char *dest, const char *dirname, const char *name));
static void clear_files __P ((void));
static void extract_dirs_from_files __P ((const char *dirname, int recursive));
static void get_link_name __P ((const char *filename, struct fileinfo *f));
static void indent __P ((int from, int to));
static void print_current_files __P ((void));
static void print_dir __P ((const char *name, const char *realname));
static void print_file_name_and_frills __P ((const struct fileinfo *f));
static void print_horizontal __P ((void));
static void print_long_format __P ((const struct fileinfo *f));
static void print_many_per_line __P ((void));
static void print_name_with_quoting __P ((const char *p, unsigned int mode,
					  int linkok));
static void print_type_indicator __P ((unsigned int mode));
static void print_with_commas __P ((void));
static void queue_directory __P ((const char *name, const char *realname));
static void sort_files __P ((void));
static void parse_ls_color __P ((void));
static void usage __P ((int status));

/* The name the program was run with, stripped of any leading path. */
char *program_name;

/* The table of files in the current directory:

   `files' points to a vector of `struct fileinfo', one per file.
   `nfiles' is the number of elements space has been allocated for.
   `files_index' is the number actually in use.  */

/* Address of block containing the files that are described.  */

static struct fileinfo *files;

/* Length of block that `files' points to, measured in files.  */

static int nfiles;

/* Index of first unused in `files'.  */

static int files_index;

/* Record of one pending directory waiting to be listed.  */

struct pending
  {
    char *name;
    /* If the directory is actually the file pointed to by a symbolic link we
       were told to list, `realname' will contain the name of the symbolic
       link, otherwise zero. */
    char *realname;
    struct pending *next;
  };

static struct pending *pending_dirs;

/* Current time (seconds since 1970).  When we are printing a file's time,
   include the year if it is more than 6 months before this time.  */

static time_t current_time;

/* The number of digits to use for block sizes.
   4, or more if needed for bigger numbers.  */

static int block_size_size;

/* Option flags */

/* long_format for lots of info, one per line.
   one_per_line for just names, one per line.
   many_per_line for just names, many per line, sorted vertically.
   horizontal for just names, many per line, sorted horizontally.
   with_commas for just names, many per line, separated by commas.

   -l, -1, -C, -x and -m control this parameter.  */

enum format
  {
    long_format,		/* -l */
    one_per_line,		/* -1 */
    many_per_line,		/* -C */
    horizontal,			/* -x */
    with_commas			/* -m */
  };

static enum format format;

/* Type of time to print or sort by.  Controlled by -c and -u.  */

enum time_type
  {
    time_mtime,			/* default */
    time_ctime,			/* -c */
    time_atime			/* -u */
  };

static enum time_type time_type;

/* print the full time, otherwise the standard unix heuristics. */

int full_time;

/* The file characteristic to sort by.  Controlled by -t, -S, -U, -X. */

enum sort_type
  {
    sort_none,			/* -U */
    sort_name,			/* default */
    sort_extension,		/* -X */
    sort_time,			/* -t */
    sort_size			/* -S */
  };

static enum sort_type sort_type;

/* Direction of sort.
   0 means highest first if numeric,
   lowest first if alphabetic;
   these are the defaults.
   1 means the opposite order in each case.  -r  */

static int sort_reverse;

/* Nonzero means to NOT display group information.  -G  */

int inhibit_group;

/* Nonzero means print the user and group id's as numbers rather
   than as names.  -n  */

static int numeric_users;

/* Nonzero means mention the size in 512 byte blocks of each file.  -s  */

static int print_block_size;

/* Nonzero means show file sizes in kilobytes instead of blocks
   (the size of which is system-dependent).  -k */

static int kilobyte_blocks;

/* Precede each line of long output (per file) with a string like `m,n:'
   where M is the number of characters after the `:' and before the
   filename and N is the length of the filename.  Using this format,
   Emacs' dired mode starts up twice as fast, and can handle all
   strange characters in file names.  */
static int dired;

/* `none' means don't mention the type of files.
   `all' means mention the types of all files.
   `not_programs' means do so except for executables.

   Controlled by -F and -p.  */

enum indicator_style
  {
    none,                      /* default */
    all,                       /* -F */
    not_programs               /* -p */
  };

static enum indicator_style indicator_style;

/* Nonzero means use colors to mark types.  Also define the different
   colors as well as the stuff for the LS_COLORS environment variable.
   The LS_COLORS variable is now in a termcap-like format.  */

static int print_with_color;

enum color_type
  {
    color_never,		/* 0: default or --color=never */
    color_always,		/* 1: --color=always */
    color_if_tty		/* 2: --color=tty */
  };

enum indicator_no
  {
    C_LEFT, C_RIGHT, C_END, C_NORM, C_FILE, C_DIR, C_LINK, C_FIFO, C_SOCK,
    C_BLK, C_CHR, C_MISSING, C_ORPHAN, C_EXEC
  };

static const char *const indicator_name[]=
  {
    "lc", "rc", "ec", "no", "fi", "di", "ln", "pi", "so",
    "bd", "cd", "mi", "or", "ex", NULL
  };

struct col_ext_type
  {
    struct bin_str ext;		/* The extension we're looking for */
    struct bin_str seq;		/* The sequence to output when we do */
    struct col_ext_type *next;	/* Next in list */
  };

static struct bin_str color_indicator[] =
  {
    { LEN_STR_PAIR ("\033[") },		/* lc: Left of color sequence */
    { LEN_STR_PAIR ("m") },		/* rc: Right of color sequence */
    { 0, NULL },			/* ec: End color (replaces lc+no+rc) */
    { LEN_STR_PAIR ("0") },		/* no: Normal */
    { LEN_STR_PAIR ("0") },		/* fi: File: default */
    { LEN_STR_PAIR ("01;34") },		/* di: Directory: bright blue */
    { LEN_STR_PAIR ("01;36") },		/* ln: Symlink: bright cyan */
    { LEN_STR_PAIR ("33") },		/* pi: Pipe: yellow/brown */
    { LEN_STR_PAIR ("01;35") },		/* so: Socket: bright magenta */
    { LEN_STR_PAIR ("01;33") },		/* bd: Block device: bright yellow */
    { LEN_STR_PAIR ("01;33") },		/* cd: Char device: bright yellow */
    { 0, NULL },			/* mi: Missing file: undefined */
    { 0, NULL },			/* or: Orphanned symlink: undefined */
    { LEN_STR_PAIR ("01;32") }		/* ex: Executable: bright green */
  };

/* FIXME: comment  */
struct col_ext_type *col_ext_list = NULL;

/* Buffer for color sequences */
static char *color_buf;

/* Nonzero means mention the inode number of each file.  -i  */

static int print_inode;

/* Nonzero means when a symbolic link is found, display info on
   the file linked to.  -L  */

static int trace_links;

/* Nonzero means when a directory is found, display info on its
   contents.  -R  */

static int trace_dirs;

/* Nonzero means when an argument is a directory name, display info
   on it itself.  -d  */

static int immediate_dirs;

/* Nonzero means don't omit files whose names start with `.'.  -A */

static int all_files;

/* Nonzero means don't omit files `.' and `..'
   This flag implies `all_files'.  -a  */

static int really_all_files;

/* A linked list of shell-style globbing patterns.  If a non-argument
   file name matches any of these patterns, it is omitted.
   Controlled by -I.  Multiple -I options accumulate.
   The -B option adds `*~' and `.*~' to this list.  */

struct ignore_pattern
  {
    const char *pattern;
    struct ignore_pattern *next;
  };

static struct ignore_pattern *ignore_patterns;

/* Nonzero means quote nongraphic chars in file names.  -b  */

static int quote_funny_chars;

/* Nonzero means output nongraphic chars in file names as `?'.  -q  */

static int qmark_funny_chars;

/* Nonzero means output each file name using C syntax for a string.
   Always accompanied by `quote_funny_chars'.
   This mode, together with -x or -C or -m,
   and without such frills as -F or -s,
   is guaranteed to make it possible for a program receiving
   the output to tell exactly what file names are present.  -Q  */

static int quote_as_string;

/* The number of chars per hardware tab stop.  Setting this to zero
   inhibits the use of TAB characters for separating columns.  -T */
static int tabsize;

/* Nonzero means we are listing the working directory because no
   non-option arguments were given. */

static int dir_defaulted;

/* Nonzero means print each directory name before listing it. */

static int print_dir_name;

/* The line length to use for breaking lines in many-per-line format.
   Can be set with -w.  */

static int line_length;

/* If nonzero, the file listing format requires that stat be called on
   each file. */

static int format_needs_stat;

/* The exit status to use if we don't get any fatal errors. */

static int exit_status;

/* If nonzero, display usage information and exit.  */
static int show_help;

/* If nonzero, print the version on standard output and exit.  */
static int show_version;

static struct option const long_options[] =
{
  {"all", no_argument, 0, 'a'},
  {"escape", no_argument, 0, 'b'},
  {"directory", no_argument, 0, 'd'},
  {"dired", no_argument, 0, 'D'},
  {"full-time", no_argument, &full_time, 1},
  {"inode", no_argument, 0, 'i'},
  {"kilobytes", no_argument, 0, 'k'},
  {"numeric-uid-gid", no_argument, 0, 'n'},
  {"no-group", no_argument, 0, 'G'},
  {"hide-control-chars", no_argument, 0, 'q'},
  {"reverse", no_argument, 0, 'r'},
  {"size", no_argument, 0, 's'},
  {"width", required_argument, 0, 'w'},
  {"almost-all", no_argument, 0, 'A'},
  {"ignore-backups", no_argument, 0, 'B'},
  {"classify", no_argument, 0, 'F'},
  {"file-type", no_argument, 0, 'F'},
  {"ignore", required_argument, 0, 'I'},
  {"dereference", no_argument, 0, 'L'},
  {"literal", no_argument, 0, 'N'},
  {"quote-name", no_argument, 0, 'Q'},
  {"recursive", no_argument, 0, 'R'},
  {"format", required_argument, 0, 12},
  {"sort", required_argument, 0, 10},
  {"tabsize", required_argument, 0, 'T'},
  {"time", required_argument, 0, 11},
  {"help", no_argument, &show_help, 1},
  {"version", no_argument, &show_version, 1},
  {"color", optional_argument, 0, 13},
  {NULL, 0, NULL, 0}
};

static char const *const format_args[] =
{
  "verbose", "long", "commas", "horizontal", "across",
  "vertical", "single-column", 0
};

static enum format const formats[] =
{
  long_format, long_format, with_commas, horizontal, horizontal,
  many_per_line, one_per_line
};

static char const *const sort_args[] =
{
  "none", "time", "size", "extension", 0
};

static enum sort_type const sort_types[] =
{
  sort_none, sort_time, sort_size, sort_extension
};

static char const *const time_args[] =
{
  "atime", "access", "use", "ctime", "status", 0
};

/* This zero-based index is used solely with the --dired option.
   When that option is in effect, this counter is incremented for each
   character of output generated by this program so that the beginning
   and ending indices (in that output) of every file name can be recorded
   and later output themselves.  */
static size_t dired_pos;

#define PUTCHAR(c) do {putchar ((c)); ++dired_pos;} while (0)

/* Write S to STREAM and increment DIRED_POS by S_LEN.  */
#define FPUTS(s, stream, s_len) \
    do {fputs ((s), (stream)); dired_pos += s_len;} while (0)

/* Like FPUTS, but for use when S is a literal string.  */
#define FPUTS_LITERAL(s, stream) \
    do {fputs ((s), (stream)); dired_pos += sizeof((s)) - 1;} while (0)

#define DIRED_INDENT()							\
    do									\
      {									\
	/* FIXME: remove the `&& format == long_format' clause.  */	\
	if (dired && format == long_format)				\
	  FPUTS_LITERAL ("  ", stdout);					\
      }									\
    while (0)

/* With --dired, store pairs of beginning and ending indices of filenames.  */
static struct obstack dired_obstack;

/* With --dired, store pairs of beginning and ending indices of any
   directory names that appear as headers (just before `total' line)
   for lists of directory entries.  Such directory names are seen when
   listing hierarchies using -R and when a directory is listed with at
   least one other command line argument.  */
static struct obstack subdired_obstack;

/* Save the current index on the specified obstack, OBS.  */
#define PUSH_CURRENT_DIRED_POS(obs)					\
  do									\
    {									\
      /* FIXME: remove the `&& format == long_format' clause.  */	\
      if (dired && format == long_format)				\
	obstack_grow ((obs), &dired_pos, sizeof (dired_pos));		\
    }									\
  while (0)

static enum time_type const time_types[] =
{
  time_atime, time_atime, time_atime, time_ctime, time_ctime
};

static char const *const color_args[] =
  {
    /* Note: "no" is a prefix of "none" so we don't include it.  */
    /* force and none are for compatibility with another color-ls version */
    "always", "yes", "force",
    "never", "none",
    "auto", "tty", "if-tty", 0
  };

static enum color_type const color_types[] =
  {
    color_always, color_always, color_always,
    color_never, color_never,
    color_if_tty, color_if_tty, color_if_tty
  };


/* Write to standard output the string PREFIX followed by a space-separated
   list of the integers stored in OS all on one line.  */

static void
dired_dump_obstack (const char *prefix, struct obstack *os)
{
  int n_pos;

  n_pos = obstack_object_size (os) / sizeof (size_t);
  if (n_pos > 0)
    {
      int i;
      size_t *pos;

      pos = (size_t *) obstack_finish (os);
      fputs (prefix, stdout);
      for (i = 0; i < n_pos; i++)
	printf (" %d", (int) pos[i]);
      fputs ("\n", stdout);
    }
}

int
main (int argc, char **argv)
{
  register int i;
  register struct pending *thispend;

  program_name = argv[0];
  setlocale (LC_ALL, "");
  bindtextdomain (PACKAGE, LOCALEDIR);
  textdomain (PACKAGE);

  exit_status = 0;
  dir_defaulted = 1;
  print_dir_name = 1;
  pending_dirs = 0;
  current_time = time ((time_t *) 0);

  i = decode_switches (argc, argv);

  if (show_version)
    {
      printf ("%s - %s\n",
	      (ls_mode == LS_LS ? "ls"
	       : (ls_mode == LS_MULTI_COL ? "dir" : "vdir")),
	      PACKAGE_VERSION);
      exit (0);
    }

  if (show_help)
    usage (0);

  if (print_with_color)
    parse_ls_color ();

  format_needs_stat = sort_type == sort_time || sort_type == sort_size
    || format == long_format
    || trace_links || trace_dirs || indicator_style != none
    || print_block_size || print_inode || print_with_color;

  if (dired && format == long_format)
    {
      obstack_init (&dired_obstack);
      obstack_init (&subdired_obstack);
    }

  nfiles = 100;
  files = (struct fileinfo *) xmalloc (sizeof (struct fileinfo) * nfiles);
  files_index = 0;

  clear_files ();

  if (i < argc)
    dir_defaulted = 0;
  for (; i < argc; i++)
    gobble_file (argv[i], 1, "");

  if (dir_defaulted)
    {
      if (immediate_dirs)
	gobble_file (".", 1, "");
      else
	queue_directory (".", 0);
    }

  if (files_index)
    {
      sort_files ();
      if (!immediate_dirs)
	extract_dirs_from_files ("", 0);
      /* `files_index' might be zero now.  */
    }
  if (files_index)
    {
      print_current_files ();
      if (pending_dirs)
	PUTCHAR ('\n');
    }
  else if (pending_dirs && pending_dirs->next == 0)
    print_dir_name = 0;

  while (pending_dirs)
    {
      thispend = pending_dirs;
      pending_dirs = pending_dirs->next;
      print_dir (thispend->name, thispend->realname);
      free (thispend->name);
      if (thispend->realname)
	free (thispend->realname);
      free (thispend);
      print_dir_name = 1;
    }

  if (dired && format == long_format)
    {
      /* No need to free these since we're about to exit.  */
      dired_dump_obstack ("//DIRED//", &dired_obstack);
      dired_dump_obstack ("//SUBDIRED//", &subdired_obstack);
    }

  exit (exit_status);
}

/* Set all the option flags according to the switches specified.
   Return the index of the first non-option argument.  */

static int
decode_switches (int argc, char **argv)
{
  register char *p;
  int c;
  int i;
  long int tmp_long;

  qmark_funny_chars = 0;
  quote_funny_chars = 0;

  /* initialize all switches to default settings */

  switch (ls_mode)
    {
    case LS_MULTI_COL:
      /* This is for the `dir' program.  */
      format = many_per_line;
      quote_funny_chars = 1;
      break;

    case LS_LONG_FORMAT:
      /* This is for the `vdir' program.  */
      format = long_format;
      quote_funny_chars = 1;
      break;

    case LS_LS:
      /* This is for the `ls' program.  */
      if (isatty (1))
	{
	  format = many_per_line;
	  qmark_funny_chars = 1;
	}
      else
	{
	  format = one_per_line;
	  qmark_funny_chars = 0;
	}
      break;

    default:
      abort ();
    }

  time_type = time_mtime;
  full_time = 0;
  sort_type = sort_name;
  sort_reverse = 0;
  numeric_users = 0;
  print_block_size = 0;
  kilobyte_blocks = getenv ("POSIXLY_CORRECT") == 0;
  indicator_style = none;
  print_inode = 0;
  trace_links = 0;
  trace_dirs = 0;
  immediate_dirs = 0;
  all_files = 0;
  really_all_files = 0;
  ignore_patterns = 0;
  quote_as_string = 0;

  line_length = 80;
  if ((p = getenv ("COLUMNS")))
    {
      if (xstrtol (p, NULL, 0, &tmp_long, NULL) == LONGINT_OK
	  && 0 < tmp_long && tmp_long <= INT_MAX)
	{
	  line_length = (int) tmp_long;
	}
      else
	{
	  error (0, 0,
	       _("ignoring invalid width in environment variable COLUMNS: %s"),
		 p);
	}
    }

#ifdef TIOCGWINSZ
  {
    struct winsize ws;

    if (ioctl (1, TIOCGWINSZ, &ws) != -1 && ws.ws_col != 0)
      line_length = ws.ws_col;
  }
#endif

  /* Using the TABSIZE environment variable is not POSIX-approved.
     Ignore it when POSIXLY_CORRECT is set.  */
  tabsize = 8;
  if (!getenv ("POSIXLY_CORRECT") && (p = getenv ("TABSIZE")))
    {
      if (xstrtol (p, NULL, 0, &tmp_long, NULL) == LONGINT_OK
	  && 0 <= tmp_long && tmp_long <= INT_MAX)
	{
	  tabsize = (int) tmp_long;
	}
      else
	{
	  error (0, 0,
	   _("ignoring invalid tab size in environment variable TABSIZE: %s"),
		 p);
	}
    }

  while ((c = getopt_long (argc, argv,
			   "abcdfgiklmnopqrstuw:xABCDFGI:LNQRST:UX1",
			   long_options, (int *) 0)) != EOF)
    {
      switch (c)
	{
	case 0:
	  break;

	case 'a':
	  all_files = 1;
	  really_all_files = 1;
	  break;

	case 'b':
	  quote_funny_chars = 1;
	  qmark_funny_chars = 0;
	  break;

	case 'c':
	  time_type = time_ctime;
	  sort_type = sort_time;
	  break;

	case 'd':
	  immediate_dirs = 1;
	  break;

	case 'f':
	  /* Same as enabling -a -U and disabling -l -s.  */
	  all_files = 1;
	  really_all_files = 1;
	  sort_type = sort_none;
	  /* disable -l */
	  if (format == long_format)
	    format = (isatty (1) ? many_per_line : one_per_line);
	  print_block_size = 0;	/* disable -s */
	  print_with_color = 0;	/* disable --color */
	  break;

	case 'g':
	  /* No effect.  For BSD compatibility. */
	  break;

	case 'i':
	  print_inode = 1;
	  break;

	case 'k':
	  kilobyte_blocks = 1;
	  break;

	case 'l':
	  format = long_format;
	  break;

	case 'm':
	  format = with_commas;
	  break;

	case 'n':
	  numeric_users = 1;
	  break;

	case 'o':  /* Just like -l, but don't display group info.  */
	  format = long_format;
	  inhibit_group = 1;
	  break;

	case 'p':
	  indicator_style = not_programs;
	  break;

	case 'q':
	  qmark_funny_chars = 1;
	  quote_funny_chars = 0;
	  break;

	case 'r':
	  sort_reverse = 1;
	  break;

	case 's':
	  print_block_size = 1;
	  break;

	case 't':
	  sort_type = sort_time;
	  break;

	case 'u':
	  time_type = time_atime;
	  break;

	case 'w':
	  if (xstrtol (optarg, NULL, 0, &tmp_long, NULL) != LONGINT_OK
	      || tmp_long <= 0 || tmp_long > INT_MAX)
	    error (1, 0, _("invalid line width: %s"), optarg);
	  line_length = (int) tmp_long;
	  break;

	case 'x':
	  format = horizontal;
	  break;

	case 'A':
	  all_files = 1;
	  break;

	case 'B':
	  add_ignore_pattern ("*~");
	  add_ignore_pattern (".*~");
	  break;

	case 'C':
	  format = many_per_line;
	  break;

	case 'D':
	  dired = 1;
	  break;

	case 'F':
	  indicator_style = all;
	  break;

	case 'G':		/* inhibit display of group info */
	  inhibit_group = 1;
	  break;

	case 'I':
	  add_ignore_pattern (optarg);
	  break;

	case 'L':
	  trace_links = 1;
	  break;

	case 'N':
	  quote_funny_chars = 0;
	  qmark_funny_chars = 0;
	  break;

	case 'Q':
	  quote_as_string = 1;
	  quote_funny_chars = 1;
	  qmark_funny_chars = 0;
	  break;

	case 'R':
	  trace_dirs = 1;
	  break;

	case 'S':
	  sort_type = sort_size;
	  break;

	case 'T':
	  if (xstrtol (optarg, NULL, 0, &tmp_long, NULL) != LONGINT_OK
	      || tmp_long < 0 || tmp_long > INT_MAX)
	    error (1, 0, _("invalid tab size: %s"), optarg);
	  tabsize = (int) tmp_long;
	  break;

	case 'U':
	  sort_type = sort_none;
	  break;

	case 'X':
	  sort_type = sort_extension;
	  break;

	case '1':
	  format = one_per_line;
	  break;

	case 10:		/* --sort */
	  i = argmatch (optarg, sort_args);
	  if (i < 0)
	    {
	      invalid_arg (_("sort type"), optarg, i);
	      usage (1);
	    }
	  sort_type = sort_types[i];
	  break;

	case 11:		/* --time */
	  i = argmatch (optarg, time_args);
	  if (i < 0)
	    {
	      invalid_arg (_("time type"), optarg, i);
	      usage (1);
	    }
	  time_type = time_types[i];
	  break;

	case 12:		/* --format */
	  i = argmatch (optarg, format_args);
	  if (i < 0)
	    {
	      invalid_arg (_("format type"), optarg, i);
	      usage (1);
	    }
	  format = formats[i];
	  break;

	case 13:		/* --color */
	  if (optarg)
	    {
	      i = argmatch (optarg, color_args);
	      if (i < 0)
		{
		  invalid_arg (_("colorization criterion"), optarg, i);
		  usage (1);
		}
	      i = color_types[i];
	    }
	  else
	    {
	      /* Using --color with no argument is equivalent to using
		 --color=always.  */
	      i = color_always;
	    }

	  print_with_color = (i == color_always
			      || (i == color_if_tty
				  && isatty (STDOUT_FILENO)));

	  if (print_with_color)
	    {
	      /* Don't use TAB characters in output.  Some terminal
		 emulators can't handle the combination of tabs and
		 color codes on the same line.  */
	      tabsize = 0;
	    }
	  break;

	default:
	  usage (1);
	}
    }

  return optind;
}

/* Parse a string as part of the LS_COLORS variable; this may involve
   decoding all kinds of escape characters.  If equals_end is set an
   unescaped equal sign ends the string, otherwise only a : or \0
   does.  Returns the number of characters output, or -1 on failure.

   The resulting string is *not* null-terminated, but may contain
   embedded nulls.

   Note that both dest and src are char **; on return they point to
   the first free byte after the array and the character that ended
   the input string, respectively.  */

static int
get_funky_string (char **dest, const char **src, int equals_end)
{
  int num;			/* For numerical codes */
  int count;			/* Something to count with */
  enum {
    ST_GND, ST_BACKSLASH, ST_OCTAL, ST_HEX, ST_CARET, ST_END, ST_ERROR
  } state;
  const char *p;
  char *q;

  p = *src;			/* We don't want to double-indirect */
  q = *dest;			/* the whole darn time.  */

  count = 0;			/* No characters counted in yet.  */
  num = 0;

  state = ST_GND;		/* Start in ground state.  */
  while (state < ST_END)
    {
      switch (state)
	{
	case ST_GND:		/* Ground state (no escapes) */
	  switch (*p)
	    {
	    case ':':
	    case '\0':
	      state = ST_END;	/* End of string */
	      break;
	    case '\\':
	      state = ST_BACKSLASH; /* Backslash scape sequence */
	      ++p;
	      break;
	    case '^':
	      state = ST_CARET; /* Caret escape */
	      ++p;
	      break;
	    case '=':
	      if (equals_end)
		{
		  state = ST_END; /* End */
		  break;
		}
	      /* else fall through */
	    default:
	      *(q++) = *(p++);
	      ++count;
	      break;
	    }
	  break;

	case ST_BACKSLASH:	/* Backslash escaped character */
	  switch (*p)
	    {
	    case '0':
	    case '1':
	    case '2':
	    case '3':
	    case '4':
	    case '5':
	    case '6':
	    case '7':
	      state = ST_OCTAL;	/* Octal sequence */
	      num = *p - '0';
	      break;
	    case 'x':
	    case 'X':
	      state = ST_HEX;	/* Hex sequence */
	      num = 0;
	      break;
	    case 'a':		/* Bell */
	      num = 7;		/* Not all C compilers know what \a means */
	      break;
	    case 'b':		/* Backspace */
	      num = '\b';
	      break;
	    case 'e':		/* Escape */
	      num = 27;
	      break;
	    case 'f':		/* Form feed */
	      num = '\f';
	      break;
	    case 'n':		/* Newline */
	      num = '\n';
	      break;
	    case 'r':		/* Carriage return */
	      num = '\r';
	      break;
	    case 't':		/* Tab */
	      num = '\t';
	      break;
	    case 'v':		/* Vtab */
	      num = '\v';
	      break;
	    case '?':		/* Delete */
              num = 127;
	      break;
	    case '_':		/* Space */
	      num = ' ';
	      break;
	    case '\0':		/* End of string */
	      state = ST_ERROR;	/* Error! */
	      break;
	    default:		/* Escaped character like \ ^ : = */
	      num = *p;
	      break;
	    }
	  if (state == ST_BACKSLASH)
	    {
	      *(q++) = num;
	      ++count;
	      state = ST_GND;
	    }
	  ++p;
	  break;

	case ST_OCTAL:		/* Octal sequence */
	  if (*p < '0' || *p > '7')
	    {
	      *(q++) = num;
	      ++count;
	      state = ST_GND;
	    }
	  else
	    num = (num << 3) + (*(p++) - '0');
	  break;

	case ST_HEX:		/* Hex sequence */
	  switch (*p)
	    {
	    case '0':
	    case '1':
	    case '2':
	    case '3':
	    case '4':
	    case '5':
	    case '6':
	    case '7':
	    case '8':
	    case '9':
	      num = (num << 4) + (*(p++) - '0');
	      break;
	    case 'a':
	    case 'b':
	    case 'c':
	    case 'd':
	    case 'e':
	    case 'f':
	      num = (num << 4) + (*(p++) - 'a') + 10;
	      break;
	    case 'A':
	    case 'B':
	    case 'C':
	    case 'D':
	    case 'E':
	    case 'F':
	      num = (num << 4) + (*(p++) - 'A') + 10;
	      break;
	    default:
	      *(q++) = num;
	      ++count;
	      state = ST_GND;
	      break;
	    }
	  break;

	case ST_CARET:		/* Caret escape */
	  state = ST_GND;	/* Should be the next state... */
	  if (*p >= '@' && *p <= '~')
	    {
	      *(q++) = *(p++) & 037;
	      ++count;
	    }
	  else if ( *p == '?' )
	    {
	      *(q++) = 127;
	      ++count;
	    }
	  else
	    state = ST_ERROR;
	  break;

	default:
	  abort();
	}
    }

  *dest = q;
  *src = p;

  return state == ST_ERROR ? -1 : count;
}

static void
parse_ls_color (void)
{
  const char *p;		/* Pointer to character being parsed */
  char *buf;			/* color_buf buffer pointer */
  int state;			/* State of parser */
  int ind_no;			/* Indicator number */
  char label[3];		/* Indicator label */
  struct col_ext_type *ext;	/* Extension we are working on */
  struct col_ext_type *ext2;	/* Extra pointer */

  if ((p = getenv ("LS_COLORS")) == NULL || *p == '\0')
    return;

  ext = NULL;
  strcpy (label, "??");

  /* This is an overly conservative estimate, but any possible
     LS_COLORS string will *not* generate a color_buf longer than
     itself, so it is a safe way of allocating a buffer in
     advance.  */
  buf = color_buf = xstrdup (p);

  state = 1;
  while (state > 0)
    {
      switch (state)
	{
	case 1:		/* First label character */
	  switch (*p)
	    {
	    case ':':
	      ++p;
	      break;

	    case '*':
	      /* Allocate new extension block and add to head of
		 linked list (this way a later definition will
		 override an earlier one, which can be useful for
		 having terminal-specific defs override global).  */

	      ext = (struct col_ext_type *)
		xmalloc (sizeof (struct col_ext_type));
	      ext->next = col_ext_list;
	      col_ext_list = ext;

	      ++p;
	      ext->ext.string = buf;

	      state = (ext->ext.len =
		       get_funky_string (&buf, &p, 1)) < 0 ? -1 : 4;
	      break;

	    case '\0':
	      state = 0;	/* Done! */
	      break;

	    default:	/* Assume it is file type label */
	      label[0] = *(p++);
	      state = 2;
	      break;
	    }
	  break;

	case 2:		/* Second label character */
	  if (*p)
	    {
	      label[1] = *(p++);
	      state = 3;
	    }
	  else
	    state = -1;	/* Error */
	  break;

	case 3:		/* Equal sign after indicator label */
	  state = -1;	/* Assume failure... */
	  if (*(p++) == '=')/* It *should* be... */
	    {
	      for (ind_no = 0; indicator_name[ind_no] != NULL; ++ind_no)
		{
		  if (STREQ (label, indicator_name[ind_no]))
		    {
		      color_indicator[ind_no].string = buf;
		      state = ((color_indicator[ind_no].len =
				get_funky_string (&buf, &p, 0)) < 0 ? -1 : 1);
		      break;
		    }
		}
	      if (state == -1)
		error (0, 0, _("unrecognized prefix: %s"), label);
	    }
	 break;

	case 4:		/* Equal sign after *.ext */
	  if (*(p++) == '=')
	    {
	      ext->seq.string = buf;
	      state = (ext->seq.len =
		       get_funky_string (&buf, &p, 0)) < 0 ? -1 : 1;
	    }
	  else
	    state = -1;
	  break;
	}
    }

  if (state < 0)
    {
      struct col_ext_type *e;

      error (0, 0,
	     _("unparsable value for LS_COLORS environment variable"));
      free (color_buf);
      for (e = col_ext_list; e != NULL ; /* empty */)
	{
	  ext2 = e;
	  e = e->next;
	  free (ext2);
	}
      print_with_color = 0;
    }
}

/* Request that the directory named `name' have its contents listed later.
   If `realname' is nonzero, it will be used instead of `name' when the
   directory name is printed.  This allows symbolic links to directories
   to be treated as regular directories but still be listed under their
   real names. */

static void
queue_directory (const char *name, const char *realname)
{
  struct pending *new;

  new = (struct pending *) xmalloc (sizeof (struct pending));
  new->next = pending_dirs;
  pending_dirs = new;
  new->name = xstrdup (name);
  if (realname)
    new->realname = xstrdup (realname);
  else
    new->realname = 0;
}

/* Read directory `name', and list the files in it.
   If `realname' is nonzero, print its name instead of `name';
   this is used for symbolic links to directories. */

static void
print_dir (const char *name, const char *realname)
{
  register DIR *reading;
  register struct dirent *next;
  register int total_blocks = 0;

  errno = 0;
  reading = opendir (name);
  if (!reading)
    {
      error (0, errno, "%s", name);
      exit_status = 1;
      return;
    }

  /* Read the directory entries, and insert the subfiles into the `files'
     table.  */

  clear_files ();

  while ((next = readdir (reading)) != NULL)
    if (file_interesting (next))
      total_blocks += gobble_file (next->d_name, 0, name);

  if (CLOSEDIR (reading))
    {
      error (0, errno, "%s", name);
      exit_status = 1;
      /* Don't return; print whatever we got. */
    }

  /* Sort the directory contents.  */
  sort_files ();

  /* If any member files are subdirectories, perhaps they should have their
     contents listed rather than being mentioned here as files.  */

  if (trace_dirs)
    extract_dirs_from_files (name, 1);

  if (print_dir_name)
    {
      const char *dir;

      DIRED_INDENT ();
      dir = (realname ? realname : name);
      PUSH_CURRENT_DIRED_POS (&subdired_obstack);
      FPUTS (dir, stdout, strlen (dir));
      PUSH_CURRENT_DIRED_POS (&subdired_obstack);
      FPUTS_LITERAL (":\n", stdout);
    }

  if (format == long_format || print_block_size)
    {
      char buf[6 + 20 + 1 + 1];

      DIRED_INDENT ();
      sprintf (buf, "total %u\n", total_blocks);
      FPUTS (buf, stdout, strlen (buf));
    }

  if (files_index)
    print_current_files ();

  if (pending_dirs)
    PUTCHAR ('\n');
}

/* Add `pattern' to the list of patterns for which files that match are
   not listed.  */

static void
add_ignore_pattern (const char *pattern)
{
  register struct ignore_pattern *ignore;

  ignore = (struct ignore_pattern *) xmalloc (sizeof (struct ignore_pattern));
  ignore->pattern = pattern;
  /* Add it to the head of the linked list. */
  ignore->next = ignore_patterns;
  ignore_patterns = ignore;
}

/* Return nonzero if the file in `next' should be listed. */

static int
file_interesting (const struct dirent *next)
{
  register struct ignore_pattern *ignore;

  for (ignore = ignore_patterns; ignore; ignore = ignore->next)
    if (fnmatch (ignore->pattern, next->d_name, FNM_PERIOD) == 0)
      return 0;

  if (really_all_files
      || next->d_name[0] != '.'
      || (all_files
	  && next->d_name[1] != '\0'
	  && (next->d_name[1] != '.' || next->d_name[2] != '\0')))
    return 1;

  return 0;
}

/* Enter and remove entries in the table `files'.  */

/* Empty the table of files. */

static void
clear_files (void)
{
  register int i;

  for (i = 0; i < files_index; i++)
    {
      free (files[i].name);
      if (files[i].linkname)
	free (files[i].linkname);
    }

  files_index = 0;
  block_size_size = 4;
}

/* Add a file to the current table of files.
   Verify that the file exists, and print an error message if it does not.
   Return the number of blocks that the file occupies.  */

static int
gobble_file (const char *name, int explicit_arg, const char *dirname)
{
  register int blocks;
  register int val;
  register char *path;

  if (files_index == nfiles)
    {
      nfiles *= 2;
      files = (struct fileinfo *) xrealloc (files, sizeof (*files) * nfiles);
    }

  files[files_index].linkname = 0;
  files[files_index].linkmode = 0;

  if (explicit_arg || format_needs_stat)
    {
      /* `path' is the absolute pathname of this file. */

      if (name[0] == '/' || dirname[0] == 0)
	path = (char *) name;
      else
	{
	  path = (char *) alloca (strlen (name) + strlen (dirname) + 2);
	  attach (path, dirname, name);
	}

      if (trace_links)
	{
	  val = stat (path, &files[files_index].stat);
	  if (val < 0)
	    /* Perhaps a symbolically-linked to file doesn't exist; stat
	       the link instead. */
	    val = lstat (path, &files[files_index].stat);
	}
      else
	val = lstat (path, &files[files_index].stat);
      if (val < 0)
	{
	  error (0, errno, "%s", path);
	  exit_status = 1;
	  return 0;
	}

#ifdef S_ISLNK
      if (S_ISLNK (files[files_index].stat.st_mode)
	  && (explicit_arg || format == long_format))
	{
	  char *linkpath;
	  struct stat linkstats;

	  get_link_name (path, &files[files_index]);
	  linkpath = make_link_path (path, files[files_index].linkname);

	  /* Avoid following symbolic links when possible, ie, when
	     they won't be traced and when no indicator is needed. */
	  if (linkpath
	      && ((explicit_arg && format != long_format)
		  || indicator_style != none)
	      && stat (linkpath, &linkstats) == 0)
	    {
	      /* Symbolic links to directories that are mentioned on the
	         command line are automatically traced if not being
	         listed as files.  */
	      if (explicit_arg && format != long_format
		  && S_ISDIR (linkstats.st_mode))
		{
		  /* Substitute the linked-to directory's name, but
		     save the real name in `linkname' for printing.  */
		  if (!immediate_dirs)
		    {
		      const char *tempname = name;
		      name = linkpath;
		      linkpath = files[files_index].linkname;
		      files[files_index].linkname = (char *) tempname;
		    }
		  files[files_index].stat = linkstats;
		}
	      else
		/* Get the linked-to file's mode for the filetype indicator
		   in long listings.  */
		files[files_index].linkmode = linkstats.st_mode;
	    }
	  if (linkpath)
	    free (linkpath);
	}
#endif

#ifdef S_ISLNK
      if (S_ISLNK (files[files_index].stat.st_mode))
	files[files_index].filetype = symbolic_link;
      else
#endif
      if (S_ISDIR (files[files_index].stat.st_mode))
	{
	  if (explicit_arg && !immediate_dirs)
	    files[files_index].filetype = arg_directory;
	  else
	    files[files_index].filetype = directory;
	}
      else
	files[files_index].filetype = normal;

      blocks = convert_blocks (ST_NBLOCKS (files[files_index].stat),
			       kilobyte_blocks);
      if (blocks >= 10000 && block_size_size < 5)
	block_size_size = 5;
      if (blocks >= 100000 && block_size_size < 6)
	block_size_size = 6;
      if (blocks >= 1000000 && block_size_size < 7)
	block_size_size = 7;
    }
  else
    blocks = 0;

  files[files_index].name = xstrdup (name);
  files_index++;

  return blocks;
}

#ifdef S_ISLNK

/* Put the name of the file that `filename' is a symbolic link to
   into the `linkname' field of `f'. */

static void
get_link_name (const char *filename, struct fileinfo *f)
{
  char *linkbuf;
  register int linksize;

  linkbuf = (char *) alloca (PATH_MAX + 2);
  /* Some automounters give incorrect st_size for mount points.
     I can't think of a good workaround for it, though.  */
  linksize = readlink (filename, linkbuf, PATH_MAX + 1);
  if (linksize < 0)
    {
      error (0, errno, "%s", filename);
      exit_status = 1;
    }
  else
    {
      linkbuf[linksize] = '\0';
      f->linkname = xstrdup (linkbuf);
    }
}

/* If `linkname' is a relative path and `path' contains one or more
   leading directories, return `linkname' with those directories
   prepended; otherwise, return a copy of `linkname'.
   If `linkname' is zero, return zero. */

static char *
make_link_path (const char *path, const char *linkname)
{
  char *linkbuf;
  int bufsiz;

  if (linkname == 0)
    return 0;

  if (*linkname == '/')
    return xstrdup (linkname);

  /* The link is to a relative path.  Prepend any leading path
     in `path' to the link name. */
  linkbuf = strrchr (path, '/');
  if (linkbuf == 0)
    return xstrdup (linkname);

  bufsiz = linkbuf - path + 1;
  linkbuf = xmalloc (bufsiz + strlen (linkname) + 1);
  strncpy (linkbuf, path, bufsiz);
  strcpy (linkbuf + bufsiz, linkname);
  return linkbuf;
}
#endif

/* Remove any entries from `files' that are for directories,
   and queue them to be listed as directories instead.
   `dirname' is the prefix to prepend to each dirname
   to make it correct relative to ls's working dir.
   `recursive' is nonzero if we should not treat `.' and `..' as dirs.
   This is desirable when processing directories recursively.  */

static void
extract_dirs_from_files (const char *dirname, int recursive)
{
  register int i, j;
  register char *path;
  int dirlen;

  dirlen = strlen (dirname) + 2;
  /* Queue the directories last one first, because queueing reverses the
     order.  */
  for (i = files_index - 1; i >= 0; i--)
    if ((files[i].filetype == directory || files[i].filetype == arg_directory)
	&& (!recursive || is_not_dot_or_dotdot (files[i].name)))
      {
	if (files[i].name[0] == '/' || dirname[0] == 0)
	  {
	    queue_directory (files[i].name, files[i].linkname);
	  }
	else
	  {
	    path = (char *) xmalloc (strlen (files[i].name) + dirlen);
	    attach (path, dirname, files[i].name);
	    queue_directory (path, files[i].linkname);
	    free (path);
	  }
	if (files[i].filetype == arg_directory)
	  free (files[i].name);
      }

  /* Now delete the directories from the table, compacting all the remaining
     entries.  */

  for (i = 0, j = 0; i < files_index; i++)
    if (files[i].filetype != arg_directory)
      files[j++] = files[i];
  files_index = j;
}

/* Return nonzero if `name' doesn't end in `.' or `..'
   This is so we don't try to recurse on `././././. ...' */

static int
is_not_dot_or_dotdot (const char *name)
{
  char *t;

  t = strrchr (name, '/');
  if (t)
    name = t + 1;

  if (name[0] == '.'
      && (name[1] == '\0'
	  || (name[1] == '.' && name[2] == '\0')))
    return 0;

  return 1;
}

/* Sort the files now in the table.  */

static void
sort_files (void)
{
  int (*func) ();

  switch (sort_type)
    {
    case sort_none:
      return;
    case sort_time:
      switch (time_type)
	{
	case time_ctime:
	  func = sort_reverse ? rev_cmp_ctime : compare_ctime;
	  break;
	case time_mtime:
	  func = sort_reverse ? rev_cmp_mtime : compare_mtime;
	  break;
	case time_atime:
	  func = sort_reverse ? rev_cmp_atime : compare_atime;
	  break;
	default:
	  abort ();
	}
      break;
    case sort_name:
      func = sort_reverse ? rev_cmp_name : compare_name;
      break;
    case sort_extension:
      func = sort_reverse ? rev_cmp_extension : compare_extension;
      break;
    case sort_size:
      func = sort_reverse ? rev_cmp_size : compare_size;
      break;
    default:
      abort ();
    }

  qsort (files, files_index, sizeof (struct fileinfo), func);
}

/* Comparison routines for sorting the files. */

static int
compare_ctime (const struct fileinfo *file1, const struct fileinfo *file2)
{
  return longdiff (file2->stat.st_ctime, file1->stat.st_ctime);
}

static int
rev_cmp_ctime (const struct fileinfo *file2, const struct fileinfo *file1)
{
  return longdiff (file2->stat.st_ctime, file1->stat.st_ctime);
}

static int
compare_mtime (const struct fileinfo *file1, const struct fileinfo *file2)
{
  return longdiff (file2->stat.st_mtime, file1->stat.st_mtime);
}

static int
rev_cmp_mtime (const struct fileinfo *file2, const struct fileinfo *file1)
{
  return longdiff (file2->stat.st_mtime, file1->stat.st_mtime);
}

static int
compare_atime (const struct fileinfo *file1, const struct fileinfo *file2)
{
  return longdiff (file2->stat.st_atime, file1->stat.st_atime);
}

static int
rev_cmp_atime (const struct fileinfo *file2, const struct fileinfo *file1)
{
  return longdiff (file2->stat.st_atime, file1->stat.st_atime);
}

static int
compare_size (const struct fileinfo *file1, const struct fileinfo *file2)
{
  return longdiff (file2->stat.st_size, file1->stat.st_size);
}

static int
rev_cmp_size (const struct fileinfo *file2, const struct fileinfo *file1)
{
  return longdiff (file2->stat.st_size, file1->stat.st_size);
}

static int
compare_name (const struct fileinfo *file1, const struct fileinfo *file2)
{
  return strcmp (file1->name, file2->name);
}

static int
rev_cmp_name (const struct fileinfo *file2, const struct fileinfo *file1)
{
  return strcmp (file1->name, file2->name);
}

/* Compare file extensions.  Files with no extension are `smallest'.
   If extensions are the same, compare by filenames instead. */

static int
compare_extension (const struct fileinfo *file1, const struct fileinfo *file2)
{
  register char *base1, *base2;
  register int cmp;

  base1 = strrchr (file1->name, '.');
  base2 = strrchr (file2->name, '.');
  if (base1 == 0 && base2 == 0)
    return strcmp (file1->name, file2->name);
  if (base1 == 0)
    return -1;
  if (base2 == 0)
    return 1;
  cmp = strcmp (base1, base2);
  if (cmp == 0)
    return strcmp (file1->name, file2->name);
  return cmp;
}

static int
rev_cmp_extension (const struct fileinfo *file2, const struct fileinfo *file1)
{
  register char *base1, *base2;
  register int cmp;

  base1 = strrchr (file1->name, '.');
  base2 = strrchr (file2->name, '.');
  if (base1 == 0 && base2 == 0)
    return strcmp (file1->name, file2->name);
  if (base1 == 0)
    return -1;
  if (base2 == 0)
    return 1;
  cmp = strcmp (base1, base2);
  if (cmp == 0)
    return strcmp (file1->name, file2->name);
  return cmp;
}

/* List all the files now in the table.  */

static void
print_current_files (void)
{
  register int i;

  switch (format)
    {
    case one_per_line:
      for (i = 0; i < files_index; i++)
	{
	  print_file_name_and_frills (files + i);
	  putchar ('\n');
	}
      break;

    case many_per_line:
      print_many_per_line ();
      break;

    case horizontal:
      print_horizontal ();
      break;

    case with_commas:
      print_with_commas ();
      break;

    case long_format:
      for (i = 0; i < files_index; i++)
	{
	  print_long_format (files + i);
	  PUTCHAR ('\n');
	}
      break;
    }
}

static void
print_long_format (const struct fileinfo *f)
{
  char modebuf[20];
  char timebuf[40];

  /* 7 fields that may (worst case: 64-bit integral values) require 20 bytes,
     1 10-character mode string,
     1 24-character time string,
     9 spaces, one following each of these fields,
     and 1 trailing NUL byte.  */
  char bigbuf[7 * 20 + 10 + 24 + 9 + 1];
  char *p;
  time_t when;

  mode_string (f->stat.st_mode, modebuf);
  modebuf[10] = '\0';

  switch (time_type)
    {
    case time_ctime:
      when = f->stat.st_ctime;
      break;
    case time_mtime:
      when = f->stat.st_mtime;
      break;
    case time_atime:
      when = f->stat.st_atime;
      break;
    }

  strcpy (timebuf, ctime (&when));

  if (full_time)
    timebuf[24] = '\0';
  else
    {
      if (current_time > when + 6L * 30L * 24L * 60L * 60L	/* Old. */
	  || current_time < when - 60L * 60L)	/* In the future. */
	{
	  /* The file is fairly old or in the future.
	     POSIX says the cutoff is 6 months old;
	     approximate this by 6*30 days.
	     Allow a 1 hour slop factor for what is considered "the future",
	     to allow for NFS server/client clock disagreement.
	     Show the year instead of the time of day.  */
	  strcpy (timebuf + 11, timebuf + 19);
	}
      timebuf[16] = 0;
    }

  p = bigbuf;

  if (print_inode)
    {
      sprintf (p, "%*lu ", INODE_DIGITS, (unsigned long) f->stat.st_ino);
      p += strlen (p);
    }

  if (print_block_size)
    {
      sprintf (p, "%*u ", block_size_size,
	       (unsigned) convert_blocks (ST_NBLOCKS (f->stat),
					  kilobyte_blocks));
      p += strlen (p);
    }

  /* The space between the mode and the number of links is the POSIX
     "optional alternate access method flag". */
  sprintf (p, "%s %3u ", modebuf, (unsigned int) f->stat.st_nlink);
  p += strlen (p);

  if (numeric_users)
    sprintf (p, "%-8u ", (unsigned int) f->stat.st_uid);
  else
    sprintf (p, "%-8.8s ", getuser (f->stat.st_uid));
  p += strlen (p);

  if (!inhibit_group)
    {
      if (numeric_users)
	sprintf (p, "%-8u ", (unsigned int) f->stat.st_gid);
      else
	sprintf (p, "%-8.8s ", getgroup (f->stat.st_gid));
      p += strlen (p);
    }

  if (S_ISCHR (f->stat.st_mode) || S_ISBLK (f->stat.st_mode))
    sprintf (p, "%3u, %3u ", (unsigned) major (f->stat.st_rdev),
	     (unsigned) minor (f->stat.st_rdev));
  else
    sprintf (p, "%8lu ", (unsigned long) f->stat.st_size);
  p += strlen (p);

  sprintf (p, "%s ", full_time ? timebuf : timebuf + 4);
  p += strlen (p);

  DIRED_INDENT ();
  FPUTS (bigbuf, stdout, p - bigbuf);
  PUSH_CURRENT_DIRED_POS (&dired_obstack);
  print_name_with_quoting (f->name, f->stat.st_mode, f->linkok);
  PUSH_CURRENT_DIRED_POS (&dired_obstack);

  if (f->filetype == symbolic_link)
    {
      if (f->linkname)
	{
	  FPUTS_LITERAL (" -> ", stdout);
	  print_name_with_quoting (f->linkname, f->linkmode, f->linkok-1);
	  if (indicator_style != none)
	    print_type_indicator (f->linkmode);
	}
    }
  else if (indicator_style != none)
    print_type_indicator (f->stat.st_mode);
}

/* Set QUOTED_LENGTH to strlen(P) and return NULL if P == quoted(P).
   Otherwise, return xmalloc'd storage containing the quoted version
   of P and set QUOTED_LENGTH to the length of the quoted P.  */

static char *
quote_filename (register const char *p, size_t *quoted_length)
{
  register unsigned char c;
  const char *p0 = p;
  char *quoted, *q;
  int found_quotable;

  if (!quote_as_string && !quote_funny_chars && !qmark_funny_chars)
    {
      *quoted_length = strlen (p);
      return NULL;
    }

  found_quotable = 0;
  for (c = *p; c; c = *++p)
    {
      if (quote_funny_chars)
	{
	  switch (c)
	    {
	    case '\\':
	    case '\n':
	    case '\b':
	    case '\r':
	    case '\t':
	    case '\f':
	    case ' ':
	    case '"':
	      found_quotable = 1;
	      break;

	    default:
	      if (!ISGRAPH (c))
		found_quotable = 1;
	      break;
	    }
	}
      else
	{
	  if (!ISPRINT (c) && qmark_funny_chars)
	    found_quotable = 1;
	}
      if (found_quotable)
	break;
    }

  if (!found_quotable && !quote_as_string)
    {
      *quoted_length = p - p0;
      return NULL;
    }

  p = p0;
  quoted = xmalloc (4 * strlen (p) + 1);
  q = quoted;

#define SAVECHAR(c) *q++ = (c)
#define SAVE_2_CHARS(c12) \
    do { *q++ = ((c12)[0]); \
	 *q++ = ((c12)[1]); } while (0)

  if (quote_as_string)
    SAVECHAR ('"');

  while ((c = *p++))
    {
      if (quote_funny_chars)
	{
	  switch (c)
	    {
	    case '\\':
	      SAVE_2_CHARS ("\\\\");
	      break;

	    case '\n':
	      SAVE_2_CHARS ("\\n");
	      break;

	    case '\b':
	      SAVE_2_CHARS ("\\b");
	      break;

	    case '\r':
	      SAVE_2_CHARS ("\\r");
	      break;

	    case '\t':
	      SAVE_2_CHARS ("\\t");
	      break;

	    case '\f':
	      SAVE_2_CHARS ("\\f");
	      break;

	    case ' ':
	      SAVE_2_CHARS ("\\ ");
	      break;

	    case '"':
	      SAVE_2_CHARS ("\\\"");
	      break;

	    default:
	      if (ISGRAPH (c))
		SAVECHAR (c);
	      else
		{
		  char buf[5];
		  sprintf (buf, "\\%03o", (unsigned int) c);
		  q = stpcpy (q, buf);
		}
	    }
	}
      else
	{
	  if (ISPRINT (c))
	    SAVECHAR (c);
	  else if (!qmark_funny_chars)
	    SAVECHAR (c);
	  else
	    SAVECHAR ('?');
	}
    }

  if (quote_as_string)
    SAVECHAR ('"');

  *quoted_length = q - quoted;

  SAVECHAR ('\0');

  return quoted;
}

static void
print_name_with_quoting (const char *p, unsigned int mode, int linkok)
{
  char *quoted;
  size_t quoted_length;

  if (print_with_color)
    print_color_indicator (p, mode, linkok);

  quoted = quote_filename (p, &quoted_length);
  FPUTS (quoted != NULL ? quoted : p, stdout, quoted_length);
  if (quoted)
    free (quoted);

  if (print_with_color)
    {
      if (color_indicator[C_END].string != NULL)
	put_indicator (&color_indicator[C_END]);
      else
	{
	  put_indicator (&color_indicator[C_LEFT]);
	  put_indicator (&color_indicator[C_NORM]);
	  put_indicator (&color_indicator[C_RIGHT]);
	}
    }
}

/* Print the file name of `f' with appropriate quoting.
   Also print file size, inode number, and filetype indicator character,
   as requested by switches.  */

static void
print_file_name_and_frills (const struct fileinfo *f)
{
  if (print_inode)
    printf ("%*lu ", INODE_DIGITS, (unsigned long) f->stat.st_ino);

  if (print_block_size)
    printf ("%*u ", block_size_size,
	    (unsigned) convert_blocks (ST_NBLOCKS (f->stat),
				       kilobyte_blocks));

  print_name_with_quoting (f->name, f->stat.st_mode, f->linkok);

  if (indicator_style != none)
    print_type_indicator (f->stat.st_mode);
}

static void
print_type_indicator (unsigned int mode)
{
  if (S_ISDIR (mode))
    PUTCHAR ('/');

#ifdef S_ISLNK
  if (S_ISLNK (mode))
    PUTCHAR ('@');
#endif

#ifdef S_ISFIFO
  if (S_ISFIFO (mode))
    PUTCHAR ('|');
#endif

#ifdef S_ISSOCK
  if (S_ISSOCK (mode))
    PUTCHAR ('=');
#endif

  if (S_ISREG (mode) && indicator_style == all
      && (mode & (S_IEXEC | S_IXGRP | S_IXOTH)))
    PUTCHAR ('*');
}

static void
print_color_indicator (const char *name, unsigned int mode, int linkok)
{
  int type = C_FILE;
  struct col_ext_type *ext;	/* Color extension */
  size_t len;			/* Length of name */

  /* Is this a nonexistent file?  If so, linkok == -1.  */

  if (linkok == -1 && color_indicator[C_MISSING].string != NULL)
    {
      ext = NULL;
      type = C_MISSING;
    }
  else
    {
      /* Test if is is a recognized extension.  */

      len = strlen (name);
      name += len;		/* Pointer to final \0.  */
      for (ext = col_ext_list; ext != NULL; ext = ext->next)
	if (ext->ext.len <= len
	    && strncmp (name - ext->ext.len, ext->ext.string,
			ext->ext.len) == 0)
	  break;

      /*      if (ext == NULL)
	{ par pad car je veux les propiete des extensions que sur les fichier*/
	  if (S_ISDIR (mode))
	    type = C_DIR;

#ifdef S_ISLNK
	  else if (S_ISLNK (mode))
	    type = C_LINK; /*((!linkok && color_indicator[C_ORPHAN].string)
		    ? C_ORPHAN : C_LINK); par pad */
#endif

#ifdef S_ISFIFO
	  else if (S_ISFIFO (mode))
	    type = C_FIFO;
#endif

#ifdef S_ISSOCK
	  else if (S_ISSOCK (mode))
	    type = C_SOCK;
#endif

#ifdef S_ISBLK
	  else if (S_ISBLK (mode))
	    type = C_BLK;
#endif

#ifdef S_ISCHR
	  else if (S_ISCHR (mode))
	    type = C_CHR;
#endif

	  if (type == C_FILE && (mode & (S_IEXEC|S_IEXEC>>3|S_IEXEC>>6)) != 0)
	    type = C_EXEC;
	  /*} fin du if du dessus par pad */
    }
  /*************** pad ****************************/
  name-=len; /* retablit la vielle valeur du pointeur name */
  if ((len >=2)&&(name[0]=='.')&& (name[1]!='.'))
    {
      type = C_ORPHAN; /* par pad pour colorie les .machin */
      /*      printf("trouve\n"); */

    }
  /************** fin pad **********************************/

  put_indicator (&color_indicator[C_LEFT]);
  /*  put_indicator (ext ? &(ext->seq) : &color_indicator[type]); par pad enleve*/
  put_indicator ((type==C_FILE||type==C_EXEC) && ext ?&(ext->seq) : &color_indicator[type]); /* par pad rajoute */
  put_indicator (&color_indicator[C_RIGHT]);
}

/* Output a color indicator (which may contain nulls).  */
static void
put_indicator (const struct bin_str *ind)
{
  register int i;
  register char *p;

  p = ind->string;

  for (i = ind->len; i > 0; --i)
    putchar (*(p++));
}

static int
length_of_file_name_and_frills (const struct fileinfo *f)
{
  register char *p = f->name;
  register unsigned char c;
  register int len = 0;

  if (print_inode)
    len += INODE_DIGITS + 1;

  if (print_block_size)
    len += 1 + block_size_size;

  if (quote_as_string)
    len += 2;

  while ((c = *p++))
    {
      if (quote_funny_chars)
	{
	  switch (c)
	    {
	    case '\\':
	    case '\n':
	    case '\b':
	    case '\r':
	    case '\t':
	    case '\f':
	    case ' ':
	      len += 2;
	      break;

	    case '"':
	      if (quote_as_string)
		len += 2;
	      else
		len += 1;
	      break;

	    default:
	      if (ISPRINT (c))
		len += 1;
	      else
		len += 4;
	    }
	}
      else
	len += 1;
    }

  if (indicator_style != none)
    {
      unsigned filetype = f->stat.st_mode;

      if (S_ISREG (filetype))
	{
	  if (indicator_style == all
	      && (f->stat.st_mode & (S_IEXEC | S_IEXEC >> 3 | S_IEXEC >> 6)))
	    len += 1;
	}
      else if (S_ISDIR (filetype)
#ifdef S_ISLNK
	       || S_ISLNK (filetype)
#endif
#ifdef S_ISFIFO
	       || S_ISFIFO (filetype)
#endif
#ifdef S_ISSOCK
	       || S_ISSOCK (filetype)
#endif
	)
	len += 1;
    }

  return len;
}

static void
print_many_per_line (void)
{
  int filesno;			/* Index into files. */
  int row;			/* Current row. */
  int max_name_length;		/* Length of longest file name + frills. */
  int name_length;		/* Length of each file name + frills. */
  int pos;			/* Current character column. */
  int cols;			/* Number of files across. */
  int rows;			/* Maximum number of files down. */

  /* Compute the maximum file name length.  */
  max_name_length = 0;
  for (filesno = 0; filesno < files_index; filesno++)
    {
      name_length = length_of_file_name_and_frills (files + filesno);
      if (name_length > max_name_length)
	max_name_length = name_length;
    }

  /* Allow at least two spaces between names.  */
  max_name_length += 2;

  /* Calculate the maximum number of columns that will fit. */
  cols = line_length / max_name_length;
  if (cols == 0)
    cols = 1;
  /* Calculate the number of rows that will be in each column except possibly
     for a short column on the right. */
  rows = files_index / cols + (files_index % cols != 0);
  /* Recalculate columns based on rows. */
  cols = files_index / rows + (files_index % rows != 0);

  for (row = 0; row < rows; row++)
    {
      filesno = row;
      pos = 0;
      /* Print the next row.  */
      while (1)
	{
	  print_file_name_and_frills (files + filesno);
	  name_length = length_of_file_name_and_frills (files + filesno);

	  filesno += rows;
	  if (filesno >= files_index)
	    break;

	  indent (pos + name_length, pos + max_name_length);
	  pos += max_name_length;
	}
      putchar ('\n');
    }
}

static void
print_horizontal (void)
{
  int filesno;
  int max_name_length;
  int name_length;
  int cols;
  int pos;

  /* Compute the maximum file name length.  */
  max_name_length = 0;
  for (filesno = 0; filesno < files_index; filesno++)
    {
      name_length = length_of_file_name_and_frills (files + filesno);
      if (name_length > max_name_length)
	max_name_length = name_length;
    }

  /* Allow two spaces between names.  */
  max_name_length += 2;

  cols = line_length / max_name_length;
  if (cols == 0)
    cols = 1;

  pos = 0;
  name_length = 0;

  for (filesno = 0; filesno < files_index; filesno++)
    {
      if (filesno != 0)
	{
	  if (filesno % cols == 0)
	    {
	      putchar ('\n');
	      pos = 0;
	    }
	  else
	    {
	      indent (pos + name_length, pos + max_name_length);
	      pos += max_name_length;
	    }
	}

      print_file_name_and_frills (files + filesno);

      name_length = length_of_file_name_and_frills (files + filesno);
    }
  putchar ('\n');
}

static void
print_with_commas (void)
{
  int filesno;
  int pos, old_pos;

  pos = 0;

  for (filesno = 0; filesno < files_index; filesno++)
    {
      old_pos = pos;

      pos += length_of_file_name_and_frills (files + filesno);
      if (filesno + 1 < files_index)
	pos += 2;		/* For the comma and space */

      if (old_pos != 0 && pos >= line_length)
	{
	  putchar ('\n');
	  pos -= old_pos;
	}

      print_file_name_and_frills (files + filesno);
      if (filesno + 1 < files_index)
	{
	  putchar (',');
	  putchar (' ');
	}
    }
  putchar ('\n');
}

/* Assuming cursor is at position FROM, indent up to position TO.
   Use a TAB character instead of two or more spaces whenever possible.  */

static void
indent (int from, int to)
{
  while (from < to)
    {
      if (tabsize > 0 && to / tabsize > (from + 1) / tabsize)
	{
	  putchar ('\t');
	  from += tabsize - from % tabsize;
	}
      else
	{
	  putchar (' ');
	  from++;
	}
    }
}

/* Put DIRNAME/NAME into DEST, handling `.' and `/' properly. */

static void
attach (char *dest, const char *dirname, const char *name)
{
  const char *dirnamep = dirname;

  /* Copy dirname if it is not ".". */
  if (dirname[0] != '.' || dirname[1] != 0)
    {
      while (*dirnamep)
	*dest++ = *dirnamep++;
      /* Add '/' if `dirname' doesn't already end with it. */
      if (dirnamep > dirname && dirnamep[-1] != '/')
	*dest++ = '/';
    }
  while (*name)
    *dest++ = *name++;
  *dest = 0;
}

static void
usage (int status)
{
  if (status != 0)
    fprintf (stderr, _("Try `%s --help' for more information.\n"),
	     program_name);
  else
    {
      printf (_("Usage: %s [OPTION]... [FILE]...\n"), program_name);
      printf (_("\
List information about the FILEs (the current directory by default).\n\
Sort entries alphabetically if none of -cftuSUX nor --sort.\n\
\n\
  -A, --almost-all           do not list implied . and ..\n\
  -a, --all                  do not hide entries starting with .\n\
  -B, --ignore-backups       do not list implied entries ending with ~\n\
  -b, --escape               print octal escapes for nongraphic characters\n\
  -C                         list entries by columns\n\
  -c                         sort by change time; with -l: show ctime\n\
      --color[=WHEN]         control whether color is used to distinguish file\n\
                               types.  WHEN may be `never', `always', or `auto'\n\
  -D, --dired                generate output designed for Emacs' dired mode\n\
  -d, --directory            list directory entries instead of contents\n\
  -F, --classify             append a character for typing each entry\n\
  -f                         do not sort, enable -aU, disable -lst\n\
      --format=WORD          across -x, commas -m, horizontal -x, long -l,\n\
                               single-column -1, verbose -l, vertical -C\n\
      --full-time            list both full date and full time\n"));

      printf (_("\
  -G, --no-group             inhibit display of group information\n\
  -g                         (ignored)\n\
  -I, --ignore=PATTERN       do not list implied entries matching shell PATTERN\n\
  -i, --inode                print index number of each file\n\
  -k, --kilobytes            use 1024 blocks, not 512 despite POSIXLY_CORRECT\n\
  -L, --dereference          list entries pointed to by symbolic links\n\
  -l                         use a long listing format\n\
  -m                         fill width with a comma separated list of entries\n\
  -N, --literal              print raw entry names (don't treat e.g. control\n\
                               characters specially)\n\
  -n, --numeric-uid-gid      list numeric UIDs and GIDs instead of names\n\
  -o                         use long listing format without group info\n\
  -p                         append a character for typing each entry\n\
  -Q, --quote-name           enclose entry names in double quotes\n\
  -q, --hide-control-chars   print ? instead of non graphic characters\n\
  -R, --recursive            list subdirectories recursively\n\
  -r, --reverse              reverse order while sorting\n\
  -S                         sort by file size\n"));

      printf (_("\
  -s, --size                 print block size of each file\n\
      --sort=WORD            ctime -c, extension -X, none -U, size -S,\n\
                               status -c, time -t\n\
      --time=WORD            atime -u, access -u, use -u\n\
  -T, --tabsize=COLS         assume tab stops at each COLS instead of 8\n\
  -t                         sort by modification time; with -l: show mtime\n\
  -U                         do not sort; list entries in directory order\n\
  -u                         sort by last access time; with -l: show atime\n\
  -w, --width=COLS           assume screen width instead of current value\n\
  -x                         list entries by lines instead of by columns\n\
  -X                         sort alphabetically by entry extension\n\
  -1                         list one file per line\n\
      --help                 display this help and exit\n\
      --version              output version information and exit\n\
\n\
By default, color is not used to distinguish types of files.  That is\n\
equivalent to using --color=none.  Using the --color option without the\n\
optional WHEN argument is equivalent to using --color=always.  With\n\
--color=auto, color codes are output only if standard output is connected\n\
to a terminal (tty).\n\
"
		));
    }
  exit (status);
}
