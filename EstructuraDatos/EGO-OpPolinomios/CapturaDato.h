//
// Created by Eduardo Gonzalez Olea on 4/14/18.
//

#ifndef EGO_OPPOLINOMIOS_CAPTURADATO_H
#define EGO_OPPOLINOMIOS_CAPTURADATO_H
#include "iostream"
/** \brief Plantilla de funci&oacute;n para capturar un dato de forma segura
   * \param const char *mensage el mensaje para capturar el dato
   * \param T  *num una referencia de tipo T al cual se le asignara un valor
  */

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

#endif //EGO_OPPOLINOMIOS_CAPTURADATO_H
