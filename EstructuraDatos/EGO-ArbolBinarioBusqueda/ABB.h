//
// Created by Eduardo Gonzalez Olea on 4/30/18.
//

#ifndef EGO_ARBOLBINARIOBUSQUEDA_ARBOLBINARIOBUSQUEDA_H
#define EGO_ARBOLBINARIOBUSQUEDA_ARBOLBINARIOBUSQUEDA_H

#include <cstdlib>
#include <iostream>
#include "Cola.h"
#include "Excepciones.h"

/**
 * \brief Plantilla de clase para crear un Arbol Binario de Busqueda (ABB)
 */
template <typename Tipo>
class ABB;


template <typename Tipo=int>
class ABB{
public:
    /**
    * \brief constructor  de la clase ABB
    */
    ABB();
    /**
     * \brief destructor  de la clase ABB
     *
     */
    ~ABB();
    /**
    * \brief constructor de copias de la clase ABB
    * \param const ABB &c una referencia constante al ABB que quieres copiar
    */
    ABB(const ABB<Tipo> &c);
    /**
    * \brief Sobrecarga del operador = para igualar dos objetos tipo ABB
    * \param const listaDoble &o una referencia constante a ABB
    * \return Una referencia a ABB
    */
    ABB<Tipo> &operator=(const ABB<Tipo> &c);
    /**
      * \brief Funci&oacute;n que agrega un elemento al ABB
      * \param tipo valor El valor que se metera al ABB
      * \exception bad_alloc, si no hay memoria disponible para agregar nuevo elemento
      * \return true si se pudo agregar el valor en el ABB, false si no
      */
    bool Agregar(Tipo valor);
    /**
     * \brief Funci&oacute;n que elimina un elemento del ABB
     *  \param tipo valor El valor que se eliminara del ABB
     * \return true si se pudo eliminar el valor en el ABB, false si no
     */
    bool EliminarElemento(Tipo _valor);
    /**
     * \brief Funci&oacute;n que ve si un objeto del tipo ABB esta vacio
     * \return true si esta vacia, false si no lo esta
     */
    bool EstaVacio() const;
    /**
     * \brief Funci&oacute;n que devuelve el  n&uacute;mero de elementos en el ABB
     * \return &uacute;mero de elementos en el ABB
     */
    int ObtenerNumElementos() const;
    /**
     * \brief Funci&oacute;n que devuelve el tama&ntilde;o del ABB
     * \return &uacute;mero de elementos en el ABB
     */
    int ObtenerTamanio()const;
    /**
     * \brief Funci&oacute;n que busca un elemento del ABB
     *  \param tipo valor El valor que se buscara en el ABB
     * \return true si lo encontro, false si no
     */
    bool Buscar(Tipo valor)const;
    /**
     * \brief Funci&oacute;n que vacia un ABB
     */
    void Vaciar();
    /**
     * \brief Funci&oacute;n que imprime de manera ascendente un ABB
     */
    void ImprimirAscendente() const ;
    /**
     * \brief Funci&oacute;n que imprime de manera descendente un ABB
     */
    void ImprimirDescendente()const;
    /**
     * \brief Funci&oacute;n que imprime por niveles un ABB
     */
    void ImprimirPorNiveles()const;

private:
    int numElementos;

    struct Elemento{
        explicit Elemento(Tipo _valor, Elemento* _hijoIzq = NULL,Elemento * _hijoDer =  NULL) :
                valor(_valor), hijoIzq(_hijoIzq),hijoDer(_hijoDer) {};

        Tipo valor;
        Elemento * hijoIzq ;
        Elemento * hijoDer ;

    };

    Elemento *raiz;

    bool Agregar(Tipo _valor , Elemento *& _raiz);
    //Inorden
    void ImprimirAscendente(Elemento * _raiz) const ;
     void Intercambia(Tipo &a, Tipo &b);
    // Inorden inverso
    void ImprimirDescendente(Elemento * _raiz)const;
    //Recorrido por niveles iterativos

    //void ImprimirPorNiveles() const;
    void Vaciar( Elemento *& _raiz);

    Elemento* BuscarMayor(Elemento* _raiz);

    bool EliminarElemento(Elemento *& _raiz, Tipo _valor);

    Elemento * BuscarPadreMayorMenores(Elemento * _raiz);
};

