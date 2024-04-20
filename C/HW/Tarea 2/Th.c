#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    FILE *file = fopen("bd_chica.csv", "r");
    if (!file) {
        printf("Error al leer el archivo/inexistente.\n");
    }
    else {
        char buffer[517];
 

        int fila = 0;
        int columna = 0;
 
        while (fgets(buffer, 517, file)) {
            columna = 0;
            fila++;
 
            if (fila == 1)
                continue;
 
            // Separamos usando strtok
            char *value = strtok(buffer, ";");
 
            while (value) {
                if (columna == 0) {
                    printf("Name :");
                }
 
                if (columna == 1) {
                    printf("\tAccount No. :");
                }
 
                if (columna == 2) {
                    printf("\tAmount :");
                }
 
                printf("%s", value);
                value = strtok(NULL, ", ");
                columna++;
            }
 
            printf("\n");
        }
 
        // Close the file
        fclose(file);
    }
    return 0;
}