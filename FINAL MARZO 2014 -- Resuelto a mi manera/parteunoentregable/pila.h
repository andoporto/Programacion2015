#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include <stdlib.h>

typedef struct
{
   char           hexa;
} t_info;

typedef struct s_nodo
{
   t_info         info;
   struct s_nodo *sig;
} t_nodo, *t_pila;

void crearPila(t_pila *p);
int pilaLlena(const t_pila *p);
int ponerEnPila(t_pila *p, const t_info *d);
int pilaVacia(const t_pila *p);
int sacarDePila(t_pila *p, t_info *d);


#endif // PILA_H_INCLUDED
