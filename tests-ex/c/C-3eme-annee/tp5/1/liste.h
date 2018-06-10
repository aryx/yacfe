typedef enum {faux,vrai}Bool;
typedef int Element;

typedef struct cellule
  {
    Element val ;
    struct cellule *succ ;
  } Cellule ;


typedef Cellule *Liste ;

extern const Liste listevide  ;

/*prototypes : */

extern  Element  car(Liste  l);
extern  Liste cdr(Liste l); 
extern  Liste cons(Element e,Liste  l);
extern  Bool null(Liste l);
