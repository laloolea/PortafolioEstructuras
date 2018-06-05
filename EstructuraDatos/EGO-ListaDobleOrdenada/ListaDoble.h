//
// Created by Eduardo Gonzalez Olea on 4/17/18.
//

#ifndef EGO_LISTADOBLEORDENADA_LISTADOBLE_H
#define EGO_LISTADOBLEORDENADA_LISTADOBLE_H

#include <cstdlib>
#include <iostream>
#include "Excepciones.h"
/**
   * \brief Funci&oacute;n que verifica si dos valores son iguales de tipo Tipo
   * \param Tipo a el primer valor a comparar
   * \param Tipo b el segundo valor a comparar
   * \return true si a es igual que b, false si b es distinto que a
   */
template <typename Tipo> bool Igual(Tipo a,Tipo b) {return a==b;}
/**
   * \brief Funci&oacute;n que verifica el menor de dos valores de tipo Tipo
   * \param Tipo a el primer valor a comparar
   * \param Tipo b el segundo valor a comparar
   * \return true si a es menor que b, false si b es menor que a
   */
template <typename Tipo> bool Menor(Tipo a,Tipo b) {return a<b;}
/**
   * \brief Funci&oacute;n que verifica el mayor de dos valores de tipo Tipo
   * \param Tipo a el primer valor a comparar
   * \param Tipo b el segundo valor a comparar
   * \return true si a es mayor o igual que b, false si b es menor que a
   */
template <typename Tipo> bool Mayor(Tipo a,Tipo b) {return a>b;}
/**
   * \brief Funci&oacute;n que verifica si dos valores de Tipo tipo son menor o iguales
   * \param Tipo a el primer valor a comparar
   * \param Tipo b el segundo valor a comparar
   * \return true si a es menor o igual que b, false si b es mayor que a
   */
template <typename Tipo> bool MenorIgual(Tipo a,Tipo b) {return a<=b;}
/**
   * \brief Funci&oacute;n que verifica si dos valores de Tipo tipo son mayor o iguales
   * \param Tipo a el primer valor a comparar
   * \param Tipo b el segundo valor a comparar
   * \return true si a es mayor o igual que b, false si b es menor que a
   */
template <typename Tipo> bool MayorIgual(Tipo a,Tipo b) {return a>=b;}
/**
   * \brief Funci&oacute;n que verifica si dos valores son distintos de tipo Tipo
   * \param Tipo a el primer valor a comparar
   * \param Tipo b el segundo valor a comparar
   * \return true si a es distinto que b, false si b es igual que a
   */
template <typename Tipo> bool Diferente(Tipo a,Tipo b) {return a!=b;}

/**
    \brief Plantilla de clase ListaSimpleOrdenada.
 */
template <typename Tipo>
class ListaDoble;

template <typename Tipo>
std::ostream& operator<<(std::ostream & salida, const ListaDoble<Tipo> &c);

template <typename Tipo =int>
class ListaDoble {
    /** \brief  sobrecarga de operador << para imprimir un objeto tipo ListaDoble la cual la tienes que hacer amiga para que esta tenga acceso
      *
      * \param ostream o donde se almacenara la cadena
      * \param ListaDoble c Lista Doble a imprimir
      * \return devuelve una variable de tipo ostream
      *
      */
    friend std::ostream & operator<< <>(std::ostream & salida, const ListaDoble<Tipo> &c);
public:
    /**
        * \brief constructor  de la clase ListaDoble
        *
        *
        */
    ListaDoble();
    /**
     * \brief constructor de copias de la clase ListaDoble
     * \param const ListaDoble &c una referencia constante a la lista doble la que quieres copiar
     */

    ListaDoble(const ListaDoble<Tipo> &c);
    /**
    * \brief destructor  de la clase ListaDoble
    *
    */
    ~ListaDoble();

