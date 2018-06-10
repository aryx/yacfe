
typedef enum {faux , vrai} Bool;


/* 
 * Comprect permet la representation des nombres complexes en rectangulaire
 *      z = partie reelle + i partie imaginaire
 */
typedef struct
  {
    float  preel;     /*      partie reelle                       */
    float  pimag;     /*      partie imaginaire                   */
  } Comprect;

/* 
 * Comppol permet la representation des nombres complexes en polaire
 *      z = module * (e exposant i argument)
 */  
typedef struct
  {
    float  module;     /*      module                             */
    float  argument;   /*      argument                           */
  } Comppol;

/* 
 * Comp permet de parler des nombres complexes en faisant abstraction
 *  de leur representation    
 */ 
typedef union
  {
    Comprect rep1;     /*      representation rectangulaire       */
    Comppol  rep2;     /*      representation polaire             */
  } Comp;

/* 
 * Repr permet le codage par la constante rect et la constante pol de
 * la representation choisie 
 */  
typedef enum
  {
    rect,
    pol
  } Repr;

/*
 * Complexe comporte a la fois l'indicateur de choix de representation
 * et la representation effective
 */  
typedef struct
  { 
    Repr indicrep;     /*    choix de representation               */
    Comp valeur;       /*    valeur dans la representation choisie */
  } Complexe;


/* prototypes */


extern float partreelle (Complexe z);

extern float partimag (Complexe z);

extern float partmodule (Complexe z);

extern float partargument (Complexe z);

extern Complexe addc (Complexe z1, Complexe z2);

extern Complexe sousc (Complexe z1, Complexe z2);

extern Complexe mulc (Complexe z1, Complexe z2);

extern Complexe divc (Complexe z1, Complexe z2);

extern Complexe lirec (void);

extern void ecrirec (Complexe z); 

extern Complexe initcrect (float pr, float pi);

extern Complexe initcpol (float md, float ar);


extern  const Complexe C_i;
