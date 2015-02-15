#include <iostream>
#include "Producto.h"

using namespace std;

void probarProductos(const char *clave1,    const char *clave2,
                     const char *descrip1,  const char *descrip2,
                     int         stock1,    int         stock2,
                     float       precio1,   float      precio2)

{
Producto p1(clave1, descrip1, precio1, stock1),
            p2(clave1, descrip1, precio1, stock1),
            p3(p1),
            p4;

   cout << "Valores iniciales de los productos:" << endl
        << "p1" << endl << p1 << endl << endl
        << "p2" << endl << p2 << endl << endl
        << "p3" << endl << p3 << endl << endl
        << "p4" << endl << p4 << endl << endl;
   p4 = p3;
   p4++;  // modifica la cantidad en existencias
   p3 = precio2;  // modifica el precio
   cout << "Valores finales:" << endl
        << "p1" << endl << p1 << endl << endl
        << "p2" << endl << p2 << endl << endl
        << "p3" << endl << p3 << endl << endl
        << "p4" << endl << p4 << endl << endl;
      cout << p1 << ( p1 != p4 ? "es distinto de" : "es igual a") << endl
           << p4 << endl << endl;

}


int main()
{
    probarProductos("Clave1", "Clave2", "Des_1", "Des_2", 33, 77, 0.09, 8.98);

    return 0;
}


