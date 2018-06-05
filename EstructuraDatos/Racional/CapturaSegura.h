//
// Created by Eduardo Gonzalez Olea on 3/2/18.
//

#ifndef RACIONAL_CAPTURASEGURA_H
#define RACIONAL_CAPTURASEGURA_H
#include "iostream"

template <typename T>
void CapturaDato (const char *mensage , T &num)
{
    while(true){
        std::cout << mensage;
        std::cin >> num;

        if(std::cin.bad()) throw "Ha ocurrido un error fatal en el flujo de entrada, el programa ha terminado";

        if(std::cin.fail()){
            std::cout << "\n\nError: el tipo de dato proporcionado no corresponde con el tipo de dato solicitado" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<int>::max(),'\n');
            continue;
        }
        return;
    }
}


#endif //RACIONAL_CAPTURASEGURA_H
