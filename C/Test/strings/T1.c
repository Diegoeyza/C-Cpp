#include <stdio.h>
#include <string.h>

int main(){
    char keyword[]="Hola cómo estás";
    char lista[100];
    //scanf("%s", lista);
    char *token=strtok(keyword," ");
    while (token!=NULL){
        printf("%s",token);
        token=strtok(NULL," ");
    }
    if (strncmp(keyword,lista,2)==0){
        printf("success");
    }


    return 0;
}