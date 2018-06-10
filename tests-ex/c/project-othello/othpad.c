#include <conio.h>
#include <stdio.h>
#define profondeur 4
#define w  1
#define b -1

#define a  64
#define x  0
#define c  32
#define d  -64
#define e  -32
#define f  1


int board[64] = {0,0,0,0,0,0,0,0,
		 0,0,0,0,0,0,0,0,
		 0,0,0,0,0,0,0,0,
		 0,0,0,w,b,0,0,0,
		 0,0,0,b,w,0,0,0,
		 0,0,0,0,0,0,0,0,
		 0,0,0,0,0,0,0,0,
		 0,0,0,0,0,0,0,0};

int boardold[64];

int heuristicboard[64] =
{a,x,c,c,c,c,x,a,
 x,d,e,e,e,e,d,x,
 c,e,f,f,f,f,e,c,
 c,e,f,f,f,f,e,c,
 c,e,f,f,f,f,e,c,
 c,e,f,f,f,f,e,c,
 x,d,e,e,e,e,d,x,
 a,x,c,c,c,c,x,a};

int result[64];        //pointeur sur l endroit ou le pion sera mis

int place;        //pointeur sur l endroit ou le pion sera mis
char coup[2];
////////////////////////////////////////////////////////////////////////////
void exit ()
{
  asm mov ax,0x4c00
    asm int 0x21




    }
////////////////////////////////////////////////////////////////////////////
/*void drawboard ()

  {
  int k,i;
  setcolor(2);
  for (k=0;k<9;k++) line(80+k*60,0, 80+k*60,480) ;   //dessine les contours
  for (k=0;k<9;k++) line(80,k*60, 560,k*60) ;        //du plateau
  for (k=0;k<8;k++)                                  //dessine les pions
  {
  for (i=0;i<8;i++)
  {
  switch (board[k*8+i])
  {
  case -1:{
  setcolor(8);
  setfillstyle(1,8);
  pieslice(80+i*60+30,0+k*60+30,0,360,25);
  delay(500);
  }
  ; break;
  case 1:{
  setcolor(15);
  setfillstyle(1,15);
  pieslice(80+i*60+30 ,0+k*60+30 ,0,360,25);
  delay(500);
  }
  ; break;
  default: ;
  }
  }
  }
  delay(500);
  }*/
////////////////////////////////////////////////////////////////////////////
void getcoup()
{

  coup[0]=getch();
  coup[1]=getch();
  if (coup[0]=='q') exit();

  place=8*((int) coup[1] - 49) + ((int) coup[0] -97);


}
///////////////////////////////////////////////////////////////////////////
int coupjouabledir(int coup,int ns,int dg,int joueur)
{
  int acc,bool,procpion;
  acc=1;
  bool=1;
  while( bool)
    {
      procpion=coup + ns*8*acc + dg*acc;
      if ((procpion <0)||     //si on est sur un bord
	  (procpion >63)||    //du plateau
	  (  (dg== 1) && (((coup +ns*8*(acc-1) + dg*(acc-1))% 8)== 7) )||
	  (  (dg== -1)&& (((coup +ns*8*(acc-1) + dg*(acc-1))% 8)== 0) )
	  )  return 0;
      if ((board[procpion]==joueur)&&(acc!=1)) return 1;
      if ((board[procpion]==joueur)&&(acc==1)) return 0;
      if (board[procpion]==0) return 0;
      acc++;
    }
  return 0;
}
///////////////////////////////////////////////////////////////////////////

int coupjouable (int coup,int joueur)
{
  return
    (board[coup]==0)&&
    ((coupjouabledir(coup,0,1,joueur))||
     (coupjouabledir(coup,0,-1,joueur))||
     (coupjouabledir(coup,1,1,joueur))||
     (coupjouabledir(coup,1,-1,joueur))||
     (coupjouabledir(coup,-1,1,joueur))||
     (coupjouabledir(coup,-1,-1,joueur))||
     (coupjouabledir(coup,1,0,joueur))||
     (coupjouabledir(coup,-1,0,joueur)));



}

