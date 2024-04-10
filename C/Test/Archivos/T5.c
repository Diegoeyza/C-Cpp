#include<stdio.h>
#include<string.h>

int main(int argc, char **argv){
    FILE *archivo;
    char line[100]="";
    if (argc>1)
        archivo=fopen(argv[1],"w+");
    else 
        archivo=fopen("salida.txt", "w+");
    if (archivo==NULL) return 1;
        return 1;
    fgets(line, 99,stdin);
    while (strlen(line)>1){
        fprintf(archivo,"%s ", line);
        fgets(line, 99,stdin);
    }
    fclose(archivo);



    return 0;
}