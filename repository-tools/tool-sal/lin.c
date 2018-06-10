#include <stdlib.h>


void FillString(__out_ecount(cchBuf) char* buf, size_t cchBuf, char ch) {

 for (size_t i = 0; i < cchBuf; i++)   {
   buf[i] = ch;
 }

}

//int main(int argc, char * argv[]) {
int main() {

       /*if (argc !=2) {
               exit(0);
       }
       int len = atoi((const char *)argv[1]);*/
       char *b = (char*)malloc(200*sizeof(char));
       FillString(b,210,'x');
       /*if (b)
               FillString(b,len,'x');*/
       return 0;

}
