#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define NO_ES_ANAGRAMA 0
#define ES_ANAGRAMA 1

///funciones a desarrollar y reemplazar en las invocaciones de "main.c"

int esAnagrama(const char *cad1, const char *cad2)
{
	const char *pcad1=cad1, *pcad2=cad2,*pcad_aux1,*pcad_aux2;
	char letra;
	int caracteres_cad1=0,caracteres_cad2=0,cont_cad1=0,cont_cad2=0,son_iguales=1;

	if(!*pcad1 && !*pcad2)
        return NO_ES_ANAGRAMA;

	///VERIFICO LONGITUD DE CADENA
    while(*pcad1)
    {
        if(es_letra(*pcad1))
            caracteres_cad1++;
        pcad1++;
    }
    while(*pcad2)
    {
        if(es_letra(*pcad2))
            caracteres_cad2++;
        pcad2++;
    }
    if(caracteres_cad1!=caracteres_cad2)
        return NO_ES_ANAGRAMA;

    ///RECUPERAR EL PUNTERO
	pcad1=cad1;
	pcad2=cad2;

    ///VERIFICO SI SON IGUALES
    while(*pcad1 && *pcad2 && son_iguales)
    {
        if(!es_letra(*pcad1))
            pcad1++;
        if(!es_letra(*pcad2))
            pcad2++;
        if(convertir_minuscula(*pcad1)==convertir_minuscula(*pcad2))
        {
            pcad1++;
            pcad2++;
        }else
            son_iguales=0;
    }
    if(!*pcad1 && !*pcad2)
        return NO_ES_ANAGRAMA;


	///RECUPERAR EL PUNTERO
	pcad1=cad1;
	pcad2=cad2;

	///RECORRER pcad1 y pcad2
	while(*pcad1)
	{
		if(!es_letra(*pcad1))
            pcad1++;

		cont_cad1=0;
		cont_cad2=0;

		pcad_aux1=cad1;
		pcad_aux2=cad2;

		///CONTAR LA CANTIDAD DE VECES QUE SE REPITE UNA LETRA EN LA CADENA 1
		letra=convertir_minuscula(*pcad1);
		while(*pcad_aux1)
		{
			if(convertir_minuscula(*pcad_aux1)==letra)
				cont_cad1++;
			pcad_aux1++;
		}

		///CONTAR LA CANTIDAD DE VECES QUE SE REPITE LA LETRA DE LA CADENA 1 EN LA CADENA 2
		while(*pcad_aux2)
		{
			if(convertir_minuscula(*pcad_aux2)==letra)
				cont_cad2++;
			pcad_aux2++;
		}

		if(cont_cad1!=cont_cad2)
			return NO_ES_ANAGRAMA;

	pcad1++;
}

	if(!*pcad1)
		return ES_ANAGRAMA;

	return ES_ANAGRAMA;
}

int es_letra(const char s)
{
    if((s>='a'&&s<='z') || (s>='A'&& s<='Z'))
        return 1;
    return 0;
}

char convertir_minuscula(char c)
{
    if(c>='A'&& c<='Z')
        return c +('a'-'A');
    return c;
}

char *aHexadecimal(unsigned num, char *cad)
{
    unsigned resto,cociente;
    char *pcad;
    t_pila pila;
    t_info info;
    cociente=num;
    pcad=cad;

    crearPila(&pila);

    while(cociente>0)
        {
            resto = cociente%16;

            //paso un entero sin signo a char
            if(resto < 10)
                resto+= '0';
            else
                resto+= ('A'-10);

            info.hexa=resto;
            ponerEnPila(&pila,&info);

            cociente/=16;
        }
    while(sacarDePila(&pila,&info))
        {
            *pcad=info.hexa;
            pcad++;
        }
    *pcad='\0';

    return pcad;
}
