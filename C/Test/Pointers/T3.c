#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Data {
	    int **ID;
        char ***Name;
        int **Country_Code;
        char ***Country_Name;
        int **Population;
        int **Elevation;
        int **Timezone;
        int **Coordinates;
	} *city;

int main(){
    struct Data data;
    city = &data;
    

    return 0;

    
}
