#pragma once

#include"rectangulo.h"

class elipse : public rectangulo {
public:
    elipse(double eje1, double eje2) : rectangulo(eje1,eje2) {}
    double area();
};