/* pour pixel utilise dans son filemanager */

char *func (char *chaine)
{
   char tampon[1000];
   int i,j,acc,acc2=0;
   char tmp[20];
   char *chaine_getenv;

   for (i=0;i<=strlen(chaine);i++)
     {
       if (chaine[i]=='~')
	 { 
	   j=0;
	   if(chaine_getenv=getenv("HOME")) while (chaine_getenv[j]) tampon[acc2++]=chaine_getenv[j++];
	   continue;
	 }

       if (chaine[i]=='$') 
	 {
	   acc=0;
	   i++;
	   while(isalpha(chaine[i])) tmp[acc++]=chaine[i++];
	   tmp[acc]='\0';
	   j=0;
	   if (chaine_getenv=getenv(tmp)) while (chaine_getenv[j]) tampon[acc2++]=chaine_getenv[j++];
	   i--;
	   continue;
	 }


       tampon[acc2++]=chaine[i];
     }
   return strdup(tampon);
}
void main(void)
{
  printf("%s\n",func("dede/de/fee/"));
  printf("\n\n\n%s\n",func("de fre$PATH"));
  printf("%d\n",strlen("de"));
}
