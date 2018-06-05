#include <iostream>
#include <cstdlib>
#include <ctime>
#include "ListaDobleOrdenada.h"
using namespace std;
int main () {
    srand(time(NULL));

    try{


        ListaDobleOrdenada<> lista;
        int dato;


        for( int i = 0 ;i< 10 ;++i){
            dato =1+rand()%50;
            lista.AgregarElemento (dato);
            cout << "Dato agregado a la lista: "<< dato << endl;

        }

        cout  << "La lista ordenada de forma ascendente es: " <<lista<<endl;

        cout  << "La lista ordenada de forma descendente es: ";

        lista.ImprimirDescendente ();

        cout<< endl;

        for(int i = 0 ; i < 10;++i){
            dato = 1 + rand()%50;
            if(lista.Buscar(dato)) {
                lista.EliminarElemento (dato);
                cout << "El dato "<< dato <<" fue eliminado de la lista "<< endl;
            }else{
                cout << "El dato " << dato <<" no existe en la lista"<<endl;
            }


        }
        cout  << "La lista ordenada de forma ascendente es: " <<lista<<endl;

        cout  << "La lista ordenada de forma descendente es: ";

        lista.ImprimirDescendente ();

        ListaDobleOrdenada<> listaCopia = lista;

        lista.Vaciar();

        cout << "\n\nLa lista original despu\xA2s de vaciar es: ";
        if(!lista.EstaVacia())cout<< lista<< endl;
        else cout << "Lista vac\241a"<<endl;

        cout << "La copia de lista es: "<<listaCopia<<endl;


        }catch(bad_alloc &m){
       cout << "Error en la asignaci\xA2n de memoria..."<<endl;
   }
    return 0;
}