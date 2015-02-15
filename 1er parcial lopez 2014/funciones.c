#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compXlong(char * cade1, char * cade2)
{
    int largo1 = 0, largo2 = 0;
    int resul;

    while(*cade1)
    {
        largo1++;
        cade1++;
    }
    while(*cade2)
    {
        largo2++;
        cade2++;
    }

    resul = largo1-largo2;
    return resul;
}

int compLexic(char * cade1, char * cade2)
{
    int resul = 0;

    *cade1 = to_lower(*cade1);
    *cade2 = to_lower(*cade2);

    while(*cade1 && *cade2 && *cade1 == *cade2)
    {
        cade1++;
        cade2++;
        *cade1 = to_lower(*cade1);
        *cade2 = to_lower(*cade2);
    }
    if(*cade1 < *cade2)
        resul = -1;
    else
    {
        if(*cade1 > *cade2)
            resul = 1;
    }
    return resul;
}

int to_lower(int letra)
{
    if(letra < 91 && letra > 64)
        letra += 32;
    return letra;
}

int ingresar2(char * cade1, char * cade2)
{
    int comp;

    puts("Ingrese cadena 1...");
    fflush(stdin);
    gets(cade1);

    puts("Ingrese cadena 2...");
    fflush(stdin);
    gets(cade2);

    if( (comp = compXlong(cade1, cade2) ) > 0 )
        return 1; //puts("Cadena 1 mayor en longitud que cadena 2");
    else
    {
        if(comp < 0)
            return -1; //puts("Cadena 2 mayor en longitud que cadena 1");
        else //SI SON IGUALES COMPARO LEXICOGRAFICAMENTE
        {
            if( (comp = compLexic(cade1, cade2) ) > 0 )
                return 1; //puts("Cadena 1 mayor que cadena 2 lexicograficamente");
            else
            {
                if(comp < 0)
                    return -1; //puts("Cadena 2 mayor que cadena 1 lexicograficamente");
                else
                    return 0; //puts("Cadenas iguales lexicograficamente y longitudinalmente");
            }
        }
    }
}

void asignar(char * cade_dest, char * cade_orig)
{
    while(*cade_orig)
    {
        *cade_dest = *cade_orig;
        cade_dest++;
        cade_orig++;
    }
    *cade_dest = '\0';
}

void mostrar_cade(char cade[][TAM], int elem)
{
    int i = 0;
    puts("\nCadenas totales:");
    while(*cade && i < elem)
    {
        printf("\nCadena: %s", cade[i]);
        i++;
    }
    puts("\n");
}

int condicion_fin(char * cadeA, char * cadeB)
{
    int resul = 0, flag1 = 0, flag2 = 0;

    flag1 = strcmp(cadeA, "fin");
    flag2 = strcmp(cadeB, "fin");

    if(flag1 == 0 || flag2 == 0)
        resul = 1;

    return resul;
}
