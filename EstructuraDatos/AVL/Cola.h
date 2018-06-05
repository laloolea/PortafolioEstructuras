//
// Created by Eduardo Gonzalez Olea on 5/17/18.
//

#ifndef AVL_COLA_H
#define AVL_COLA_H
//
// Created by Eduardo Gonzalez Olea on 3/12/18.
//


#include <iostream>
#include "Excepciones.h"
/**
   * \brief Plantilla de clase Cola
   *
   */
template <typename Tipo>
class Cola;


template <typename Tipo>
std::ostream& operator<<(std::ostream & salida, const Cola<Tipo>& c);

template <typename Tipo>
class Cola{
    /** \brief  sobrecarga de operador << para imprimir un objeto tipo Cola la cual la tienes que hacer amiga para que esta tenga acceso
   *
   * \param ostream o donde se almacenara la cadena
   * \param Cola v Cola a imprimir
   * \return devuelve una variable de tipo ostream
   *
   */
    friend std::ostream & operator<< <>(std::ostream & salida, const Cola<Tipo> &c);

public:
    /**
     * \brief constructor  de la clase Cola
     *
     */

    Cola();
    /**
    * \brief destructor  de la clase Cola
    *
    */
    ~Cola();
    /**
       * \brief constructor de copias de la clase Cola
       * \param const Cola &c una referencia constante a la cola a la que quieres copiar
       */
    Cola(const Cola& c);
    /**
    * \brief Sobrecarga del operador = para igualar dos colas
    * \param const Cola &o una referencia constante a cola
    * \return Una referencia a cola
    */

    Cola &operator =(const Cola &p);
    /**
      * \brief Funci&oacute;n que agrega un elemento al tope de una cola
      * \param tipo valor El valor que se metera al tope de la cola
      * \exception bad_alloc, si no hay memoria disponible para agregar nuevo elemento
      */
    void AgregarElemento(Tipo valor);
    /**
    * \brief Funci&oacute;n que elimina un elemento el del tope de la cola
    * \pre Que la cola no este vacia
    * \exception  Excepcion si no se cumple la precondici&oacute;n
    */
    Tipo EliminarElemento();
    /**
    * \brief Funci&oacute;n que vacia la cola eliminando todos sus datos
    */
    void Vaciar();
    /**
   * \brief Funci&oacute;n que ve si una Cola esta vacia
    * \return true si esta vacia, false si no lo esta
   */
    bool EstaVacia();
    /**
      * \brief Funci&oacute;n que devuelve el elemento al tope de una cola
      * \pre Que la Cola no este vacia
      * \exception Excepcion si no se cumple la precondici&oacute;n
      */
    Tipo ObtenerTope();
    /**
     * \brief Funci&oacute;n que devuelve el tama&ntilde;o actual de la cola
     * \return el tama&ntilde;o de la cola
     */

    int ObtenerTamanio();

private:
    /**
       * \brief Estructura Elemento para simular una lista
       *
       */
    struct Elemento{
        explicit Elemento(Tipo _valor, Elemento* _siguiente = NULL) : valor(_valor), siguiente(_siguiente){};

        Tipo valor;
        Elemento * siguiente;
    };

    int numElementos;
    Elemento *Primero;
    Elemento *Ultimo;
};

template<typename Tipo>
Cola<Tipo>::Cola() : numElementos(0), Primero(NULL), Ultimo(NULL){

}

template<typename Tipo>
Cola<Tipo>::~Cola() {
    Vaciar();
}

template<typename Tipo>
Cola<Tipo>::Cola(const Cola &c) : numElementos(0), Primero(NULL), Ultimo(NULL) {
    *this = c;
}

template<typename Tipo>
void Cola<Tipo>::AgregarElemento(Tipo valor) {
    Elemento * nuevo = new Elemento(valor);

    if(EstaVacia()){
        Primero = nuevo;
        Ultimo = nuevo;
    }else{
        Ultimo -> siguiente = nuevo;
        Ultimo = nuevo;
    }
    numElementos++;
}

template<typename Tipo>
Tipo Cola<Tipo>::EliminarElemento() {
    if(EstaVacia()){
        throw Excepcion("No se puede eliminar elemento, ya que la cola se encuentra vacia");
    }

    Elemento * aux = Primero;
    Primero = Primero->siguiente;

    Tipo valor = aux -> valor;
    delete aux;
    numElementos--;

    if(numElementos == 0)
        Ultimo = NULL;

    return valor;
}

template<typename Tipo>
bool Cola<Tipo>::EstaVacia(){
    return numElementos == 0;
}

template<typename Tipo>
void Cola<Tipo>::Vaciar() {
    while(!EstaVacia()){
        EliminarElemento();
    }
}

template<typename Tipo>
Cola<Tipo> &Cola<Tipo>::operator=(const Cola &c) {
    if(this == &c) return *this;

    Vaciar();

    for(Elemento *aux = c.Primero; numElementos <= c.numElementos; aux = aux -> siguiente){
        AgregarElemento(aux -> valor);
        if(aux -> siguiente == NULL)
            break;
    }

    return *this;
}

template<typename Tipo>
std::ostream &operator<<(std::ostream &salida, const Cola <Tipo> &c) {
    if(c.Primero == NULL || c.Ultimo == NULL){
        salida << "La cola esta vacia";
        return salida;
    }

    struct Cola<Tipo>::Elemento * auxiliar = c.Primero; //Se pone el especificador struct para indicarle al preporcesador que elemento es una estructura, dentro de la clase cola

    salida << "Primero -> ";
    while(auxiliar != NULL){
        salida << "[" << auxiliar -> valor << "] , ";
        auxiliar = auxiliar -> siguiente;
    }
    salida << "\b\b<- ultimo.";

    return salida << std::endl;
}

template<typename Tipo>
Tipo Cola<Tipo>::ObtenerTope () {
    return Primero ->siguiente;
}

template<typename Tipo>
int Cola<Tipo>::ObtenerTamanio () {
    return numElementos;
}



#endif //AVL_COLA_H
