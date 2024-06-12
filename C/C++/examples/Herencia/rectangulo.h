#pragma once

class figura {
    virtual double area() = 0;
};

class rectangulo : public figura {
private:
    double base;
    double altura;
public:
    rectangulo(double, double);
    double area();
};