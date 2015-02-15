#include <iostream>
#include <string.h>
#include "Producto.h"

Producto::Producto()
{
    *(this->clave)='\0';
    *(this->descrip)='\0';
    this->stock=0;
    this->precio=0;
}

Producto::Producto(const char *clave,const char *descrip,int stock, float precio)
{
    if(clave==NULL)
        *(this->clave)='\0';
    else
        strcpy(this->clave,clave);

    if(descrip==NULL)
        *(this->descrip)='\0';
    else
        strcpy(this->descrip,descrip);

    this->stock=stock;
    this->precio=precio;
}

Producto::Producto(const Producto &obj)
{
    if(obj.clave==NULL)
        *(this->clave)='\0';
    else
        strcpy(this->clave,obj.clave);

    if(obj.descrip==NULL)
        *(this->descrip)='\0';
    else
        strcpy(this->descrip,obj.descrip);

    this->stock=obj.stock;
    this->precio=obj.precio;

}


Producto& Producto::operator=(const Producto &obj)
{
    if(obj.clave==NULL)
        *(this->clave)='\0';
    else
        strcpy(this->clave,obj.clave);

    if(obj.descrip==NULL)
        *(this->descrip)='\0';
    else
        strcpy(this->descrip,obj.descrip);

    this->stock=obj.stock;
    this->precio=obj.precio;

    return *this;
}

Producto& Producto::operator=(float precio)
{
    this->precio=precio;

    return *this;
}

Producto& Producto::operator++()
{
    this->stock++;

    return *this;
}

Producto Producto::operator++(int)
{
    Producto aux(*this);

    this->stock++;

    return *this;
}

bool Producto::operator!=(const Producto &obj)
{
    return strcmp(this->clave,obj.clave);
}

ostream& operator<<(ostream &sal ,const Producto &obj)
{
    sal<<"Clave: "<<obj.clave<<endl;
    sal<<"Descripcion: "<<obj.descrip<<endl;
    sal<<"Stock: "<<obj.stock<<endl;
    sal<<"Precio: "<<obj.precio<<endl;

    return sal;
}
