typedef struct {
  int nf;
  int np;
  int qte;
  char nom[12];
  int remise;
  char ville[12];
} JOINTURE;

typedef struct {
  int nf;
  int np;
  int qte;
} MAFOURNITURE;
	
typedef struct {
  int nf;
  char nom[12];
  int remise;
  char ville[12];
} FOURNISSEUR;

typedef struct {
  int nf;
  long adoctet;
} ENTREE;
