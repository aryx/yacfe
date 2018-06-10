/************************************************************************
 *module de gestion des couleurs
 *par pad
 *tiré du package de gnu fileutils notemment ls.c
 *************************************************************************/
  
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <sys/stat.h>

#define S_IXUGO         (S_IXUSR|S_IXGRP|S_IXOTH) /* dans linux/stat.h mais pas standard */
/* jai modifie error qui etait lourd -> dans tout ce qui suit 
   jai modifie les appels a error */

static void error (char *status)
{
  fprintf(stderr,"%s\n",status);
  exit (1);
}


/* regex.c */
#define STREQ(s1, s2) ((strcmp (s1, s2) == 0))

/*xmalloc.c */
static void *
fixup_null_alloc (n)
     size_t n;
{
  void *p;

  p = 0;
  if (n == 0)
    p = malloc ((size_t) 1);
  if (p == 0)
    error ("Memory exhausted"); /* modif pad */
  return p;
}

/* Allocate N bytes of memory dynamically, with error checking.  */

static void *
xmalloc (n)
     size_t n;
{
  void *p;

  p = malloc (n);
  if (p == 0)
    p = fixup_null_alloc (n);
  return p;
}




/*xstdup.c du rep lib */
/* Return a newly allocated copy of STRING.  */

static char *
xstrdup (string)
     char *string;
{
  return strcpy (xmalloc (strlen (string) + 1), string);
}


/* */





#define LEN_STR_PAIR(s) sizeof (s) - 1, s

/* Null is a valid character in a color indicator (think about Epson
   printers, for example) so we have to use a length/buffer string
   type.  */

struct bin_str
  {
    unsigned int len;		/* Number of bytes */
    char *string;		/* Pointer to the same */
  };






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
static struct col_ext_type *col_ext_list = NULL;

static char *color_buf;


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
	  else if ( *p == '?')
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







extern void
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
		error ("unrecognized prefix"); /* modif pad */
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

      error ("unparsable value for LS_COLORS environment variable"); /* modif pad */
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

/**********************************************************************
 * fonction de pad 
 **********************************************************************/


static struct bin_str trouve_extension(const char *name,umode_t mode)
{
  struct col_ext_type *ext;    
  size_t len;

  int type = C_FILE;
  if (S_ISDIR (mode))
    type = C_DIR;
  else if (S_ISLNK (mode))
    type = C_LINK;
  else if (S_ISFIFO (mode))
    type = C_FIFO;
  else if (S_ISSOCK (mode))
    type = C_SOCK;
  else if (S_ISBLK (mode))
    type = C_BLK;
  else if (S_ISCHR (mode))
    type = C_CHR;
  if (type == C_FILE && (mode & S_IXUGO) != 0)
    type = C_EXEC;
  

  if (type!=C_FILE) return color_indicator[type];

  len = strlen (name);
  name += len;		/* Pointer to final \0.  */
  for (ext = col_ext_list; ext != NULL; ext = ext->next)
    {
      if (ext->ext.len <= len
	  && strncmp (name - ext->ext.len, ext->ext.string,
		      ext->ext.len) == 0) return ext->seq;
    }
  return color_indicator[C_FILE]; /* pas trouve -> retourne la couleur de fi */
}

/* pas de gestion des background color */
static int couleur_de_bin_str(struct bin_str val)
{
  if ((val.len!=5)||
      (val.string[2]!=';')||
      (!isdigit(val.string[0]))||
      (!isdigit(val.string[1]))||
      (!isdigit(val.string[3]))||
      (!isdigit(val.string[4]))
      ) return 0; /* erreur de format */
  
  return ((val.string[1]-'0')*8 + (val.string[4]-'0'));

}

/* fonction exporte */
extern int color_of_extension(const char *chaine,umode_t mode)
{
  return couleur_de_bin_str(trouve_extension(chaine,mode));
}


/******************************************************************************/
/* utile pour le deboggage */

/* je defini print car peut pas faire de printf("%s",val.string[i]) car les string se termine pas par \0 */
void print(struct bin_str val)
{
  int i;
  for (i=0;i<val.len;i++)
    printf("%c",val.string[i]);
  
}

void affiche_ls_color(void)
{
  struct col_ext_type *ext;
  int i; 

  printf("extension \n");
  for (ext = col_ext_list; ext != NULL; ext = ext->next)
    {
      print(ext->ext);
      printf("\t->");
      print(ext->seq);
      printf("\tvaleur%d\n",couleur_de_bin_str(ext->seq));
    }
  printf("les autres \n");
  for (i=0;indicator_name[i]!=NULL;i++)
    {
      printf("%s\t->",indicator_name[i]);
      print(color_indicator[i]);
      printf("\tvaleur%d\n",couleur_de_bin_str(color_indicator[i]));
    }
}




void main(void)
{
  struct stat buf;
  char *chaine;

  chaine=malloc(20);

  parse_ls_color(); 
  affiche_ls_color();

  /*  printf("extension ->");
  print(trouve_extension("dde.zip"));
  printf(" val: %d\n",trouve_couleur("dde.zip"));
  printf("\n");*/
  
  while(1) {
    printf("rentrer file\n");
    scanf("%s",chaine);
    lstat(chaine,&buf);
    printf(" val: %d\n",color_of_extension(chaine,buf.st_mode));

    

  }


  
  
}
