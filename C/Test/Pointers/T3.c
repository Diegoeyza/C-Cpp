#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CITY 190 //el nombre real de bangkok
#define COUNTRY 58 //UK

char* nstrtok(char *string, const char *delimeter)
{
  static char *start = NULL;
  char *token = NULL; 
  if (string) start = string;               //asigno la dirección de memoria del string a utilizar a la variable en la función
  if (start){                               //verifico si esque hay un string que dividir o si es null
    token = start;
    start = strpbrk(start, delimeter);      //divido el string con el delimeter
    if (start) *start++ = '\0';             //agrego un carácter de término al final del string (\0)
    return token;}                          //retorno el pointer a la lista de strings
  else if (!start) return NULL;             //retorno null si esque no hay un string
}
//Función complementaria a strtok, porque strtok tiene problemas al trabajar con entradas vacías de bases de datos (idea modificada de stack overflow)


typedef struct data {
	    int ID;
        int Geoname_ID;
        char Name[CITY];
        char Country_Code[3];
        char Country_Name[COUNTRY];
        int Population;
        int Elevation;
        char Timezone[100];
        char Coordinates[40];
	} city;

void distribute(char *info, city *Database){
    int column=0;
    while (info) {
        switch (column){
            case 0: Database->ID = atoi(info); break;
            case 1: Database->Geoname_ID = atoi(info); break;
            case 2: strcpy(Database->Name, info); break;
            case 3: strcpy(Database->Country_Code, info); break;
            case 4: strcpy(Database->Country_Name, info); break;
            case 5: Database->Population = atoi(info); break;
            case 6: Database->Elevation = atoi(info); break;
            case 7: strcpy(Database->Timezone, info); break;
            case 8: strcpy(Database->Coordinates, info); break;
        }
        info = nstrtok(NULL, ";");
        column++;
    }
}

int Population(const void *a, const void *b) {
    const city *cityA = (const city *)a;
    const city *cityB = (const city *)b;

    // Comparamos la población de las ciudades
    return cityB->Population - cityA->Population;
}
int Elevation(const void *a, const void *b) {
    const city *cityA = (const city *)a;
    const city *cityB = (const city *)b;

    // Comparamos la elevación de las ciudades
    return cityB->Elevation - cityA->Elevation;
}

int Latitude(const void *a, const void *b) {
    const city *cityA = (const city *)a;
    const city *cityB = (const city *)b;

    // Extraer la latitud de las coordenadas
    double latitudeA, latitudeB;
    sscanf(cityA->Coordinates, "%lf, %*f", &latitudeA);
    sscanf(cityB->Coordinates, "%lf, %*f", &latitudeB);

    // Comparar las latitudes
    if (latitudeA > latitudeB) {
        return -1; // ciudad A está más al norte
    } else if (latitudeA < latitudeB) {
        return 1; // ciudad B está más al norte
    } else {
        return 0; // Las latitudes son iguales
    }
}

int main ()
{
    /*if ( argc != 2 ) 
    {
        printf( "usage: %s filename", argv[0] );
    }
    else
    {
        FILE *file = fopen( argv[1], "r" );*/
        FILE * file=fopen("bd_chica.csv","r");
        if (file==0) printf( "Could not open file\n" );

        else{
            city *Database = (city *)malloc(146959 * sizeof(city));
            char storage[512];
            int row = 0;
            int column = 0;

            while (fgets(storage,512, file)) {
                column = 0;
                row++;
                if (row == 1) continue;     //me salto la primera línea
                char* info = nstrtok(storage, ";");
                if (row>1) distribute(info,&Database[row-2]); 
                }
                printf("\n");
            
            char entry[100];
            int k;
            row=row-1;
            while (1) {
                printf("Ingrese lo que desea consultar de la base de datos ([K] siendo la posición)\n(POBL [K], ELEV [K], LAT [K], [ciudad], SALIR): ");
                fgets(entry, sizeof(entry), stdin);
            
                if (!strncmp(entry, "POBL", 4)||!strncmp(entry, "pobl", 4)) {
                    sscanf(entry, "POBL %d", &k);
                    qsort(Database, row, sizeof(city), Population);
                    if (k > 0)
                        printf("La %dª ciudad por población es: %s, Población: %d\n\n", k, Database[k - 1].Name, Database[k - 1].Population);
                    else if (k < 0)
                        printf("La %dª ciudad por población (de menor población) es: %s, Población: %d\n\n", -k, Database[row + k].Name, Database[row + k].Population);

                }
                else if (strncmp(entry, "ELEV", 4) == 0) {
                    sscanf(entry, "ELEV %d", &k);
                    qsort(Database, row, sizeof(city), Elevation);
                    if (k > 0)
                        printf("La %dª ciudad por elevación es: %s, Elevación: %d\n\n", k, Database[k - 1].Name, Database[k - 1].Elevation);
                    else if (k < 0)
                        printf("La %dª ciudad por elevación (de menor elevación) es: %s, Elevación: %d\n\n", -k, Database[row + k].Name, Database[row + k].Elevation);
                } 
                else if (strncmp(entry, "LAT", 3) == 0) {
                    sscanf(entry, "LAT %d", &k);
                    qsort(Database, row, sizeof(city), Latitude);
                    if (k > 0)  printf("La %dª ciudad más al norte es: %s\n\n", k, Database[k - 1].Name);
                    else if (k < 0) printf("La %dª ciudad más al sur es: %s\n\n", -k, Database[row + k].Name);
                    else if (strncmp(entry, "SALIR", 5) == 0) break;
                }
                else {
                // Buscar la ciudad por nombre
                    char asked_city[CITY];
                    sscanf(entry, "%[^\n]", asked_city);
                    int found = 0;
                    for (int i = 0; i < row; i++) {
                        if (strcmp(Database[i].Name, asked_city) == 0) {
                            if (!found) {
                                printf("Se encontraron las siguientes ciudades con el nombre '%s':\n", asked_city);
                                found = 1;
                            }
                            printf("Datos de la ciudad:\n");
                            printf("Nombre: %s\n", Database[i].Name);
                            printf("País: %s\n", Database[i].Country_Name);
                            printf("Población: %d\n", Database[i].Population);
                            printf("Elevación: %d\n", Database[i].Elevation);
                            printf("Zona Horaria: %s\n", Database[i].Timezone);
                            printf("Coordenadas: %s\n", Database[i].Coordinates);
                            printf("\n");
                        }
                    }
                    if (!found) printf("Ciudad no encontrada.\n\n");
                }
            }
            free(Database);
            fclose(file);
        }
    return 0;
}