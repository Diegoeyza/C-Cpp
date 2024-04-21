#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{

        FILE * file=fopen("bd_chica.csv","r");
        if (file==0) printf( "Could not open file\n" );

        else{
            int row=0;
            char save[500];
            while(fgets(save,500,file)){
                row++;
            }
            printf("%d", row);
        }
        fclose(file);

        return 0;}