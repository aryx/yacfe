typedef enum {faux,vrai}Bool;
typedef int Element ;

typedef struct cellule
  { 
    Element val ;
    struct cellule *succ ;
   } Cellule ;

typedef struct {Cellule *tete, *ec, *predec ;} Liste ;

/*prototypes : */
extern void initliste(Liste  *l);
extern Bool horsliste(Liste *l);
extern void entete(Liste  *l);
extern void suc (Liste *l);
extern Bool listevide(Liste *l);
extern void ajoutd(Liste *l, Element v);
extern void supprime(Liste *l);
extern Element valcour(Liste *l);
 
