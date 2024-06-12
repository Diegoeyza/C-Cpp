#include"rectangulo.h"

rectangulo::rectangulo(double base, double altura) {
    this->base=base;
    this->altura=altura;
}

double rectangulo::area() {
    return base*altura;
}
