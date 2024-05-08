#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "file.c"



typedef struct storage {
	oper funcion;
	char descripcion[50];
} storage;

int suma(int a, int b){return (a+b);}
int resta(int a,int b){return (a-b);}

void muestrastruct(oper * o) {
	printf("la operacion '%c' esta en %p\n", o->operador, (*o).funcion);
}

int main(int argc,char ** argv){
    char *entry= malloc(sizeof(char)*100);
    int *seleccion= malloc(sizeof(int));

    storage almacen[]={{{'+',suma},"Sumar"},{{'-',resta},"Restar"}};
    int size=sizeof(almacen)/sizeof(storage);
    printf("Please select the operation to use:\n");
    for (int i=0;i<size;i++){
        printf("%d-%s\n",i,almacen[i].descripcion);
    }
    fgets(entry,sizeof(entry),stdin);
    printf("Please enter the 2 numbers as a,b\n->");
    *seleccion=atoi(entry);
    fgets(entry,sizeof(entry),stdin);
    char *a;
    a=strtok(entry,",");
    char *b;
    b=strtok(NULL,",");
    b[strcspn(b, "\n")] = 0;

    printf("%s %s%c%s=%d\n",almacen[*seleccion].descripcion,a,almacen[*seleccion].funcion.operador,b,almacen[*seleccion].funcion.funcion(atoi(a),atoi(b)));
    free(entry);
    free(seleccion);
    return 0;

}