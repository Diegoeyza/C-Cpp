#include<iostream>

#include"fraccion.h"

using namespace std;

double parabola(double x, double a, double b=0, double c=0) {
    return a*x*x+b*x+c;
}

int main() {
    fraccion f1=fraccion(4,-12);
    fraccion f2=fraccion(5);
    cout<<(string)f1<<"+"<<(string)f2<<endl;
    cout<<(string)(f1+f2)<<endl;
    cout<<(string)f1<<"~="<<f1<<endl;

    return 0;
}