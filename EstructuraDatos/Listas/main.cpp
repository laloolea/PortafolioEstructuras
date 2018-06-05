#include <iostream>
#include "Pila.h"
#include "Excepcion.h"

using namespace std;
int main () {

    try {
        Pila<int>pilaInt ;

        cout << "PILA INT."<<endl<<endl<<"Agregar  elementos"<<endl;
        for (int i =0, n=1+rand()%20 ;i < n ; ++i){
            pilaInt.AgregarElemento (1+rand()%100);
            cout << pilaInt<<endl;
            cout <<"Tamaño pila: "<<pilaInt.ObtenerTamanio ()<<endl;
        }

        cout << endl << "PILA INT"<<endl;

        cout<<pilaInt<<endl;
        cout <<endl<< "PILA INT COPIA.  "<<endl;


        Pila<int>pilaCopia=pilaInt;//  llama constructor de copias

        cout << pilaCopia<<endl;



        cout  << "\nELIMINAR ELEMENTOS PILA INT"<<endl;
        //for ( int i=0 ; i< pilaInt.ObtenerTamanio ();++i){
        //cout << "Elemento eliminado:"<< pilaInt.EliminarElemento()<<endl;
        //}

        while (!pilaInt.EstaVacia()){
            cout << "Elemento eliminado:"<< pilaInt.EliminarElemento()<<endl;
        };


        cout <<"\nIMPRESI\xA2N COPIA DE PILA INT (COMPROBACI\xA2N CONSTRUCTOR DE COPIAS)\n\n";

        cout << pilaCopia<<endl;

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

        cout << "PILA FLOAT."<<endl<<endl<<"Agregar  elementos"<<endl;
        for (int i =0, n=1+rand()%20 ;i < n ; ++i){
            float aux= 1+rand()%500;
            pilaFloat.AgregarElemento (aux +aux/100);
            cout << pilaFloat<<endl;
            cout <<"Tamaño pila: "<<pilaFloat.ObtenerTamanio ()<<endl;
        }

        cout << endl << "PILA FLOAT"<<endl;

        cout<<pilaFloat<<endl;
        cout <<endl<< "PILA FLOAT COPIA.  "<<endl;


        Pila<float>pilaCopia=pilaFloat;//  llama constructor de copias

        cout << pilaCopia<<endl;



        cout  << "\nELIMINAR ELEMENTOS PILA FLOAT"<<endl;
        //for ( int i=0 ; i< pilaInt.ObtenerTamanio ();++i){
        //cout << "Elemento eliminado:"<< pilaInt.EliminarElemento()<<endl;
        //}

        while (!pilaFloat.EstaVacia()){
            cout << "Elemento eliminado:"<< pilaFloat.EliminarElemento()<<endl;
        };


        cout <<"\nIMPRESI\xA2N COPIA DE PILA FLOAT (COMPROBACI\xA2N CONSTRUCTOR DE COPIAS)\n\n";

        cout << pilaCopia<<endl;

        cout  << "\nELIMINAR ELEMENTOS COPIA PILA FLOAT"<<endl;

        while (!pilaCopia.EstaVacia()){
            cout << "Elemento eliminado:"<< pilaCopia.EliminarElemento()<<endl;
        };


        cout<< "\nTOPE PILA FLOAT VACIADA: " <<boolalpha<<(pilaFloat.EstaVacia ())<<endl;

        cout<< "TOPE PILA COPIA FLOAT VACIADA: " <<boolalpha<<pilaCopia.EstaVacia ()<<endl<<endl;


    }catch(Excepcion &exc){
        cout <<"PILA FLOAT:  "<< exc.QuePaso()<<std::endl;
    }
    catch(bad_alloc){
        cout << "Error asignaci\xA2n de memoria";
    }
    catch(...) {
        cout<< "Algun error ocurrio" <<endl;
    }
    try {
        Pila<char>pilaChar ;

        cout << "PILA CHAR."<<endl<<endl<<"Agregar  elementos"<<endl;
        for (int i =0, n=1+rand()%20 ;i < n ; ++i){
            pilaChar.AgregarElemento (char(i+33));
            cout << pilaChar<<endl;
            cout <<"Tamaño pila: "<<pilaChar.ObtenerTamanio ()<<endl;
        }

        cout << endl << "PILA CHAR"<<endl;

        cout<<pilaChar<<endl;
        cout <<endl<< "PILA CHAR COPIA.  "<<endl;


        Pila<char>pilaCopia=pilaChar;//  llama constructor de copias

        cout << pilaCopia<<endl;



        cout  << "\nELIMINAR ELEMENTOS PILA CHAR"<<endl;


        while (!pilaChar.EstaVacia()){
            cout << "Elemento eliminado:"<< pilaChar.EliminarElemento()<<endl;
        };


        cout <<"\nIMPRESI\xA2N COPIA DE PILA CHAR (COMPROBACI\xA2N CONSTRUCTOR DE COPIAS)\n\n";

        cout << pilaCopia<<endl;

        cout  << "\nELIMINAR ELEMENTOS COPIA PILA CHAR"<<endl;

        while (!pilaCopia.EstaVacia()){
            cout << "Elemento eliminado:"<< pilaCopia.EliminarElemento()<<endl;
        };


        cout<< "\nTOPE PILA CHAR VACIADA: " <<boolalpha<<(pilaChar.EstaVacia ())<<endl;

        cout<< "TOPE PILA COPIA CHAR VACIADA: " <<boolalpha<<pilaCopia.EstaVacia ()<<endl<<endl;


    }catch(Excepcion &exc){
        cout <<"PILA CHAR:  "<< exc.QuePaso()<<std::endl;
    }
    catch(bad_alloc){
        cout << "Error asignaci\xA2n de memoria";
    }
    catch(...) {
        cout<< "Algun error ocurrio" <<endl;
    }
    return 0;
}