#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void compare(const void * a, const void * b){
    char *s1=*(char **)a;
    char *s2=*(char **)b;


    
    

}

int main(){
    int *list;
    list=malloc(10*sizeof(int));
    rate(list);
    printf("%d",list[0]);




    free(list);
    return 0;

}