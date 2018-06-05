#include <iostream>
#include <cstdlib>
#include"Cola.h"
using namespace std;

int main () {

    Cola<int> colita;


    colita.AgregarElemento(1);
    colita.AgregarElemento(2);

    cout<< colita.ObtenerTope ()<<endl;

    cout << colita;

    return 0;
}
