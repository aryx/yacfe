#include <stdio.h>
#include "othello.h"

int evaluer()
{
  int val = 0;
  
  val+= 64 * (Tableau[0] + Tableau[7-0] + Tableau[63-0] + Tableau[63-7]);
  val+= 00 * (Tableau[1] + Tableau[7-1] + Tableau[63-1] + Tableau[63-7+1]);
  val+= 32 * (Tableau[2] + Tableau[7-2] + Tableau[63-2] + Tableau[63-7+2]);
  val+= 32 * (Tableau[3] + Tableau[7-3] + Tableau[63-3] + Tableau[63-7+3]);

  val+= 00 * (Tableau[8+0] + Tableau[8+7-0] + Tableau[63-8-0] + Tableau[63-8-7]);
  val+=-64 * (Tableau[8+1] + Tableau[8+7-1] + Tableau[63-8-1] + Tableau[63-8-7+1]);
  val+=-32 * (Tableau[8+2] + Tableau[8+7-2] + Tableau[63-8-2] + Tableau[63-8-7+2]);
  val+=-32 * (Tableau[8+3] + Tableau[8+7-3] + Tableau[63-8-3] + Tableau[63-8-7+3]);

  val+= 32 * (Tableau[16+0] + Tableau[16+7-0] + Tableau[63-16-0] + Tableau[63-16-7]);
  val+=-32 * (Tableau[16+1] + Tableau[16+7-1] + Tableau[63-16-1] + Tableau[63-16-7+1]);
  val+= 01 * (Tableau[16+2] + Tableau[16+7-2] + Tableau[63-16-2] + Tableau[63-16-7+2]);
  val+= 01 * (Tableau[16+3] + Tableau[16+7-3] + Tableau[63-16-3] + Tableau[63-16-7+3]);

  val+= 32 * (Tableau[24+0] + Tableau[24+7-0] + Tableau[63-24-0] + Tableau[63-24-7]);
  val+=-32 * (Tableau[24+1] + Tableau[24+7-1] + Tableau[63-24-1] + Tableau[63-24-7+1]);
  val+= 01 * (Tableau[24+2] + Tableau[24+7-2] + Tableau[63-24-2] + Tableau[63-24-7+2]);
  val+= 01 * (Tableau[24+3] + Tableau[24+7-3] + Tableau[63-24-3] + Tableau[63-24-7+3]);

  val *= 256;
  if (val < 0) val *= 16;
  return(val);
}


int coupJouableHG(int i, int jo)
{ int fRetour = 0;
  for(;;) { if (i < 8 || (i % 8) == 0) return(0);
            i -= 9;
            if (Tableau[i] ==  jo) return(fRetour);
            if (Tableau[i] == -jo) fRetour = 1; else return(0); }  }
int coupJouableH (int i, int jo)
{ int fRetour = 0;
  for(;;) { if (i < 8) return(0);
            i -= 8;
            if (Tableau[i] ==  jo) return(fRetour);
            if (Tableau[i] == -jo) fRetour = 1; else return(0); }  }
int coupJouableHD(int i, int jo)
{ int fRetour = 0;
  for(;;) { if (i < 8 || (i % 8) == 7) return(0);
            i -= 7;
            if (Tableau[i] ==  jo) return(fRetour);
            if (Tableau[i] == -jo) fRetour = 1; else return(0); }  }

int coupJouableG (int i, int jo)
{ int fRetour = 0;
  for(;;) { if ((i % 8) == 0) return(0);
            i -= 1;
            if (Tableau[i] ==  jo) return(fRetour);
            if (Tableau[i] == -jo) fRetour = 1; else return(0); }  }

int coupJouableD (int i, int jo)
{ int fRetour = 0;
  for(;;) { if ((i % 8) == 7) return(0);
            i += 1;
            if (Tableau[i] ==  jo) return(fRetour);
            if (Tableau[i] == -jo) fRetour = 1; else return(0); }  }
int coupJouableBG(int i, int jo)
{ int fRetour = 0;
  for(;;) { if (i > 48 || (i % 8) == 0) return(0);
            i += 7;
            if (Tableau[i] ==  jo) return(fRetour);
            if (Tableau[i] == -jo) fRetour = 1; else return(0); }  }
int coupJouableB (int i, int jo)
{ int fRetour = 0;
  for(;;) { if (i > 48) return(0);
            i += 8;
            if (Tableau[i] ==  jo) return(fRetour);
            if (Tableau[i] == -jo) fRetour = 1; else return(0); }  }
int coupJouableBD(int i, int jo)
{ int fRetour = 0;
  for(;;) { if (i > 48 || (i % 8) == 7) return(0);
            i += 9;
            if (Tableau[i] ==  jo) return(fRetour);
            if (Tableau[i] == -jo) fRetour = 1; else return(0); }  }


int coupJouable(int i, int jo)
{
  return( 
    (Tableau[i] == 0) &&
    (coupJouableHG(i, jo) || coupJouableH(i, jo) || coupJouableHD(i, jo) || 
     coupJouableG (i, jo) || coupJouableD(i, jo) || 
     coupJouableBG(i, jo) || coupJouableB(i, jo) || coupJouableBD(i, jo)));
}


void jouerCoupDir(int i, int jo, int dir)
{ for(;;) { i += dir;
            if (Tableau[i] == jo) return;
            Tableau[i] = -Tableau[i]; } }


