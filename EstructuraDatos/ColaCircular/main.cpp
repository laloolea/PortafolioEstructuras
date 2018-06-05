#include <iostream>
#include "Cola.h"

using namespace std;
int main() {

    srand(time(NULL));
    try {
        Cola<int>colaInt ;

        Cola<int>cola2;
        cola2.EliminarElemento ();

        cout << "COLA INT."<<endl<<endl<<"Agregar  elementos"<<endl;
        for (int i =0, n=1+rand()%20 ;i < n ; ++i){
            colaInt.AgregarElemento (1+rand()%100);
            cout << colaInt<<endl;
            cout <<"Tamaño cola: "<<colaInt.ObtenerTamanio ()<<endl<<endl;
        }

        cout << "COLA INT"<<endl;

        cout<<colaInt<<endl;
        cout <<endl<< "COLA INT COPIA.  "<<endl;


        Cola<int>colaCopia=colaInt;//  llama constructor de copias

        cout << colaCopia<<endl;



        cout  << "\nELIMINAR ELEMENTOS COLA INT"<<endl;


        while (!colaInt.EstaVacia()){
            cout << "Elemento eliminado:"<< colaInt.EliminarElemento()<<endl;
        };


        cout <<"\nIMPRESI\xA2N COPIA DE COLA INT (COMPROBACI\xA2N CONSTRUCTOR DE COPIAS)\n\n";

        cout << colaCopia<<endl;

        cout  << "\nELIMINAR ELEMENTOS COPIA COLA INT"<<endl;

        while (!colaCopia.EstaVacia()){
            cout << "Elemento eliminado:"<< colaCopia.EliminarElemento()<<endl;
        };


        cout<< "\nCOLA INT VACIADA: " <<boolalpha<<(colaInt.EstaVacia ())<<endl;

        cout<< "COLA COPIA INT VACIADA: " <<boolalpha<<colaCopia.EstaVacia ()<<endl<<endl;


    }catch(Excepcion &exc){
        cout <<"COLA INT:  "<< exc.QuePaso()<<std::endl;
    }
    catch(bad_alloc){
        cout << "Error asignaci\xA2n de memoria";
    }
    catch(...) {
        cout<< "Algun error ocurrio" <<endl;
    }
    try {
        Cola<float>colaFloat ;

        cout <<"///////////////////////////////////////////////////////////////\n\n";

        cout << "COLA FLOAT."<<endl<<endl<<"Agregar  elementos"<<endl;
        for (int i =0, n=1+rand()%20 ;i < n ; ++i){
            colaFloat.AgregarElemento (1+rand()%100);
            cout << colaFloat<<endl;
            cout <<"Tamaño cola: "<<colaFloat.ObtenerTamanio ()<<endl<<endl;
        }

        cout << "COLA FLOAT"<<endl;

        cout<<colaFloat<<endl;
        cout <<endl<< "COLA FLOAT COPIA.  "<<endl;


        Cola<float>colaCopia=colaFloat;//  llama constructor de copias

        cout << colaCopia<<endl;



        cout  << "\nELIMINAR ELEMENTOS COLA FLOAT"<<endl;


        while (!colaFloat.EstaVacia()){
            cout << "Elemento eliminado:"<< colaFloat.EliminarElemento()<<endl;
        };


        cout <<"\nIMPRESI\xA2N COPIA DE COLA FLOAT (COMPROBACI\xA2N CONSTRUCTOR DE COPIAS)\n\n";

        cout << colaCopia<<endl;

        cout  << "\nELIMINAR ELEMENTOS COPIA COLA FLOAT"<<endl;

        while (!colaCopia.EstaVacia()){
            cout << "Elemento eliminado:"<< colaCopia.EliminarElemento()<<endl;
        };


        cout<< "\nCOLA FLOAT VACIADA: " <<boolalpha<<(colaFloat.EstaVacia ())<<endl;

        cout<< "COLA COPIA FLOAT VACIADA: " <<boolalpha<<colaCopia.EstaVacia ()<<endl<<endl;


    }catch(Excepcion &exc){
        cout <<"COLA FLOAT:  "<< exc.QuePaso()<<std::endl;
    }
    catch(bad_alloc){
        cout << "Error asignaci\xA2n de memoria";
    }
    catch(...) {
        cout<< "Algun error ocurrio" <<endl;
    }
    try {
        Cola<char>colaChar ;
        cout <<"///////////////////////////////////////////////////////////////\n\n";
        cout << "COLA CHAR."<<endl<<endl<<"Agregar  elementos"<<endl;
        for (int i =0, n=1+rand()%20 ;i < n ; ++i){
            colaChar.AgregarElemento (i+33);
            cout << colaChar <<endl;
            cout <<"Tamaño cola: "<<colaChar.ObtenerTamanio ()<<endl<<endl;
        }

        cout << "COLA CHAR"<<endl;

        cout<<colaChar <<endl;
        cout <<endl<< "COLA CHAR COPIA.  "<<endl;


        Cola<char>colaCopia=colaChar;//  llama constructor de copias

        cout << colaCopia<<endl;



        cout  << "\nELIMINAR ELEMENTOS COLA CHAR"<<endl;


        while (!colaChar.EstaVacia()){
            cout << "Elemento eliminado:"<< colaChar.EliminarElemento()<<endl;
        };


        cout <<"\nIMPRESI\xA2N COPIA DE COLA CHAR (COMPROBACI\xA2N CONSTRUCTOR DE COPIAS)\n\n";

        cout << colaCopia<<endl;

        cout  << "\nELIMINAR ELEMENTOS COPIA COLA CHAR"<<endl;

        while (!colaCopia.EstaVacia()){
            cout << "Elemento eliminado:"<< colaCopia.EliminarElemento()<<endl;
        };


        cout<< "\nCOLA CHAR VACIADA: " <<boolalpha<<(colaChar.EstaVacia ())<<endl;

        cout<< "COLA COPIA CHAR VACIADA: " <<boolalpha<<colaCopia.EstaVacia ()<<endl<<endl;


    }catch(Excepcion &exc){
        cout <<"COLA CHAR:  "<< exc.QuePaso()<<std::endl;
    }
    catch(bad_alloc){
        cout << "Error asignaci\xA2n de memoria";
    }
    catch(...) {
        cout<< "Algun error ocurrio" <<endl;
    }
    return 0;
}