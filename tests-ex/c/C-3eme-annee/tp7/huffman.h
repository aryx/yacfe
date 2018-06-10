/* Type booleen */
typedef enum {FAUX, VRAI} Bool;

/* Type feuille */
typedef struct {
  char car;
  int freq;
} t_feuille;
 
/* Type noeud contenu dans l'arbre de Huffman */

typedef struct t_noeudfeuille *ptr_noeudfeuille;

typedef struct {
  int spoids;
  ptr_noeudfeuille filsg, filsd;
} t_noeud;

typedef enum {FEUILLE, NOEUD} t_type;

/* Type union contenant soit un noeud, soit une feuille */
typedef struct t_noeudfeuille{
  t_type type;
  union {
    t_noeud noeud;
    t_feuille feuille;
  } un;
} t_noeudfeuille;

/* Type de l'arbre de Huffman */
typedef struct{
  ptr_noeudfeuille racine, ec, predec;
} t_arbre_huffman;


/* Type de la file de priorite */
typedef struct t_elemfile {
  t_noeudfeuille *val;
  struct t_elemfile *succ;
} t_elemfile;

typedef struct {
  t_elemfile *tete, *ec;
} t_file;


/* Type de l'alphabet */
typedef struct {
  int nb;
  t_feuille *alph;
} t_alphabet ;
