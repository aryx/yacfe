#include <stdio.h>
#include <stdlib.h>

#include "splint.h" 

//from splint stdio.h

/*@null@*/ /*@dependent@*/ FILE *fopen (char *filename, char *mode) 
   /*@modifies fileSystem@*/ ;         


//1: add __only, but default
//2: add NULL
//3: add __null
//4: try owned, keep, dependent
static FILE __null *fp = NULL;
static char __null __only *line = NULL;

//5: try globals, requires
// /*@globals fp,line@*/
// /*@requires isnull fp@*/

//6: must add the undef ... found by looking at code of splint ...
int main(int argc ,char *argv[]) 
/*@globals undef  line @*/
{
	if (argc !=2 ) 
    {
		printf("erreur du nombre d arguments\n");
		exit(0);
    }
	line=malloc(100);

	//0: splint addon:
	if(line == NULL) exit(0);

	if ((fp=fopen(argv[1],"r"))==NULL) 
		printf("erruer d ouverture de fichier \n");
	else 
    {
		/*printf("%p\n",fp);*/
		
		while (fgets(line,100,fp)!=NULL) 
			/*printf("erruer de lecture  fichier \n");*/
		{
			printf("%s",line);
		}
    }
	free(line);
	line=NULL;
	return 0;
}
