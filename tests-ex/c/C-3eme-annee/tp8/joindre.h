#include "schema.h"


/* Type booleen */
typedef enum {FAUX, VRAI} Bool;

typedef struct t_elem_i {
  ENTREE ent;
  struct t_elem_i *succ;
} t_elem_i;

typedef struct {
  t_elem_i *tete, *ec;
} t_liste_i;

