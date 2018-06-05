//
// Created by Eduardo Gonzalez Olea on 4/30/18.
//

#ifndef MONTICULO_MONTICULO_H
#define MONTICULO_MONTICULO_H

#include <cstdlib>
#include <iostream>
#include <cmath>
#include "Excepciones.h"
/**
 * \brief funci&oacute;n que compara dos valores y te dice si el primero es menor que el segundo o no
 * \param El primer valor a comparar
 * \param El segundo valor a comparar
 * \return true si es menor y false si es mayor
*/
template <typename Tipo> bool Min(Tipo _valor1, Tipo _valor2)
{
    return _valor1 < _valor2;
}
/**
 * \brief Funci&oacute;n que compara dos valores y te dice si el primero es mayor que el segundo o no
 * \param El primer valor a comparar
 * \param El segundo valor a comparar
 * \return true si es mayor y false si es menor
*/
template <typename Tipo> bool Max(Tipo _valor1, Tipo _valor2)
{
    return _valor1 > _valor2;
}

/**
 * \brief Plantilla de clase para crear un mont&iacute;culo maximo /  minimo
 */
template <typename Tipo, bool (*criterio)(Tipo,Tipo)>
class Monticulo;

template <typename Tipo, bool (*criterio)(Tipo,Tipo)>
std::ostream &operator<<(std::ostream & salida, const Monticulo<Tipo,criterio> &c);

template <typename Tipo = int, bool (*criterio)(Tipo,Tipo) = Min>
class Monticulo{
    /** \brief  sobrecarga de operador << para imprimir un objeto tipo Monticulo la cual la tienes que hacer amiga para que esta tenga acceso
     *
     * \param ostream o donde se almacenara la cadena
     * \param Monticulo c Lista Doble a imprimir
     * \return devuelve una variable de tipo ostream
     *
     */
    friend std::ostream & operator<< <>(std::ostream & salida, const Monticulo<Tipo> &c);
public:
    /**
        * \brief constructor  de la clase Monticulo
        *
        *
        */
    Monticulo();
    /**
    * \brief constructor de copias de la clase Monticulo
    * \param const Monticulo &c una referencia constante al Monticulo que quieres copiar
    */
    Monticulo(const Monticulo<Tipo,criterio> &c);
    /**
     * \brief destructor  de la clase Monticulo
     *
     */
    ~Monticulo();
    /**
      * \brief Funci&oacute;n que agrega un elemento al Monticulo
      * \param tipo valor El valor que se metera al Monticulo
      * \exception bad_alloc, si no hay memoria disponible para agregar nuevo elemento
      */
    void AgregaElemento(Tipo valor);
    //Precondicion
    /**
     * \brief Funci&oacute;n que elimina un elemento del Monticulo (siempre el ultimo hijo)
     * \return true si se pudo eliminar el valor en el Monticulo
     */
    void EliminarElemento();
    /**
     * \brief Sobrecarga del operador = para igualar dos objetos tipo Monticulo
     * \param const listaDoble &o una referencia constante a Monticulo
     * \return Una referencia a Monticulo
     */
    Monticulo<Tipo,criterio> &operator=(const Monticulo<Tipo,criterio> &c);

    /**
    * \brief Funci&oacute;n que ve si un objeto del tipo Monticulo esta vacio
    * \return true si esta vacia, false si no lo esta
    */
    bool EstaVacio() const;

    /**
     * \brief M&eacute;todo que imprime el mont&iacute;culo por niveles
     */
    void Imprimir();
    /**
     * \brief M&eacute;todo que devuelve la ra&iacute;z del objeto tipo Monticulo
     * \return el elemento posicionado en la ra&iacute;z
     */
    Tipo ObtenerRaiz() const;

    int ObtenerNumElementos() const;

    void Vaciar();
private:
    int capacidad;
    int numElementos;
    Tipo *arbol;
    /**
     * \brief Funci&oacute;n que crea un arreglo
     * \return Un puntero a tipo
     * \exception bad_alloc
     */
    Tipo *CreaArreglo();
    /**
    * \brief Funci&oacute;n que libera memoria ocupada por un arreglo dinamico.
    */
    void LiberaMemoria();
    int ObtenerCapacidad() const;
    bool EstaLleno() const;
    void Redimensionar();
    void EmpujarHaciaArriba(int indice);
    void EmpujarHaciaAbajo(int indice);
    void Intercambia(Tipo &a, Tipo &b);

};

template <typename Tipo, bool (*criterio)(Tipo,Tipo)>
Monticulo<Tipo, criterio>::Monticulo() : capacidad(0), numElementos(0), arbol(NULL)
{

}

template <typename Tipo, bool (*criterio)(Tipo,Tipo)>
Monticulo<Tipo, criterio>::Monticulo(const Monticulo<Tipo,criterio> &c) : capacidad(0), numElementos(0), arbol(NULL)
{
    *this=c;
}



template <typename Tipo, bool (*criterio)(Tipo,Tipo)>
Monticulo<Tipo, criterio>::~Monticulo()
{
    LiberaMemoria();
}

template <typename Tipo, bool (*criterio)(Tipo,Tipo)>
Tipo *Monticulo<Tipo, criterio>::CreaArreglo()
{
    return new Tipo[capacidad];
}

template <typename Tipo, bool (*criterio)(Tipo,Tipo)>
void Monticulo<Tipo, criterio>::LiberaMemoria()
{
    delete [] arbol;
    arbol = NULL;
}

