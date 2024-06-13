#pragma once
#include<string>
#include "dinosaurio.h"
#include<string>
using namespace std;

class Herviboro : public Dinosaurio {
    public:
    Herviboro(string apodod,string alturad,string carnivorod,string periodod,string infod) : Dinosaurio(apodod,alturad,carnivorod,periodod,infod) {}
    void hacerSonido();
    void mostrarInfo();


};