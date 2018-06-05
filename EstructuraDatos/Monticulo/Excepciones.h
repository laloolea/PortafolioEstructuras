//
// Created by Eduardo Gonzalez Olea on 4/30/18.
//

#ifndef MONTICULO_EXCEPCIONES_H
#define MONTICULO_EXCEPCIONES_H

#include <string>

class Excepcion {
public:
    Excepcion(std::string _msn) : msn(_msn){}
    std::string QuePaso() const {
        return msn;
    }

private:
    std::string msn;
};

#endif //MONTICULO_EXCEPCIONES_H
