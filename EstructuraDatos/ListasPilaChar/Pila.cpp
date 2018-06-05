//
// Created by Eduardo Gonzalez Olea on 2/21/18.
//

#include "Pila.h"
#include "Excepcion.h"
//metodos indispensables
Pila::Pila () :numElementos(0),tope(NULL) {

}

Pila::~Pila () {
    Vaciar();
}

Pila::Pila (const Pila &p) : numElementos(0),tope(NULL) {
    *this=p;
}


Pila & Pila::operator=(const Pila &p){

//Este if evita la autoasignacion
    if (this != &p){

        Vaciar();

        numElementos = p.numElementos;

        Elemento * direcciones[numElementos];

        // direcciones[0] = p.tope;

        Elemento * aux = p.tope;

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
void Pila::AgregarElemento (int valor)
{

    Elemento * aux= new Elemento(valor,tope);
    tope = aux;

    ++numElementos;

}

int Pila::ObtenerTope () {
    if(EstaVacia ()) throw Excepcion("Pila vacia");
    return tope -> valor;
}

int Pila::EliminarElemento ()
{
    if(EstaVacia ())throw Excepcion("Esta vacia no puedes elimnar");

    Elemento * aux = tope;

    tope = tope -> siguiente;//tope =  aux -> siguiente; la misma

    int valor =  aux -> valor;

    delete aux;

    --numElementos;
    return valor;
}


int Pila::ObtenerTamanio () {
    return numElementos;
}

void Pila::Vaciar ()
{
    while(!EstaVacia ()){
        EliminarElemento ();
    };
}
//metodos para conocer el estado
bool Pila::EstaVacia ()
{
    return tope==NULL;
}
//amigos de clase
std::ostream &operator<< (std::ostream &o , const Pila &pila)
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


    for(Elemento * aux = pila.tope; aux !=NULL ; aux = aux -> siguiente ){
        o << "["<< aux -> valor << "]";
    }
    return o;



}






