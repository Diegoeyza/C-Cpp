#include<stdio.h>
#include<stdlib.h>

int vg=4;

void muestra_dir(char * nombre, void * p) {
    printf("%s esta en la dir %p\n", nombre, p);
}

void funcion(int parametro) {
    int vlf=3;

    muestra_dir("variable local en la funcion", &vlf);
    muestra_dir("parametro de la funcion", &parametro);
}

int main(int argc, char **argv) {
    int vl=6;
    float vl2=3.14;
    int * puntero=(int *)malloc(sizeof(int));
    *puntero = 428;

    muestra_dir("la variable local vl", &vl);
    muestra_dir("la variable local vl2", &vl2);
    funcion(57);
    muestra_dir("el puntero en si", &puntero);
    muestra_dir("el int apuntado por el puntero", puntero);
    muestra_dir("la variable global vg", &vg);
    printf("vl vale %d\n", vl);
    free(puntero);
    return 0;
}