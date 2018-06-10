/*******************************************************************************************/
/* pinger.c nouvelle version avec gestion du fichier hosts                                 */
/*******************************************************************************************/
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <fcntl.h>
#include <time.h>

#include <stdlib.h>

#define TIME 100 /*temps d attente en nano seconde*/
#define NB_MACHINE_MAXI 20
#define NB_CARACTERE_MAXI 20

/**********************************************************************************************/
/* variable globale */
/**********************************************************************************************/
int nb_machine;  
char host[NB_MACHINE_MAXI][NB_CARACTERE_MAXI];


/*******************************************************************************************/
int pinger(int *socket_pad,char *host,int port,int tourne)
{
  struct sockaddr_in hisaddr;
  struct hostent *hptr;
  
  if((hptr = gethostbyname(host)) == NULL)
     {
       printf("probleme gethost\n");
       exit(1);
     }
  bzero(&hisaddr,sizeof(hisaddr));
  bcopy((char *)hptr->h_addr,(char *)&hisaddr.sin_addr,hptr->h_length);
  hisaddr.sin_family=AF_INET;
  hisaddr.sin_port=port;
  
  if (tourne==1) /* je connecte juste */
    {
      if((*socket_pad = socket(AF_INET,SOCK_STREAM,0))<0)
	{
	  printf("probleme socket\n");
	  exit(1);
	}
      /* pour que connect rende la main */
      fcntl(*socket_pad,F_SETFL,O_NONBLOCK);
      connect(*socket_pad,(struct sockaddr *)&hisaddr,sizeof(hisaddr));
      return 1;
    }
  if (tourne==2) /* je regarde si le host est bien la au bout de Time nanosecond 
		  si il est pas la -> no route to host devrait bientot apparaitre*/
    {
      if(connect(*socket_pad,(struct sockaddr *)&hisaddr,sizeof(hisaddr))==0) return 1;
      else return 0;
    }
  return 0;
}
/*******************************************************************************************/
/* s appuie sur le file lire_host.c */
/*******************************************************************************************/

void remplit_host(void)
{
  FILE *fp;
  char *line;
  int i,j;

  line=malloc(100);
  if ((fp=fopen("/etc/hosts","r"))==NULL) printf("erruer d ouverture de fichier \n");
  else {
    while (fgets(line,100,fp)!=NULL)  {
      if (line[0]=='1' && line[1]=='0') { 
	i=0;j=0;

	while (line[i] < 'A') i++;
	while (line[i] != '.') {
	  host[nb_machine][j]=line[i];
	  i++;j++;
	}
	host[nb_machine][j]='\0';
	nb_machine++;
      }
    }
  }
  fclose(fp);
}

/**********************************************************************************/
/* main */
/**********************************************************************************/
void main (void)
{

  int i,k;
  char *os[2]={"lin","win"};
  int socket[NB_CARACTERE_MAXI][2];
  int port[2];
  struct servent *sptr;
  struct timespec temps_attente;

  remplit_host();
  /*  for (i=0;i<nb_machine;i++) printf("%s",host[i]); info de debug*/
  temps_attente.tv_sec=0;
  temps_attente.tv_nsec=TIME;

  /* je recopie les valeurs de port car getservbyname renvoie comme valeur une addresse
     constante,cad qu il met a jour une zone de donnee et renvoie l addresse de 
     cette zone */
  /* pixel a utilise time tcp mais au meme pb que pour le 258 */
  /* sptr=getservbyname("time","tcp"); */
  port[0]=258; /* pour suse */
  /*  port[0]=258;*/ /* marche pour dede et xork mais fait planter au bout d une centaine d essais */
  sptr=getservbyname("netbios-ssn","tcp");
  port[1]=sptr->s_port;

  for (i=0;i<nb_machine;i++)
    {
      pinger(&socket[i][0],host[i],port[0],1);
      pinger(&socket[i][1],host[i],port[1],1);
    }
  nanosleep(&temps_attente,NULL);

  for (i=0;i<nb_machine;i++)
    {
      int yakkun=0;
      for (k=0;k<2;k++)
	if(pinger(&socket[i][k],host[i],port[k],2))
	  {
	    printf("%s(%s)",host[i],os[k]);
	    close(socket[i][k]);
	    yakkun=1;
	  }
      if(yakkun) printf("\n");
    }
  exit(0); /*exit normally pour que pingertcl marche (cf file bug_du_exit.c pour infos )*/
}









