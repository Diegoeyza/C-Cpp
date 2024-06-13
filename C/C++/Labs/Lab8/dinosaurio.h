#pragma once
#include<string>
using namespace std;

class Dinosaurio {
    public:
    string apodo;
    string altura;
    bool esCarnivoro;
    string periodo;
    string infoAdicional;
    void hacerSonido();
    void mostrarInfo();
    Dinosaurio(string,string,string,string,string);
};
