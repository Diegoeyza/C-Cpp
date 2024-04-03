#include <stdio.h>
#include <string.h>

int main(){
    char keyword[]="Hola";
    char lista[100];
    scanf("%s", lista);
    puts(lista);
    if (strncmp(keyword,lista,2)==0){
        printf("success");
    }


    return 0;
}