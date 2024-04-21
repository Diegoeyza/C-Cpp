#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAX_SIZE 146959
#define TAMANO_STRINGS 1000
#define TAMANO_LINEA 1000
//bdfinal tiene 146959 datos (reemplazar en el max), bd chica tiene 510 datos, (ya estoy considerando el +1)


//Defino el struct ciudad con los distintos parametros
typedef struct {
int id;
int geoname_id;
char name [TAMANO_STRINGS];
char country_code [TAMANO_STRINGS];
char country_name[TAMANO_STRINGS];
int population;
int elevation;
char timezone[TAMANO_STRINGS];
char coordinates[TAMANO_STRINGS];
}Ciudad;

void analisis_de_linea(char *linea, Ciudad *ciudad) {
    char *cursor = linea;
    char *inicio_de_campo = cursor;
    int indice_de_campo = 0;
    

    while (*cursor != '\0') {
        if (*cursor == ';' || *cursor == '\n' || *cursor == '\r') {
            *cursor = '\0';
            

            switch (indice_de_campo) {
                case 0:
                    ciudad->id = atoi(inicio_de_campo);
                    break;
                case 1:
                    ciudad->geoname_id = atoi(inicio_de_campo);
                    break;
                case 2:
                    strcpy(ciudad->name, inicio_de_campo);
                    break;
                case 3:
                    strcpy(ciudad->country_code, inicio_de_campo);
                    break;
                case 4:
                    strcpy(ciudad->country_name, inicio_de_campo);
                    break;
                case 5:
                    ciudad->population = atoi(inicio_de_campo);
                    break;
                case 6:
                    ciudad->elevation = atoi(inicio_de_campo);
                    break;
                case 7:
                    strcpy(ciudad->timezone, inicio_de_campo);
                    break;
                case 8:
                    strcpy(ciudad->coordinates, inicio_de_campo);
                    break;
            }

            inicio_de_campo = cursor + 1;
            indice_de_campo++;
        } 
        cursor++;
    }
}

int comparar_poblacion(const void *a, const void *b) {
    const Ciudad *ciudadA = (const Ciudad *)a;
    const Ciudad *ciudadB = (const Ciudad *)b;

    // Comparamos la población de las ciudades
    return ciudadB->population - ciudadA->population;
}
int comparar_elevacion(const void *a, const void *b) {
    const Ciudad *ciudadA = (const Ciudad *)a;
    const Ciudad *ciudadB = (const Ciudad *)b;

    // Comparamos la elevación de las ciudades
    return ciudadB->elevation - ciudadA->elevation;
}

int comparar_latitud(const void *a, const void *b) {
    const Ciudad *ciudadA = (const Ciudad *)a;
    const Ciudad *ciudadB = (const Ciudad *)b;

    // Extraer la latitud de las coordenadas
    double latitudA, latitudB;
    sscanf(ciudadA->coordinates, "%lf, %*f", &latitudA);//sscanf para leer la latitud de las coordenadas, ignoro lo que viene dsps
    sscanf(ciudadB->coordinates, "%lf, %*f", &latitudB);

    // Comparar las latitudes
    if (latitudA > latitudB) {
        return -1; // Ciudad A está más al norte
    } else if (latitudA < latitudB) {
        return 1; // Ciudad B está más al norte
    } else {
        return 0; // Las latitudes son iguales
    }
}


int main(int argc, char **argv) {
    FILE *entrada = fopen("bd_chica.csv", "r");
    char linea[TAMANO_LINEA];

    if (entrada == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    Ciudad *ciudades = (Ciudad *)malloc(MAX_SIZE * sizeof(Ciudad));
    if (ciudades == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    int ids = 0;

    // Leer cada línea del archivo y analizarla
    fgets(linea, sizeof(linea), entrada);
    while (fgets(linea, sizeof(linea), entrada)) {
        analisis_de_linea(linea, &ciudades[ids]);
        ids++;
    }

    fclose(entrada);

    printf("Se leyeron %d ciudades\n\n", ids);
    

    // Consultas en tiempo de ejecución
    char consulta[TAMANO_STRINGS];
    int k;
    while (1) {
        printf("Ingrese una consulta (POBL [K], ELEV [K], LAT [K], [ciudad], SALIR): ");
        fgets(consulta, sizeof(consulta), stdin);
      
        if (strncmp(consulta, "POBL", 4) == 0) {
            sscanf(consulta, "POBL %d", &k);
            qsort(ciudades, ids, sizeof(Ciudad), comparar_poblacion);
            if (k > 0)
                printf("La %dª ciudad por población es: %s, Población: %d\n", k, ciudades[k - 1].name, ciudades[k - 1].population);
            else if (k < 0)
                printf("La %dª ciudad por población (de menor población) es: %s, Población: %d\n", -k, ciudades[ids + k].name, ciudades[ids + k].population);
          
        } else if (strncmp(consulta, "ELEV", 4) == 0) {
            sscanf(consulta, "ELEV %d", &k);
            qsort(ciudades, ids, sizeof(Ciudad), comparar_elevacion);
            if (k > 0)
                printf("La %dª ciudad por elevación es: %s, Elevación: %d\n", k, ciudades[k - 1].name, ciudades[k - 1].elevation);
            else if (k < 0)
                printf("La %dª ciudad por elevación (de menor elevación) es: %s, Elevación: %d\n", -k, ciudades[ids + k].name, ciudades[ids + k].elevation);
          
        } else if (strncmp(consulta, "LAT", 3) == 0) {
            sscanf(consulta, "LAT %d", &k);
            qsort(ciudades, ids, sizeof(Ciudad), comparar_latitud);
            if (k > 0)
                printf("La %dª ciudad más al norte es: %s\n", k, ciudades[k - 1].name);
            else if (k < 0)
                printf("La %dª ciudad más al sur es: %s\n", -k, ciudades[ids + k].name);
        } else if (strncmp(consulta, "SALIR", 5) == 0) {
            break;
      } else {
          // Buscar la ciudad por nombre
          char ciudad_buscada[TAMANO_STRINGS];
          sscanf(consulta, "%[^\n]", ciudad_buscada); // Leer toda la línea
          int encontrado = 0;
          for (int i = 0; i < ids; i++) {
              if (strcmp(ciudades[i].name, ciudad_buscada) == 0) {
                  if (!encontrado) {
                      printf("Se encontraron las siguientes ciudades con el nombre '%s':\n", ciudad_buscada);
                      encontrado = 1;
                  }
                  printf("Datos de la ciudad:\n");
                  printf("Nombre: %s\n", ciudades[i].name);
                  printf("País: %s\n", ciudades[i].country_name);
                  printf("Población: %d\n", ciudades[i].population);
                  printf("Elevación: %d\n", ciudades[i].elevation);
                  printf("Zona Horaria: %s\n", ciudades[i].timezone);
                  printf("Coordenadas: %s\n", ciudades[i].coordinates);
                  printf("\n");
              }
          }
          if (!encontrado)
              printf("Ciudad no encontrada.\n");
      }
    }

    free(ciudades);

    return 0;
}