void jouerCoup(int i, int jo)
{
  if (Tableau[i] == 0) {
    if (coupJouableHG(i, jo)) jouerCoupDir(i, jo, -9);
    if (coupJouableH (i, jo)) jouerCoupDir(i, jo, -8);
    if (coupJouableHD(i, jo)) jouerCoupDir(i, jo, -7);
    if (coupJouableG (i, jo)) jouerCoupDir(i, jo, -1);
    if (coupJouableD (i, jo)) jouerCoupDir(i, jo, +1);
    if (coupJouableBG(i, jo)) jouerCoupDir(i, jo, +7);
    if (coupJouableB (i, jo)) jouerCoupDir(i, jo, +8);
    if (coupJouableBD(i, jo)) jouerCoupDir(i, jo, +9);
    Tableau[i] = jo;
  } else {
    printf("Erreur, coup non jouable\n");
    exit(1);
  }    
}

void afficherTableau(int *pstTableau)
{ int i, j; 
  
  printf("\n_|");
  for(i = 0; i < 8; i++) printf("%d ", i);
  for(i = 0; i < 8; i++) {
    printf("\n%d|", i);
    for(j = 0; j < 8; j++) {
      if (pstTableau[j*8 + i] == -1) printf("X");
      if (pstTableau[j*8 + i] ==  1) printf("O");
      if (pstTableau[j*8 + i] ==  0) printf(" ");
      printf("|");
    }
  }
  printf("\n");
  for(i = 0; i < 8; i++) printf("--");
  printf("\n");
}


void afficherTableaux(int *pstTableau, int * pstTableauOld) 
{ int i, j; 
  
  printf("\n_|");
  for(i = 0; i < 8; i++) printf("%d ", i);
  printf("  --apres--->  _|");
  for(i = 0; i < 8; i++) printf("%d ", i);
      
  for(i = 0; i < 8; i++) {
    printf("\n%d|", i);
    for(j = 0; j < 8; j++) {
      if (pstTableauOld[j*8 + i] == -1) printf("X");
      if (pstTableauOld[j*8 + i] ==  1) printf("O");
      if (pstTableauOld[j*8 + i] ==  0) printf(" ");
      printf("|");
    }
    printf("               %d|", i);
    for(j = 0; j < 8; j++) {
      if (pstTableau[j*8 + i] == -1) printf("X");
      if (pstTableau[j*8 + i] ==  1) printf("O");
      if (pstTableau[j*8 + i] ==  0) printf(" ");
      printf("|");
    }
  }
  printf("\n  ");
  for(i = 0; i < 8; i++) printf("--");
  printf("\n");
}


void afficherTableauEvaluation(int *pstTableau)
{ int i, j; 
  
  printf("\n_|");
  for(i = 0; i < 8; i++) printf("%d ", i);
  for(i = 0; i < 8; i++) {
    printf("\n%d|", i);
    for(j = 0; j < 8; j++) {
      printf("%6d ", pstTableau[j*8+i] / 256);
    }
  }
  printf("\n");
  for(i = 0; i < 8; i++) printf("--");
  printf("\n");
}


int chercherCoupRec(int jo, int depth)
{ 
  if (depth == 0) return(evaluer());
  else {
    int i, val, nb;
    int TableauLocal[64];

    memcpy(TableauLocal, Tableau, 64 * sizeof(int));
  
    for(i = 0, nb = 0, val = 0; i < 64; i++)
      if (coupJouable(i, jo)) {
	jouerCoup(i, jo);
	val += chercherCoupRec(-jo, depth-1);
	memcpy(Tableau, TableauLocal, 64 * sizeof(int));
	nb++;
      }
    if (nb) { val /= nb;    
              return(val); } 
    else return(-128 * jo);
  }
}


int chercherCoup(int jo)
{  
  int i, maxCoup, maxVal, val;
  int TableauLocal[64];
  
  memcpy(TableauLocal, Tableau, 64 * sizeof(int));
  for(i=0;i<64;i++) TableauEvaluation[i] = 999;
  
  for(i = 0, maxVal = -1234568; i < 64; i++)
    if (coupJouable(i, jo)) {
      jouerCoup(i, jo);
      val = chercherCoupRec(-jo, depth-1);   	
      TableauEvaluation[i] = val;
      if (val > maxVal) {   
	maxVal = val;
	maxCoup = i;  
      }
      memcpy(Tableau, TableauLocal, 64 * sizeof(int));
    }
  if (maxVal == -1234567) {
    printf("Pas de coup\n");
    exit(1);
  }
  printf("Coup (%d,%d), valeur %d\n", maxCoup / 8, maxCoup % 8, maxVal); 
  return(maxCoup);   
}


void transpose()
{
  int i, j, tmp;
  
  for(i = 0; i < 8; i++)
    for(j = 0; j <= i; j++) {
      tmp = Tableau[j*8+i];
      Tableau[j*8+i] = Tableau[i*8+j];	 
      Tableau[i*8+j] = tmp;
    }  
}


int main()
{  
  int coup, i, j;
  
  memcpy(Tableau, TableauInitial, 64 * sizeof(int));
  transpose();   
  
  afficherTableau(Tableau);
  while(1) {  
    printf("Quel coup ? ");
    scanf("%d %d", &j, &i);
    jouerCoup(j*8 + i, -1);
    memcpy(TableauOld, Tableau, 64 * sizeof(int));    

    coup = chercherCoup(1);  
    afficherTableauEvaluation(TableauEvaluation);	    
    jouerCoup(coup, 1);
    afficherTableaux(Tableau, TableauOld);   
  }  
}
