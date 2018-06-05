//
// Created by Eduardo Gonzalez Olea on 5/16/18.
//

#ifndef EGO_ARBOLBINARIOBUSQUEDA_CAPTURASEGURA_H
#define EGO_ARBOLBINARIOBUSQUEDA_CAPTURASEGURA_H
#include "iostream"
    /**
     * \brief Funci&oacute;n que captura un dato de forma segura
     * \param const char *mensage el mensaje de la captura
     * \param T &num  el dato a capturar de tipo T
     */
template < typename T>
void CapturaDato (const char *mensage , T &num)
{
    while ( true  ){
        std::cout << mensage;
        std::cin >> num;

        if( std::cin.bad()) throw "Ha ocurrido un error fatal en el flujo de entrada, el programa ha terminado";

        if( std::cin.fail()){
            std::cout << "\n\nError: el tipo de dato proporcionado no corresponde con el tipo de dato solicitado" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits< int >::max(),'\n');
            continue ;
        }
        return;
    }
}

#endif //EGO_ARBOLBINARIOBUSQUEDA_CAPTURASEGURA_H
