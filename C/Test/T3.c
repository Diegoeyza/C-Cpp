#include <stdio.h>


//variables a usar a lo largo del código

/*
int A[]={2,2,3,3,1,2,1,2};
int B[]={2,3,1,2};
int C[]={4,4,1,2};
int D[]={1,1,3,3};
int E[]={2,3,3,3};
int F[]={4,4,3,3};
int G[]={1,1,4,5};
int H[]={2,2,4,4};
int I[]={4,4,4,5};
*/

//int l=0; l<9; l++
//int c=0; c<2; c++
void tablero(char Letters[],int Pieces[10][8]){
    int columnc=1;
    int rowc=1;
    int counter=0;
    int horizontal0[]={0,0,0,0};
    int horizontal1[]={0,0,0,0};
    printf("+---------------+\n");
    while (rowc<6){
        for (int c=0; c<4; c++){ //l de letra
        counter++;
            for (int l=0; l<12; l++){  //c de columna
                if (Pieces[l][c]==columnc && Pieces[l][c+4]==rowc){
                    if (columnc==1 && l<10){    //reviso si esque es la primera columna para poner un |
                        printf("| %c ", Letters[l]);
                        columnc++;  
                    }
                    else if (columnc==4 && l==1){   //reviso si es la última columna y si antes tiene una letra B para cerrar con |
                        printf("  %c |\n", Letters[l]);
                        columnc=1;
                        }
                        rowc++;
                        
                    }
                    else if (columnc==4 && l!=1 && l<10 && Pieces[l][1]==Pieces[l][0] && Pieces[l][4]==Pieces[l][5]){   //reviso si es la última columna y si antes tiene una letra distinta de B pero igual para cerrar con |
                        printf("  %c |\n", Letters[l]);
                        columnc=1;
                        rowc++;
                    }
                    else if (columnc==4 && l<10){   //reviso si es la última columna para cerrar con |
                        printf("| %c |\n", Letters[l]);
                        columnc=1;
                        rowc++;
                        
                    }
                    else if (c==1 && l!=1 && l<10 && Pieces[l][1]==Pieces[l][0]+1 && Pieces[l][4]==Pieces[l][5]){ //reviso si la letra anterior era la misma
                        printf("  %c ", Letters[l]);
                        columnc++;
                        
                    }
                    else if ((c==2||c==3) && l==1 && Pieces[l][c]==Pieces[l][c-2]+1){
                        printf("  %c ", Letters[l]);
                        columnc++;
                        
                    }
                    else if (l<10){
                        columnc++;
                        printf("| %c ", Letters[l]);
                    }
                    else if (l>=10 && columnc==1){
                        printf("|   ");
                        columnc++;
                    }
                    else if (l>=10 && columnc==4){
                        printf("|   |");
                        columnc=1;
                        rowc++;
                    }
                    else if (c==0 && l==10 && Pieces[10][0]==Pieces[11][0]+1){
                        printf("    ");
                        columnc++;
                    }
                    else if (c==0 && l==11 && Pieces[11][0]==Pieces[10][0]+1){
                        printf("    ");
                        columnc++;
                    }
                    else if (l>=10){
                        printf("|   ");
                        columnc++;
                    }


                }    

            }
        }
    }
int main(){
    int row[]={0,0,0,0,0,0,0,0,0}; //0 es no, 1 es si, si esque una letra está en la fila deseada, cambio su valor referencial (1er valor es A, segundo es B, etc) por un 1 en esta lista
    char movement;
    int x;
    int y;
    int Pieces[12][8]={{1,1,0,0,1,2,0,0},{2,2,3,3,1,2,1,2},{4,4,0,0,1,2,0,0},{1,0,0,0,3,0,0,0},{2,3,0,0,3,3,0,0},{4,0,0,0,3,0,0,0},{1,1,0,0,4,5,0,0},{2,0,0,0,4,0,0,0},{3,0,0,0,4,0,0,0},{4,4,0,0,4,5,0,0},{2,0,0,0,5,0,0,0},{3,0,0,0,5,0,0,0}}; //primeras 2 coordenadas de cada sublista es la posición en x de cada letra y las otras 2 la posición en y
    char Letters[]={"ABCDEFGHIJ"};    
    //scanf("%c",&movement);
    //printf("%d",movement);

    tablero(Letters, Pieces);
    printf("end");


    return 0;
}
