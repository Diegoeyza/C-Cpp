#pragma once
#include<string>
#include "dinosaurio.h"
using namespace std;

class Carnivoro : public Dinosaurio {
    public:
    Carnivoro(string apodod,string alturad,string carnivorod,string periodod,string infod) : Dinosaurio(apodod,alturad,carnivorod,periodod,infod) {}
    void hacerSonido();
    void mostrarInfo();
};