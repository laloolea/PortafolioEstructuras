//
// Created by Eduardo Gonzalez Olea on 4/14/18.
//

#include "Polinomio.h"


Polinomio::Polinomio() :  numElementos(0) , Primero (NULL){

}
Polinomio::Polinomio(const Polinomio &c): numElementos(0) , Primero (NULL) {
    *this = c;
}

Polinomio::~Polinomio () {
    Vaciar();
}



void Polinomio::AgregarElemento (Monomio valor) {
    Elemento *aux = Primero , *ant = NULL;

    while ( aux != NULL &&( aux->valor.ObtenerGrado () > valor.ObtenerGrado () )) {
        ant = aux;
        aux = aux->siguiente;
    }
    Elemento *nuevo = new Elemento (valor, aux);
    ant == NULL ? Primero = nuevo : ant->siguiente = nuevo;
    ++numElementos;

    Elemento* aux2=Primero;
    while(aux2!=NULL){
        if(aux2->siguiente!=NULL && (aux2->valor.ObtenerGrado () == aux2->siguiente->valor.ObtenerGrado ())){
            aux2->valor.CambiarCoeficiente (aux2->valor.ObtenerCoeficiente ()+aux2->siguiente->valor.ObtenerCoeficiente ());
            aux2->siguiente=aux2->siguiente->siguiente;
            --numElementos;
            break;
        }
        aux2=aux2->siguiente;
    }



}

bool Polinomio::EliminarElemento (Monomio valor) {
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

Polinomio &Polinomio::operator=(const Polinomio &c)
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



void Polinomio::Vaciar () {

    Elemento *aux;
    while(!Vacia()){
        aux= Primero;
        Primero = Primero->siguiente;
        delete aux;
    }
    numElementos = 0;
}

bool Polinomio::Vacia () {
    return Primero==NULL;
}
std::ostream &operator<<(std::ostream &salida, const Polinomio &c) {

    if(c.Primero == NULL){
        salida << "";
        return salida;
    }
    struct Polinomio::Elemento * aux = c.Primero;

    while(aux!=  NULL){
        salida <<  aux -> valor<<" + ";
        aux = aux -> siguiente;
    }
    salida << "\b\b\b ";

    //salida << "[" << aux -> valor << "] , ";

    return salida ;

}

int Polinomio::ObtenerTamanio () {
    return numElementos;
}

Polinomio Polinomio::operator+(const Polinomio &p) {
    Polinomio resultado;
    Elemento *aux = Primero, *aux2 = p.Primero;
    while(aux != NULL){
        resultado.AgregarElemento(aux->valor);
        aux = aux->siguiente;
    }
    while(aux2 != NULL){
        resultado.AgregarElemento(aux2->valor);
        aux2 = aux2->siguiente;
    }
    return resultado;
}

double Polinomio::EvaluarPolinomio (double x) {
    double evaluacion;

    Elemento*aux=Primero;
    //while(aux!=NULL){
    for(;aux!=NULL;aux=aux->siguiente)
        evaluacion+= (double)(aux->valor.ObtenerCoeficiente ().ObtenerNumerador ())/
                aux->valor.ObtenerCoeficiente ().ObtenerDenominador () * pow(x,aux->valor.ObtenerGrado ());
        //aux=aux->siguiente;
   // }

    return evaluacion;
}
Polinomio Polinomio::operator-(const Polinomio &p) {
    Polinomio resultado;
    Elemento *aux = Primero , *aux2 = p.Primero;
    while ( aux != NULL ) {
        resultado.AgregarElemento (aux->valor);
        aux = aux->siguiente;
    }
    while ( aux2 != NULL ) {
        resultado.AgregarElemento (
                Monomio (Racional (-1 , 1) * aux2->valor.ObtenerCoeficiente () , aux2->valor.ObtenerGrado ()));
        aux2 = aux2->siguiente;
    }
    return resultado;
}

Polinomio Polinomio::DerivarPolinomio () {
    Elemento *aux = Primero;
    Polinomio derivado;
    for(;aux != NULL; aux = aux->siguiente){
        if(aux->valor.ObtenerGrado() == 0)
            break;
        derivado.AgregarElemento(Monomio(aux->valor.ObtenerCoeficiente() * Racional(aux->valor.ObtenerGrado(),1),aux->valor.ObtenerGrado()-1));
    }
    return derivado;
}
