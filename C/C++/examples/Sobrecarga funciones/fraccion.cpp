#include"fraccion.h"

void fraccion::simplificar() {
    int gcd=num;
    if(num<0) gcd=-num;
    int otro=den;
    while (otro != 0) {
        int r = gcd % otro;
        gcd = otro;
        otro = r;
    }
    num/=gcd;
    den/=gcd;
}

fraccion::fraccion(int num,int den){
    if(den<0) {
        num=-num;
        den=-den;
    }
    this->num=num;
    this->den=den;
    simplificar();
}

fraccion fraccion::operator+(fraccion otra) {
    int nums=num*otra.den + den*otra.num;
    int dens=den*otra.den;
    return fraccion(nums,dens);
}

fraccion::operator std::string() {
    return std::to_string(num)+"/"+std::to_string(den);
}

std::string fraccion::mostrar() {
    return std::to_string(num)+"/"+std::to_string(den);
}

fraccion::operator double() {
    return 1.0*num/den;
}