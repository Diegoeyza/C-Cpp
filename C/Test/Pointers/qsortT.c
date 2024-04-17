#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int compare(void *s1,void *s2){
    char * string1=*(char **)s1;
    char * string2=*(char **)s2;
    if (string2[0]<string1[0]){
        return 1;

    }
    else return 0;

}

int main(){
    char nombres[][30] = {"Ignacio Carrera",
        "Arturo Prat",
        "Bernardo O'Higgins"
    };
    int cant_nombres = sizeof(nombres)/30;
    char * ptr_porletra[cant_nombres];
    for(int i=0;i<cant_nombres;i++) ptr_porletra[i]=nombres[i];
    qsort(ptr_porletra, cant_nombres, sizeof(char*), compare);
    for(int i=0;i<cant_nombres;i++) printf("%s\n", ptr_porletra[i]);




    return 0;
}