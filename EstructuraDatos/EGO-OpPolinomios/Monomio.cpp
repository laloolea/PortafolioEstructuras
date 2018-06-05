//
// Created by Eduardo Gonzalez Olea on 4/14/18.
//

#include "Monomio.h"

std::ostream &operator<< (std::ostream &o , const Monomio &v) {
    if(v.grado==0){
        o << v.racional;
    }else if(v.grado==1){
        o << v.racional << "x";
    }else {
        o << v.racional << "x^" << v.grado;
    }
    return o;
}


bool Monomio::operator== (const Monomio &m) const {
    return (grado!=m.grado||racional!=m.racional);
}

bool Monomio::operator!= (const Monomio &b) const {

    return (grado!=b.grado||racional!=b.racional);
    /* if(grado!=b.grado){
         return true;
     }else if(racional!=b.racional){
         return true;
     }else{
         return false;
     }
     return false;
     */
}

bool Monomio::operator<= (const Monomio &b) const {

    if(grado <= b.grado){
        return true;
    }
    else if(grado == b.grado){
        if(racional <= b.racional) return true;
    }else{
        return false;
    }
    return false;
    return grado<=b.grado;
}

bool Monomio::operator>= (const Monomio &b) const {
    //return grado>=b.grado;

    if(grado >= b.grado){
        return true;
    }
    else if(grado == b.grado){
        if(racional >= b.racional) return true;
    }else{
        return false;
    }
    return false;

}


bool Monomio::operator< (const Monomio &b) const {

    return grado < b.grado;

    if(grado < b.grado){
        return true;
    }
    else if(grado == b.grado){
        if(racional<b.racional) return true;
    }else{
        return false;
    }
    return false;

}

bool Monomio::operator> (const Monomio &b) const {
    //return grado > b.grado;

    if(grado > b.grado){
        return true;
    }
    else if(grado == b.grado){
        if(racional>b.racional) return true;
    }else{
        return false;
    }
    return false;

}

Monomio Monomio::operator+ (const Monomio &w) const {
    if(grado ==w.grado) {
        return Monomio (Racional (racional + w.racional) , grado);
    }else{
        throw("bye");
    }

}

Monomio::Monomio (Monomio const &v) {
    *this=v;

}

Monomio &Monomio::operator= (const Monomio &v) {
    racional=v.racional;
    grado=v.grado;

    return *this;
}

void Monomio::CambiarCoeficiente (Racional r) {
    racional=r;
}
/*
double Monomio::EvaluarMonomio (int x) {
    //return racional*pow(Racional(x/1),grado);
}
*/