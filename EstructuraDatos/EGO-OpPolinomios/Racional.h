//
// Created by Eduardo Gonzalez Olea on 4/14/18.
//

#ifndef EGO_OPPOLINOMIOS_RACIONAL_H
#define EGO_OPPOLINOMIOS_RACIONAL_H

#include <cmath>
#include "Excepcion.h"
#include <sstream>
#include <iostream>
#include "CapturaDato.h"

/** \brief  Clase Racional que simula una fracci&oacute;n.

   */
class Racional {
    /** \brief  sobrecarga de operador << para imprimir un objeto tipo Racional
     *
     * \param ostream o donde se almacenara la cadena
     * \param Racional v Racional a imprimir
     * \return devuelve una variable de tipo ostream
     *
     */
    friend std::ostream & operator<< (std::ostream & o, const Racional &v);
    /** \brief  sobrecarga de operador >> para capturar una objeto tipo Racional
   *
   * \param istream entrada en la cual se almacena las entradas del n&uacute;mero  racional
   * \param Racional v Arreglo a capturar
   * \return devuelve una variable de tipo istream
   *
   */
    friend std::istream & operator>> (std::istream & o,  Racional &r);

public:
    /** \brief Constructor de la clase Racional
 */
    Racional(int _numerador ,int _denominador): numerador(_numerador), denominador(_denominador)
    {
        if(denominador==0)throw Excepcion("El denominador no puede ser 0");
        if (denominador<0){
            numerador = -numerador;
            denominador = abs(denominador);
        }
        Simplificar ();
    }
    /** \brief Constructor de la clase Racional que no lleva parametros
     */
    Racional():numerador(0),denominador(1){

    }
    /** \brief Constructor de copias de la clase Racional
     * \param Racional const &v una referencia constante de tipo Racional la cual se copiara
     * \return Racional Un objeto tipo Racional
 */

    Racional(Racional const &v);
    /** \brief Sobrecarga operador =  para igualar objetos de tipo Racional
    *
    * \param const Racional &w una referencia constante de un Racional
    * \return Racional Un objeto Racional el cual se igualo al del parametros
    *
    */
    Racional& operator=(const Racional &v);
    /** \brief Sobrecarga operador +  para sumar Racionales
     *
     * \param const Racional &w una referencia constante de un objeto Racional
     * \return Racional El Racional de la suma
     *
     */

    Racional operator+(const Racional &w) const;
    /** \brief Sobrecarga operador -  para restar Racionales
     *
     * \param const Racional &w una referencia constante de un objeto Racional
     * \return Racional El Racional de la resta
     *
     */

    Racional operator-(const Racional &w) const;
    /** \brief Sobrecarga operador * para multiplicar Racionales
     *
     * \param const Racional &w una referencia constante de un objeto Racional
     * \return Racional El Racional del producto
     *
     */

    Racional operator*(const Racional &w) const;
    /** \brief Sobrecarga operador /  para multiplicar Racionales
     *
     * \param const Racional &w una referencia constante de un objeto Racional
     * \return Racional El Racional de la divisi&oacute;n
     *
     */

    Racional operator/(const Racional &w) const;

    /** \brief Sobrecarga operador <  para saber si un Racional es menor a otro
     *
     * \param const Racional &w una referencia constante de un objeto Racional
     * \return bool un booleano que indica si es menor o no
     */
    bool operator<(const Racional &r) const;
    /** \brief Sobrecarga operador >  para saber si un Racional es mayor a otro
     *
     * \param const Racional &w una referencia constante de un objeto Racional
     * \return bool un booleano que indica si es mayor o no
     */
    bool operator>(const Racional &r) const;
    /** \brief Sobrecarga operador ==  para saber si un Racional es igual a otro
     *
     * \param const Racional &w una referencia constante de un objeto Racional
     * \return bool un booleano que indica si es igual o no
     */
    bool operator==(const Racional &r) const;

    bool operator<=(const Racional &r) const;
    bool operator>=(const Racional &r) const;
    bool operator!=(const Racional &r) const;
    int  ObtenerNumerador(){return numerador;}
    int  ObtenerDenominador(){return denominador;}
private:
    int numerador;
    int denominador;
    //Metodos de utileria
    /** \brief funci&oacute;n que simplifica un objeto tipo Racional
     */
    void Simplificar();
    /** \brief funci&oacute;n encuentra un maximo com&uacute;n divisor, el cual se usa para simplificar un Racional
     *
     * \param int numerador
     * \param int denominador
     * \return int El maximo com&uacute;n divisor
     */
    int MaximoComunDivisor(int numerador, int denominador);



};



#endif //EGO_OPPOLINOMIOS_RACIONAL_H
