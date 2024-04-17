#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void intercambiar(int * n1, int * n2) {
    int aux;
    aux=*n1;
    *n1=*n2;
    *n2=aux;
}


// esto SI funciona
int * retorna_arreglo() {
    //no es muy elegante dejar el malloc separado
    //del free, aqui se hace sólo por motivos
    //didácticos
    int * arreglo = malloc(10*sizeof(int));
    for(int i=0;i<10;i++)
        arreglo[i]=i*i;

    return arreglo;
}

int main() {
    //arr es el arreglo con que quiero trabajar

    int a = 5, b=6;
    intercambiar(&a, &b);
    int * arr = retorna_arreglo();
    for (int i=0;i<10;i++)
        printf("%d ", arr[i]);

    //lo mismo con realloc
    arr=realloc(arr, 30*sizeof(int));

    free(arr);
    return 0;
}