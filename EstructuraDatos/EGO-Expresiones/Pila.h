//
// Created by Eduardo Gonzalez Olea on 3/14/18.
//

#ifndef EGO_EXPRESIONES_PILA_H
#define EGO_EXPRESIONES_PILA_H
#include "Excepciones.h"
#include <cstdlib>
#include <iostream>
//  #define CAP_MAX 50
template <typename  tipo=int>
class Pila {
//metodo estatico solo puede acceder a los atributos estaticos

public:
    /**
     * \brief constructor  de la clase Pila
     *
     */
    Pila ();
    /**
     * \brief constructor de copias de la clase Pila
     * \param const Pila &pila una referencia constante a la pila a la que quieres copiar
     */
    Pila (const  Pila &pila);
    /**
     * \brief destructor  de la clase Pila
     *
     */
    ~Pila();
    /**
    * \brief Funci&oacute;n que devuelve el elemento al tope de una pila
    * \pre Que la pila no este vacia
    * \exception Excepcion si no se cumple la precondici&oacute;n
    */
    tipo ObtenerTope();
    /**
     * \brief Funci&oacute;n que agrega un elemento al tope de una pila
     * \param tipo valor El valor que se metera al tope de la pila
     * \exception bad_alloc, si no hay memoria disponible para agregar nuevo elemento
     */
    void AgregarElemento(tipo valor); // push();
    /**
     * \brief Funci&oacute;n que agrega un elemento al tope de una pila
     * \param tipo valor El valor que se metera al tope de la pila
     * \pre Que la pila no este vacia
     * \exception  Excepcion si no se cumple la precondici&oacute;n
     */

    tipo EliminarElemento();          // int pop();
    /**
     * \brief Funci&oacute;n que devuelve el tama&ntilde;o actual de la pila
     * \return el tama&ntilde;o de la pila
     */

    int ObtenerTamanio() const;            // int size();


    /**
     * \brief Funci&oacute;n que devuelve la capacidad actual de la pila
     * \return la capacidad de la pila
     */
    int ObtenerCapacidad() const;          // int capacity();
    /**
     * \brief Funci&oacute;n que indica si la pila esta vacia
     * \return un booleano que dice indica si la pila esta vacia
     */
    bool EstaVacia() const ;                // bool empty();
    /**
     * \brief Funci&oacute;n que vacia la pila asignandole a tope -1
     */
    void VaciarPila();
    /**
     * \brief Sobrecarga del operador = para igualar dos pilas
     * \param const Pila &pila una referencia constante a pila
     * \return Una referencia a pila
     */

    Pila &operator=(const  Pila &pila);
    /**
     * \brief Funci&oacute;n que imprime una pila
     */
    void ImprimirPila();

private:

    int tope;
    int capacidad;
    tipo  * elemento;
    /**
     * \brief Funci&oacute;n que crea un arreglo
     * \return Un puntero a tipo
     * \exception bad_alloc
     */
    tipo *CreaArreglo ();
    /**
     * \brief Funci&oacute;n que indica si la pila esta llena
     * \return un booleano que dice indica si la pila esta llena
     */
    bool EstaLlena();
    /**
     * \brief Funci&oacute;n que libera memoria ocupada por un arreglo dinamico.
     */
    void LiberaArreglo();





};

template<typename tipo >
Pila<tipo>::Pila () :tope(-1),capacidad(0),elemento(NULL)
{
}

template<typename tipo >
Pila<tipo>::Pila (const Pila &pila):tope(-1),capacidad(0),elemento(NULL)
{
    *this = pila;
}

template<typename tipo >
Pila<tipo >::~Pila ()
{
    LiberaArreglo();
}

template<typename tipo >
Pila<tipo> &Pila<tipo >::operator= (const Pila<tipo> &pila) {

    if(this == &pila) return *this;

    LiberaArreglo();

    capacidad = pila.ObtenerCapacidad ();

    tope = pila.tope;

    if(capacidad !=0) {


        elemento = CreaArreglo ();

        for ( int i = 0 ; i < pila.ObtenerCapacidad () ; ++i ) {
            elemento[ i ] = pila.elemento[ i ];
        }

    }
    return *this;

}

template <typename tipo>// plantilla de función
tipo Pila<tipo>::ObtenerTope () {// segundo cambio<tipo>

    if(EstaVacia()) throw Excepcion("Esta Vacia, no hay elementos");
    return elemento[tope];
}
template <typename tipo>
void Pila<tipo>::AgregarElemento (tipo valor)
{
    //++tope;


    if(EstaLlena ())
    {
        capacidad = EstaVacia () ? 1 : 2*capacidad;

        tipo * aux = elemento;

        elemento  = new tipo[capacidad];
        for(int i = 0 ; i <= tope ;++i){
            elemento [i]=aux [i];
        }
        delete [] aux;
        //aux = NULL;

    }

    //cuando esta vacia y quieres sacar elemento,
    // cuando esta vacia y queires conocer tope pila

    elemento[++tope]= valor;

}

template <typename tipo>
tipo Pila<tipo>::EliminarElemento () {

    if(EstaVacia ())throw Excepcion("Pila vacia no puedes eliminar");
    return elemento[ tope-- ];// devuelve tope y luego decrementa en uno


}
template <typename tipo>
int Pila<tipo>::ObtenerTamanio () const {
    return tope+1;
}
template <typename tipo>
int Pila<tipo>::ObtenerCapacidad () const  {
    return capacidad;
}
template <typename tipo>
bool Pila<tipo>::EstaVacia () const   {
    return tope==-1;
}

template <typename tipo>
void Pila<tipo>::VaciarPila ()
{
    tope = -1;

}

template<typename tipo >
void Pila<tipo >::LiberaArreglo() {
    delete [] elemento;
    elemento = NULL;
}


template<typename tipo >
tipo *Pila<tipo>::CreaArreglo () {


    return new tipo[capacidad]; //bad_alloc

}

template<typename tipo>
bool Pila<tipo>::EstaLlena () {
    return tope==(capacidad -1);
}

template<typename tipo>
void Pila<tipo>::ImprimirPila () {
    for(int i = 0 ; i <= tope; ++i){
        std::cout << "[" << elemento[i] <<  "] ";
    }

    std::cout << "<- tope"<<std::endl;
}


#endif //EGO_EXPRESIONES_PILA_H
