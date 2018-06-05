#include <iostream>
#include  <iomanip>
#include "Monomio.h"
#include"Polinomio.h"
using namespace std;
int main () {

    try{
        cout <<"SUMA DE POLINOMIOS"<<endl;
        Polinomio p,x;
        p.AgregarElemento(Monomio(Racional(3,1),5));
        p.AgregarElemento(Monomio(Racional(1,-1),3));
        p.AgregarElemento(Monomio(Racional(4,2),2));
        p.AgregarElemento(Monomio(Racional(-5,1),1));
        p.AgregarElemento(Monomio(Racional(2,1),0));


        x.AgregarElemento(Monomio(Racional(2,1),4));
        x.AgregarElemento(Monomio(Racional(1,1),1));
        x.AgregarElemento(Monomio(Racional(-1,1),0));


        cout << p<< " + \n"<< x << " =\n" << p+x;

        cout <<"\n\nRESTA DE POLINOMIOS"<<endl;
        cout << p<< " - \n"<< x << " =\n" << p-x;

        cout <<"\n\nDERIVADA DE POLINOMIOS\n";



        cout <<"P(x)= "<< p << "\nP'(x)="<<p.DerivarPolinomio();

        cout <<  "\n\nEVALUAR POLINOMIO\n";

        cout <<"P(x)= "<< p <<"con x=1.2 es = "<< p.EvaluarPolinomio (1.2);


    }catch(Excepcion &exc){
        cout<< exc.QuePaso()<<endl;
    }

    return 0;
}



