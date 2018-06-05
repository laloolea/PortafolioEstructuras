//
// Created by Eduardo Gonzalez Olea on 4/14/18.
//

#include "Racional.h"



Racional::Racional (Racional const &v) {
    *this=v;
}


Racional &Racional::operator= (const Racional &v) {
    if(this == &v) return *this;

    numerador  = v.numerador;
    denominador= v.denominador;

    return *this;
}


Racional Racional::operator+ (const Racional &w) const {
    return Racional (numerador *w.denominador + denominador * w.numerador,denominador * w.denominador);
}

Racional Racional::operator- (const Racional &w) const {
    return Racional (numerador *w.denominador - denominador * w.numerador,denominador * w.denominador);
}

Racional Racional::operator* (const Racional &w) const {

    return Racional (numerador * w.numerador, denominador * w.denominador);

}

Racional Racional::operator/ (const Racional &w) const {

    return Racional(numerador * w.denominador, denominador * w.numerador);

}

std::ostream &operator<< (std::ostream &o , const Racional &v) {
    o <<"(" <<v.numerador << "/" <<  v.denominador<<")";
    return o;
}

void Racional::Simplificar() {
    int CMD = MaximoComunDivisor(abs(numerador), abs(denominador));
    numerador = numerador/CMD;
    denominador = denominador/CMD;
}


int Racional::MaximoComunDivisor(int numerador, int denominador) {
    if(numerador == 0 )return numerador;
    if (denominador > numerador) {
        if ((denominador % numerador) == 0) {
            return numerador;
        } else {
            return MaximoComunDivisor(numerador, denominador % numerador);
        }
    }
    else {
        if ((numerador % denominador) == 0)
            return denominador;
        else
            return MaximoComunDivisor(denominador, numerador % denominador);
    }
}

std::istream &operator>> (std::istream &o ,  Racional &r) {

    CapturaDato ("Favor de introducir el numerador: ",r.numerador);

    CapturaDato ("Favor de introducir el numerador: ",r.denominador);


    if(r.denominador == 0){
        throw Excepcion("El valor del denominador no puede ser cero.");
    }
    if(r.denominador < 0){
        r.numerador = -r.numerador;
        r.denominador = abs(r.denominador);
    }
    r.Simplificar();

    return o;
}

bool Racional::operator< (const Racional &m) const {
    return ((double)numerador/denominador < (double)m.numerador/m.denominador);
}

bool Racional::operator> (const Racional &m) const {
    return ((double)numerador/denominador > (double)m.numerador/m.denominador);
}

bool Racional::operator== (const Racional &m) const {
    return ((double)numerador/denominador == (double)m.numerador/m.denominador);
}

bool Racional::operator<= (const Racional &m) const {
    return ((double)numerador/denominador <= (double)m.numerador/m.denominador);
}

bool Racional::operator>= (const Racional &m) const {
    return ((double)numerador/denominador >= (double)m.numerador/m.denominador);
}

bool Racional::operator!= (const Racional &m) const {
    return ((double)numerador/denominador != (double)m.numerador/m.denominador);
}


