#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <arpa/inet.h>

typedef unsigned char u8;
typedef unsigned long u32;

typedef struct {
  u32 registers[8];
  int finger;
  u32 *program;
  void (*output)(u8);
  u32 (*input)(void);
} um32;

static void um32_give_up()
{
  fprintf(stderr, "Giving up.\n");
  exit(EXIT_FAILURE);
}

static void um32_init(um32 *u, void (*output)(u8), u32 (*input)(void), u32 *program) {
  int i;

  for(i = 0; i < 8; i ++) u->registers[i] = 0;
  u->finger = 0;
  u->output = output;
  u->input = input;
  u->program = program;
}

static inline u32 *um32_allocate_table(int m)
{
  u32 *t;

  t = malloc((m + 1) * sizeof(u32));
  if(!t) {
    fprintf(stderr, "um32_allocate_table: can't allocate %d words.\n", m);
    um32_give_up();
  }
  memset(t + 1, 0, m * sizeof(u32));
  *t = m;
  return t + 1;
}

static inline u32 um32_table_size(u32 *t)
{
  return t[-1];
}

static inline u32 *um32_duplicate_table(u32 *t)
{
  int m;
  u32 *s;

  m = um32_table_size(t);
  s = um32_allocate_table(m);
  memcpy(s, t, m * sizeof(u32));
  return s;
}

static inline void um32_free_table(u32 *t)
{
  free(t - 1);
}

void um32_read_bytes(int fd, u8 *dst, int m) {
  int r;
  while(m > 0) {
    r = read(fd, dst, m);
    if(r < 0) {
      fprintf(stderr, "um32_stat: can't read: %s.\n", strerror(errno));
      um32_give_up();
    }
    m -= r;
    dst += r;
  }
}

u32 *um32_read_scroll(char *fn)
{
  int fd;
  struct stat st;
  u32 *t;
  int m;
  int i;

  fd = open(fn, O_RDONLY);

  if(fd < 0) {
    fprintf(stderr, "um32_read_scroll: can't open file %s: %s.\n", fn, strerror(errno));
    um32_give_up();
  }

  if(fstat(fd, &st)) {
    fprintf(stderr, "um32_stat: can't stat file %s: %s.\n", fn, strerror(errno));
    um32_give_up();
  }

  m = st.st_size / sizeof(u32);
  t = um32_allocate_table(m);
  um32_read_bytes(fd, (u8 *) t, sizeof(u32) * m);

  for(i = 0; i < m; i++) {
    t[i] = ntohl(t[i]);
  }
  return t;
}

#define OP_CMOVE 0
#define OP_INDEX 1
#define OP_AMEND 2
#define OP_ADD 3
#define OP_MUL 4
#define OP_DIV 5
#define OP_NAND 6
#define OP_HALT 7
#define OP_ALLOC 8
#define OP_ABANDON 9
#define OP_OUTPUT 10
#define OP_INPUT 11
#define OP_LOAD 12
#define OP_ORTHOGRAPHY 13

void um32_debug(FILE *f, um32 *u)
{
  int i;
  fprintf(f, "Finger: 0x%08x\n", u->finger);
  fprintf(f, "Registers:");
  for(i = 0; i < 8; i++) {
    fprintf(f, " 0x%08lx", u->registers[i]);
  }
  fprintf(f, "\n");
}

static inline int um32_step(um32 *u) {
  u32 instr;
  u8 opcode;
  u8 a, b, c;
  u32 *r;

  r = u->registers;

  instr = u->program[u->finger ++];
  opcode = instr >> 28;
  if(opcode == OP_ORTHOGRAPHY) {
    a = (instr >> 25) & 7;
    r[a] = (instr & 0x1ffffff);
    return 1;
  }
  a = (instr >> 6) & 7;
  b = (instr >> 3) & 7;
  c = instr & 7;
  switch(opcode) {
    case OP_CMOVE: if(r[c]) r[a] = r[b]; break;
    case OP_INDEX:
                     if(!r[b]) {
                       r[a] = u->program[r[c]];
                     } else {
                       r[a] = ((u32 *) r[b])[r[c]];
                     }
                     break;
    case OP_AMEND:
                     if(!r[a]) {
                       u->program[r[b]] = r[c];
                     } else {
                       ((u32 *) r[a])[r[b]] = r[c];
                     }
                     break;
    case OP_ADD: r[a] = r[b] + r[c]; break;
    case OP_MUL: r[a] = r[b] * r[c]; break;
    case OP_DIV: r[a] = r[b] / r[c]; break;
    case OP_NAND: r[a] = ~(r[b] & r[c]); break;
    case OP_HALT: return 0; break; /* Halted */
    case OP_ALLOC: r[b] = (u32) um32_allocate_table(r[c]); break;
    case OP_ABANDON: um32_free_table((u32 *) r[c]); break;
    case OP_OUTPUT: u->output(r[c]); break;
    case OP_INPUT: r[c] = u->input(); break;
    case OP_LOAD:
         if(!r[b]) {
           u->finger = r[c];
         } else {
           //u32 *old_program;
           //old_program = u->program;
           u->program = um32_duplicate_table((u32 *) r[b]);
           u->finger = r[c];
           //um32_free_table(old_program);
         }
         break;
  }
  return 1;
}

static inline void um32_stdoutput(u8 c)
{
  fputc(c, stdout);
  fflush(stdout);
}

static inline u32 um32_stdinput(void)
{
  u32 c;
  c = fgetc(stdin);
  if(c == EOF) c = -1;
  return c;
}

int main(int argc, char **argv)
{
  um32 u;
  u32 *program;
  char *fn;

  if(argc != 2) {
    fprintf(stderr, "usage: um32 <program>\n");
    exit(EXIT_FAILURE);
  }

  fn = argv[1];

  program = um32_read_scroll(fn);
  printf("Loaded program of %ld words.\n", um32_table_size(program));
  um32_init(&u, um32_stdoutput, um32_stdinput, program);

  while(um32_step(&u)) {
    /* um32_debug(stdout, &u); */
  }

  return 0;
}
