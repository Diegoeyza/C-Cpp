#include<iostream>

using namespace std;

#include"funciones.h"

int main(int argc, char ** argv) {
	int a = 5, b=6;

	char operador;

	operacion *oo[4];
		
	oo[0]=new operacion(suma, '+', "suma");
	oo[1]=new operacion(resta, '-', "resta");
	oo[2]=new operacion(mult, 'x', "multiplicacion");
	oo[3]=new operacion(potencia, '^', "potencia");
		
	cout << "Menu:" << endl << "=====" << endl;
	for(int i=0;i<4;i++) {
		cout << i+1 << ") " << oo[i]->nombre << endl;
	}	
		
	for(int i=0;i<4;i++) {
		operador=oo[i]->oper;
cout << a << operador << b << "=" << oo[i]->calcular(a,b) << endl;
	}
	
	for(int i=0;i<4;i++) delete oo[i];
	
	return 0;
}