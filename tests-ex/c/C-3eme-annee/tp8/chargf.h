#include "schema.h"

/* Type booleen */
typedef enum {FAUX, VRAI} Bool;

typedef struct t_elem_f {
  int nf, rang;
  struct t_elem_f *succ;
} t_elem_f;

typedef struct {
  t_elem_f *tete, *ec, *predec;
} t_liste_f;

