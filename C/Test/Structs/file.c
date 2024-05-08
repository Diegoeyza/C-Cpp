#include<stdio.h>
#include<stdlib.h>

typedef int (*func)(int, int);

typedef struct operacion {
	char operador;
	func funcion;
} oper;