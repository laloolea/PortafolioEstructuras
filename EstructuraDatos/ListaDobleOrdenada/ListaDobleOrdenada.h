//
// Created by Eduardo Gonzalez Olea on 4/5/18.
//
#ifndef LISTADOBLEORDENADA_LISTADOBLEORDENADA_H
#define LISTADOBLEORDENADA_LISTADOBLEORDENADA_H

#include <cstdlib>
#include <iostream>
/*
template <typename Tipo> bool Igual(Tipo a,Tipo b) {return a==b;}
template <typename Tipo> bool Menor(Tipo a,Tipo b) {return a<b;}
template <typename Tipo> bool Mayor(Tipo a,Tipo b) {return a>b;}
template <typename Tipo> bool MenorIgual(Tipo a,Tipo b) {return a<=b;}
template <typename Tipo> bool MayorIgual(Tipo a,Tipo b) {return a>=b;}
template <typename Tipo> bool Diferente(Tipo a,Tipo b) {return a!=b;}
*/
template <typename Tipo>
class ListaDobleOrdenada;
template <typename Tipo>
std::ostream& operator<<(std::ostream & salida, const ListaDobleOrdenada<Tipo> &c);

template <typename Tipo =int>
class ListaDobleOrdenada {

    friend std::ostream & operator<< <>(std::ostream & salida, const ListaDobleOrdenada<Tipo> &c);
public:

    ListaDobleOrdenada();

    ListaDobleOrdenada(const ListaDobleOrdenada<Tipo> &c);

    ~ListaDobleOrdenada();

    /*
    //Agregar elementos
    void AgregarPrincipio(Tipo _valor);
    void AgregarFinal (Tipo _valor);
    void AgregarEnPos(Tipo _valor, int pos);

    // Eliminar elemento
    void EliminarPrincipio(Tipo _valor);
    void EliminarFinal (Tipo _valor);
    void EliminarEnPos(Tipo _valor, int pos);

    Tipo ObtenerPrimero() const;

    Tipo ObtenerUltimo() const;
    Tipo ObtenerEnPos(int pos) const;

    int BuscarPosDe(Tipo _valor, bool(*criterio)  (Tipo,Tipo) = Igual)const;

*/


    void AgregarElemento(Tipo valor);

    bool EliminarElemento(Tipo valor);

    bool Buscar(Tipo valorB) const ;

    void Vaciar();

    bool EstaVacia () const ;

    int ObtenerTamanio() const;

    ListaDobleOrdenada<Tipo> &operator=(const ListaDobleOrdenada<Tipo> &c);

    void ImprimirAscendente()const;

