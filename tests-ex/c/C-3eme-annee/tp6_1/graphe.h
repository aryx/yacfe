
typedef enum {faux , vrai} Bool;


/*
 * Sommet code le sommet d'un graphe par un entier positif
 */
 
 
typedef int     Sommet;



/*
 * Succ comporte la double information
 *           un pointeur sur une table de sommets successeurs
 *           le nombre de successeur
 */
typedef struct
   {
     Sommet *ptsom;
     int    nbsucc;
   } Succ;



/*
 * Grapheds comporte la double information
 *           un pointeur sur un vecteur de pointeur
 *           le nombre de sommet du graphe
 */
typedef struct
   {
     Succ   *ptsucc;
     int     nbsom;
   } Grapheds;


/*
 * Graphema comporte la double information
 *           un pointeur sur les booleens codant pa presence des arcs
 *           le nombre de sommet du graphe
 */
typedef struct
   {
     Bool   *pt2dim;
     int    nbsom;
   } Graphema;



/* prototypes */

extern Graphema ds_vers_ma(Grapheds *g);

extern Grapheds ma_vers_ds(Graphema g);

extern Grapheds saisiegraphe_ds(void);

extern void ecrigraphe_ma(Graphema g);

extern Succ *alloueptsucc(int nb);

extern Sommet *ajuste( Succ *pts);

extern void ajoute(Succ *pts, Sommet s);

extern Sommet *alloueptsom(int nb);

extern void libere(Grapheds *gds) ;