template<typename Tipo, bool (*criterio)(Tipo, Tipo)>
Monticulo<Tipo,criterio> &Monticulo<Tipo, criterio>::operator=(const Monticulo<Tipo,criterio> &c)
{
    if(this == &c ){
        return *this;
    }else {
        LiberaMemoria();
        capacidad = c.ObtenerCapacidad();
        numElementos = c.ObtenerNumElementos();
        if(capacidad != 0){
            arbol = CreaArreglo();
            for(int i = 0; i < capacidad ; ++i){
                arbol[i] = c.arbol[i];
            }
        }
    }

    return *this;
}


template <typename Tipo, bool (*criterio)(Tipo,Tipo)>
void Monticulo<Tipo, criterio>::AgregaElemento(Tipo valor)
{
    if(EstaLleno()) Redimensionar();
    arbol[numElementos] = valor;
    EmpujarHaciaArriba(numElementos++);

}

template<typename Tipo, bool (*criterio)(Tipo, Tipo)>
void Monticulo<Tipo, criterio>::EliminarElemento()
{
    if(EstaVacio()) throw Excepcion("Monticulo esta vacio");
    Intercambia(arbol[0],arbol[--numElementos]);
    EmpujarHaciaAbajo(arbol[0]);
}

template <typename Tipo, bool (*criterio)(Tipo,Tipo)>
bool Monticulo<Tipo, criterio>::EstaVacio() const{
    return numElementos == 0;
}

template <typename Tipo, bool (*criterio)(Tipo,Tipo)>
std::ostream &operator<<(std::ostream &salida, const Monticulo <Tipo,criterio> &c) {

    int nivelActual = 0, nivelAnterior=-1;
    for (int i = 0 ; i < c.ObtenerNumElementos () ; ++i){
        if(nivelActual != nivelAnterior) salida << "NIVEL " << nivelActual << ": ";
        nivelAnterior = nivelActual;
        nivelActual = (int)(log(i+2) / log(2));
        salida << "[" << c.arbol[i] << "] " << ", ";
        if(nivelActual != nivelAnterior)  salida << "\b\b " << std::endl;

    }
    salida<< "\b\b " << std::endl;
    return salida;
}


template <typename Tipo, bool (*criterio)(Tipo,Tipo)>
void Monticulo<Tipo, criterio>::Imprimir()
{

    int nivelActual = 0, nivelAnterior=-1;
    for (int i = 0 ; i < numElementos ; ++i){
        if(nivelActual != nivelAnterior) std::cout << "NIVEL " << nivelActual << ": ";
        nivelAnterior = nivelActual;
        nivelActual = (int)(log(i+2) / log(2));
        std::cout << "[" << arbol[i] << "] " << ", ";
        if(nivelActual != nivelAnterior)  std::cout << "\b\b " << std::endl;

    }
    std::cout << "\b\b " << std::endl;
}




template <typename Tipo, bool (*criterio)(Tipo,Tipo)>
void Monticulo<Tipo, criterio>::Redimensionar()
{
    //Redimension de arreglo cuando el arreglo se encuentre lleno
    if(capacidad == 0) capacidad++;
    else capacidad = (capacidad * 2) + 1;
    Tipo *aux = new Tipo[capacidad];
    for(int i = 0 ; i < numElementos ; ++i){
        aux[i] = arbol[i];
    }
    delete [] arbol;
    arbol = aux;

}

template <typename Tipo, bool (*criterio)(Tipo,Tipo)>
bool Monticulo<Tipo, criterio>::EstaLleno() const
{
    return numElementos == capacidad;
}

template <typename Tipo, bool (*criterio)(Tipo,Tipo)>
void Monticulo<Tipo, criterio>::EmpujarHaciaArriba(int indice)
{
    while(indice != 0 && criterio(arbol[indice], arbol[(indice-1)/2])){
        Intercambia(arbol[indice], arbol[(indice-1)/2]);
        indice = (indice - 1)/2;
    }
}

template <typename Tipo, bool (*criterio)(Tipo,Tipo)>
void Monticulo<Tipo, criterio>::Intercambia(Tipo &a, Tipo &b)
{
    Tipo aux= a;
    a = b;
    b = aux;
}

template<typename Tipo, bool (*criterio)(Tipo, Tipo)>
void Monticulo<Tipo, criterio>::EmpujarHaciaAbajo(int indice)
{

    while(indice < numElementos){
        //Que el elemento es una hoja del árbol
        if(2*indice + 2 >= numElementos && 2*indice + 1 >= numElementos){
            return;
        }

        Tipo aux = arbol[indice];


        if(2*indice + 1 < numElementos && 2*indice + 2 >= numElementos){
            arbol[indice] = arbol[2*indice + 1];
            arbol[2*indice + 1] = aux;
            indice = 2*indice + 1;
            continue;
        }

        if(criterio(arbol[2*indice + 1],arbol[2*indice + 2])){
            arbol[indice] = arbol[2*indice + 1];
            arbol[2*indice + 1] = aux;
            indice = 2*indice + 1;
        }else{
            arbol[indice] = arbol[2*indice + 2];
            arbol[2*indice + 2] = aux;
            indice = 2*indice + 2;
        }

    }
}
template<typename Tipo, bool (*criterio)(Tipo, Tipo)>
int Monticulo<Tipo, criterio>::ObtenerCapacidad() const
{
    return capacidad;
}

template<typename Tipo, bool (*criterio)(Tipo, Tipo)>
int Monticulo<Tipo, criterio>::ObtenerNumElementos() const
{
    return numElementos;
}

template<typename Tipo, bool (*criterio)(Tipo, Tipo)>
Tipo Monticulo<Tipo, criterio>::ObtenerRaiz() const
{
    return arbol[0];
}

template<typename Tipo , bool (*criterio)(Tipo, Tipo)>
void Monticulo<Tipo , criterio>::Vaciar () {
    numElementos=0;
}


#endif //MONTICULO_MONTICULO_H
