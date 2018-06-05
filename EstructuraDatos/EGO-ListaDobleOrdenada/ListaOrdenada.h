//
// Created by Eduardo Gonzalez Olea on 4/17/18.
//

#ifndef EGO_LISTADOBLEORDENADA_LISTAORDENADA_H
#define EGO_LISTADOBLEORDENADA_LISTAORDENADA_H

#include <cstdlib>
#include <iostream>
#include  "ListaDoble.h"

template <typename Tipo>
class ListaOrdenada;
template <typename Tipo>
std::ostream& operator<<(std::ostream & salida, const ListaOrdenada<Tipo> &c);

/**
    \brief Plantilla de clase ListaSimpleOrdenada.
 */
template <typename Tipo =int>
class ListaOrdenada {
    /** \brief  sobrecarga de operador << para imprimir un objeto tipo ListaOrdenada de manera ascendente)
      * la cual la tienes que hacer amiga para que esta tenga acceso
      *
      * \param ostream o donde se almacenara la cadena
      * \param ListaORdenada c Lista Ordenada a imprimir
      * \return devuelve una variable de tipo ostream
      *
      */
    friend std::ostream & operator<< <>(std::ostream & salida, const ListaOrdenada<Tipo> &c);
public:
    /**
        * \brief constructor  de la clase ListaOrdenada
        *
        *
        */
    ListaOrdenada();
    /**
     * \brief constructor de copias de la clase ListaOrdenada
     * \param const ListaORdenada &c una referencia constante a la lista ordenada la que quieres copiar
     */

    ListaOrdenada(const ListaOrdenada<Tipo> &c);
    /**
    * \brief destructor  de la clase ListaOrdenada
    *
    */
    ~ListaOrdenada();



    /**
      * \brief Funci&oacute;n que agrega un elemento a la lista Ordenada
      * \param tipo valor El valor que se metera a la listaOrdenada
      * \exception bad_alloc, si no hay memoria disponible para agregar nuevo elemento
      */
    void AgregarElemento(Tipo valor);
    /**
    * \brief Funci&oacute;n que elimina un elemento de una lista ordenada
    * \param  Tipo valor el valor a eliminar en la lista ordenada
    * return true si se pudo eliminar el valor en la lista ordenada
    */
    bool EliminarElemento(Tipo valor);
    /**
    * \brief Funci&oacute;n que busca un elemento de una lista ordenada
    * \param  Tipo valor el valor a buscar en la lista ordenada
     * return true si se encontro el valor en la lista ordenada
    */
    bool Buscar(Tipo valorB) const ;
    /**
    * \brief Funci&oacute;n que vacia la lista ordenada
    */
    void Vaciar();
    /**
     * \brief Funci&oacute;n que ve si una lista ordenada esta vacia
     * \return true si esta vacia, false si no lo esta
     */
    bool EstaVacia () const ;
    /**
     * \brief Funci&oacute;n que devuelve el tama&ntilde;o actual de la lista  ordenada
     * \return el tama&ntilde;o de la lista ordenada
     */

    int ObtenerTamanio() const;
    /**
     * \brief Sobrecarga del operador = para igualar dos listas ordenadas
     * \param const ListaOrdenada &o una referencia constante a ListaOrdenada
     * \return Una referencia a ListaOrdenada
     */
    ListaOrdenada<Tipo> &operator=(const ListaOrdenada<Tipo> &c);
    /**
     * \brief Funci&oacute;n que imprime una lista ordenada de manera ascendente
     */

    void ImprimirAscendente()const;
    /**
     * \brief Funci&oacute;n que imprime una lista doble de manera descendente
     */
    void ImprimirDescendente()const;

private:
    ListaDoble<Tipo> lista;
};


template<typename Tipo>
ListaOrdenada<Tipo>::ListaOrdenada () {

}

template<typename Tipo>
ListaOrdenada<Tipo>::ListaOrdenada (const ListaOrdenada<Tipo> &c) {
    *this = c;
}

template<typename Tipo>
ListaOrdenada<Tipo>::~ListaOrdenada () {
    lista.Vaciar();
}

template<typename Tipo>
ListaOrdenada<Tipo> &ListaOrdenada<Tipo>::operator=(const ListaOrdenada<Tipo> &c){

    if (this!=&c)lista= c.lista;
    return *this;
}


template<typename Tipo>
void ListaOrdenada<Tipo>::ListaOrdenada::AgregarElemento (Tipo valor) {

    lista.AgregarEnPos(valor,lista.BuscarPosDe(valor,Mayor));
}


template<typename Tipo>
bool ListaOrdenada<Tipo>::EliminarElemento (Tipo valor) {

    int pos = lista.BuscarPosDe(valor);
    if(pos== lista.ObtenerTamanio ())return false;
    lista.EliminarEnPos(pos);
    return true;

}

template<typename Tipo>
bool ListaOrdenada<Tipo>::Buscar (Tipo valorB) const{
    return lista.BuscarPosDe(valorB)!=ObtenerTamanio();
}

template<typename Tipo>
void ListaOrdenada<Tipo>::Vaciar () {

    lista.Vaciar ();
}

template<typename Tipo>
bool ListaOrdenada<Tipo>::EstaVacia ()const {
    return lista.EstaVacia ();
}

template<typename Tipo>
int ListaOrdenada<Tipo>::ObtenerTamanio () const{
    return lista.ObtenerTamanio ();
}



template <typename Tipo>
std::ostream &operator<<(std::ostream &salida, const ListaOrdenada <Tipo> &c) {
    salida<<c.lista;
    return salida;
}

template<typename Tipo>
void ListaOrdenada<Tipo>::ImprimirAscendente () const{
    std::cout << lista;
}


template<typename Tipo>
void ListaOrdenada<Tipo>::ImprimirDescendente () const{
    lista.ImprimirInversa ();
}

#endif //EGO_LISTADOBLEORDENADA_LISTAORDENADA_H
