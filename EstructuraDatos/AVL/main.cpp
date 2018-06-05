#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "AVL.h"
using namespace std;

int main () {
    srand (time (NULL));
    try{
        cout<<boolalpha;
        AVL <int> arbol;


        cout<<"Creaci\xA2n del arbol\n\n";
        for ( int i = 0 , n = 1 + rand () % 10 ; i < n ; ++i ) {
            int x=1 + rand () % 20;

            if(arbol.AgregarElemento (x)) {
                cout << "Elemento agregado: " << x << endl;
                arbol.ImprimirPorNiveles ();
            }
        }
        cout<<"\nArbol impresi\xA2n ascendente:\n";

        arbol.ImprimirAscendente ();

        cout<<"\nArbol impresi\xA2n descendente:\n";

        arbol.ImprimirDescendente ();

        cout<<"\nArbol impresi\xA2n por niveles:\n";

        arbol.ImprimirPorNiveles ();


        AVL<int> arbolCopia;

        arbolCopia= arbol;

        cout<<"\nCreando copia del arbol..\n";


        cout<<"\nArbol copia impresi\xA2n ascendente:\n";

        arbolCopia.ImprimirAscendente ();

        cout<<"\nArbol copia impresi\xA2n descendente:\n";

        arbolCopia.ImprimirDescendente ();

        cout<<"\nArbol copia impresi\xA2n por niveles:\n";

        arbolCopia.ImprimirPorNiveles ();

        cout<<"\nProceso de  eliminaci\xA2n del arbol original...\n\n";

        for ( int i = 0 , n = 1 + rand () % 10 ; i < n ; ++i ) {
            int x=1 + rand () % 20;

            if(arbol.Buscar (x)) {
                cout << "Elemento Eliminado: " << x << endl;
                arbol.EliminarElemento (x);
            }

        }
        arbol.ImprimirAscendente();
        cout <<"\n\nEl arbol original esta vacio: "<<arbol.EstaVacio();

        cout <<"\n\nComparaci\xA2n arbol copia despues de eliminar el arbol original (impresi\xA2n ascendente): \n";

        arbolCopia.ImprimirAscendente ();


        cout<<"\n\nVaciando arbol copia..";

        arbolCopia.Vaciar();
        cout <<"\nEl arbol copia esta vacio: "<<arbolCopia.EstaVacio();


    }catch(Excepcion &exc){
        cout<< exc.QuePaso()<<endl;
    }
}
