#include <stdio.h>

void Tablero(int Pieces[11][8]){
    char letters[]={"ABCDEFGHIJ  "};
    int grid[5][4]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    for (int l=0;l<12;l++){
        for (int c=0;c<4;c++){
            if (Pieces[l][c]!=0){
                grid[Pieces[l][c+4]-1][Pieces[l][c]-1]=l;  //creo una tabla con la ubicación de cada letra (esto se podría dar de antemano, pero preferí crearla para dar una mayor libertad de coordenadas)
            }
        }
    }
    for (int i=0;i<5;i++){

        for (int j=0;j<4;j++){
            if (i>0&&(grid[i-1][j]==grid[i][j]||((grid[i-1][j]==10&&grid[i][j]==11)||(grid[i-1][j]==11&&grid[i][j]==10)))){
                printf("+   ");
            }
            else{
                printf("+---");
            }
            }
        printf("+\n");
        for (int k=0;k<4;k++){
            if (k==0){
                printf("| %c ", letters[grid[i][k]]);
            }
            else if (grid[i][k]==grid[i][k-1]||((grid[i][k]==10&&grid[i][k-1]==11)||(grid[i][k]==11&&grid[i][k-1]==10))){
                printf("  %c ", letters[grid[i][k]]);
            }
            else{
                printf("| %c ", letters[grid[i][k]]);
            }
        }
        printf("|\n");

    }
    printf("+---+---+---+---+\n");
}

int main(){
int Pieces[12][8]={{1,1,0,0,1,2,0,0},{2,2,3,3,1,2,1,2},{4,4,0,0,1,2,0,0},{1,0,0,0,3,0,0,0},{2,3,0,0,3,3,0,0},{4,0,0,0,3,0,0,0},{1,1,0,0,4,5,0,0},{2,0,0,0,4,0,0,0},{3,0,0,0,4,0,0,0},{4,4,0,0,4,5,0,0},{2,0,0,0,5,0,0,0},{3,0,0,0,5,0,0,0}}; //primeras 4 coordenadas de cada sublista es la posición en x de cada letra y las otras 4 la posición en y
Tablero(Pieces);
int exit=0;
char ficha, sentido;
int cantidad;
while ((Pieces[1][0]!=2 && Pieces[1][1]!=2 && Pieces[1][2]!=3 && Pieces[1][3]!=3 && Pieces[1][4]!=4 && Pieces[1][5]!=4 && Pieces[1][6]!=5 && Pieces[1][7]!=5) || exit!=1){
    printf("Escriba la pieza que desea mover (a,b,c,d,e,f,g,h,i,j), la dirección (n,s,e,w) y la cantidad de movimientos (1 o 2). Si desea terminar escriba 0 como movimiento: ");
    scanf("%c%c%d%*c", &ficha, &sentido, &cantidad);  //use el %*c para guardar como un input la tecla enter pero sin almacenarla en ni una parte (si no lo usaba el scanf se saltaba un ciclo)
    if (cantidad==0){
        exit=1;

    }
    else if ((cantidad==1 || cantidad==2)&&(ficha=='a'||ficha=='A'||ficha=='b'||ficha=='B'||ficha=='c'||ficha=='C'||ficha=='d'||ficha=='D'||ficha=='e'||ficha=='E'||ficha=='f'||ficha=='F'||ficha=='g'||ficha=='G'||ficha=='h'||ficha=='H'||ficha=='i'||ficha=='I'||ficha=='j'||ficha=='J')&&(sentido=='n'||sentido=='N'||sentido=='s'||sentido=='S'||sentido=='e'||sentido=='E'||sentido=='w'||sentido=='W')){
         
    }
    else{
        printf("\nInstrucción incorrecta \n");

    }
}
return 0;
}