//
// Created by Eduardo Gonzalez Olea on 5/21/18.
//

#ifndef AVL_EXCEPCIONES_H
#define AVL_EXCEPCIONES_H

#include <string>
/**
 * \brief Clase Excepcion que se crea cada que se genera una excepcion.
 *
 */

class Excepcion {
public:
    /**
     * \brief Constructor de la clase Excepcion
     *
     */
    Excepcion (std::string _msn) : msn (_msn) {}
    /**
     * \brief M&eacute;todo que devuelve el mensaje de excepci&oacute;n
     *  \return string msn El mensaje de la excepci&oacute;n
     */

    std::string QuePaso() const { return msn; }

private:
    std::string msn;
};



#endif //AVL_EXCEPCIONES_H
