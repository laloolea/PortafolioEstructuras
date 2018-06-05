//
// Created by Eduardo Gonzalez Olea on 3/14/18.
//

#ifndef EGO_EXPRESIONES_EXCEPCIONES_H
#define EGO_EXPRESIONES_EXCEPCIONES_H
#include <string>
class Excepcion {
public:

    Excepcion (std::string _msn) : msn (_msn) {}

    std::string QuePaso() const { return msn; }

private:
    std::string msn;
};

#endif //EGO_EXPRESIONES_EXCEPCIONES_H