///////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
void retourne (int coup,int ns,int dg,int joueur)
{
  int acc,bool,procpion;
  acc=1;
  bool=1;
  while (bool)
    {
      procpion=coup + ns*8*acc + dg*acc;
      if (board[procpion]==joueur) return;
      board[procpion]=joueur;
      acc++;
    }
}
///////////////////////////////////////////////////////////////////////////
void changeboard(int coup,int joueur)
{
  int ns,dg;

  for (ns= -1 ;ns< 2;ns++)
    {
      for (dg= -1 ;dg < 2 ;dg++)
	{
	  if (coupjouabledir(coup,ns,dg,joueur)) retourne (coup,ns,dg,joueur) ;
	}
    }
}
///////////////////////////////////////////////////////////////////////////
/*void retourngraph(int joueur,int ns,int dg,int acc)
  {
  int k,i;
  if (board[*place + ns*8*acc + dg*acc]==joueur) return;
  board[*place + ns*8*acc + dg*acc]=joueur;

  switch (joueur)
  {
  case b:{
  setcolor(8);
  setfillstyle(1,8);
  k=(*place + ns*8*acc + dg*acc)/8;
  i=(*place + ns*8*acc + dg*acc) %8;

  pieslice(80+i*60+30,0+k*60+30,0,360,25);
  delay(500);
  }
  ; break;
  case w:{
  setcolor(15);
  setfillstyle(1,15);
  k=(*place + ns*8*acc + dg*acc)/8;
  i=(*place + ns*8*acc + dg*acc) %8;
  pieslice(80+i*60+30 ,0+k*60+30 ,0,360,25);
  delay(500);
  }
  ; break;
  default: ;
  }
  retourngraph (joueur,ns,dg,acc+1);
  } */
////////////////////////////////////////////////////////////////////////////
/*void changeboardgraph(int joueur)
  {
  int k,i,ns,dg;
  board[*place]=joueur;
  switch (joueur)
  {
  case b:{
  setcolor(8);
  setfillstyle(1,8);
  k=*place/8;
  i=*place %8;

  pieslice(80+i*60+30,0+k*60+30,0,360,25);
  delay(500);
  }
  ; break;
  case w:{
  setcolor(15);
  setfillstyle(1,15);
  k=*place/8;
  i=*place %8;
  pieslice(80+i*60+30 ,0+k*60+30 ,0,360,25);
  delay(500);
  }
  ; break;
  default: ;
  }
  for (ns= -1 ;ns< 2;ns++)
  {
  for (dg= -1 ;dg < 2 ;dg++)
  {
  if (coupjouabledir(*place,ns,dg,joueur))
  {
  retourngraph (joueur,ns,dg,1) ;
  } //fin du if
  } //fin du for
  } //fin du for
  } */

//////////////////////////////////////////////////////////////////////////
int compte(int joueur)
{
  int k;
  int valeur;
  valeur=0;
  for (k=0;k<64;k++)
    {
      if (board[k]==joueur) valeur+=heuristicboard[k];
      if (board[k]==-joueur) valeur-=2*heuristicboard[k];

    }
  return valeur;
}
/////////////////////////////////////////////////////////////////////////
int moyenne (int joueur,int depth)
{
  int k,i,valeur,nbcoup,inter;
  int backup[64];
  valeur=0;
  nbcoup=0;
  if (depth==0) return compte(joueur);

  for (k=0;k<64;k++)
    {
      if (coupjouable(k,joueur))
	{
	  for (i=0;i<64;i++) backup[i]=board[i];
	  board[k]=joueur;
	  changeboard(k,joueur);
	  inter=moyenne(-joueur,depth-1);
	  if (inter <0) valeur=valeur+2*inter;
	  else valeur=valeur+inter;

	  nbcoup++;
	  for (i=0;i<64;i++) board[i]=backup[i];

	}
    }
  if (nbcoup==0) return 0;
  return valeur /nbcoup;
}


