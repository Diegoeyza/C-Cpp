#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CITY 190 //el nombre real de bangkok
#define COUNTRY 58 //UK

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

void distribute(char **info, city *Database,int row){
    int column=0;
    while (info) {
        switch (column){
            case 0: Database->ID = atoi(info); break;
            case 1: printf("Geoname ID: "); break;
            case 2: printf("City: "); break;
            case 3: printf("Country Code: "); break;
            case 4: printf("Countryname: "); break;
            case 5: printf("Population: "); break;
            case 6: printf("Elevation: "); break;
            case 7: printf("Timezone: "); break;
            case 8: printf("Coordinates: "); break;
        }
        info = strtok(NULL, ";");
        column++;

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
    city *Database = (city *)malloc(1000 * sizeof(city));


        if ( file == 0 )
        {
            printf( "Could not open file\n" );
        }
        else{
            char storage[512];
            int row = 0;
            int column = 0;
        while (fgets(storage,512, file)) {
            column = 0;
            row++;
            if (row == 1) continue;     //me salto la primera línea
            char* info = strtok(storage, ";");
            while (info) {
                switch (column){
                    case 1: printf("Geoname ID: "); break;
                    case 2: printf("City: "); break;
                    case 3: printf("Country Code: "); break;
                    case 4: printf("Countryname: "); break;
                    case 5: printf("Population: "); break;
                    case 6: printf("Elevation: "); break;
                    case 7: printf("Timezone: "); break;
                    case 8: printf("Coordinates: "); break;
                }     

                
                if (column!=0) printf("%s\n", info);
                info = strtok(NULL, ";");
                column++;
            }
            printf("\n");
        }
        free(Database);
 
        fclose(file);
    }
    return 0;
}
