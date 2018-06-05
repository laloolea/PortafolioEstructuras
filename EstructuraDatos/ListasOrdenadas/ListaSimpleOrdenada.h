//
// Created by Eduardo Gonzalez Olea on 3/22/18.
//

#ifndef LISTASORDENADAS_LISTASIMPLEORDENADA_H
#define LISTASORDENADAS_LISTASIMPLEORDENADA_H

#include <cstdlib>
#include <iostream>
/**
   * \brief Funci&oacute;n que verifica el menor de dos valores de tipo Tipo
   * \param Tipo a el primer valor a comparar
   * \param Tipo b el segundo valor a comparar
   * \return true si a es menor o igual que b, false si b es menor que a
   */
template <typename Tipo>  bool ascendente(Tipo a,Tipo b)
{
    return a <= b;
}
/**
   * \brief Funci&oacute;n que verifica el mayor de dos valores de tipo Tipo
   * \param Tipo a el primer valor a comparar
   * \param Tipo b el segundo valor a comparar
   * \return true si a es mayor o igual que b, false si b es mayor que a
   */
template <typename Tipo>  bool descendente(Tipo a,Tipo b)
{
    return a >= b;
}


template <typename Tipo, bool (*criterio) (Tipo,Tipo)>
class ListaSimpleOrdenada;
template <typename Tipo, bool (*criterio) (Tipo,Tipo)>
std::ostream& operator<<(std::ostream & salida, const ListaSimpleOrdenada<Tipo,criterio> &c);
/**
    Plantilla de clase ListaSimpleOrdenada.
 */
template <typename Tipo =  int , bool (*criterio) (Tipo,Tipo) = ascendente>
class ListaSimpleOrdenada {
    /** \brief  sobrecarga de operador << para imprimir un objeto tipo ListaSimpleOrdenada la cual la tienes que hacer amiga para que esta tenga acceso
       *
       * \param ostream o donde se almacenara la cadena
       * \param listaSimpleOrdenada c Lista Simple Ordenada a imprimir
       * \return devuelve una variable de tipo ostream
       *
       */
    friend std::ostream & operator<< <>(std::ostream & salida, const ListaSimpleOrdenada<Tipo,criterio> &c);

public:

    /**
     * \brief constructor  de la clase ListaSimpleOrdenada
     *
     *
     */
    ListaSimpleOrdenada();
    /**
       * \brief constructor de copias de la clase ListaSimpleOrdenada
       * \param const ListaSimpleOrdenada &c una referencia constante a la lista simple ordenada a la que quieres copiar
       */
    ListaSimpleOrdenada(const ListaSimpleOrdenada<Tipo,criterio> &c);
    /**
    * \brief destructor  de la clase ListaSimpleOrdenada
    *
    */
    ~ListaSimpleOrdenada ();

/**
      * \brief Funci&oacute;n que agrega un elemento a una lista simple ordenada
      * \param tipo valor El valor que se metera a la lista simple ordenada
      * \exception bad_alloc, si no hay memoria disponible para agregar nuevo elemento
      */
    void AgregarElemento(Tipo valor);
    /**
    * \brief Funci&oacute;n que elimina un elemento de una lista simple ordenada
    * \param  Tipo valor el valor a eliminar en la lista ordenada simple
     * return true si se pudo eliminar el valor en la lista ordenada simple
    */
    bool EliminarElemento(Tipo valor);

/**
    * \brief Funci&oacute;n que busca un elemento de una lista simple ordenada
    * \param  Tipo valor el valor a buscar en la lista ordenada simple
     * return true si se encontro el valor en la lista ordenada simple
    */
    bool Buscar(Tipo valorB);
    /**
    * \brief Funci&oacute;n que vacia la lista simple ordenada eliminando todos sus datos
    */
    void Vaciar();
    /**
   * \brief Funci&oacute;n que ve si una lista simple ordenada esta vacia
    * \return true si esta vacia, false si no lo esta
   */
    bool Vacia();
    /**
     * \brief Funci&oacute;n que devuelve el tama&ntilde;o actual de la lista simple ordenada
     * \return el tama&ntilde;o de la lista simple ordenada
     */

    int ObtenerTamanio();

    /**
    * \brief Sobrecarga del operador = para igualar dos listas simples ordenadas
    * \param const Cola &o una referencia constante a ListaSimpleOrdenada
    * \return Una referencia a listaSimpleOrdenada
    */

