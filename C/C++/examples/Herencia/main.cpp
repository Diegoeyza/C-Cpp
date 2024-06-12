#include<iostream>
#include<vector>

#include"rectangulo.h"
#include"cuadrado.h"
#include"elipse.h"
#include"circulo.h"

using namespace std;

int main() {
    rectangulo r(10, 3.14);
    rectangulo * s = new rectangulo(5, 12);
    elipse e(10,5);
    circulo ci(10);
    cuadrado c(7.0715);

    vector<rectangulo *> vec = vector<rectangulo *>();
    vec.push_back(&r);
    vec.push_back(s);
    vec.push_back(&e);
    vec.push_back(&ci);
    vec.push_back(&c);

    for(int i=0;i<vec.size();i++) {
        cout<<"el area de la figura "<<i<<" es "<<vec[i]->area()<<endl;
    }


    delete s;
    return 0;
}