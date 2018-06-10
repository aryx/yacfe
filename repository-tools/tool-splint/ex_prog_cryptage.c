/* ligne de command sous debian gcc cryptage.c -lcrypt */

#include "splint.h"

/*@constant int _PC_MAX_CANON@*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

//1: add int for main and return 0
//2: add null check for return of malloc
//3: look return value of scanf 
//4: add free

int main (void)
{
    char *chaine;
    char *code;
	int res;
    chaine = (char *) malloc (20);
    code = (char *) malloc (2);
	if(chaine == NULL) exit(0);
	if(code == NULL) exit(0);

    printf ("\nentrez votre chaine :(- de 20 caracteres)");

    res = scanf ("%s", chaine);
    printf ("\nentrez le code (-de 2 caracteres)");
    res = scanf ("%s", code);
    printf ("val %s\n", crypt (chaine, code));

	free(chaine);
	free(code);
	return 0;
}
