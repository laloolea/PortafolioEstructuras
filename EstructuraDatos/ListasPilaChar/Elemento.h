//
// Created by Eduardo Gonzalez Olea on 2/28/18.
//

#ifndef LISTASPILACHAR_ELEMENTO_H
#define LISTASPILACHAR_ELEMENTO_H
#include <cstdlib>
#include <iostream>

class Pila;

class Elemento {
    friend class Pila;
    friend std::ostream & operator<< (std::ostream & o, const Pila &pila);
public:
    Elemento(int _valor,Elemento * _siguiente=NULL):valor(_valor) , siguiente(_siguiente){ }


private:
    char valor;
    Elemento * siguiente;
};



#endif //LISTASPILACHAR_ELEMENTO_H