/////////////////////////////////////////////////////////////////////////
void cherchecoup(int joueur)
{
  int k,i;
  int backup[64];
  for (k=0;k<64;k++)
    {
      if (coupjouable(k,joueur))
	{
	  for (i=0 ;i<64;i++) backup[i]=board[i];
	  board[k]=joueur;
	  changeboard(k,joueur);
	  result[k]=moyenne(joueur,profondeur);
	  for (i=0 ;i<64;i++) board[i]=backup[i];
	}
      else result[k]= -400;
    }
}
/////////////////////////////////////////////////////////////////////////

int meilleurcoup(int joueur,int acc,int coup)
{
  if (acc>63) return coup;
  if (result[acc]>result[coup]) return meilleurcoup(joueur,acc+1,acc);
  return meilleurcoup(joueur,acc+1,coup);
}

////////////////////////////////////////////////////////////////////////
void  ordi(int joueur)
{
  cherchecoup(joueur);
  place=meilleurcoup(joueur,0,0);

}
////////////////////////////////////////////////////////////////////////

void init()
{
  asm {
    mov ax,3
      int 0x10

      }




  //int gdriver = DETECT, gmode=VGAHI, errorcode;

  //initgraph(&gdriver, &gmode, "");
}

//////////////////////////////////////////////////////////////////////////
void afficherTableaux( )
{ int i, j;

printf("\n_|");
for(i = 0; i < 8; i++) printf("%d ", i);
printf("  --apres--->  _|");
for(i = 0; i < 8; i++) printf("%d ", i);

for(i = 0; i < 8; i++) {
  printf("\n%d|", i);
  for(j = 0; j < 8; j++) {
    if (boardold[j*8 + i] == -1) printf("X");
    if (boardold[j*8 + i] ==  1) printf("O");
    if (boardold[j*8 + i] ==  0) printf(" ");
    printf("|");
  }
  printf("               %d|", i);
  for(j = 0; j < 8; j++) {
    if (board[j*8 + i] == -1) printf("X");
    if (board[j*8 + i] ==  1) printf("O");
    if (board[j*8 + i] ==  0) printf(" ");
    printf("|");
  }
}
printf("\n  ");
for(i = 0; i < 8; i++) printf("--");
printf("\n");
}



///////////////////////////////////////////////////////////////////////////
void afficherTableauEvaluation(int *pstTableau)
{ int i, j;

printf("\n_|");
for(i = 0; i < 8; i++) printf("%d ", i);
for(i = 0; i < 8; i++) {
  printf("\n%d|", i);
  for(j = 0; j < 8; j++) {
    printf("%6d ", pstTableau[j*8+i] );
  }
}
printf("\n");
for(i = 0; i < 8; i++) printf("--");
printf("\n");
}
////////////////////////////////////////////////////////////////////////////
void main ()
{
  int k,i,j;
  int compteur=1;
  init();
  //drawboard();
  for (i=0;i<64;i++) boardold[i]=board[i];
  afficherTableaux();
  while (compteur <62)
    {

      printf("Quel coup ? ");
      scanf("%d %d", &j, &i);
      if (j==9) exit();
      place=j*8+i;

      //    getcoup();
      //    changeboardgraph(w);
      for (i=0;i<64;i++) boardold[i]=board[i];
      board[place]=w;

      changeboard(place,w);

      afficherTableaux();
      for (i=0;i<64;i++) boardold[i]=board[i];

      ordi(b);
      board[place]=b;
      changeboard(place,b);
      afficherTableauEvaluation(result);

      afficherTableaux();

      //    changeboardgraph(b);


      compteur++;
    }
  exit();
}


 
