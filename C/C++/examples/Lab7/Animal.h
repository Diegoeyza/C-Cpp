#pragma once
#include<string>
class Animales {
    virtual double VelocidadF() = 0;
};

class Animal : public Animales {
private:
    double peso;
    int velocidad;
    std::string nombre;
public:
    Animal(std::string,double,int);
    Animal(std::string,int);
    void setP(double);
    void setV(int);
    void setN(std::string);
    double VelocidadF();
    int velR();
    double pesR();
    std::string nameR();
};