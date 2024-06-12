#pragma once

#include<string>

class fraccion {
    int num;
    unsigned int den;
    void simplificar();
public:
    fraccion(int,int);
    fraccion(int num) : fraccion(num, 1) {};
    fraccion operator+(fraccion otra);
    operator std::string();
    std::string mostrar();
    operator double();
};