    void ImprimirDescendente()const;

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


//Igual
<template<typename Tipo>
ListaDobleOrdenada<Tipo>::ListaDobleOrdenada ()  :  numElementos(0) , Primero (NULL), Ultimo(NULL){ }

//Igual
template<typename Tipo>
ListaDobleOrdenada<Tipo>::ListaDobleOrdenada (const ListaDobleOrdenada<Tipo> &c) : numElementos(0) , Primero (NULL), Ultimo(NULL) {
    *this = c;
}

//Igual
template<typename Tipo>
ListaDobleOrdenada<Tipo>::~ListaDobleOrdenada () {
    Vaciar();
}

template<typename Tipo>
ListaDobleOrdenada<Tipo> &ListaDobleOrdenada<Tipo>::operator=(const ListaDobleOrdenada<Tipo> &c){

    if(this == &c) return *this;

    Vaciar();

    Elemento *aux = c.Primero;

    while(aux != NULL ){
        //AgregaAlFinal... en lista doble enlazada no ordenada
        //AgregarFinal(actual->valor;
        AgregarElemento (aux->valor);
        aux = aux->siguiente;
    }

    return *this;
}/*
template<typename Tipo>
void ListaDobleOrdenada<Tipo>::ListaDobleOrdenada::AgregarPrincipio (Tipo valor) {

    //Elemento *nuevo = new Elemento(_valor,primero);

    //EstaVacia()?Ultimo = nuevo:Primero->ant= nuevo;
    //primero=nuevo;
    //++numElementos


}
*/

/*
template<typename Tipo>
void ListaDobleOrdenada<Tipo>::ListaDobleOrdenada::AgregarFinal (Tipo valor) {

    //Elemento *nuevo = new Elemento(_valor,NULL,ultimo);

    //EstaVacia()?primero = nuevo:ultimo->sig= nuevo;
    //ultimo=nuevo;
    //++numElementos


}
*/
/*
template<typename Tipo>
void ListaDobleOrdenada<Tipo>::ListaDobleOrdenada::AgregarEnPos (Tipo valor,int pos) {

    //Elemento *aux =primero;

    for(int i = 0 i < pos;++i){
    if(actual!=NULL)aux =aux->sig;
    }else break;

    if(actual==Primrero)AgregarPrincipio(_valor);

    else if(aux==NULL)AgregarFinal(_valor);

    else{
        Elemento *nuevo = new Elemento(_valor,aux,aux->ant);
        aux->ant->sig = nuevo ;
        aux->ant = nuevo;
        ++numElementos;
    {


}
*/

/*
 template<typename Tipo>
bool ListaDobleOrdenada<Tipo>::EliminarPrincipio () {

    if(EstaVacia()) throw Excepcion("No hay elementos en la lista")
    Elemento *aux = Primero;
    primero= primero->siguiente;

    primero !=NULL ?primero->ant=NULL :Ultimo = NULL;

    delete aux;

    --numElementos;
}
 */
/*
 template<typename Tipo>
bool ListaDobleOrdenada<Tipo>::EliminarFinal (Tipo valor) {

     Elemento *aux = Primero;
    while ( aux != NULL && aux->valor != valor) aux = aux->siguiente;


    if ( aux == NULL )return false;
    aux != Primero ? aux->anterior->siguiente = aux->siguiente : Primero = aux->siguiente;
    aux != Ultimo ? aux->siguiente->anterior = aux->anterior : Ultimo = aux->anterior;

    delete aux;
    --numElementos;

    return true;

}
 */
/*
 template<typename Tipo>
bool ListaDobleOrdenada<Tipo>::EliminarEnPos (int Pos) {

    //if(pos<0 || pos>= tamanio())throw Excepcion("posicion fuera de rango");

    Elemento *aux = Primero;
    for(int i = 0 i < pos;++i) aux = aux->siguiente;
    if(actual == primero) EliminarPrincipio();
    else if(actual== ultimo)EliminarFinal()
    else{
        aux->ant->sigueinte = aux->sig;
        aux->siguiente->anterior=aux->ant;
        delete aux;
        --numElementos
    }

}
 */
/*
Tipo ObtenerPrimero() const{

    if(EstaVacia()) throw Excepcion("No hay elementos en la lista")
    return Primero->valor;


}


Tipo ObtenerUltimo() const{

    if(EstaVacia()) throw Excepcion("No hay elementos en la lista")
    return Ultimo->valor;
 }
Tipo ObtenerEnPos(int pos) const{
    //if(pos<0 || pos>= Obtenertamanio())throw Excepcion("posicion fuera de rango");
    Elemento *aux = Primero;
    for(int i = 0 i < pos;++i) aux = aux->siguiente;

    return aux->valor;
 }

int Buscar(valor)const{
    return BuscarPosDe(_va;lor) !=ObtenerTamanio();

 }
int BuscarPosDe(Tipo _valor, bool(*criterio)  (Tipo,Tipo) = Igual)const{
    int posicion= 0;

    for(Elemento*aux=primero;aux!= NULL && !criterio(actual->valor,valor;actual=actual->sig){
        ++posicion;
    }

    return pos;

 }

 */

template<typename Tipo>
void ListaDobleOrdenada<Tipo>::ListaDobleOrdenada::AgregarElemento (Tipo valor) {

    Elemento *aux = Primero;
    while ( aux != NULL && aux->valor <= valor) aux = aux->siguiente;

    Elemento *nuevo = new Elemento (valor , aux , aux != NULL ? aux->anterior : Ultimo);
    aux
    != Primero ? ( aux != NULL ? aux->anterior->siguiente = nuevo : Ultimo->siguiente = nuevo ) : Primero = nuevo;

    aux != NULL ? aux->anterior = nuevo : Ultimo = nuevo;

    ++numElementos;
}


template<typename Tipo>
bool ListaDobleOrdenada<Tipo>::EliminarElemento (Tipo valor) {

    Elemento *aux = Primero;
    while ( aux != NULL && aux->valor != valor) aux = aux->siguiente;


    if ( aux == NULL )return false;
    aux != Primero ? aux->anterior->siguiente = aux->siguiente : Primero = aux->siguiente;
    aux != Ultimo ? aux->siguiente->anterior = aux->anterior : Ultimo = aux->anterior;

    delete aux;
    --numElementos;

    return true;

}

template<typename Tipo>
bool ListaDobleOrdenada<Tipo>::Buscar (Tipo valorB) const{
    Elemento *aux = Primero;
    while(aux != NULL  && aux-> valor != valorB) aux = aux->siguiente;

    return aux != NULL;

}

template<typename Tipo>
void ListaDobleOrdenada<Tipo>::Vaciar () {

    //while(!vacia())EliminarPrincipio();
    Elemento *aux;
    while(Primero!=NULL){
        aux= Primero;
        Primero = Primero->siguiente;
        delete aux;
    }
    Ultimo = NULL;
    numElementos = 0;
}

template<typename Tipo>
bool ListaDobleOrdenada<Tipo>::EstaVacia ()const {
    return (Primero ==NULL && Ultimo ==NULL);
}

template<typename Tipo>
int ListaDobleOrdenada<Tipo>::ObtenerTamanio () const{
    return numElementos;
}



template <typename Tipo>
std::ostream &operator<<(std::ostream &salida, const ListaDobleOrdenada <Tipo> &c) {

    if(c.EstaVacia ()) return salida;
    struct ListaDobleOrdenada<Tipo>::Elemento * aux = c.Primero;
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
void ListaDobleOrdenada<Tipo>::ImprimirAscendente () const{
    std::cout << *this;
}


template<typename Tipo>
void ListaDobleOrdenada<Tipo>::ImprimirDescendente () const{

    if(EstaVacia ())return ;
    struct ListaDobleOrdenada<Tipo>::Elemento * aux = Ultimo;
    //salida << "Primero -> ";

    while(aux!=  NULL){
        std::cout << "[" << aux -> valor << "] <=> ";
        aux = aux -> anterior;
    }
    std::cout << "\b\b\b\b   \b\b\b\b";

}


#endif //LISTADOBLEORDENADA_LISTADOBLEORDENADA_H