template <typename Tipo>
ABB<Tipo>::ABB() : numElementos(0), raiz(NULL){}


template<typename Tipo>
ABB<Tipo>::ABB (const ABB<Tipo> &c) : numElementos (),raiz(NULL) {
    *this=c;
}

template <typename Tipo>
ABB<Tipo>::~ABB()
{
    Vaciar(raiz);
}


template <typename Tipo>
bool ABB<Tipo>::Agregar(Tipo valor)
{
    numElementos++;
    return Agregar(valor,raiz);

}

template<typename Tipo>
bool ABB<Tipo>::Agregar (Tipo _valor , ABB::Elemento *& _raiz){

    if(_raiz==NULL) {
        _raiz= new Elemento(_valor);
        return true;
    }
    if( _valor == _raiz->valor) return false;


     return _valor < _raiz->valor ? Agregar(_valor,_raiz->hijoIzq) : Agregar(_valor,_raiz->hijoDer);


}


template<typename Tipo>
bool ABB<Tipo>::EliminarElemento(Tipo _valor)
{

    return EliminarElemento (raiz,_valor);
    //Iterativo
    /*
    Elemento *aux=raiz,*padre = NULL;

    while(aux!=NULL && aux -> valor != _valor){
        padre=aux;
        aux= _valor < aux -> valor ? aux -> hijoIzq : aux -> hijoDer;
    }

    if(aux == NULL ) return false;

    if(aux->hijoIzq==NULL && aux -> hijoDer == NULL)
        padre ==NULL ? raiz=NULL: padre -> hijoIzq == aux ? padre -> hijoIzq = NULL : padre -> hijoDer = NULL;


    else if (aux->hijoIzq !=NULL && aux -> hijoDer == NULL)

        padre == NULL ? raiz = aux -> hijoIzq : padre -> hijoIzq == aux ? padre -> hijoIzq = aux->hijoIzq :
                        padre -> hijoDer = aux-> hijoIzq;

    else if (aux->hijoIzq == NULL & aux -> hijoDer !=NULL)
        padre == NULL ? raiz = aux -> hijoDer : padre -> hijoIzq == aux ? padre -> hijoIzq = aux -> hijoDer :
                        padre->hijoDer = aux->hijoDer;

    else{
        Elemento * mayor= BuscarMayor(aux->hijoIzq);
        mayor -> hijoDer = aux->hijoDer;
        padre == NULL ? raiz= aux-> hijoIzq : padre->hijoIzq == aux ? padre->hijoIzq = aux -> hijoIzq :
                        padre->hijoDer =aux->hijoIzq;

    }
    delete aux;
    --numElementos;
    return true;
     */
}

//Eliminar Recursivo
template<typename Tipo>
bool ABB<Tipo>::EliminarElemento (ABB::Elemento *& _raiz , Tipo _valor) {
    if(_raiz == NULL) return false;

    if(_valor == _raiz -> valor){
        Elemento * aux = _raiz;
        if(_raiz -> hijoIzq == NULL && _raiz -> hijoDer == NULL)_raiz = NULL;
        else if(_raiz -> hijoIzq != NULL  && _raiz -> hijoDer == NULL)
            _raiz = _raiz -> hijoIzq;
        else if(_raiz -> hijoIzq == NULL && _raiz ->hijoDer !=NULL)
            _raiz = _raiz -> hijoDer;
        else{
            Elemento * padre = BuscarPadreMayorMenores(_raiz);
            Intercambia(_raiz->valor,padre == _raiz ? _raiz -> hijoIzq -> valor : padre->hijoDer->valor);
            return EliminarElemento (padre == _raiz ? _raiz ->hijoIzq : padre -> hijoDer, _valor);
        }
        delete aux;
        --numElementos;
        return true;
    }

    return _valor < _raiz -> valor ? EliminarElemento(_raiz -> hijoIzq,_valor): EliminarElemento(_raiz -> hijoDer, _valor);

}       


template <typename Tipo>
bool ABB<Tipo>::EstaVacio()  const {
    return raiz==NULL;
}

//Publica
template<typename Tipo>
void ABB<Tipo>::ImprimirAscendente () const
{
    ImprimirAscendente(raiz);
    std::cout<<"\b\b";
}

