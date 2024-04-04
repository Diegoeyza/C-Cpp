#include <stdio.h>
#include <string.h>
#include <ctype.h>
void palindromo(char palabra[]){
    char fusedword[100]="";
    char reversedword[100]="";
    int count=0;
    for (int i=0; i<strlen(palabra); i++){
        if ((palabra[i]>=65&&palabra[i]<=90)||(palabra[i]>=97&&palabra[i]<=122)){
            fusedword[count]=tolower(palabra[i]); count++;
        }
    }
    int largo=strlen(fusedword);
    for (int i=0;i<largo;i++)
        reversedword[i]=fusedword[largo-i-1];
    switch (strcmp(fusedword,reversedword)){
        case 0: printf("\n¡La entrada %s ES un palindromo!\n",palabra); break;
        default: printf("\n¡La entrada %s NO ES un palindromo!\n",palabra);
    }
}
int main(){
    int exit=0;
    char exitorder[4];
    printf("Bienvenido al Verificador de Palíndromos AI-WordCheck\n-----------------------------------------------------");
    while (exit==0){
        char palabra[100];
        printf("\nPor favor, ingresa una palabra o frase para verificar: ");
        fgets(palabra,100,stdin);
        printf("\nVerificando...\n");
        int largo=strlen(palabra);palabra[largo-1]='\0';
        palindromo(palabra);
        printf("\n¿Deseas verificar otra entrada? (sí/no): ");
        fgets(exitorder,4,stdin);
        if(strncmp(exitorder,"no",2)==0||strncmp(exitorder,"No",2)==0||strncmp(exitorder,"NO",2)==0){
            exit=1;
        }
    }
    printf("\nGracias por usar AI-WordCheck.\n\n");
    return 0;
}