    /**
     * \brief Sobrecarga del operador = para igualar dos listas dobles
     * \param const listaDoble &o una referencia constante a ListaDoble
     * \return Una referencia a ListaDoble
     */

    ListaDoble<Tipo> &operator=(const ListaDoble<Tipo> &c);

    /**
      * \brief Funci&oacute;n que agrega un elemento al principio de una lista doble
      * \param tipo valor El valor que se metera a la listaDoble
      * \exception bad_alloc, si no hay memoria disponible para agregar nuevo elemento
      */
    void AgregarPrincipio(Tipo valor);
    /**
     * \brief Funci&oacute;n que agrega un elemento al final de una lista doble
     * \param tipo valor El valor que se metera a la listaDoble
     * \exception bad_alloc, si no hay memoria disponible para agregar nuevo elemento
     */
    void AgregarFinal (Tipo valor);
    /**
    * \brief Funci&oacute;n que agrega un elemento en una posicion dada de la lista doble
    * \param tipo valor El valor que se metera a la listaDoble
    *\param int pos la posici&oacute;n del valor a ingresar
    * \exception bad_alloc, si no hay memoria disponible para agregar nuevo elemento
    */
    void AgregarEnPos(Tipo valor , int pos);
    /**
    * \brief Funci&oacute;n que elimina un elemento al principio
    * \param tipo valor El valor que se eliminara a la listaDoble
    *\param int pos la posici&oacute;n del valor a ingresar
    *\pre Que la lista  no este vac&iacute;a
    * \exception Excepcion si la precondici&oacute;n no se cumple
    */
    void EliminarPrincipio();
    /**
    * \brief Funci&oacute;n que elimina un elemento en una posicion dada de la lista doble
    * \param tipo valor El valor que se eliminara a la listaDoble
    *\param int pos la posici&oacute;n del valor a ingresar
    *\pre Que la lista  no este vac&iacute;a
    * \exception Excepcion si la precondici&oacute;n no se cumple
    */
    void EliminarFinal ();
    /**
    * \brief Funci&oacute;n que elimina un elemento en una posicion dada de la lista doble
    *\param int pos la posici&oacute;n del valor a ingresar
    *\pre Que la posici&oacute;n no este fuera del tama&ntilde;o de la lista
    * \exception Excepcion si la precondici&oacute;n no se cumple
    */
    void EliminarEnPos(int pos);
    /**
    * \brief Funci&oacute;n que devuelve el primer elemento de la lista doble
    *\pre que la lista  no este vac&iacute;a
    * \exception Excepcion si la precondici&oacute;n no se cumple
    *\return Tipo el valor de la primer posici&oacute;n
    */
    Tipo ObtenerPrimero() const;
    /**
   * \brief Funci&oacute;n que devuelve el ultimo elemento de la lista doble
   *\pre que la lista  no este vac&iacute;a
   * \exception Excepcion si la precondici&oacute;n no se cumple
   *\return Tipo el valor de la ultima posici&oacute;n
   */
    Tipo ObtenerUltimo() const;
    /**
   * \brief Funci&oacute;n que devuelve el elemento de una posici&oacute;n dada
   *\pre Que la posici&oacute;n no este fuera del tama&ntilde;o de la lista
   * \exception Excepcion si la precondici&oacute;n no se cumple
   *\return Tipo el valor de la ultima posici&oacute;n
   */
    Tipo ObtenerEnPos(int pos) const;
    /**
   * \brief Funci&oacute;n que devuelve la posici&oacute;n de un valor dado un criterio de busqueda
   * \param tipo valor El valor que se buscara
   * \param bool(*criterio)  el criterio de busqueda
   * \return Tipo el valor de la ultima posici*oacute;n
   */
    int BuscarPosDe(Tipo valor, bool(*criterio)  (Tipo,Tipo) = Igual) const;