//Inorden privada
template<typename Tipo>
void ABB<Tipo>::ImprimirAscendente (ABB::Elemento * _raiz) const
{
    if(_raiz != NULL){
        ImprimirAscendente (_raiz->hijoIzq);
        std::cout << _raiz ->valor<<", ";
        ImprimirAscendente (_raiz->hijoDer);
    }

}

//Publica
template<typename Tipo>
void ABB<Tipo>::ImprimirDescendente () const
{
    ImprimirDescendente (raiz);
    std::cout<<"\b\b";

}
//Inorden inverso privada
template<typename Tipo>
void ABB<Tipo>::ImprimirDescendente (ABB::Elemento *_raiz) const
{
    if(_raiz != NULL){
        ImprimirDescendente(_raiz->hijoDer);
        std::cout << _raiz ->valor<<", ";
        ImprimirDescendente (_raiz->hijoIzq);
    }

}

template<typename Tipo>
void ABB<Tipo>::ImprimirPorNiveles() const{
    if(raiz == NULL){
        std::cout << "El arbol est\240 vac\243o" << std::endl;
        return;
    }

    Cola<Elemento *> colaDeEspera;
    colaDeEspera.AgregarElemento(raiz);
    Elemento *aux;

    while(!colaDeEspera.EstaVacia()) {
        aux = colaDeEspera.EliminarElemento();
        std::cout << aux->valor << " , ";
        if ( aux->hijoIzq != NULL )
            colaDeEspera.AgregarElemento(aux->hijoIzq);
        if ( aux->hijoDer != NULL )
            colaDeEspera.AgregarElemento(aux->hijoDer);
    }
    std::cout << "\b\b" << std::endl;
}



template <typename Tipo>
void ABB<Tipo>::Intercambia(Tipo &a, Tipo &b)
{
    Tipo aux= a;
    a = b;
    b = aux;
}



template<typename Tipo>
ABB<Tipo> &ABB<Tipo>::operator=(const ABB<Tipo> &c){
    if(this == &c)
        return *this;

    Vaciar();

    if(c.EstaVacio())
        return *this;

    Cola<Elemento *> colaDeEspera;
    colaDeEspera.AgregarElemento(c.raiz);
    Elemento *aux;

    while(!colaDeEspera.Vaciar()) {
        aux = colaDeEspera.EliminarElemento();
        Agregar(aux->valor);
        if ( aux->hijoIzq != NULL )
            colaDeEspera.AgregarElemento(aux->hijoIzq);
        if ( aux->hijoDer != NULL )
            colaDeEspera.AgregarElemento(aux->hijoDer);
    }

    return *this;
}
template<typename Tipo>
int ABB<Tipo>::ObtenerNumElementos() const
{
    return numElementos;
}

template<typename Tipo>
void ABB<Tipo>::Vaciar ()
{
    Vaciar(raiz);
    numElementos=0;

}

template<typename Tipo>
void ABB<Tipo>::Vaciar (ABB::Elemento *& _raiz)
{
    if (_raiz != NULL){
        Vaciar (_raiz->hijoIzq);
        Vaciar(_raiz->hijoDer);
        delete  _raiz;
        _raiz=NULL;

    }


}

template<typename Tipo>
int ABB<Tipo>::ObtenerTamanio () const
{
    return numElementos;
}

template<typename Tipo>
bool ABB<Tipo>::Buscar (Tipo valor) const
{
    Elemento *aux = raiz;
    while (aux!= NULL && aux->valor != valor){
        if (aux->valor > valor)aux= aux->hijoIzq;
        else aux= aux->hijoDer;
    }
    if (aux==NULL)return false;

    return true;
}


template<typename Tipo>
struct ABB<Tipo>::Elemento* ABB<Tipo>::BuscarMayor (Elemento *_raiz) {
    while(_raiz -> hijoDer != NULL){
        _raiz = _raiz->hijoDer;
    }
    return _raiz;
}

template<typename Tipo>
struct ABB<Tipo>::Elemento* ABB<Tipo>::BuscarPadreMayorMenores (Elemento * _raiz) {
    if(_raiz->hijoIzq->hijoDer  == NULL) return _raiz;

    _raiz = _raiz->hijoIzq;
    while ( _raiz->hijoDer != NULL ) {
        _raiz = _raiz->hijoDer;
    }
    return _raiz;
}


#endif //EGO_ARBOLBINARIOBUSQUEDA_ARBOLBINARIOBUSQUEDA_H



