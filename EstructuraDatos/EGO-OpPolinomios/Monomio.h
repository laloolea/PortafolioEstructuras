//
// Created by Eduardo Gonzalez Olea on 4/14/18.
//

#ifndef EGO_OPPOLINOMIOS_MONOMIO_H
#define EGO_OPPOLINOMIOS_MONOMIO_H

#include  "Racional.h"

/** \brief  Clase Monomio

   */
class Monomio {
/** \brief  sobrecarga de operador << para imprimir un objeto tipo Monomio
    *
    * \param ostream o donde se almacenara la cadena
    * \param Monomio v Monomio a imprimir
    * \return devuelve una variable de tipo ostream
    *
    */

    friend std::ostream & operator<< (std::ostream & o, const  Monomio &v);

public:
    Monomio(Racional _r,int _grado): racional(_r) , grado(_grado){}

    //Monomio(int _dem , int _num ,int grado ):dem(_dem),num(_num) , grado(_grado){}

    Monomio(Monomio const &v);
    Monomio& operator=(const Monomio &v);
    Monomio operator+(const Monomio &w) const;
    /** \brief Sobrecarga operador ==  para saber si un Monomio es igual a otro
     *
     * \param const Monomio &w una referencia constante de un objeto Monomio
     * \return bool un booleano que indica si es igual o no
     */
    bool operator==(const Monomio &r) const;
/** \brief Sobrecarga operador <=  para saber si un Monomio es menor o igual a otro
     *
     * \param const Monomio &w una referencia constante de un objeto Monomio
     * \return bool un booleano que indica si es menor o igual
     */
    bool operator<=(const Monomio &r) const;
    /** \brief Sobrecarga operador >=  para saber si un Monomio es mayor o igual a otro
     *
     * \param const Monomio &w una referencia constante de un objeto Monomio
     * \return bool un booleano que indica si es mayor o igual
     */
    bool operator>=(const Monomio &r) const;
    /** \brief Sobrecarga operador <  para saber si un Monomio es menor a otro
     *
     * \param const Monomio &w una referencia constante de un objeto Monomio
     * \return bool un booleano que indica si es menor
     */
    bool operator<(const Monomio &r) const;
    /** \brief Sobrecarga operador >  para saber si un Monomio es mayor a otro
     *
     * \param const Monomio &w una referencia constante de un objeto Monomio
     * \return bool un booleano que indica si mayor
     */
    bool operator>(const Monomio &r) const;
    /** \brief Sobrecarga operador !=  para saber si un Monomio es diferente a otro
     *
     * \param const Monomio &w una referencia constante de un objeto Monomio
     * \return bool un booleano que indica si diferente
     */
    bool operator!=(const Monomio &r) const;
    /** \brief metodo para obtener el grado del monomio
     *

     * \return int grado del monomio
     */
    int ObtenerGrado(){return grado;}
    /** \brief metodo para obtener el coeficiente del monomio
     *
     * \return Racional coeficiente del monomio
     */
    Racional ObtenerCoeficiente(){return racional;}

    /** \brief metodo para cambiar el Coeficiente del monomio
    *   \param Racional r
    */
    void CambiarCoeficiente(Racional r);




private:
     Racional racional;
    int grado;


};


#endif //EGO_OPPOLINOMIOS_MONOMIO_H
