#include <iostream>
#include "ListaSimpleOrdenada.h"
#include <cstdlib>
using namespace std;

int main () {
    srand(time(NULL));
    try {
        ListaSimpleOrdenada<int , ascendente> listaInt;

        cout<<boolalpha;

        cout << "-----------------LISTA ORDENADA ASCENDENTE INT.---------------" << endl << endl << "Agregar  elementos" << endl;
        for ( int i = 0 , n = 1 + rand () % 10 ; i < n ; ++i ) {
            listaInt.AgregarElemento (1 + rand () % 100);
            cout << listaInt << endl;
            cout << "Tamaño lista: " << listaInt.ObtenerTamanio () << endl << endl;
        }

        cout << "LISTA ORDENADA ASCENDENTE INT." << endl;

        cout << listaInt << endl;

        for ( int i = 0 , n = 1 + rand () % 5 ; i < n ; ++i ) {
            int valor =(1 + rand () % 100);
            cout << "Buscando valor "<<valor<<" existe"
                    ": "<< listaInt.Buscar (valor)<<endl<<endl;
        }
/*
        cout << "Buscando valor 1... existe: "<< listaInt.Buscar (1)<<endl<<endl;
        cout << "Buscando valor 18... existe: "<< listaInt.Buscar (18)<<endl<<endl;
        cout << "Buscando valor 58... existe: "<< listaInt.Buscar (58)<<endl<<endl;
        cout << "Buscando valor 80... existe: "<< listaInt.Buscar (80)<<endl<<endl;
*/
        cout << endl << "COPIA LISTA ORDENADA ASCENDENTE INT.  " << endl;

        ListaSimpleOrdenada<int,ascendente> listaCopia;
        listaCopia = listaInt;//  llama constructor de copias

        cout << listaCopia << endl;


        cout << "\nELIMINAR ELEMENTOS LISTA ORDENADA ASCENDENTE INT." << endl;


        for ( int i = 0 , n = 1 + rand () % 10 ; i < n ; ++i ) {
            //int x = 1 + rand () % 100;

            cout <<  "Eliminar elemento  "<< i << ": "<< listaInt.EliminarElemento (i)<<endl;
            cout << listaInt << endl;
            cout << "Tamaño lista: " << listaInt.ObtenerTamanio () << endl << endl;
        }


        cout << "\nIMPRESI\xA2N COPIA DE LISTA ORDENADA ASCENDENTE INT (COMPROBACI\xA2N CONSTRUCTOR DE COPIAS)\n\n";

        cout << listaCopia << endl;

        cout << "\nELIMINAR ELEMENTOS COPIA LISTA  ORDENADA ASCENDENTE INT" << endl;


        int n = 100;
        for ( int i = 0  ; i < n ; ++i ) {
            int x = 1 + rand () % 100;
            cout <<  "Eliminar elemento  "<< x << ": "<< listaCopia.EliminarElemento (x)<<endl;
            cout << listaCopia << endl;
            cout << "Tamaño lista: " << listaCopia.ObtenerTamanio () << endl << endl;
        }

        cout << "VACIANDO LISTAS ORDENADAS ASCENDENTES INT Y COPIA\n\n"<<endl;
        listaInt.Vaciar();
        listaCopia.Vaciar();

        cout << "\nLISTA  ORDENADA ASCENDENTE INT VACIA: " << boolalpha << (listaInt.Vacia ()) << endl;

        cout << "COPIA LISTA  ORDENADA ASCENDENTE INT VACIA : " << boolalpha << listaCopia.Vacia () << endl << endl;


    }catch(bad_alloc){
        cout << "Error asignaci\xA2n de memoria";
    }
    catch(...) {
        cout<< "Algun error ocurrio" <<endl;
    }

    try {
        ListaSimpleOrdenada<float , descendente> listaFloat;

        cout<<boolalpha;

        cout << "-----------------LISTA ORDENADA DESCENDENTE FLOAT.-----------------" << endl << endl << "Agregar  elementos" << endl;
        for ( int i = 0 , n = 1 + rand () % 10 ; i < n ; ++i ) {
            float aux= 1+rand()%500;
            listaFloat.AgregarElemento (aux +aux/100);
            cout << listaFloat << endl;
            cout << "Tamaño lista: " << listaFloat.ObtenerTamanio () << endl << endl;
        }

        cout << "LISTA ORDENADA DESCENDENTE FLOAT." << endl;

        cout << listaFloat << endl;



        for ( int i = 0 , n = 1 + rand () % 5 ; i < n ; ++i ) {
            float aux= 1+rand()%500;

            cout << "Buscando valor "<<aux+aux/100<<" existe: "<< listaFloat.Buscar (aux+aux/100)<<endl<<endl;
        }


        cout << endl << "COPIA LISTA ORDENADA DESCENDENTE FLOAT.  " << endl;


        ListaSimpleOrdenada<float,descendente> listaCopia;
        listaCopia = listaFloat;//  llama constructor de copias

        cout << listaCopia << endl;


        cout << "\nELIMINAR ELEMENTOS LISTA ORDENADA DESCENDENTE FLOAT." << endl;


        for ( int i = 0 , n = 1 + rand () % 10 ; i < n ; ++i ) {
            int x = 1 + rand () % 100;
            cout <<  "Eliminar elemento  "<< x << ": "<< listaFloat.EliminarElemento (x)<<endl;
            cout << listaFloat << endl;
            cout << "Tamaño lista: " << listaFloat.ObtenerTamanio () << endl << endl;

        }


        cout << "\nIMPRESI\xA2N COPIA DE LISTA ORDENADA DESCENDENTE INT (COMPROBACI\xA2N CONSTRUCTOR DE COPIAS)\n\n";

        cout << listaCopia << endl;


        cout << "\nELIMINAR ELEMENTOS COPIA LISTA  ORDENADA DESCENDENTE FLOAT" << endl;



        for ( int i = 0 , n = 1 + rand () % 10 ; i < n ; ++i ) {
            int x = 1 + rand () % 100;
            cout <<  "Eliminar elemento  "<< x << ": "<< listaCopia.EliminarElemento (x)<<endl;
            cout << listaCopia << endl;
            cout << "Tamaño lista: " << listaCopia.ObtenerTamanio () << endl << endl;
        }

        cout << "VACIANDO LISTAS ORDENADAS ASCENDENTES FLOAT Y COPIA\n\n"<<endl;
        listaFloat.Vaciar();
        listaCopia.Vaciar();
        cout << "\nLISTA  ORDENADA DESCENDENTE FLOAT VACIA: " << (listaFloat.Vacia ()) << endl;

        cout << "COPIA LISTA  ORDENADA DESCENDENTE FLOAT VACIA : " <<  listaCopia.Vacia () << endl << endl;


    }catch(bad_alloc){
        cout << "Error asignaci\xA2n de memoria";
    }
    catch(...) {
        cout<< "Algun error ocurrio" <<endl;
    }
    try {
        ListaSimpleOrdenada<char , ascendente> listaChar;

        cout<<boolalpha;

        cout << "-----------------LISTA ORDENADA ASCENDENTE CHAR.---------------" << endl << endl << "Agregar  elementos" << endl;
        for ( int i = 0 , n = 1 + rand () % 10 ; i < n ; ++i ) {
            listaChar.AgregarElemento (char(i+33));
            cout << listaChar << endl;
            cout << "Tamaño lista: " << listaChar.ObtenerTamanio () << endl << endl;
        }

        cout << "LISTA ORDENADA ASCENDENTE CHAR." << endl;

        cout << listaChar << endl;


        for ( int i = 0 , n = 1 + rand () % 5 ; i < n ; ++i ) {
            char valor = char( 33 + rand()%11);
            cout << "Buscando valor '"<<valor<<"' existe: "<< listaChar.Buscar (valor)<<endl;

        }

        cout << endl << "COPIA LISTA ORDENADA ASCENDENTE CHAR.  " << endl;

        ListaSimpleOrdenada<char,ascendente> listaCopia;
        listaCopia = listaChar;//  llama constructor de copias

        cout << listaCopia << endl;


        cout << "\nELIMINAR ELEMENTOS LISTA ORDENADA ASCENDENTE CHAR." << endl;


        for ( int i = 0 , n = 1 + rand () % 10 ; i < n ; ++i ) {
            int x = 1 + rand () % 100;
            cout <<  "Eliminar elemento  "<< x << ": "<< listaChar.EliminarElemento (x)<<endl;
            cout << listaChar << endl;
            cout << "Tamaño lista: " << listaChar.ObtenerTamanio () << endl << endl;
        }



        cout << "\nIMPRESI\xA2N COPIA DE LISTA ORDENADA ASCENDENTE CHAR (COMPROBACI\xA2N CONSTRUCTOR DE COPIAS)\n\n";

        cout << listaCopia << endl;

        cout << "\nELIMINAR ELEMENTOS COPIA LISTA  ORDENADA ASCENDENTE CHAR" << endl;



        for ( int i = 0 , n = 1 + rand () % 10 ; i < n ; ++i ) {
            int x = 1 + rand () % 100;
            cout <<  "Eliminar elemento  "<< x << ": "<< listaCopia.EliminarElemento (x)<<endl;
            cout << listaCopia << endl;
            cout << "Tamaño lista: " << listaCopia.ObtenerTamanio () << endl << endl;
        }


        cout << "\nLISTA  ORDENADA ASCENDENTE CHAR VACIA: " << boolalpha << (listaChar.Vacia ()) << endl;

        cout << "COPIA LISTA  ORDENADA ASCENDENTE CHAR VACIA : " << boolalpha << listaCopia.Vacia () << endl << endl;


    }catch(bad_alloc){
        cout << "Error asignaci\xA2n de memoria";
    }
    catch(...) {
        cout<< "Algun error ocurrio" <<endl;
    }

}