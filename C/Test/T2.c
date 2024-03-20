#include <stdio.h>
#include <stdio.h>

int id(piece){  //funcion para asignarle un valor a la letra que entrega el usuario
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
    else{       //en el caso de que la letra ingresada no sea una registrada
      num=100;
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

int win=0;
int exit=0;
char piece, direction;
int ammount;
while (win!=1 && exit!=1){
    printf("Escriba la pieza que desea mover (a,b,c,d,e,f,g,h,i,j), la dirección (n,s,e,w) y la cantidad de movimientos (1 o 2). Si desea terminar escriba 0 como movimiento: ");
    scanf("%c%c%d%*c", &piece, &direction, &ammount);  //use el %*c para guardar como un input la tecla enter pero sin almacenarla en ni una parte (si no lo usaba el scanf se saltaba un ciclo)
    int npiece=id(piece);
    if (ammount==0){
        exit=1;
        printf("Game Over :D");

    }
    else if ((ammount==1 || ammount==2)&&(npiece==0||npiece==1||npiece==2||npiece==3||npiece==4||npiece==5||npiece==6||npiece==7||npiece==8||npiece==9)&&(direction=='n'||direction=='N'||direction=='s'||direction=='S'||direction=='e'||direction=='E'||direction=='w'||direction=='W')){
        int bank=0;
        if (npiece==3||npiece==5||npiece==7||npiece==8){  //el script para mover las piezas de 1x1
            if (direction=='n'||direction=='N'){
                if (ammount==1){
                    if (Pieces[10][4]==Pieces[npiece][4]-1&&Pieces[10][0]==Pieces[npiece][0]&&Pieces[npiece][4]-1!=0){
                        bank=Pieces[10][4];
                        Pieces[10][4]=Pieces[npiece][4];
                        Pieces[npiece][4]=bank;
                    }
                    else if (Pieces[11][4]==Pieces[npiece][4]-1&&Pieces[11][0]==Pieces[npiece][0]&&Pieces[npiece][4]-1!=0){
                        bank=Pieces[11][4];
                        Pieces[11][4]=Pieces[npiece][4];
                        Pieces[npiece][4]=bank;
                    }
                    else{
                        printf("Movimiento no válido");
                    }
                }
                else if (ammount==2){
                    if ((Pieces[10][4]==Pieces[npiece][4]-1&&Pieces[npiece][4]-2==Pieces[11][4])||(Pieces[11][4]==Pieces[npiece][4]-1&&Pieces[npiece][4]-2==Pieces[10][4])&&Pieces[npiece][4]+2>0){
                        if (Pieces[10][4]>Pieces[11][4]){
                            bank=Pieces[11][4];
                            Pieces[11][4]=Pieces[npiece][4];
                            Pieces[npiece][4]=bank;
                        }
                        else if (Pieces[10][4]<Pieces[11][4]){
                            bank=Pieces[10][4];
                            Pieces[10][4]=Pieces[npiece][4];
                            Pieces[npiece][4]=bank;
                        }
                        else{
                            printf("Error");
                        }
                    }
                    else{
                        printf("Movimiento no válido");
                    }
                }
            }


            else if (direction=='s'||direction=='S'){
                if (ammount==1){
                    if (Pieces[10][4]==Pieces[npiece][4]+1&&Pieces[10][0]==Pieces[npiece][0]&&Pieces[npiece][4]+1!=6){
                        bank=Pieces[10][4];
                        Pieces[10][4]=Pieces[npiece][4];
                        Pieces[npiece][4]=bank;
                    }
                    else if (Pieces[11][4]==Pieces[npiece][4]+1&&Pieces[11][0]==Pieces[npiece][0]&&Pieces[npiece][4]+1!=6){
                        bank=Pieces[11][4];
                        Pieces[11][4]=Pieces[npiece][4];
                        Pieces[npiece][4]=bank;
                    }
                    else{
                        printf("Movimiento no válido");
                    }
                }
                else if (ammount==2){
                    if ((Pieces[10][4]==Pieces[npiece][4]+1&&Pieces[npiece][4]+2==Pieces[11][4])||(Pieces[11][4]==Pieces[npiece][4]+1&&Pieces[npiece][4]+2==Pieces[10][4])&&Pieces[npiece][4]+2<6){
                        if (Pieces[10][4]<Pieces[11][4]){
                            bank=Pieces[11][4];
                            Pieces[11][4]=Pieces[npiece][4];
                            Pieces[npiece][4]=bank;
                        }
                        else if (Pieces[10][4]>Pieces[11][4]){
                            bank=Pieces[10][4];
                            Pieces[10][4]=Pieces[npiece][4];
                            Pieces[npiece][4]=bank;
                        }
                        else{
                            printf("Error");
                        }
                    }
                    else{
                        printf("Movimiento no válido");
                    }
                }
            }
            else if (direction=='e'||direction=='E'){
                if (ammount==1){
                    if (Pieces[10][0]==Pieces[npiece][0]+1&&Pieces[10][4]==Pieces[npiece][4]&&Pieces[npiece][0]+1!=5){
                        bank=Pieces[10][0];
                        Pieces[10][0]=Pieces[npiece][0];
                        Pieces[npiece][0]=bank;
                    }
                    else if (Pieces[11][0]==Pieces[npiece][0]+1&&Pieces[11][4]==Pieces[npiece][4]&&Pieces[npiece][0]+1!=5){
                        bank=Pieces[11][0];
                        Pieces[11][4]=Pieces[npiece][0];
                        Pieces[npiece][0]=bank;
                    }
                    else{
                        printf("Movimiento no válido");
                    }
                }
                else if (ammount==2){
                    if ((Pieces[10][0]==Pieces[npiece][0]+1&&Pieces[npiece][0]+2==Pieces[11][0])||(Pieces[11][0]==Pieces[npiece][0]+1&&Pieces[npiece][0]+2==Pieces[10][0])&&Pieces[npiece][0]+2<5){
                        if (Pieces[10][0]<Pieces[11][0]){
                            bank=Pieces[11][0];
                            Pieces[11][0]=Pieces[npiece][0];
                            Pieces[npiece][0]=bank;
                        }
                        else if (Pieces[10][0]>Pieces[11][0]){
                            bank=Pieces[10][0];
                            Pieces[10][0]=Pieces[npiece][0];
                            Pieces[npiece][0]=bank;
                        }
                        else{
                            printf("Error");
                        }
                    }
                    else{
                        printf("Movimiento no válido");
                    }
                }
            }
            else if (direction=='w'||direction=='W'){
                if (ammount==1){
                    if (Pieces[10][0]==Pieces[npiece][0]-1&&Pieces[10][4]==Pieces[npiece][4]&&Pieces[npiece][0]-1!=0){
                        bank=Pieces[10][0];
                        Pieces[10][0]=Pieces[npiece][0];
                        Pieces[npiece][0]=bank;
                    }
                    else if (Pieces[11][0]==Pieces[npiece][0]-1&&Pieces[11][4]==Pieces[npiece][4]&&Pieces[npiece][0]-1!=0){
                        bank=Pieces[11][0];
                        Pieces[11][0]=Pieces[npiece][0];
                        Pieces[npiece][0]=bank;
                    }
                    else{
                        printf("Movimiento no válido");
                    }
                }
                else if (ammount==2){
                    if ((Pieces[10][0]==Pieces[npiece][0]-1&&Pieces[npiece][0]-2==Pieces[11][0])||(Pieces[11][0]==Pieces[npiece][0]-1&&Pieces[npiece][0]-2==Pieces[10][0])&&Pieces[npiece][0]-2>0){
                        if (Pieces[10][0]>Pieces[11][0]){
                            bank=Pieces[11][0];
                            Pieces[11][0]=Pieces[npiece][0];
                            Pieces[npiece][0]=bank;
                        }
                        else if (Pieces[10][0]<Pieces[11][0]){
                            bank=Pieces[10][0];
                            Pieces[10][0]=Pieces[npiece][0];
                            Pieces[npiece][0]=bank;
                        }
                        else{
                            printf("Error");
                        }
                    }
                    else{
                        printf("Movimiento no válido");
                    }
                }
            }
    }



}
    else{
        printf("\nInstrucción incorrecta \n");

    }
    if (exit!=1){
        printf("\n");
        Tablero(Pieces);  //printeo el tablero luego de cada turno
        printf("\n");
    }
    
    if (Pieces[1][1]==2 && Pieces[1][3]==3 && Pieces[1][5]==5 && Pieces[1][7]==5){
        win=1;
        printf("You Win!! :D");
    }
}

return 0;
}