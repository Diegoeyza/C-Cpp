#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CITY 190 //el nombre real de bangkok
#define COUNTRY 58 //UK

char* nstrtok(char *string, const char *delimeter){
    static char *start = NULL;
    char *token = NULL; 
    if (string) start = string;               //asigno la dirección de memoria del string a utilizar a la variable en la función
    if (!start) return NULL;                  //retorno null si esque no hay un string
    token = start;                            //verifico si esque hay un string que dividir o si es null
    start = strpbrk(start, delimeter);        //divido el string con el delimeter
    if (start) *start++ = '\0';               //agrego un carácter de término al final del string (\0)
    return token;}                            //retorno el pointer a la lista de strings
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

int Alphabetical(const void *a,const void *b){
    const city *cityA=(const city *)a;
    const city *cityB=(const city *)b;
    if (cityB->Name[0]<cityA->Name[0]) return 1;                                                                                //comparo la primera letra de ambos
    else if ((cityB->Name[0]==cityA->Name[0])&&(cityB->Name[1]<cityA->Name[1])) return 1;                                       //comparo la segunda letra de ambos
    else if ((cityB->Name[0]==cityA->Name[0])&&(cityB->Name[1]==cityA->Name[1])&&(cityB->Name[2]<cityA->Name[2])) return 1;     //comparo la tercera letra de ambos
    else return 0;
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

int main(int argc, char **argv) {
    if (argc == 1){
        printf("\nNo se ha entregado el nombre de un archivo\n");
        return 0;}
    
    FILE * file=fopen(argv[1],"r");  

    if (file==0) printf( "No se ha podido abrir el archivo\n" );
    else{
        char storage[512];
        int row = 0;
        int frow=1;
        while(fgets(storage,512,file)){
            frow++;
        }
        printf("Se registraron %d ciudades\n", frow-2);
        rewind(file);
        city *Database = (city *)malloc(frow*sizeof(city));
        while (fgets(storage,512, file)) {
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
            printf("Ingrese lo que desea consultar de la base de datos (para consultar comandos escriba COMANDOS)\n(POBL [K], ELEV [K], LAT [K], ALPH [K], [ciudad], SALIR): ");
            fgets(entry, sizeof(entry), stdin);
        
            if (!strncmp(entry, "POBL", 4)||!strncmp(entry, "pobl", 4)) {
                sscanf(entry, "POBL %d", &k);
                qsort(Database, row, sizeof(city), Population);
                if (k > 0 && k <= row)
                    printf("La %dª ciudad por población es: %s, Población: %d\n\n", k, Database[k - 1].Name, Database[k - 1].Population);
                else if (k < 0&& k >= -row)
                    printf("La %dª ciudad por población (de menor población) es: %s, Población: %d\n\n", -k, Database[row + k].Name, Database[row + k].Population);
                else printf("El K ingresado está fuera del rango de la base de datos de tamaño %d\n\n",row);
            }
            else if (strncmp(entry, "ELEV", 4) == 0) {
                sscanf(entry, "ELEV %d", &k);
                qsort(Database, row, sizeof(city), Elevation);
                if (k > 0 && k <= row)
                    printf("La %dª ciudad por elevación es: %s, Elevación: %d\n\n", k, Database[k - 1].Name, Database[k - 1].Elevation);
                else if (k < 0&& k >= -row)
                    printf("La %dª ciudad por elevación (de menor elevación) es: %s, Elevación: %d\n\n", -k, Database[row + k].Name, Database[row + k].Elevation);
                else printf("El K ingresado está fuera del rango de la base de datos de tamaño %d\n\n",row);
            } 
            else if (strncmp(entry, "LAT", 3) == 0) {
                sscanf(entry, "LAT %d", &k);
                qsort(Database, row, sizeof(city), Latitude);
                if (k > 0 && k <= row)  printf("La %dª ciudad más al norte es: %s\n\n", k, Database[k - 1].Name);
                else if (k < 0&& k >= -row) printf("La %dª ciudad más al sur es: %s\n\n", -k, Database[row + k].Name);
                else printf("El K ingresado está fuera del rango de la base de datos de tamaño %d\n\n",row);
            }
            else if (strncmp(entry, "ALPH", 4) == 0) {
                sscanf(entry, "ALPH %d", &k);
                qsort(Database, row, sizeof(city), Alphabetical);
                if (k > 0 && k <= row)
                    printf("La %dª ciudad por orden alfabético es es: %s\n\n", k, Database[k - 1].Name);
                else if (k < 0&& k >= -row)
                    printf("La %dª ciudad por orden alfabétido (de atrás hacia delante) es: %s\n\n", -k, Database[row + k].Name);
                else printf("El K ingresado está fuera del rango de la base de datos de tamaño %d\n\n",row);
            }
            //Lista de comandos
            else if ((strncmp(entry, "COMANDOS", 8) == 0)||(strncmp(entry, "comandos", 8) == 0)) printf("\n[K] es un entero, si se ingresa un -, se considera que es invertido el orden\n- POBL [k]: Busco la ciudad con la K-esima población más alta\n- ELEV [k]: Busco la ciudad con la K-esima elevación más alta\n- LAT [k]: Busco la ciudad con la K-esima latitud más alta\n- ALPH [k]: Busco la ciudad con la K-esima población alfabética (si hay una sin nombre esta será la primera)\n- ciudad: Busco la ciudad en cuestión y doy sus datos\n\n");
            else if ((strncmp(entry, "SALIR", 5) == 0)||(strncmp(entry, "salir", 5) == 0)) break;
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
                        printf("Elevación: %d metros sobre el nivel del mar\n", Database[i].Elevation);
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