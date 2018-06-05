#include <iostream>
#include "ListaOrdenada.h"

using namespace std;
int main () {
    srand (time (NULL));

    try {
        ListaOrdenada<> lista;

        int dato;
        cout << "------------LISTA INT------------\n\n";

        for ( int i = 0 ; i < 10 ; ++i ) {
            dato = 1 + rand () % 50;
            lista.AgregarElemento (dato);
            cout << "Dato agregado a la lista int: " << dato << endl;

        }

        cout << "La lista int ordenada de forma ascendente es: " << lista << endl;

        cout << "La lista int ordenada de forma descendente es: ";

        lista.ImprimirDescendente ();

        cout << endl<<endl;

        for ( int i = 0 ; i < 100 ; ++i ) {
            dato = 1 + rand () % 50;
            if ( lista.Buscar (dato)) {
                lista.EliminarElemento (dato);
                cout << "El dato " << dato << " fue eliminado de la lista int" << endl;
            } else {
                cout << "El dato " << dato << " no existe en la lista int" << endl;
            }


        }
        cout << "La lista int ordenada de forma ascendente es: " << lista << endl;

        cout << "La lista int ordenada de forma descendente es: ";

        lista.ImprimirDescendente ();

        ListaOrdenada<> listaCopia = lista;

        lista.Vaciar ();

        cout << "\n\nLa lista int original despu\xA2s de vaciar es: ";
        if ( !lista.EstaVacia ())cout << lista << endl;
        else cout << "Lista vac\241a" << endl;

        cout << "La copia de lista int es: " << listaCopia << endl;


    } catch ( Excepcion &exc ) {
        cout << exc.QuePaso () << endl;
    } catch ( bad_alloc &m ) {
        cout << "Error en la asignaci\xA2n de memoria..." << endl;
    }
    try {
        ListaOrdenada<float> lista;

        float dato;

        cout << "------------LISTA FLOAT------------\n\n";

        for ( int i = 0 ; i < 10 ; ++i ) {
            dato = (1 + rand () % 200);
            dato=(dato+dato)/25;
            lista.AgregarElemento (dato);
            cout << "Dato agregado a la lista float: " << dato << endl;

        }

        cout << "La lista float ordenada de forma ascendente es: " << lista << endl;

        cout << "La lista float ordenada de forma descendente es: ";

        lista.ImprimirDescendente ();

        cout << endl<<endl;

        for ( int i = 0 ; i < 10 ; ++i ) {
            dato=(1 + rand () % 200);
            dato=(dato+dato)/25;
            if ( lista.Buscar (dato)) {
                lista.EliminarElemento (dato);
                cout << "El dato " << dato << " fue eliminado de la lista float " << endl;
            } else {
                cout << "El dato " << dato << " no existe en la lista float" << endl;
            }


        }
        cout << "La lista float ordenada de forma ascendente es: " << lista << endl;

        cout << "La lista float ordenada de forma descendente es: ";

        lista.ImprimirDescendente ();

        ListaOrdenada<float> listaCopia = lista;

        lista.Vaciar ();

        cout << "\n\nLa lista float original despu\xA2s de vaciar es: ";
        if ( !lista.EstaVacia ())cout << lista << endl;
        else cout << "Lista vac\241a" << endl;

        cout << "La copia de lista float es: " << listaCopia << endl;

    } catch ( Excepcion &exc ) {
        cout << exc.QuePaso () << endl;
    } catch ( bad_alloc &m ) {
        cout << "Error en la asignaci\xA2n de memoria..." << endl;
    }
    try {
        ListaOrdenada<char> lista;

        char dato;
        cout << "------------LISTA CHAR------------\n\n";

        for ( int i = 0 ; i < 10 ; ++i ) {
            dato =  char(33 + rand () % 30);
            lista.AgregarElemento (dato);
            cout << "Dato agregado a la lista char: " << dato << endl;

        }

        cout << "La lista char ordenada de forma ascendente es: " << lista << endl;

        cout << "La lista char ordenada de forma descendente es: ";

        lista.ImprimirDescendente ();

        cout << endl<<endl;

        for ( int i = 0 ; i < 10 ; ++i ) {
            dato = char(33 + rand () % 30);
            if ( lista.Buscar (dato)) {
                lista.EliminarElemento (dato);
                cout << "El dato " << dato << " fue eliminado de la lista char" << endl;
            } else {
                cout << "El dato " << dato << " no existe en la lista char" << endl;
            }


        }
        cout << "La lista char ordenada de forma ascendente es: " << lista << endl;

        cout << "La lista char ordenada de forma descendente es: ";

        lista.ImprimirDescendente ();

        ListaOrdenada<char> listaCopia = lista;

        lista.Vaciar ();

        cout << "\n\nLa lista char original despu\xA2s de vaciar es: ";
        if ( !lista.EstaVacia ())cout << lista << endl;
        else cout << "Lista vac\241a" << endl;

        cout << "La copia de lista char es: " << listaCopia << endl;


    } catch ( Excepcion &exc ) {
        cout << exc.QuePaso () << endl;
    } catch ( bad_alloc &m ) {
        cout << "Error en la asignaci\xA2n de memoria..." << endl;
    }
}