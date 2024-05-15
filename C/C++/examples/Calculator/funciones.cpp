#include"funciones.h"

operacion::operacion(func f, char operador, string nombre_operacion) {
	funcion = f;
	oper = operador;
	nombre = nombre_operacion;
}

int operacion::calcular(int o1, int o2) {
	return funcion(o1,o2);
}



int suma(int a, int b) {
	return a+b;
}

int resta(int a, int b) {
	return a-b;
}

int mult(int a, int b) {
	return a*b;
}

int potencia(int a, int b) {
	int r=a;
	for(int i=1;i<b;i++) r*=a;
	return r;
}