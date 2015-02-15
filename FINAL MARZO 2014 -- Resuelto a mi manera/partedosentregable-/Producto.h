#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED
#include <iostream>

using namespace std;

class Producto{

    char clave[11];
    char descrip[46];
    int stock;
    float precio;

public:

    Producto();
    Producto(const char*, const char*,int,float);
    Producto(const Producto&);
    Producto& operator=(const Producto&);
    Producto& operator=(float);
    Producto& operator++();
    Producto operator++(int);
    bool operator!=(const Producto&);
    friend ostream& operator<<(ostream&,const Producto&);
};

#endif // PRODUCTO_H_INCLUDED
