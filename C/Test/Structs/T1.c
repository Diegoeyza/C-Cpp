#include<stdio.h>
#include<stdlib.h>

// desde ahora, "func", usado como tipo en una declaración (ej. func f),
// equivale a puntero a función que recibe dos int y retorna int: int (*f)(int, int) 
typedef int (*func)(int, int);

// desde ahora, oper equivale a struct operacion,
// que es un "paquete" que "contiene" un char (para el operador) y una func
// (para calcular el resultado)
typedef struct operacion {
	char operador;
	func funcion;
} oper;

// funciones para tener en un arreglo e iterar
int suma(int a, int b) {
    return a+b;
}

int mult(int a, int b) {
    return a*b;
}

int resta(int a, int b) { 
    return a-b;
}

int pot(int a, int b) {
	int r=a;
	for(int i=1;i<b;i++) r*=a;
	return r;
}

// paso por referencia, para no copiar la struct completa
void muestrastruct(oper * o) {
	//(*o).algo es igual a o->algo
	printf("la operacion '%c' esta en %p\n", o->operador, (*o).funcion);
}

int main(int argc, char **argv) {
    int op1 = 3;
    int op2 = 3;

    oper ff[] = {
    	{'+', suma},
    	{'x', mult},
    	{'-', resta},
    	{'^', pot}
    };

	// con sizeof(ff)/sizeof(oper) tenemos el largo del arreglo. No funciona con punteros,
	// solo con arreglos declarados con []. Esta es de las pocas diferencias prácticas
	// entre arreglos y punteros.
    for(int i = 0;i<sizeof(ff)/sizeof(oper);i++) {
        printf("%d %c %d = %d\n", op1, ff[i].operador, op2, ff[i].funcion(op1, op2));
    }
    
    return 0;
}