    ListaSimpleOrdenada<Tipo,criterio> &operator=(const ListaSimpleOrdenada<Tipo,criterio> &c);


private:

    struct Elemento{
        explicit Elemento(Tipo _valor, Elemento* _siguiente = NULL) : valor(_valor), siguiente(_siguiente){};

        Tipo valor;
        Elemento * siguiente;
    };

    int numElementos;
    Elemento *Primero;

};


template <typename Tipo, bool (*criterio) (Tipo,Tipo)>
ListaSimpleOrdenada<Tipo,criterio>::ListaSimpleOrdenada() :  numElementos(0) , Primero (NULL){

}
template <typename Tipo, bool (*criterio) (Tipo,Tipo)>
ListaSimpleOrdenada<Tipo,criterio>::ListaSimpleOrdenada (const ListaSimpleOrdenada &c): numElementos(0) , Primero (NULL) {
    *this = c;
}

template <typename Tipo, bool (*criterio) (Tipo,Tipo)>
ListaSimpleOrdenada<Tipo,criterio>::~ListaSimpleOrdenada () {
    Vaciar();
}



template <typename Tipo, bool (*criterio) (Tipo,Tipo)>
void ListaSimpleOrdenada<Tipo,criterio>::AgregarElemento (Tipo valor) {

    Elemento *aux = Primero, *ant = NULL;

    while(aux != NULL &&  criterio(aux -> valor, valor)){
        ant = aux;
        aux = aux ->siguiente;

    }
    Elemento * nuevo = new Elemento (valor,aux) ;
    ant == NULL ? Primero = nuevo : ant->siguiente =nuevo;

    ++numElementos;

}

template <typename Tipo, bool (*criterio) (Tipo,Tipo)>
bool ListaSimpleOrdenada<Tipo,criterio>::EliminarElemento (Tipo valor) {
    Elemento *aux = Primero, *ant = NULL;

    while(aux != NULL &&  aux ->valor != valor){
        ant = aux;
        aux = aux ->siguiente;

    }
    if(aux == NULL)return false;

    ant == NULL ? Primero = aux->siguiente: ant->siguiente = aux->siguiente;
    delete aux;

    --numElementos;
    return true;
}

template <typename Tipo, bool (*criterio) (Tipo,Tipo)>
ListaSimpleOrdenada<Tipo,criterio> &ListaSimpleOrdenada<Tipo,criterio>::operator=(const ListaSimpleOrdenada<Tipo,criterio> &c)
{

    if(this == &c) return *this;

    Vaciar();


    Elemento *aux = c.Primero;

    while(aux != NULL ){
        AgregarElemento (aux->valor);
        aux = aux->siguiente;
    }



    return *this;
}



template <typename Tipo, bool (*criterio) (Tipo,Tipo)>
void ListaSimpleOrdenada<Tipo,criterio>::Vaciar () {

    Elemento *aux;
    while(!Vacia()){
        aux= Primero;
        Primero = Primero->siguiente;
        delete aux;
    }
    numElementos = 0;
}

template <typename Tipo, bool (*criterio) (Tipo,Tipo)>
bool ListaSimpleOrdenada<Tipo,criterio>::Vacia () {
    return Primero==NULL;
}
template <typename Tipo, bool (*criterio) (Tipo,Tipo)>
std::ostream &operator<<(std::ostream &salida, const ListaSimpleOrdenada <Tipo,criterio> &c) {

    if(c.Primero == NULL){
        salida << "La cola esta vacia";
        return salida;
    }
    struct ListaSimpleOrdenada<Tipo,criterio>::Elemento * aux = c.Primero;
    salida << "Primero -> ";

    while(aux!=  NULL){
        salida << "[" << aux -> valor << "] , ";
        aux = aux -> siguiente;
    }
    salida << "\b\b ";

    //salida << "[" << aux -> valor << "] , ";

    return salida << std::endl;

}

template <typename Tipo, bool (*criterio) (Tipo,Tipo)>
int ListaSimpleOrdenada<Tipo,criterio>::ObtenerTamanio () {
    return numElementos;
}

template <typename Tipo, bool (*criterio) (Tipo,Tipo)>
bool ListaSimpleOrdenada<Tipo,criterio>::Buscar (Tipo valorB) {
    Elemento *aux = Primero;

    if(aux==NULL)return false;
    while(aux != NULL ){
        if(aux->valor==valorB)return true;
        aux = aux->siguiente;
    }
    return false;
}


#endif //LISTASORDENADAS_LISTASIMPLEORDENADA_H
