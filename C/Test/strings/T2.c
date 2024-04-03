#include <stdio.h>
#include <string.h>

int Fire(char weapon[],int ammountF,int ammountO){
    if (ammountF<=ammountO){
        printf("You have fired %d times with the %s\n",ammountF,weapon);
        return ammountO-ammountF;
    }
    else{
        printf("Are you dumb? you want to fire %d times but you only have %d rounds",ammountF,ammountO);
        return ammountO;
    }
}

int main(){
    printf("Select which weapon to use (pistol, bazooka): ");
    char weapon[20];
    int ammountO=10;
    scanf("%s", weapon);
    if (strcmp(weapon,"pistol")==0||strcmp(weapon,"Pistol")==0||strcmp(weapon,"bazooka")==0||strcmp(weapon,"Bazooka")==0){
        int ammountF;
        printf("Select how many times do you want to fire it: ");
        scanf("%d",&ammountF);
        ammountO=Fire(weapon,ammountF,ammountO);
        return 0;
    }
    return 0;

}