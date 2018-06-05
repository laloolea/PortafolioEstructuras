#include <iostream>
#include <cstdlib>
#include <fstream>
#include "ABB.h"
#include "CapturaSegura.h"

using namespace std;


int main () {

    ABB<string> arbolPalabrasReservadas;
    ABB<string> arbol;
    string palabraReservada;
    string palabra;
    string ubicacion = "PalabrasReservadas.txt";

    string ruta;
    try{
        CapturaDato ("Por favor ingrese la ruta completa del archivo a buscar palabras reservadas: ",ruta);

        //"/Users/eduardogonzalez/Desktop/EstructuraDatos/EGO-ArbolBinarioBusqueda/Cola.h"
        ifstream entrada1 ("PalabrasReservadas.txt");

        ifstream entrada2(ruta);

        if (!entrada1 ){
            cout << "No se pudo abrir el archivo de palabras reservadas por problemas de fuerza mayor" << endl;
            return 0;
        }

        if (!entrada2 ){
            cout << "No se pudo abrir el archivo dado por problemas de fuerza mayor" << endl;
            return 0;
        }
            //Se lee el archivo con palabras reservadas
        if (entrada1.is_open()){
            while (getline(entrada1,palabraReservada)){
                if (entrada1.bad()) throw "Ocurrio una falla irrecuperable en el flujo del archivo";
                if (entrada1.fail()) throw "Los datos del archivo no tienen el formato esperado";
                arbolPalabrasReservadas.Agregar(palabraReservada);
            }
            entrada1.close();
        }
        cout << "Buscando palabras reservadas en archivo dado..." << endl;
        //Se lee el archivo para detectar palabras reservadas
        if (entrada2.is_open()){
            while (!entrada2.eof()){
                if (entrada2.bad()) throw "Ocurrio una falla irrecuperable en el flujo del archivo";
                if (entrada2.fail()) throw "Los datos del archivo no tienen el formato esperado";
                entrada2 >> palabra;
                //Busca la palabra que se leyo del archivo en el arbol que tiene todas las palabras reservadas y si lo encuentra
                //la agrega al otro arbol
                if (arbolPalabrasReservadas.Buscar(palabra)) arbol.Agregar(palabra);
            }
            entrada2.close();
        }

        cout << "Palabras reservadas encontradas: ";
        arbol.ImprimirPorNiveles ();


    }catch(Excepcion &e){
        cout << "ERROR: " << e.QuePaso() << endl;
    }catch(bad_alloc &exc){
        std::cout << "ERROR." << std::endl;
    }
    return 0;
}


