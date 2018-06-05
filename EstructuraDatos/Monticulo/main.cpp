#include <iostream>
#include "Monticulo.h"
using namespace std;


int main()
{
    srand (time(NULL));
    try {

        Monticulo<int,Min> MonticuloInt, MonticuloIntCopia;
        for(int i = 0; i < 10; ++i){
            MonticuloInt.AgregaElemento(rand() % 100 + 1);
        }
        cout << "------MONTICULO MINIMO INT------" << endl<<endl<<endl;
        MonticuloInt.Imprimir();
        cout << "El valor m\xA1"<<"nimo del mont\xA1"<<"culo: " << MonticuloInt.ObtenerRaiz() << endl;
        cout << "Copiando el mont\xA1"<<"culo..." << endl;
        MonticuloIntCopia = MonticuloInt;
        cout << "Vaciando mont\xA1"<<"culo original..." << endl;
        MonticuloInt.Vaciar();
        cout << "Esta vac\xA1"<<"o el mont\xA1"<<"culo original?: " << boolalpha << MonticuloInt.EstaVacio();
        cout << endl;
        cout << "Imprimiendo mont\xA1"<<"culo copia..." << endl;
        MonticuloIntCopia.Imprimir();

        cout << "Eliminando mont\xA1"<<"culo copia elemento por elemento..." << endl;
        int raiz = MonticuloIntCopia.ObtenerRaiz();
        for(int i = 0; !MonticuloIntCopia.EstaVacio(); ++i){
            MonticuloIntCopia.EliminarElemento();
            cout << "La ra\xA1"<<"z actual del monticulo: " << MonticuloIntCopia.ObtenerRaiz() << endl;

        }
        cout << "La ra\xA1"<<"z actual del mont\xA1"<<"culo: " << raiz << endl;
        cout << "Esta vac\xA1"<<"o el mont\xA1"<<"culo copia?: " << boolalpha << MonticuloIntCopia.EstaVacio();
        cout << endl;
        cout << endl << endl << endl;

    }catch(bad_alloc &exc){
        std::cout << "ERROR." << std::endl;
    }catch(Excepcion &msn){
        cout << "ERROR: " << msn.QuePaso() << endl;
    }

    try{
        Monticulo<float, Max> MonticuloFloat, MonticuloFloatCopia;
        for(int i = 0; i < 10; ++i){
            MonticuloFloat.AgregaElemento((rand() % 100 + 1)*.156);
        }
        cout << "------MONTICULO MAXIMO FLOAT------" << endl<<endl<<endl;
        MonticuloFloat.Imprimir();
        cout << "El valor m\xA0ximo del mont\xA1"<<"culo: " << MonticuloFloat.ObtenerRaiz() << endl;
        cout << "Copiando el mont\xA1"<<"culo..." << endl;
        MonticuloFloatCopia = MonticuloFloat;
        cout << "Vaciando mont\xA1"<<"culo original..." << endl;
        MonticuloFloat.Vaciar();
        cout << "Esta vac\xA1"<<" el mont\xA1"<<"culo original? " << boolalpha << MonticuloFloat.EstaVacio();
        cout << endl;
        cout << "Imprimiendo mont\xA1"<<"culo copia..." << endl;
        MonticuloFloatCopia.Imprimir();

        cout << "Eliminando mont\xA1"<<"culo copia elemento por elemento..." << endl;
        double raiz2 = MonticuloFloatCopia.ObtenerRaiz();
        for(int i = 0; !MonticuloFloatCopia.EstaVacio(); ++i){
            MonticuloFloatCopia.EliminarElemento();
            cout << "La ra\xA1"<<"z actual del mont\xA1"<<"culo: " << MonticuloFloatCopia.ObtenerRaiz() << endl;
            cout << MonticuloFloat <<endl;
        }
        cout << "La ra\xA1"<<"z actual del mont\xA1"<<"culo: " << raiz2 << endl;


        cout << "Esta vac\xA1"<<" el mont\xA1"<<"culo copia?: " << boolalpha << MonticuloFloatCopia.EstaVacio();
        cout<<endl<<endl<<endl;
    }catch(bad_alloc &exc){
        std::cout << "ERROR." << std::endl;
    }catch(Excepcion &msn){
        cout << "ERROR: " << msn.QuePaso() << endl;
    }
    try{


        Monticulo<char,Min> MonticuloChar, MonticuloCharCopia;
        char  dato;
        for ( int i = 0 ; i < 10 ; ++i ) {
            dato =  char(33 + rand () % 30);
            MonticuloChar.AgregaElemento (dato);
        }
        cout << "------MONTICULO MINIMO CHAR------" << endl<<endl<<endl;
        MonticuloChar.Imprimir();
        cout << "El valor m\xA1"<<"nimo del mont\xA1"<<"culo: " << MonticuloChar.ObtenerRaiz() << endl;
        cout << "Copiando el mont\xA1"<<"culo..." << endl;
        MonticuloCharCopia = MonticuloChar;
        cout << "Vaciando mont\xA1"<<"culo original..." << endl;
        MonticuloChar.Vaciar();
        cout << "Esta vacio el mont\xA1"<<"culo original?: " << boolalpha << MonticuloChar.EstaVacio();
        cout << endl;
        cout << "Imprimiendo mont\xA1"<<"culo copia..." << endl;
        MonticuloCharCopia.Imprimir();

        cout << "Eliminando mont\xA1"<<"culo copia elemento por elemento..." << endl;
        int raiz = MonticuloCharCopia.ObtenerRaiz();
        for(int i = 0; !MonticuloCharCopia.EstaVacio(); ++i){
            MonticuloCharCopia.EliminarElemento();
            cout << "La ra\xA1"<<"z actual del monticulo: " << MonticuloCharCopia.ObtenerRaiz() << endl;
        }
        cout << "La ra\xA1"<<"z actual del mont\xA1"<<"culo: " << raiz << endl;
        cout << "Esta vacio el mont\xA1"<<"culo copia?: " << boolalpha << MonticuloCharCopia.EstaVacio();
        cout << endl;

    }catch(bad_alloc &exc){
        std::cout << "ERROR." << std::endl;
    }catch(Excepcion &msn){
        cout << "ERROR: " << msn.QuePaso() << endl;
    }
    system("Pause");
    return 0;
}
