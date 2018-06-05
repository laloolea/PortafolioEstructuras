#include <iostream>
#include "Racional.h"
#include "Arreglo.h"

using namespace std;

int main () {
    try {
        Racional a(0,3) , b(2,4),c(7,5);


        cout  <<  a <<" + " << b << " = "<< a+b  <<endl;
    }catch(Excepcion &exc){
        cout << exc.QuePaso ()<<endl;
    }catch ( bad_alloc &exc ) {
        cout << "ERROR: asignacion de memoria incorrecta " << endl;
    }catch (...){
        cout <<"Error inesperado "<<endl;
    }
    system("pause");
    return 0;
}


