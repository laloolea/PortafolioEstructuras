//
// Created by Eduardo Gonzalez Olea on 3/2/18.
//

#ifndef RACIONAL_EXCEPCION_H
#define RACIONAL_EXCEPCION_H

#include <string>

class Excepcion {
public:

    Excepcion (std::string _msn) : msn (_msn) {}

    std::string QuePaso() const { return msn; }

private:
    std::string msn;
};


#endif //RACIONAL_EXCEPCION_H
