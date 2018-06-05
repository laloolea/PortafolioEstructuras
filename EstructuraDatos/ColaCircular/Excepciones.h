//
// Created by Eduardo Gonzalez Olea on 3/20/18.
//

#ifndef COLACIRCULAR_EXCEPCIONES_H
#define COLACIRCULAR_EXCEPCIONES_H


#include <iostream>
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

    Excepcion(std::string _msn) : msn(_msn) {}

    /**
     * \brief M&eacute;todo que devuelve el mensaje de excepci&oacute;n
     *  \return string msn El mensaje de la excepci&oacute;n
     */
    std::string QuePaso() const { return msn; }

private:
    std::string msn;
};


#endif //COLACIRCULAR_EXCEPCIONES_H
