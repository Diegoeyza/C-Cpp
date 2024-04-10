#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define M 10

int main(){
    FILE * archivo=fopen("tester.txt","w+");
    char entry[M]="";
    printf("start\n");
    fgets(entry,M,stdin);
    fprintf(archivo,"%s",entry);
    char salida[100]="";
    rewind(archivo);
    fgets(salida,10,archivo);
    printf("%s",salida);
    fclose(archivo);
    
}
