//
// Created by Eduardo Gonzalez Olea on 2/21/18.
//

#ifndef LISTAS_ELEMENTO_H
#define LISTAS_ELEMENTO_H
#include <cstdlib>
#include <iostream>

template <typename  tipo>
class Pila;


template <typename tipo>
std::ostream & operator<< (std::ostream & o, const Pila <tipo> &v);

    /**
    * \brief plantilla de clase Elemento para simular una lista
    *
    */
template <typename tipo>
class Elemento {

    /**
       * \brief plantilla de clase Pila que se define como amiga para que tenga acceso a ella
       *
       */
    template <typename  tipo2> friend class Pila;
    /** \brief  sobrecarga de operador << para imprimir un objeto tipo Pila la cual la tienes que hacer amiga para que esta tenga acceso
    *
    * \param ostream o donde se almacenara la cadena
    * \param Pila v arreglo a imprimir
    * \return devuelve una variable de tipo ostream
    *
    */
    friend std::ostream & operator<< <>(std::ostream & o, const Pila <tipo> &v);

public:
    /**
     * \brief constructor de la clase Elemento
     * \param tipo _valor el valor que se desea meter en la pila
     * \param  Elemento * _siguiente un puntero tipo Elemento para saber cual seria el siguiente elemento a donde apunta

     */
    Elemento(tipo _valor,Elemento * _siguiente=NULL): valor(_valor) , siguiente(_siguiente){ }

private:
    tipo valor;
    Elemento<tipo> * siguiente;
};


#endif //LISTAS_ELEMENTO_H


