//
// Created by Eduardo Gonzalez Olea on 3/12/18.
//

#ifndef ESTRUCTURA_FIFO_COLA_H
#define ESTRUCTURA_FIFO_COLA_H
#include <cstdlib>
#include <iostream>
#include "Excepciones.h"
template  <typename tipo>
class Cola;

template  <typename tipo>
std::ostream & operator<<  (std::ostream & o, const Cola<tipo>&v);

template  <typename tipo>
class Cola {

    friend std::ostream & operator<< <> (std::ostream & o, const Cola<tipo>&v);

public:

    Cola();
    ~Cola();
    Cola(const Cola &c);

    Cola &operator =(const Cola &p);

    void AgregarElemento(tipo valor);

    bool Vacia() const;
    tipo EliminarElemento();

    void Vaciar();

    int ObtenerTamanio();
    tipo ObtenerTope();

private:


    struct Elemento {

        //friend std::ostream & operator<< <>std::ostream & o, const Cola<tipo>&v);
        Elemento(tipo _valor,Elemento * _siguiente=NULL): valor(_valor) , siguiente(_siguiente){ }

        tipo  valor;
        Elemento * siguiente;
    };

    int numElementos;
    Elemento * primero;
    Elemento * ultimo;


};

template<typename tipo>
Cola<tipo>::Cola() : numElementos(0), primero(NULL), ultimo(NULL) {

}


template<typename tipo>
Cola<tipo>::~Cola () {
    Vaciar();
}

template<typename Tipo>
Cola<Tipo>::Cola(const Cola &c) : numElementos(0), primero(NULL), ultimo(NULL) {
    *this = c;
}
template<typename Tipo>
Cola<Tipo> &Cola<Tipo>::operator=(const Cola &c) {
    if(this == &c) return *this;

    Vaciar();

    for(Elemento *aux = c.primero; numElementos <= c.numElementos; aux = aux -> siguiente){
        AgregarElemento(aux -> valor);
        if(aux -> siguiente == NULL)
            break;
    }

    return *this;
}

template<typename tipo>
bool Cola<tipo>::Vacia ()const {
    return primero == NULL && ultimo == NULL;
}

template<typename tipo>
void Cola<tipo>::AgregarElemento (tipo valor) {
    Elemento * nuevo= new Elemento(valor);

    Vacia() ? primero = nuevo : ultimo -> siguiente = nuevo;

    ultimo = nuevo;

    numElementos++;
}

template<typename tipo>
std::ostream &operator<< (std::ostream &o , const Cola<tipo> &v) {
    if(v.Vacia()){
        o<<"Esta Vacia";
        return o;
    }

    struct Cola<tipo>::Elemento * aux = v.primero;
    o << "Primero -> ";
    while(aux != NULL){
        o << "[" << aux -> valor << "] ";
        aux = aux -> siguiente;
    }
    o << "\b <- Ultimo.";
    return o;

}


template<typename tipo>
tipo Cola<tipo>::EliminarElemento ()
{
    if(Vacia ()) throw Excepcion("Cola Vacia");
    Elemento *aux = primero;
    primero = primero -> siguiente;
    tipo valor = aux-> valor;
    delete aux;
    numElementos--;
    if(numElementos == 0 )ultimo =NULL;
    return valor;
}

template<typename tipo>
void Cola<tipo>::Vaciar () {
    while(!Vacia ()){
        EliminarElemento ();
    }
}

template<typename tipo>
int Cola<tipo>::ObtenerTamanio () {
    return numElementos;
}

template<typename tipo>
tipo Cola<tipo>::ObtenerTope () {
    return primero->valor;
}


#endif //ESTRUCTURA_FIFO_COLA_H
