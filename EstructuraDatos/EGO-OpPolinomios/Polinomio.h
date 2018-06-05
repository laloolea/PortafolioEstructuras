//
// Created by Eduardo Gonzalez Olea on 4/14/18.
//

#ifndef EGO_OPPOLINOMIOS_POLINOMIO2_H
#define EGO_OPPOLINOMIOS_POLINOMIO2_H

#include <cstdlib>
#include <iostream>

#include "Monomio.h"





/** \brief  Clase Polinomio

   */
class Polinomio {
    /** \brief  sobrecarga de operador << para imprimir un objeto tipoPolinomio
       *
       * \param ostream o donde se almacenara la cadena
       * \param Polinomio c Polinomio a imprimir
       * \return devuelve una variable de tipo ostream
       *
       */
    friend std::ostream& operator<<(std::ostream & salida, const Polinomio &c);

public:

    /**
     * \brief constructor  de la clase Polinomio
     *
     *
     */
    Polinomio();
    /**
       * \brief constructor de copias de la clase Polinomio
       * \param const Polinomio &c una referencia constante al Polinomio a la que quieres copiar
       */
    Polinomio(const Polinomio &c);
    /**
    * \brief destructor  de la clase Polinomio
    *
    */
    ~Polinomio();

/**
      * \brief Funci&oacute;n que agrega un elemento a un Polinomio
      * \param tipo valor El valor que se metera al Polinomio
      * \exception bad_alloc, si no hay memoria disponible para agregar nuevo elemento
      */
    void AgregarElemento(Monomio valor);
    /**
    * \brief Funci&oacute;n que elimina un elemento del Polinomio
    * \param  Tipo valor el valor a eliminar en el Polinomio
     * return true si se pudo eliminar el valor en el Polinomio
    */
    bool EliminarElemento(Monomio valor);


    /**
    * \brief Funci&oacute;n que vacia El polinomio
    */
    void Vaciar();
    /**
   * \brief Funci&oacute;n que ve si un Polinomio
    * \return true si esta vacio, false si no lo esta
   */
    bool Vacia();
    /**
     * \brief Funci&oacute;n que devuelve el tama&ntilde;o actual del Polinomio
     * \return el tama&ntilde;o del Polinomio
     */

    int ObtenerTamanio();

    /**
    * \brief Sobrecarga del operador = para igualar dos polinomios
    * \param const Polinomio &o una referencia constante a Polinomio
    * \return Una referencia a listaSimpleOrdenada
    */

    Polinomio &operator=(const Polinomio &c);

    /**
   * \brief Sobrecarga del operador + para sumar 2 polinomios
   * \param const Polinomio &o una referencia constante a Polinomio
   * \return Un Polinomio de la suma
   */
    Polinomio operator+(const Polinomio &c);
    /**
   * \brief Sobrecarga del operador - para restar 2 polinomios
   * \param const Polinomio &o una referencia constante a Polinomio
   * \return Un Polinomio de la resta
   */
    Polinomio operator-(const Polinomio &c);
    /**
   * \brief Metodo para evaluar  un polinomio
   * \param double x el valor de x que quieres evaluar
   * \return Double el valor de la evaluac&oacute;n
   */
    double EvaluarPolinomio(double x);
    /**
   * \brief Metodo para Derivar  un polinomio
   * \return Polinomio  el polinomio derivado
   */
    Polinomio DerivarPolinomio();
private:

    struct Elemento{
        explicit Elemento(Monomio _valor, Elemento* _siguiente = NULL) : valor(_valor), siguiente(_siguiente){};

        Monomio valor;
        Elemento * siguiente;
    };

    int numElementos;
    Elemento *Primero;

};



#endif //EGO_OPPOLINOMIOS_POLINOMIO2_H
