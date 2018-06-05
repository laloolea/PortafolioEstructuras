//
// Created by Eduardo Gonzalez Olea on 3/2/18.
//

#ifndef QUE_EJEMPLO_H
#define QUE_EJEMPLO_H


class Ejemplo{
public:
    Ejemplo(int y = 10): dato(y) {}
    int getDatoIncrementado()  { return ++dato; }
private:
    int dato;
};
#endif //QUE_EJEMPLO_H
