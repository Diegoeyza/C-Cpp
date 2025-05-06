#include <stdio.h>
#include <string.h>

#define TAMANO 1000

int main(int argc, char *argv[]){
    FILE * f;
    
    char linea[1000];

    if(argc>1) {
        f = fopen(argv[1], "r");
    } else{
        f = fopen("ERROR.txt", "w");
        printf("ERROR: No pusiste el nombre del archivo a abrir\n");
        return 1;
    }
    
    if(f == NULL){
        printf("Error: No existe archivo que se llame así\n");
        return 1;
    }

    int length = 0;

    feof(f);

    fgets(linea, 99, f);
    while(!feof(f)){
        int a = strlen(linea);
        printf("%sTamaño: %d caracteres\n\n", linea, a);
        fgets(linea, 99, f);


    }
    
    

    fclose(f);

    return 0;
}