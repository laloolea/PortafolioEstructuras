//
// Created by Eduardo Gonzalez Olea on 2/28/18.
//

#ifndef LISTASPILACHAR_PILA_H
#define LISTASPILACHAR_PILA_H

#include "Elemento.h"
#include <iostream>

class Pila {
    friend std::ostream & operator<< (std::ostream & o, const Pila &pila);

public:
    //Metodos indispensables
    Pila();
    ~Pila();
    Pila(const Pila &p);

    Pila &operator=(const  Pila &p);

    //Métodos de operaciones

    void AgregarElemento(int valor);//push

    int ObtenerTope();

    int EliminarElemento();

    int ObtenerTamanio();

    void Vaciar();

    // Métodos para conocer el estado

    bool EstaVacia();




private:
    int numElementos;
    Elemento *tope;
};



#endif //LISTASPILACHAR_PILA_H
