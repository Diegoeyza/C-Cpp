#include <stdio.h>

int id(int piece){  //funcion para asignarle un valor a la letra que entrega el usuario, lo podrìa hacer usando el valor de la tabla del carácter y restarle A, pero esto fallaría si ingreso minúsculas
    if (piece=='a'||piece=='A'){
        return 0;
    }
        else if (piece=='b'||piece=='B'){
        return 1;
    }
        else if (piece=='c'||piece=='C'){
        return 2;
    }
        else if (piece=='d'||piece=='D'){
        return 3;
    }
        else if (piece=='e'||piece=='E'){
        return 4;
    }
        else if (piece=='f'||piece=='F'){
        return 5;
    }
        else if (piece=='g'||piece=='G'){
        return 6;
    }
        else if (piece=='h'||piece=='H'){
        return 7;
    }
        else if (piece=='i'||piece=='I'){
        return 8;
    }
        else if (piece=='j'||piece=='J'){
        return 9;
    }
    else{       //en el caso de que la letra ingresada no sea una registrada
      return 100;
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
char input[20];
while (win!=1 && exit!=1){
    printf("Escriba la pieza que desea mover (a,b,c,d,e,f,g,h,i,j), la dirección (n,s,e,w) y la cantidad de movimientos (1 o 2) (dejarlo en blanco implica 1). Si desea terminar ingrese 0: ");
    scanf("%s", input);
    char piece=input[0];
    char direction=input[1];
    char ammount=input[2];
    int npiece=id(piece);
    if (ammount=='0'||direction=='0'||piece=='0'){
        exit=1;
        printf("Game Over :D\n");

    }
    else if ((ammount=='1' || ammount=='2' || ammount=='\0')&&(npiece==0||npiece==1||npiece==2||npiece==3||npiece==4||npiece==5||npiece==6||npiece==7||npiece==8||npiece==9)&&(direction=='n'||direction=='N'||direction=='s'||direction=='S'||direction=='e'||direction=='E'||direction=='w'||direction=='W')){
        int bank=0;
        if (npiece==3||npiece==5||npiece==7||npiece==8){  //el script para mover las piezas de 1x1
            if (direction=='n'||direction=='N'){
                if (ammount=='1' || ammount=='\0'){
                    if (Pieces[10][4]==Pieces[npiece][4]-1&&Pieces[10][0]==Pieces[npiece][0]){
                    Pieces[10][4]++;
                    Pieces[npiece][4]--;
                    }
                    else if (Pieces[11][4]==Pieces[npiece][4]-1&&Pieces[11][0]==Pieces[npiece][0]){
                        Pieces[11][4]++;
                        Pieces[npiece][4]--;
                    }
                    else{
                        printf("\n\nMovimiento no válido\n\n");
                    }
                }
                else if (ammount=='2'){
                    if ((Pieces[10][4]==Pieces[npiece][4]-1&&Pieces[npiece][4]-2==Pieces[11][4])||(Pieces[11][4]==Pieces[npiece][4]-1&&Pieces[npiece][4]-2==Pieces[10][4])){
                        if (Pieces[10][4]>Pieces[11][4]){
                            Pieces[11][4]+=2;
                            Pieces[npiece][4]-=2;
                        }
                        else if (Pieces[10][4]<Pieces[11][4]){

                            Pieces[10][4]+=2;
                            Pieces[npiece][4]-=2;
                        }
                    }
                    else{
                        printf("\nMovimiento no válido\n");
                    }
                }
            }
            else if (direction=='s'||direction=='S'){
                if (ammount=='1' || ammount=='\0'){
                    if (Pieces[10][4]==Pieces[npiece][4]+1&&Pieces[10][0]==Pieces[npiece][0]){
                        Pieces[10][4]--;
                        Pieces[npiece][4]++;
                    }
                    else if (Pieces[11][4]==Pieces[npiece][4]+1&&Pieces[11][0]==Pieces[npiece][0]){
                        Pieces[11][4]--;
                        Pieces[npiece][4]++;
                    }
                    else{
                        printf("\nMovimiento no válido\n");
                    }
                }
                else if (ammount=='2'){
                    if ((Pieces[10][4]==Pieces[npiece][4]+1&&Pieces[npiece][4]+2==Pieces[11][4])||(Pieces[11][4]==Pieces[npiece][4]+1&&Pieces[npiece][4]+2==Pieces[10][4])){
                        if (Pieces[10][4]<Pieces[11][4]){
                            Pieces[11][4]-=2;
                            Pieces[npiece][4]+=2;
                        }
                        else if (Pieces[10][4]>Pieces[11][4]){
                            Pieces[10][4]-=2;
                            Pieces[npiece][4]+=2;
                        }
                    }
                    else{
                        printf("\nMovimiento no válido\n");
                    }
                }
            }
            else if (direction=='e'||direction=='E'){
                if (ammount=='1' || ammount=='\0'){
                    if (Pieces[10][0]==Pieces[npiece][0]+1&&Pieces[10][4]==Pieces[npiece][4]){
                        Pieces[10][0]--;
                        Pieces[npiece][0]++;
                    }
                    else if (Pieces[11][0]==Pieces[npiece][0]+1&&Pieces[11][4]==Pieces[npiece][4]){
                        Pieces[11][0]--;
                        Pieces[npiece][0]++;
                    }
                    else{
                        printf("\nMovimiento no válido\n");
                    }
                }
                else if (ammount=='2'){
                    if ((Pieces[10][0]==Pieces[npiece][0]+1&&Pieces[npiece][0]+2==Pieces[11][0])||(Pieces[11][0]==Pieces[npiece][0]+1&&Pieces[npiece][0]+2==Pieces[10][0])){
                        if (Pieces[10][0]<Pieces[11][0]){
                            Pieces[11][0]-=2;
                            Pieces[npiece][0]+=2;
                        }
                        else if (Pieces[10][0]>Pieces[11][0]){
                            Pieces[10][0]-=2;
                            Pieces[npiece][0]+=2;
                        }
                    }
                    else{
                        printf("\nMovimiento no válido\n");
                    }
                }
            }
            else if (direction=='w'||direction=='W'){
                if (ammount=='1' || ammount=='\0'){
                    if (Pieces[10][0]==Pieces[npiece][0]-1&&Pieces[10][4]==Pieces[npiece][4]){
                        Pieces[10][0]++;
                        Pieces[npiece][0]--;
                    }
                    else if (Pieces[11][0]==Pieces[npiece][0]-1&&Pieces[11][4]==Pieces[npiece][4]){
                        Pieces[11][0]++;
                        Pieces[npiece][0]--;
                    }
                    else{
                        printf("\nMovimiento no válido\n");
                    }
                }
                else if (ammount=='2'){
                    if ((Pieces[10][0]==Pieces[npiece][0]-1&&Pieces[npiece][0]-2==Pieces[11][0])||(Pieces[11][0]==Pieces[npiece][0]-1&&Pieces[npiece][0]-2==Pieces[10][0])){
                        if (Pieces[10][0]>Pieces[11][0]){
                            Pieces[11][0]+=2;
                            Pieces[npiece][0]-=2;
                        }
                        else if (Pieces[10][0]<Pieces[11][0]){
                            Pieces[10][0]+=2;
                            Pieces[npiece][0]-=2;
                        }
                    }
                    else{
                        printf("\nMovimiento no válido\n");
                    }
                }
            }
        }
        else if (npiece==0||npiece==2||npiece==6||npiece==9){  //el script para mover las piezas de 2x1
            if (direction=='n'||direction=='N'){
                if (ammount=='1' || ammount=='\0'){
                    if (Pieces[10][4]==Pieces[npiece][4]-1&&Pieces[10][0]==Pieces[npiece][0]){
                        Pieces[10][4]+=2;
                        Pieces[npiece][4]--;
                        Pieces[npiece][5]--;
                    }
                    else if (Pieces[11][4]==Pieces[npiece][4]-1&&Pieces[11][0]==Pieces[npiece][0]){
                        Pieces[11][4]+=2;
                        Pieces[npiece][4]--;
                        Pieces[npiece][5]--;
                    }
                    else{
                        printf("\n\nMovimiento no válido\n\n");
                    }
                }   
                else if (ammount=='2'){
                    if ((Pieces[10][4]==Pieces[npiece][4]-2&&Pieces[npiece][5]-2==Pieces[11][4])||(Pieces[11][4]==Pieces[npiece][4]-2&&Pieces[npiece][5]-2==Pieces[10][4])){
                        if (Pieces[10][4]>Pieces[11][4]){
                            Pieces[11][4]+=2;
                            Pieces[10][4]+=2;
                            Pieces[npiece][4]-=2;
                            Pieces[npiece][5]-=2;
                        }
                        else if (Pieces[10][4]<Pieces[11][4]){
                            Pieces[11][4]+=2;
                            Pieces[10][4]+=2;
                            Pieces[npiece][4]-=2;
                            Pieces[npiece][5]-=2;
                        }
                    }
                    else{
                        printf("\nMovimiento no válido\n");
                    }
                }
            }
            else if (direction=='s'||direction=='S'){
                if (ammount=='1' || ammount=='\0'){
                    if (Pieces[10][4]==Pieces[npiece][5]+1&&Pieces[10][0]==Pieces[npiece][0]){
                        Pieces[10][4]-=2;
                        Pieces[npiece][4]++;
                        Pieces[npiece][5]++;
                    }
                    else if (Pieces[11][4]==Pieces[npiece][5]+1&&Pieces[11][0]==Pieces[npiece][0]){
                        Pieces[11][4]-=2;
                        Pieces[npiece][4]++;
                        Pieces[npiece][5]++;
                    }
                    else{
                        printf("\nMovimiento no válido\n");
                    }
                }
                else if (ammount=='2'){
                    if ((Pieces[10][4]==Pieces[npiece][4]+2 && Pieces[11][4]==Pieces[npiece][5]+2)||(Pieces[11][4]==Pieces[npiece][4]+2 && Pieces[10][4]==Pieces[npiece][5]+2)){
                        if (Pieces[10][4]<Pieces[11][4]){                            Pieces[11][4]-=2;
                            Pieces[10][4]-=2;
                            Pieces[npiece][4]+=2;
                            Pieces[npiece][5]+=2;
                        }
                        else if (Pieces[10][4]>Pieces[11][4]){
                            Pieces[11][4]-=2;
                            Pieces[10][4]-=2;
                            Pieces[npiece][4]+=2;
                            Pieces[npiece][5]+=2;
                        }
                    }
                    else{
                        printf("\nMovimiento no válido\n");
                    }
                }
            }
            else if (direction=='e'||direction=='E'){
                if (ammount=='1' || ammount=='\0'){
                    if (((Pieces[10][0]==Pieces[npiece][0]+1&&Pieces[11][0]==Pieces[npiece][1]+1)||(Pieces[10][0]==Pieces[npiece][1]+1&&Pieces[11][0]==Pieces[npiece][0]+1))&&((Pieces[10][4]==Pieces[npiece][4]&&Pieces[11][4]==Pieces[npiece][5])||(Pieces[10][4]==Pieces[npiece][5]&&Pieces[11][4]==Pieces[npiece][4]))){
                        Pieces[10][0]--;
                        Pieces[11][0]--;
                        Pieces[npiece][0]++;
                        Pieces[npiece][1]++;
                    }
                    else{
                        printf("\nMovimiento no válido\n");
                    }
                }
                else{
                    printf("\nMovimiento no válido\n");
                }
            }
            else if (direction=='w'||direction=='W'){
                if (ammount=='1' || ammount=='\0'){
                    if (((Pieces[10][0]==Pieces[npiece][0]-1&&Pieces[11][0]==Pieces[npiece][1]-1)||(Pieces[10][0]==Pieces[npiece][1]-1&&Pieces[11][0]==Pieces[npiece][0]-1))&&((Pieces[10][4]==Pieces[npiece][4]&&Pieces[11][4]==Pieces[npiece][5])||(Pieces[10][4]==Pieces[npiece][5]&&Pieces[11][4]==Pieces[npiece][4]))){
                        Pieces[10][0]++;
                        Pieces[11][0]++;
                        Pieces[npiece][0]--;
                        Pieces[npiece][1]--;
                    }
                    else{
                        printf("\nMovimiento no válido\n");
                    }
                }
                else{
                    printf("\nMovimiento no válido\n");
                }
            }
        }


        else if (npiece==4){  //el script para mover la piezas de 1x2
            if (direction=='n'||direction=='N'){
                if (ammount=='1' || ammount=='\0'){
                    if (((Pieces[10][4]==Pieces[npiece][4]-1&&Pieces[11][4]==Pieces[npiece][5]-1)||(Pieces[10][4]==Pieces[npiece][5]-1&&Pieces[11][4]==Pieces[npiece][4]-1))&&((Pieces[10][0]==Pieces[npiece][0]&&Pieces[11][0]==Pieces[npiece][1])||(Pieces[10][0]==Pieces[npiece][1]&&Pieces[11][0]==Pieces[npiece][0]))){
                        Pieces[10][4]++;
                        Pieces[11][4]++;
                        Pieces[npiece][4]--;
                        Pieces[npiece][5]--;
                    }
                    else{
                        printf("\nMovimiento no válido\n");
                    }
                }
                else{
                    printf("\nMovimiento no válido\n");
                }
            }
            else if (direction=='s'||direction=='S'){
                if (ammount=='1' || ammount=='\0'){
                    if (((Pieces[10][4]==Pieces[npiece][4]+1&&Pieces[11][4]==Pieces[npiece][5]+1)||(Pieces[10][4]==Pieces[npiece][5]+1&&Pieces[11][4]==Pieces[npiece][4]+1))&&((Pieces[10][0]==Pieces[npiece][0]&&Pieces[11][0]==Pieces[npiece][1])||(Pieces[10][0]==Pieces[npiece][1]&&Pieces[11][0]==Pieces[npiece][0]))){
                        Pieces[10][4]--;
                        Pieces[11][4]--;
                        Pieces[npiece][4]++;
                        Pieces[npiece][5]++;
                    }
                    else{
                        printf("\nMovimiento no válido\n");
                    }
                }
                else{
                    printf("\nMovimiento no válido\n");
                }
            }
            else if (direction=='e'||direction=='E'){
                if (ammount=='1' || ammount=='\0'){
                    if (((Pieces[10][0]==Pieces[npiece][0]+1&&Pieces[11][0]==Pieces[npiece][1]+1)||(Pieces[10][0]==Pieces[npiece][1]+1&&Pieces[11][0]==Pieces[npiece][0]+1))&&((Pieces[10][4]==Pieces[npiece][4]&&Pieces[11][4]==Pieces[npiece][5])||(Pieces[10][4]==Pieces[npiece][5]&&Pieces[11][4]==Pieces[npiece][4]))){
                        Pieces[10][0]--;
                        Pieces[11][0]--;
                        Pieces[npiece][0]++;
                        Pieces[npiece][1]++;
                    }
                    else{
                        printf("\nMovimiento no válido\n");
                    }
                }
            }
            else if (direction=='w'||direction=='W'){
                if (ammount=='1' || ammount=='\0'){
                    if (((Pieces[10][0]==Pieces[npiece][0]-1&&Pieces[11][0]==Pieces[npiece][1]-1)||(Pieces[10][0]==Pieces[npiece][1]-1&&Pieces[11][0]==Pieces[npiece][0]-1))&&((Pieces[10][4]==Pieces[npiece][4]&&Pieces[11][4]==Pieces[npiece][5])||(Pieces[10][4]==Pieces[npiece][5]&&Pieces[11][4]==Pieces[npiece][4]))){
                        Pieces[10][0]++;
                        Pieces[11][0]++;
                        Pieces[npiece][0]--;
                        Pieces[npiece][1]--;
                    }
                    else{
                        printf("\nMovimiento no válido\n");
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
        printf("You Win!! :D\n");
    }
}

return 0;
}