/* Module de visualisation des differents fichiers */
#include <stdio.h>
#include "schema.h"

void main (int argc, char *argv[]){
  FILE *relf, *relmf;
  int j;
  FOURNISSEUR four;
  MAFOURNITURE mafo;

  if ((relf = fopen ("relf", "r")) == NULL) {
    printf ("\n***Impossible d'ouvrir le fichier relf.\n");
    return (2);
  }

  if ((relmf = fopen ("relmf", "r")) == NULL) {
    printf ("\n***Impossible d'ouvrir le fichier relmf.\n");
    return (2);
  }

  printf ("\nLecture de relf:\n");
  fseek (relf, 28, SEEK_SET);
  for (j=0; j<3; j++){
	/* Lecture dans le fichier temporaire */
    if (fread (&four, sizeof(FOURNISSEUR), 1, relf) != 0)

      printf ("  %d  %s  %d  %s\n", four.nf, four.nom, four.remise, four.ville);
  }

  printf ("\nLecture de relmf:\n");
  for (j=0; j<8; j++){
	/* Lecture dans le fichier temporaire */
    fread (&mafo, sizeof(MAFOURNITURE), 1, relmf);

    printf ("  %d %d  %d\n", mafo.nf, mafo.np, mafo.qte);
  }
}
