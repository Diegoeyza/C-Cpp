#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define M 100

int main(){
    FILE * archivo=fopen("tester.txt","w+");
    char entry[M]="";
    printf("start\n");
    fgets(entry,M,stdin);
    fprintf(archivo,"%s",entry);
    fprintf(archivo,"%s",entry);
    char salida[100]="";
    rewind(archivo);
    fgets(salida,100,archivo);
    while (!feof(archivo)){
    printf("%s",salida);
    fgets(salida,100,archivo);}
    fflush(salida);
    fclose(archivo);
    
}
