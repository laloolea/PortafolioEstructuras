//
// Created by Eduardo Gonzalez Olea on 4/17/18.
//

#ifndef EGO_LISTADOBLEORDENADA_EXCEPCIONES_H
#define EGO_LISTADOBLEORDENADA_EXCEPCIONES_H

#include <string>
/** \brief Clase de excepci&oacute;n que sirve para manejar las excepciones
 *
 */
class Excepcion {
public:
    /** \brief Constructor de la clase Excepci&oacute;n
    * \param string _msn el mensaje de la excepci&oacute;n
 */
    Excepcion (std::string _msn) : msn (_msn) {}
    /** \brief Metodo que devuelve el mensaje de la excepci&oacute;n
     * \return string msn el mensaje de error.
   */
    std::string QuePaso() const { return msn; }

private:
    std::string msn;
};

#endif //EGO_LISTADOBLEORDENADA_EXCEPCIONES_H
