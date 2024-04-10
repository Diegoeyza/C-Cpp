#include<stdio.h>
#include<string.h>

//cuenta cuantos espacios hay en un string
int cuentaespacios(char * linea) {
    int espacios=0;
    for(int i=0;i<strlen(linea);i++)
        if(linea[i]==' ') espacios++;
    return espacios;
}

//programa que convierte una secuencia de números enteros
//a su equivalente asumiendo que son codigos ascii
int main() {
    FILE * entrada = fopen("saludos.ascii", "r");
    FILE * salida=fopen("decodificado.txt", "w");

    char linea[1000];
    int letrasporlinea, leido;

    //para cada linea, pasa dos veces:
    fgets(linea, 999, entrada);
    while(!feof(entrada)) {

        //la primera pasada, cuenta cuantos espacios hay
        letrasporlinea=cuentaespacios(linea);

        //retrocede
        fseek(entrada, -strlen(linea)-1, SEEK_CUR);

        //la segunda pasada, lee los números
        int j;
        //tiene que contar uno mas: si hay n espacios, hay n+1 numeros
        for(j=0;j<=letrasporlinea;j++) {
            fscanf(entrada, " %d ", &leido);
            linea[j]=(char)leido;
        }
        //agrega el cero para terminar el string
        linea[j]=0;
        fprintf(salida, "%s\n", linea);
        fgets(linea, 999, entrada);
    }
    fclose(entrada);
    fclose(salida);

    return 0;
}