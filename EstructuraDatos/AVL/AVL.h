//
// Created by Eduardo Gonzalez Olea on 5/17/18.
//

#ifndef AVL_AVL_H
#define AVL_AVL_H


#include <cstdlib>
#include <iostream>
#include "Cola.h"
/**
 * \brief Plantilla de clase para crear un AVl
 */
template <typename Tipo>
class AVL;

template <typename Tipo=int>
class AVL{
public:
    /**
    * \brief constructor  de la clase AVL
    */
    AVL();
    /**
     * \brief destructor  de la clase AVL
     *
     */
    ~AVL();
    /**
    * \brief constructor de copias de la clase AVL
    * \param const AVL &c una referencia constante al AVL que quieres copiar
    */
    AVL(const AVL<Tipo> &c);
    /**
    * \brief Sobrecarga del operador = para igualar dos objetos tipo AVL
    * \param const listaDoble &o una referencia constante a AVL
    * \return Una referencia a AVL
    */
    AVL<Tipo> &operator=(const AVL<Tipo> &c);
    /**
      * \brief Funci&oacute;n que agrega un elemento al AVL
      * \param tipo valor El valor que se metera al AVL
      * \exception bad_alloc, si no hay memoria disponible para agregar nuevo elemento
      * \return true si se pudo agregar el valor en el AVL, false si no
     */
    bool AgregarElemento (Tipo valor);
    /**
     * \brief Funci&oacute;n que elimina un elemento del AVL
     *  \param tipo valor El valor que se eliminara del AVL
     * \return true si se pudo eliminar el valor en el AVL, false si no
     */
    bool EliminarElemento(Tipo _valor);

    /**
     * \brief Funci&oacute;n que ve si un objeto del tipo AVL esta vacio
     * \return true si esta vacia, false si no lo esta
     */
    bool EstaVacio() const;

    /**
     * \brief Funci&oacute;n que devuelve el  n&uacute;mero de elementos en el AVL
     * \return n&uacute;mero de elementos en el AVL
     */
    int ObtenerNumElementos() const;
    /**
    * \brief Funci&oacute;n que devuelve el tama&ntilde;o del AVL
    * \return &uacute;mero de elementos en el AVL
    */
    int ObtenerTamanio()const;
    /**
     * \brief Funci&oacute;n que busca un elemento del AVL
     * \param tipo valor El valor que se buscara en el AVL
     * \return true si lo encontro, false si no
     */
    bool Buscar(Tipo valor)const;
    /**
     * \brief Funci&oacute;n que vacia un AVL
     */
    void Vaciar();
    /**
    * \brief Funci&oacute;n que imprime de manera ascendente un AVL
    */
    void ImprimirAscendente() const ;
    /**
     * \brief Funci&oacute;n que imprime de manera descendente un AVL
     */
    void ImprimirDescendente()const;
    /**
     * \brief Funci&oacute;n que imprime por niveles un AVL
     */
    void ImprimirPorNiveles()const;

private:
    int numElementos;

    struct Elemento{
        explicit Elemento(Tipo _valor, Elemento* _hijoIzq = NULL,Elemento * _hijoDer =  NULL,int _altura= 0) :
                valor(_valor), hijoIzq(_hijoIzq),hijoDer(_hijoDer),altura(_altura) {};

        Tipo valor;
        Elemento * hijoIzq ;
        Elemento * hijoDer ;
        int altura;
    };

    Elemento *raiz;
    int max(int a, int b);
    int ObtenerAltura(Elemento * raiz);


    bool AgregarElemento (Tipo _valor , Elemento *&_raiz);
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

    void RotacionDerecha(Elemento* &p);
    //Elemento * &RotacionDerecha(Elemento * p);

    void RotacionIzquierda(Elemento *& p);

    void   RotacionDobleDerecha(Elemento *& p);

    void RotacionDobleIzquierda(Elemento *& p);

    int FactorBalance(Elemento * _raiz);

};

template <typename Tipo>
AVL<Tipo>::AVL() : numElementos(0), raiz(NULL){}


template<typename Tipo>
AVL<Tipo>::AVL (const AVL<Tipo> &c) : numElementos (0),raiz(NULL) {
    *this=c;
}

template <typename Tipo>
AVL<Tipo>::~AVL()
{
    Vaciar(raiz);
}


