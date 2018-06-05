//
// Created by Eduardo Gonzalez Olea on 2/21/18.
//

#ifndef LISTAS_PILA_H
#define LISTAS_PILA_H

#include "Elemento.h"
#include <iostream>
#include "Excepcion.h"

/** \brief  sobrecarga de operador << para imprimir un objeto tipo Pila la cual la tienes que hacer amiga para que esta tenga acceso
   *
   * \param ostream o donde se almacenara la cadena
   * \param Pila v arreglo a imprimir
   * \return devuelve una variable de tipo ostream
   *
   */
template <typename tipo>
std::ostream & operator<< (std::ostream & o, const Pila <tipo> &v);

template <typename tipo>
class Pila {
    friend std::ostream & operator<< <>(std::ostream & o, const Pila <tipo> &v);

public:
    //Metodos indispensables
    /**
     * \brief constructor  de la clase Pila
     *
     */
    Pila();
    /**
    * \brief destructor  de la clase Pila
    *
    */
    ~Pila();
    /**
        * \brief constructor de copias de la clase Pila
        * \param const Pila &pila una referencia constante a la pila a la que quieres copiar
        */
    Pila(const Pila &p);
    /**
    * \brief Sobrecarga del operador = para igualar dos pilas
    * \param const Pila &pila una referencia constante a pila
    * \return Una referencia a pila
    */

    Pila &operator=(const  Pila &p);

    //Métodos de operaciones
    /**
   * \brief Funci&oacute;n que agrega un elemento al tope de una pila
   * \param tipo valor El valor que se metera al tope de la pila
   * \exception bad_alloc, si no hay memoria disponible para agregar nuevo elemento
   */
    void AgregarElemento(tipo valor);//push
    /**
    * \brief Funci&oacute;n que devuelve el elemento al tope de una pila
    * \pre Que la pila no este vacia
    * \exception Excepcion si no se cumple la precondici&oacute;n
    */
    tipo ObtenerTope();
    /**
    * \brief Funci&oacute;n que elimina un elemento el del tope de la pila
    * \pre Que la pila no este vacia
    * \exception  Excepcion si no se cumple la precondici&oacute;n
    */

    tipo EliminarElemento();
    /**
    * \brief Funci&oacute;n que devuelve el tama&ntilde;o actual de la pila
    * \return el tama&ntilde;o de la pila
    */

    int ObtenerTamanio();
    /**
    * \brief Funci&oacute;n que vacia la pila asignandole a tope -1
    */
    void Vaciar();
    /**
    * \brief Funci&oacute;n que ve si una Pila esta vacia
     * \return true si esta vacia, false si no lo esta
    */
    // Métodos para conocer el estado
    bool EstaVacia();



private:
    int numElementos;
    Elemento<tipo> *tope;
};

template <typename  tipo>
Pila<tipo>::Pila() : numElementos(0),tope(NULL) {

}
template<typename tipo>
Pila<tipo>::~Pila () {
    Vaciar();
}

template <typename  tipo>
Pila<tipo>::Pila (const Pila &p) : numElementos(0),tope(NULL) {
    *this=p;
}

template <typename  tipo>
Pila<tipo> & Pila<tipo>::operator=(const Pila &p){

//Este if evita la autoasignacion
    if (this != &p){

        Vaciar();

        numElementos = p.numElementos;

        Elemento<tipo> * direcciones[numElementos];

        // direcciones[0] = p.tope;

        Elemento<tipo> * aux = p.tope;

        for(int i = 0; aux !=NULL; aux = aux-> siguiente){

            direcciones[i++] = aux;
        }//Fin for

        for (int i = numElementos - 1; i >= 0; --i){

            AgregarElemento(direcciones[i]->valor);

        }//Fin for


    }//Fin if

    return *this;
}

//metodos de operaciones
template <typename  tipo>
void Pila<tipo>::AgregarElemento (tipo valor)
{

    Elemento<tipo> * aux= new Elemento<tipo> (valor,tope);
    tope = aux;

    ++numElementos;

}
template <typename  tipo>
tipo Pila<tipo>::ObtenerTope () {
    if(EstaVacia ()) throw Excepcion("Pila vacia");
    return tope -> valor;
}
template <typename  tipo>
tipo Pila<tipo>::EliminarElemento ()
{
    if(EstaVacia ())throw Excepcion("Esta vacia no puedes elimnar");

    Elemento<tipo> * aux = tope;

    tope = tope -> siguiente;//tope =  aux -> siguiente; la misma

    int valor =  aux -> valor;

    delete aux;

    --numElementos;
    return valor;
}

template <typename  tipo>
int Pila<tipo>::ObtenerTamanio () {
    return numElementos;
}
template <typename  tipo>
void Pila<tipo>::Vaciar ()
{
    while(!EstaVacia ()){
        EliminarElemento ();
    };
}
//metodos para conocer el estado
template <typename  tipo>
bool Pila<tipo>::EstaVacia ()
{
    return tope==NULL;
}
//amigos de clase
template <typename  tipo>
std::ostream &operator<< (std::ostream &o , const Pila <tipo> &pila)
{

    o << "tope -> ";
    //Elemento * aux = pila.tope;
/*
    while(aux != NULL){
        o << "["<< aux -> valor << "]";
        aux = aux -> siguiente;
    };
    return o;
    */
    //Cualquiera de los dos es correcto pero primero es mas consistente


    for(Elemento<tipo> * aux = pila.tope; aux !=NULL ; aux = aux -> siguiente ){
        o << "["<< aux -> valor << "]";
    }
    return o;



}



#endif //LISTAS_PILA_H
