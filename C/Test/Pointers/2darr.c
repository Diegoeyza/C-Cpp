#include<stdio.h>
#include<stdlib.h>

int main() {
    int **matriz;
    int i;
 
    //para crear una matriz con malloc, hay que
    //crear un arreglo de arreglos, y reservar memoria
    //para cada uno: el "grande" y los "chicos"
    
    //en este caso, la matriz será de 10x10
    
    //crea el arreglo grande, que va a contener punteros
    //a int (o sea, int*)
    matriz=malloc(10*sizeof(int *));
    
    //crea cada uno de los arreglos chicos, con malloc
    for(i=0;i<10;i++)
        i[matriz]=malloc(10*sizeof(int));

    //llena la matriz, en este caso, con i*j
    for(i=0;i<10;i++)
        for(int j=0;j<10;j++)
            matriz[i][j]=i*j;

    //muestra la matriz en la consola
    for(i=0;i<10;i++) {
        for(int j=0;j<10;j++)
            printf("%d ", matriz[i][j]);
        printf("\n");
    }
    
    //libera la memoria: primero hay que liberar
    //los arreglos chicos, y al final el grande
    //(si no, saldrá segmentation fault).
    for(i=0;i<10;free(matriz[i++])) ;
    free(matriz); 

    return 0;
}