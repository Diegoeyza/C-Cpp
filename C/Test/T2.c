#include <stdio.h>
#include <stdio.h>

int id(piece){
    int num;
    if (piece=='a'||piece=='A'){
        num=0;
        return num;
    }
        else if (piece=='b'||piece=='B'){
        num=1;
        return num;
    }
        else if (piece=='c'||piece=='C'){
        num=2;
        return num;
    }
        else if (piece=='d'||piece=='D'){
        num=3;
        return num;
    }
        else if (piece=='e'||piece=='E'){
        num=4;
        return num;
    }
        else if (piece=='f'||piece=='F'){
        num=5;
        return num;
    }
        else if (piece=='g'||piece=='G'){
        num=6;
        return num;
    }
        else if (piece=='h'||piece=='H'){
        num=7;
        return num;
    }
        else if (piece=='i'||piece=='I'){
        num=8;
        return num;
    }
        else if (piece=='j'||piece=='J'){
        num=9;
        return num;
    }
}

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
char piece, direction;
int ammount;
while ((Pieces[1][0]!=2 && Pieces[1][1]!=2 && Pieces[1][2]!=3 && Pieces[1][3]!=3 && Pieces[1][4]!=4 && Pieces[1][5]!=4 && Pieces[1][6]!=5 && Pieces[1][7]!=5) || exit!=1){
    printf("Escriba la pieza que desea mover (a,b,c,d,e,f,g,h,i,j), la dirección (n,s,e,w) y la cantidad de movimientos (1 o 2). Si desea terminar escriba 0 como movimiento: ");
    scanf("%c%c%d%*c", &piece, &direction, &ammount);  //use el %*c para guardar como un input la tecla enter pero sin almacenarla en ni una parte (si no lo usaba el scanf se saltaba un ciclo)
    if (ammount==0){
        exit=1;

    }
    else if ((ammount==1 || ammount==2)&&(piece=='a'||piece=='A'||piece=='b'||piece=='B'||piece=='c'||piece=='C'||piece=='d'||piece=='D'||piece=='e'||piece=='E'||piece=='f'||piece=='F'||piece=='g'||piece=='G'||piece=='h'||piece=='H'||piece=='i'||piece=='I'||piece=='j'||piece=='J')&&(direction=='n'||direction=='N'||direction=='s'||direction=='S'||direction=='e'||direction=='E'||direction=='w'||direction=='W')){
        int bank=0;
        int pieza=id(piece);
        if (pieza==3||pieza==5||pieza==7||pieza==8){
            if (direction=='n'||direction=='N'){
                if (ammount==1){
                    if (Pieces[10][4]==Pieces[pieza][4]-1&&Pieces[pieza][4]-1!=0){
                        Pieces [10][4]=bank;
                        Pieces[10][4]=Pieces[pieza][4];
                        Pieces[pieza][4]=bank;
                    }
                    else if (Pieces[11][4]==Pieces[pieza][4]-1&&Pieces[pieza][4]-1!=0){
                        Pieces [11][4]=bank;
                        Pieces[11][4]=Pieces[pieza][4];
                        Pieces[pieza][4]=bank;
                    }
                    else{
                        printf("Movimiento no válido");
                    }
                }
                else if (ammount==2){
                    if ((Pieces[10][4]==Pieces[pieza][4]-1&&Pieces[pieza][4]-2==Pieces[11][4])||(Pieces[11][4]==Pieces[pieza][4]-1&&Pieces[pieza][4]-2==Pieces[10][4])&&Pieces[pieza][4]+2>0)
                        if (Pieces[10][4]>Pieces[11][4]){
                            Pieces [11][4]=bank;
                            Pieces[11][4]=Pieces[pieza][4];
                            Pieces[pieza][4]=bank;
                        }
                        else if (Pieces[10][4]<Pieces[11][4]){
                            Pieces [10][4]=bank;
                            Pieces[10][4]=Pieces[pieza][4];
                            Pieces[pieza][4]=bank;
                        }
                        else{
                            printf("Error");
                        }
                }
            }


            else if (direction=='s'||direction=='S'){
            }
            else if (direction=='e'||direction=='E'){
            }
            else if (direction=='w'||direction=='W'){
            }
    }



}
    else{
        printf("\nInstrucción incorrecta \n");

    }
}

return 0;
}