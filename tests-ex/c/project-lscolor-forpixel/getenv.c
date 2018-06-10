/* pour pixel utilise dans son filemanager */
char *func (char *chaine)
{
   char tampon[1000];
   int i,j,acc,acc2=0;
   int trouve=0;
   char tmp[20];
   char *chaine_getenv;

   for (i=0;i<strlen(chaine);i++)
     {
       if (chaine[i]=='$') 
	 {
	   trouve=1;
	   acc=0;
	   continue;
	 }

       if (chaine[i]=='~')
	 {
	   chaine_getenv=getenv("HOME");
	   j=0;
	   while (chaine_getenv[j]) tampon[acc2++]=chaine_getenv[j++];
	   continue;
	 }

       if (trouve) {
	 if(isalpha(chaine[i])) tmp[acc++]=chaine[i];
	 else
	   {
	     trouve=0;
	     tmp[acc]='\0';
	     j=0;
	     chaine_getenv=getenv(tmp);
	     while (chaine_getenv[j]) tampon[acc2++]=chaine_getenv[j++];
	     tampon[acc2++]=chaine[i];
	   }
       }
       else tampon[acc2++]=chaine[i];
     }

   if (trouve)
     {
       tmp[acc]='\0';
       j=0;
       chaine_getenv=getenv(tmp);
       while (chaine_getenv[j]) tampon[acc2++]=chaine_getenv[j++];
     }
   tampon[acc2]='\0';
   return strdup(tampon);
}
void main(void)
{
  printf("%s\n",func("dede~/$DISPLAY$PATH1$PATH"));
  printf("\n\n\n%s\n",func("de fre$PATH"));

}