    /**
   * \brief Funci&oacute;n que devuelve un booleano que indica si un valor esta o no en la lista
   * \param tipo valor El valor que se buscara
   * \return true si esta, false s&iacute; no
   */
    bool Buscar(Tipo valorB) const ;
    /**
       * \brief Funci&oacute;n que vacia la lista doble eliminando todos sus datos
       */
    void Vaciar();
    /**
     * \brief Funci&oacute;n que ve si una lista doble esta vacia
     * \return true si esta vacia, false si no lo esta
     */
    bool EstaVacia () const ;
    /**
     * \brief Funci&oacute;n que devuelve el tama&ntilde;o actual de la lista doble
     * \return el tama&ntilde;o de la lista doble
     */

    int ObtenerTamanio() const;

    /**
     * \brief Funci&oacute;n que imprime una lista doble de manera ascendente
     */

    void ImprimirAscendente()const;
    /**
     * \brief Funci&oacute;n que imprime una lista doble de manera inversa
     */

    void ImprimirInversa()const;

private:

    struct Elemento{
        explicit Elemento(Tipo _valor, Elemento* _siguiente = NULL,Elemento *_anterior =  NULL) :
                valor(_valor), siguiente(_siguiente),anterior(_anterior) {};

        Tipo valor;
        Elemento * siguiente;
        Elemento * anterior;
    };

    int numElementos;
    Elemento *Primero;
    Elemento *Ultimo;

};

template<typename Tipo>
ListaDoble<Tipo>::ListaDoble ()  :  numElementos(0) , Primero (NULL), Ultimo(NULL){ }

template<typename Tipo>
ListaDoble<Tipo>::ListaDoble (const ListaDoble<Tipo> &c) : numElementos(0) , Primero (NULL), Ultimo(NULL) {
    *this = c;
}


template<typename Tipo>
ListaDoble<Tipo>::~ListaDoble () {
    Vaciar();
}

template<typename Tipo>
ListaDoble<Tipo> &ListaDoble<Tipo>::operator=(const ListaDoble<Tipo> &c){

    if(this == &c) return *this;

    Vaciar();

    Elemento *aux = c.Primero;

    while(aux != NULL ){
        AgregarFinal(aux->valor);
        aux = aux->siguiente;
    }

    return *this;

}
template<typename Tipo>
void ListaDoble<Tipo>::ListaDoble::AgregarPrincipio (Tipo valor) {

    Elemento *nuevo = new Elemento(valor,Primero);

    EstaVacia()?Ultimo = nuevo:Primero->anterior= nuevo;
    Primero=nuevo;
    ++numElementos;


}

template<typename Tipo>
void ListaDoble<Tipo>::ListaDoble::AgregarFinal (Tipo valor) {

    Elemento *nuevo = new Elemento(valor,NULL,Ultimo);

    EstaVacia() ? Primero = nuevo:Ultimo->siguiente= nuevo;
    Ultimo=nuevo;
    ++numElementos;


}

template<typename Tipo>
void ListaDoble<Tipo>::ListaDoble::AgregarEnPos (Tipo valor,int pos) {

    Elemento *aux = Primero;

    for ( int i = 0 ;i < pos ; ++i ) {
        if ( aux != NULL ) {
            aux = aux->siguiente;
        } else {
            break;
        }
    }

    if ( aux == Primero ) AgregarPrincipio (valor);

    else if ( aux == NULL ) AgregarFinal (valor);

    else {
        Elemento *nuevo = new Elemento (valor , aux , aux->anterior);
        aux->anterior->siguiente = nuevo;
        aux->anterior = nuevo;
        ++numElementos;
    }

}

template<typename Tipo>
void ListaDoble<Tipo>::EliminarPrincipio () {
    if(EstaVacia()) throw Excepcion("No hay elementos en la lista");
    Elemento *aux = Primero;
    Primero= Primero->siguiente;

    Primero !=NULL ?Primero->anterior=NULL :Ultimo = NULL;

    delete aux;

    --numElementos;
}

