#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define TAM 80
#define FIL_MAX 20


int main()
{

    printf("\n################################################\n\tPRIMER PARCIAL PROGRAMACION I 05-05-2014\n################################################\n");
    char cade1[TAM], cade2[TAM];
    char cade[FIL_MAX][TAM];
    int comp, cant = 0, fin = 0;

    while(cant < FIL_MAX && fin == 0)
    {
        comp = ingresar2(cade1, cade2);
        if( (fin = condicion_fin(cade1,cade2) ) != 0)
        {
            puts("\nFin del ingreso");
        }
        else
        {
            if( comp > 0)
            {
                asignar(cade[cant], cade2);
                asignar(cade[cant+1], cade1);
                //puts("Cadena 1 mayor que cadena 2.");
            }
            else
            {
                if(comp < 0)
                {
                    asignar(cade[cant], cade1);
                    asignar(cade[cant+1], cade2);
                    //puts("Cadena 2 mayor que cadena 1.");
                }
                else
                {
                    asignar(cade[cant], cade2);
                    asignar(cade[cant+1], cade1);
                    //puts("Cadenas iguales.");
                }
            }
            cant += 2;
        }

    }

    //while(i < TAM){
    //puts(cade[i]);
    mostrar_cade(cade, cant);
    //  i++;
    //}



//PRUEBA 1
    /*
        if( (comp = ingresar2(cade1, cade2) ) > 0 )
            puts("Cadena 1 mayor que cadena 2.");
        else{
            if(comp < 0)
                puts("Cadena 2 mayor que cadena 1.");
            else
                puts("Cadenas iguales.");
        }
    */
    return 0;
}