template <typename Tipo>
bool AVL<Tipo>::AgregarElemento (Tipo valor)
{
    numElementos++;
    return AgregarElemento (valor , raiz);

}
// RR =rotacion derecha
// LL rotacionIzquierda
//  LR = Rotacion Doble a la Izquierda
// RL = Rotacion Doble a la Derech
template<typename Tipo>
bool AVL<Tipo>::AgregarElemento (Tipo _valor , AVL::Elemento *&_raiz){

    if(_raiz==NULL) {
        _raiz= new Elemento(_valor);
        return true;
    }
    if( _valor == _raiz->valor) return false;


    _valor < _raiz->valor ? AgregarElemento (_valor , _raiz->hijoIzq) : AgregarElemento (_valor , _raiz->hijoDer);



    if(FactorBalance (_raiz) == -2){
        if(FactorBalance (_raiz->hijoIzq)==1)
            RotacionDobleDerecha (_raiz);
        else
            RotacionDerecha (_raiz);

    }
    else if(FactorBalance (_raiz)==2){
        if( FactorBalance(_raiz->hijoDer)==-1)
            RotacionDobleIzquierda (_raiz);
        else
            RotacionIzquierda (_raiz);
    }
    _raiz->altura = max(ObtenerAltura (_raiz->hijoIzq), ObtenerAltura (_raiz->hijoDer))+1;

    return true;

}


