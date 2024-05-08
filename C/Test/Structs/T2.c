#include <stdio.h>
#include <string.h>


typedef int (*func)(int, int);

typedef struct operacion {
	char operador;
	func funcion;
} oper;

typedef struct storage {
	oper funcion;
	char descripcion[50];
    int id;
} storage;

int suma(int a, int b){return (a+b);}
int resta(int a,int b){return (a-b);}

void muestrastruct(oper * o) {
	printf("la operacion '%c' esta en %p\n", o->operador, (*o).funcion);
}

int main(int argc,char ** argv){
storage almacen[]={{{'+',suma},"Sumar",1},{{'-',resta},"Restar",2}};
for (int i=0; i<sizeof(almacen)/sizeof(storage);i++){
    char entry[10];
    printf("Please enter the 2 numbers as a,b\n->");
    fgets(entry,9,stdin);
    char *a=strtok(entry,",");
    char *b=strtok(NULL,",");
    printf("%s %d%c%d=%d\n",almacen[i].descripcion,*a,almacen[i].funcion.operador,*b,almacen[i].funcion.funcion(*a,*b));
}
}