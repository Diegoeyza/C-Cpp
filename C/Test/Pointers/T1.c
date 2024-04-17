#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void rate(int *list){
    char rat[11];
    fgets(rat,10,stdin);
    list[0]=atoi(rat);


    
    

}

int main(){
    int *list;
    list=malloc(10*sizeof(int));
    rate(list);
    printf("%d",list[0]);




    free(list);
    return 0;

}