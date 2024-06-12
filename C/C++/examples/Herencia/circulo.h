#include"elipse.h"

class circulo : public virtual elipse {
public:
    circulo(double diametro) : elipse(diametro, diametro) {};
};