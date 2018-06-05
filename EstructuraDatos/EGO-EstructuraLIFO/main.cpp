#include <iostream>
#include "Pila.h"
#include <ctime>
#include <cmath>
//#include "Complejo.h"
#include <new>
using namespace std;


int main () {

    srand(time(NULL));

    //á = \xA0, é = \x82, í =\xA1, ó = \xA2, ú=\xA3,  ñ = \xA4
    try {
        Pila<int>pilaInt ;

        cout << "PILA INT."<<endl<<endl<<"Agregar  elementos"<<endl;
        for (int i =0, n=1+rand()%20 ;i < n ; ++i){
            pilaInt.AgregarElemento (1+rand()%500);
            pilaInt.ImprimirPila ();
            cout <<"Capacidad de la pila: "<< pilaInt.ObtenerCapacidad ()<<endl<<
                 "Tamaño pila: "<<pilaInt.ObtenerTamanio ()<<endl;
        }

        cout << endl << "PILA INT"<<endl;

        pilaInt.ImprimirPila ();
        cout <<endl<< "PILA INT COPIA.  "<<endl;


        Pila<int>pilaCopia=pilaInt;//  llama constructor de copias

        pilaCopia.ImprimirPila () ;



        cout  << "\nELIMINAR ELEMENTOS PILA INT"<<endl;
        //for ( int i=0 ; i< pilaInt.ObtenerTamanio ();++i){
        //cout << "Elemento eliminado:"<< pilaInt.EliminarElemento()<<endl;
        //}

        while (!pilaInt.EstaVacia()){
            cout << "Elemento eliminado:"<< pilaInt.EliminarElemento()<<endl;
        };


        cout <<"\nIMPRESI\xA2N COPIA DE PILA INT (COMPROBACI\xA2N CONSTRUCTOR DE COPIAS)\n\n";

        pilaCopia.ImprimirPila();

        cout  << "\nELIMINAR ELEMENTOS COPIA PILA INT"<<endl;

        while (!pilaCopia.EstaVacia()){
            cout << "Elemento eliminado:"<< pilaCopia.EliminarElemento()<<endl;
        };


        cout<< "\nTOPE PILA INT VACIADA: " <<boolalpha<<(pilaInt.EstaVacia ())<<endl;

        cout<< "TOPE PILA COPIA INT VACIADA: " <<boolalpha<<pilaCopia.EstaVacia ()<<endl<<endl;


    }catch(Excepcion &exc){
        cout <<"PILA INT:  "<< exc.QuePaso()<<std::endl;
        }
    catch(bad_alloc){
        cout << "Error asignaci\xA2n de memoria";
    }
    catch(...) {
        cout<< "Algun error ocurrio" <<endl;
    }
    try {
        Pila<float>pilaFloat ;

        cout << "***************************************************************************\n\nPILA FLOAT."<<endl<<endl<<"Agregar  elementos"<<endl;
        for (int i =0, n=1+rand()%20 ;i < n ; ++i){
            float aux= 1+rand()%500;
            pilaFloat.AgregarElemento (aux +aux/100);
            pilaFloat.ImprimirPila ();
            cout <<"Capacidad de la pila: "<< pilaFloat.ObtenerCapacidad ()<<endl<<
                 "Tamaño pila: "<<pilaFloat.ObtenerTamanio ()<<endl;
        }

        cout << endl << "PILA FLOAT"<<endl;

        pilaFloat.ImprimirPila ();
        cout <<endl<< "PILA FLOAT COPIA.  "<<endl;


        Pila<float>pilaCopia=pilaFloat;//  llama constructor de copias

        pilaCopia.ImprimirPila () ;



        cout  << "\nELIMINAR ELEMENTOS PILA FlOAT"<<endl;
        //for ( int i=0 ; !pilaCopia.EstaVacia();++i){
        //cout << "Elemento eliminado:"<< pilaInt.EliminarElemento()<<endl;
        //}

        while (!pilaFloat.EstaVacia()){
            cout << "Elemento eliminado:"<< pilaFloat.EliminarElemento()<<endl;
        };


        cout <<"\nIMPRESI\xA2N COPIA DE PILA FLOAT (COMPROBACI\xA2N CONSTRUCTOR DE COPIAS)\n\n";

        pilaCopia.ImprimirPila();

        cout  << "\nELIMINAR ELEMENTOS COPIA PILA FLOAT"<<endl;

        while (!pilaCopia.EstaVacia()){
            cout << "Elemento eliminado:"<< pilaCopia.EliminarElemento()<<endl;
        };


        cout<< "\nTOPE PILA FLOAT VACIADA: " <<boolalpha<<(pilaFloat.EstaVacia ())<<endl;

        cout<< "TOPE PILA COPIA FLOAT VACIADA: " <<boolalpha<<pilaCopia.EstaVacia ()<<endl<<endl;


    }catch(Excepcion &exc){
        cout <<"PILA FLOAT:"<< exc.QuePaso()<<std::endl;
    }
    catch(bad_alloc){
        cout << "Error asignaci\xA2n de memoria";
    }
    catch(...) {
        cout<< "Algun error ocurrio" <<endl;
    }

    try {
        Pila<char>pilaChar ;

        cout << "***************************************************************************\n\nPILA CHAR."<<endl<<endl<<"Agregar  elementos"<<endl;
        for (int i =0, n=1+rand()%10 ;i < n ; ++i){
            pilaChar.AgregarElemento (char(i+33));
            pilaChar.ImprimirPila ();
            cout <<"Capacidad de la pila: "<< pilaChar.ObtenerCapacidad ()<<endl<<
                 "Tamaño pila: "<<pilaChar.ObtenerTamanio ()<<endl;
        }

        cout << endl << "PILA CHAR"<<endl;

        pilaChar.ImprimirPila ();
        cout <<endl<< "PILA CHAR COPIA.  "<<endl;


        Pila<char>pilaCopia=pilaChar;//  llama constructor de copias

        pilaCopia.ImprimirPila () ;



        cout  << "\nELIMINAR ELEMENTOS PILA CHAR"<<endl;
        //for ( int i=0 ; !pilaCopia.EstaVacia();++i){
        //cout << "Elemento eliminado:"<< pilaInt.EliminarElemento()<<endl;
        //}

        while (!pilaChar.EstaVacia()){
            cout << "Elemento eliminado:"<< pilaChar.EliminarElemento()<<endl;
        };


        cout <<"\nIMPRESI\xA2N COPIA DE PILA CHAR (COMPROBACI\xA2N CONSTRUCTOR DE COPIAS)\n\n";

        pilaCopia.ImprimirPila();

        cout  << "\nELIMINAR ELEMENTOS COPIA PILA CHAR"<<endl;

        while (!pilaCopia.EstaVacia()){
            cout << "Elemento eliminado:"<< pilaCopia.EliminarElemento()<<endl;
        };


        cout<< "\nTOPE PILA CHAR VACIADA: " <<boolalpha<<(pilaChar.EstaVacia ())<<endl;

        cout<< "TOPE PILA COPIA CHAR VACIADA: " <<boolalpha<<pilaCopia.EstaVacia ()<<endl<<endl;


    }catch(Excepcion &exc){
        cout <<"PILA CHAR:"<< exc.QuePaso()<<std::endl;
    }
    catch(bad_alloc){
        cout << "Error asignaci\xA2n de memoria";
    }
    catch(...) {
        cout<< "Algun error ocurrio" <<endl;
    }


    //std::cout  <<"Pila [ " <<

    //system("pause");
    return 0;
}