template<typename Tipo>
void ListaDoble<Tipo>::EliminarFinal () {

    if(EstaVacia()) throw Excepcion("No hay elementos a eliminar.");
    Elemento * actual = Ultimo;
    Ultimo = Ultimo ->anterior;
    Ultimo != NULL ? Ultimo ->siguiente = NULL : Primero = NULL;
    delete actual;
    --numElementos;


}
template<typename Tipo>
void ListaDoble<Tipo>::EliminarEnPos ( int pos) {
    if(pos<0 || pos>= ObtenerTamanio ())throw Excepcion("posicion fuera de rango");

    Elemento *aux = Primero;
    for(int i = 0 ;i < pos;++i) aux = aux->siguiente;

    if(aux == Primero) {
        EliminarPrincipio ();
    }else if(aux== Ultimo) {
        EliminarFinal();
    }
    else{
        aux->anterior->siguiente = aux->siguiente;
        aux->siguiente->anterior=aux->anterior;
        delete aux;
        --numElementos;
    }
}



template<typename Tipo>
Tipo ListaDoble<Tipo>::ObtenerPrimero () const {
    if(EstaVacia()) throw Excepcion("No hay elementos en la lista");
    return Primero->valor;
}

template<typename Tipo>
Tipo ListaDoble<Tipo>::ObtenerUltimo () const {
    if(EstaVacia()) throw Excepcion("No hay elementos en la lista");
    return Ultimo->valor;
}
template<typename Tipo>
Tipo ListaDoble<Tipo>::ObtenerEnPos (int pos) const {
    if(pos<0 || pos>= ObtenerTamanio())throw Excepcion("posicion fuera de rango");
    Elemento *aux = Primero;
    for(int i = 0 ;i < pos;++i) aux = aux->siguiente;

    return aux->valor;
}


template<typename Tipo>
int ListaDoble<Tipo>::BuscarPosDe (Tipo valor , bool (*criterio) (Tipo , Tipo)) const {
    int posicion= 0;

    for(Elemento*aux=Primero;aux!= NULL && !criterio(aux->valor,valor);aux=aux->siguiente){
        ++posicion;
    }

    return posicion;
}



template<typename Tipo>
bool ListaDoble<Tipo>::Buscar (Tipo valorB) const{
    return BuscarPosDe(valorB) !=ObtenerTamanio();
}

template<typename Tipo>
void ListaDoble<Tipo>::Vaciar () {

    while(!EstaVacia())EliminarPrincipio();

}

template<typename Tipo>
bool ListaDoble<Tipo>::EstaVacia ()const {
    return (Primero ==NULL && Ultimo ==NULL);
}

template<typename Tipo>
int ListaDoble<Tipo>::ObtenerTamanio () const{
    return numElementos;
}



template <typename Tipo>
std::ostream &operator<<(std::ostream &salida, const ListaDoble <Tipo> &c) {

    if(c.EstaVacia ()) return salida;
    struct ListaDoble<Tipo>::Elemento * aux = c.Primero;
    //salida << "Primero -> ";

    while(aux!=  NULL){
        salida << "[" << aux -> valor << "] <=> ";
        aux = aux -> siguiente;
    }
    salida << "\b\b\b\b   \b\b\b\b";

    //salida << "[" << aux -> valor << "] , ";

    return salida << std::endl;

}

template<typename Tipo>
void ListaDoble<Tipo>::ImprimirAscendente () const{
    std::cout << *this;
}


template<typename Tipo>
void ListaDoble<Tipo>::ImprimirInversa () const{

    if(EstaVacia ())return ;
    struct ListaDoble<Tipo>::Elemento * aux = Ultimo;
    //salida << "Primero -> ";

    while(aux!=  NULL){
        std::cout << "[" << aux -> valor << "] <=> ";
        aux = aux -> anterior;
    }
    std::cout << "\b\b\b\b   \b\b\b\b";

}


#endif //EGO_LISTADOBLEORDENADA_LISTADOBLE_H