template<typename Tipo>
bool AVL<Tipo>::EliminarElemento(Tipo _valor)
{

    EliminarElemento (raiz,_valor);

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
bool AVL<Tipo>::EliminarElemento (AVL::Elemento *&_raiz , Tipo _valor) {
    if(_raiz == NULL) return false;
    if(_valor == _raiz->valor){
        Elemento *aux = _raiz;
        if(_raiz->hijoIzq == NULL && _raiz->hijoDer == NULL)
            _raiz = NULL;
        else {
            if ( _raiz->hijoIzq != NULL && _raiz->hijoDer == NULL )
                _raiz = _raiz->hijoIzq;
            else
            if ( _raiz->hijoIzq == NULL && _raiz->hijoDer != NULL )
                _raiz = _raiz->hijoDer;
            else {
                Elemento *padre = BuscarPadreMayorMenores(_raiz);
                Intercambia(_raiz->valor, padre == _raiz ? _raiz->hijoIzq->valor : padre->hijoDer->valor);
                return EliminarElemento(padre == _raiz ? _raiz->hijoIzq : padre->hijoDer, _valor);
            }
        }
        delete aux;
        --numElementos;
        return true;
    }

    bool resultado = _valor < _raiz -> valor ? EliminarElemento(_raiz -> hijoIzq,_valor): EliminarElemento(_raiz -> hijoDer, _valor);

    if(resultado) {
        if ( FactorBalance (_raiz) == -2 ) {
            if ( FactorBalance (_raiz->hijoIzq) == 1 )
                RotacionDobleDerecha (_raiz);
            else
                RotacionDerecha (_raiz);

        } else if ( FactorBalance (_raiz) == 2 ) {
            if ( FactorBalance (_raiz->hijoDer) == -1 )
                RotacionDobleIzquierda (_raiz);
            else
                RotacionIzquierda (_raiz);
        }
        _raiz->altura = max(ObtenerAltura (_raiz->hijoIzq), ObtenerAltura (_raiz->hijoDer))+1;
    }

    return resultado;

}


template <typename Tipo>
bool AVL<Tipo>::EstaVacio()  const {
    return raiz==NULL;
}

//Publica
template<typename Tipo>
void AVL<Tipo>::ImprimirAscendente () const
{
    ImprimirAscendente(raiz);
    std::cout<<"\b\b  ";
}

//Inorden privada
template<typename Tipo>
void AVL<Tipo>::ImprimirAscendente (AVL::Elemento * _raiz) const
{
    if(_raiz != NULL){
        ImprimirAscendente (_raiz->hijoIzq);
        std::cout << _raiz ->valor<<", ";
        ImprimirAscendente (_raiz->hijoDer);
    }

//    std::cout<<"\b\b, ";

}

//Publica
template<typename Tipo>
void AVL<Tipo>::ImprimirDescendente () const
{
    ImprimirDescendente (raiz);
    std::cout<<"\b\b  ";
}
//Inorden inverso privada
template<typename Tipo>
void AVL<Tipo>::ImprimirDescendente (AVL::Elemento *_raiz) const
{
    if(_raiz != NULL){
        ImprimirDescendente(_raiz->hijoDer);
        std::cout << _raiz ->valor<<", ";
        ImprimirDescendente (_raiz->hijoIzq);
    }

}

template<typename Tipo>
void AVL<Tipo>::ImprimirPorNiveles() const {
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
void AVL<Tipo>::Intercambia(Tipo &a, Tipo &b)
{
    Tipo aux= a;
    a = b;
    b = aux;
}



template<typename Tipo>
AVL<Tipo> &AVL<Tipo>::operator=(const AVL<Tipo> &c){
    if(this == &c)
        return *this;

    Vaciar();

    if(c.EstaVacio())
        return *this;

    Cola<Elemento *> colaDeEspera;
    colaDeEspera.AgregarElemento(c.raiz);
    Elemento *aux;

    while(!colaDeEspera.EstaVacia()) {
        aux = colaDeEspera.EliminarElemento();
        AgregarElemento (aux->valor);
        if ( aux->hijoIzq != NULL )
            colaDeEspera.AgregarElemento(aux->hijoIzq);
        if ( aux->hijoDer != NULL )
            colaDeEspera.AgregarElemento(aux->hijoDer);
    }
    return *this;
}

template<typename Tipo>
int AVL<Tipo>::ObtenerNumElementos() const
{
    return numElementos;
}

template<typename Tipo>
void AVL<Tipo>::Vaciar ()
{
    Vaciar(raiz);
    numElementos=0;

}

template<typename Tipo>
void AVL<Tipo>::Vaciar (AVL::Elemento *& _raiz)
{
    if (_raiz != NULL){
        Vaciar (_raiz->hijoIzq);
        Vaciar(_raiz->hijoDer);
        delete  _raiz;
        _raiz=NULL;

    }


}

template<typename Tipo>
int AVL<Tipo>::ObtenerTamanio () const
{
    return numElementos;
}

template<typename Tipo>
bool AVL<Tipo>::Buscar (Tipo valor) const
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
struct AVL<Tipo>::Elemento* AVL<Tipo>::BuscarMayor (Elemento *_raiz) {
    while(_raiz -> hijoDer != NULL){
        _raiz = _raiz->hijoDer;
    }
    return _raiz;
}

template<typename Tipo>
struct AVL<Tipo>::Elemento *AVL<Tipo>::BuscarPadreMayorMenores (Elemento * _raiz) {
    if(_raiz->hijoIzq->hijoDer  == NULL)return _raiz;

    _raiz = _raiz->hijoIzq;
    while ( _raiz->hijoDer != NULL ) {
        _raiz = _raiz->hijoDer;
    }
    return _raiz;

}

template<typename Tipo>
int AVL<Tipo>::ObtenerAltura (Elemento * _raiz) {
    return (_raiz==NULL)? -1:_raiz->altura;
}

template<typename Tipo>
int AVL<Tipo>::max (int a , int b) {
    return a > b ? a : b;
}



template<typename Tipo>
void AVL<Tipo>::RotacionDerecha (AVL::Elemento *&p) {
    Elemento * q = p->hijoIzq;
    p->hijoIzq = q->hijoDer;
    q->hijoDer=p;
    p=q;
    p->hijoDer->altura= max(ObtenerAltura (p->hijoDer->hijoIzq), ObtenerAltura (p->hijoDer->hijoDer)) + 1;


}

template<typename Tipo>
void AVL<Tipo>::RotacionIzquierda (AVL::Elemento *&p) {
    Elemento * q = p -> hijoDer;
    p->hijoDer = q->hijoIzq;
    q -> hijoIzq = p;
    p=q;
    p->hijoIzq->altura= max(ObtenerAltura (p->hijoIzq->hijoIzq), ObtenerAltura (p->hijoIzq->hijoDer)) + 1;

}



template<typename Tipo>
void AVL<Tipo>::RotacionDobleDerecha (AVL::Elemento *&p) {
    RotacionIzquierda(p->hijoIzq);
    RotacionDerecha (p);
}

template<typename Tipo>
void AVL<Tipo>::RotacionDobleIzquierda (AVL::Elemento *&p) {
    RotacionDerecha (p->hijoDer);
    RotacionIzquierda (p);
}

template<typename Tipo>
int AVL<Tipo>::FactorBalance (AVL::Elemento *_raiz) {

    if(_raiz == NULL) return 0;


    return ObtenerAltura (_raiz->hijoDer ) - ObtenerAltura (_raiz->hijoIzq);
}


#endif //AVL_AVL_H
