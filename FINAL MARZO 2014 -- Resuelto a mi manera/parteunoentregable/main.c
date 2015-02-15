
#include "main.h"

char* aHexadecimal(unsigned int num,char* cad);

int main()
{
   anagrama();

   hexadecimal();

   return 0;
}


void anagrama(void)
{
   char        cad1[] = { "AnAGramas" },
               cad2[] = { "Mas a ganar" };
   int         esAna = esAnagrama(cad1, cad2);

   printf("Las cadenas \"%s\" y \"%s\" %sson anagramas\n\n",
          cad1, cad2, esAna ? "" : "NO ");
}


void hexadecimal(void)
{
   char  cad[9];
   //unsigned num = /*3456789012U*/ 65535U;
    unsigned num = 6899;
   aHexadecimal(num, cad);
   printf("%u - %s\n\n", num, cad);
}

