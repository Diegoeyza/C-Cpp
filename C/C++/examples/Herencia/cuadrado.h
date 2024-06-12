#include"rectangulo.h"

class cuadrado : public rectangulo {
public:
    cuadrado(double lado) : rectangulo(lado, lado) {};
};