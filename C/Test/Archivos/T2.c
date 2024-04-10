#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define L 100

int palindrome(char * string){
    char nstring[L]="";
    int counter=0;
    int lenght=strlen(string);
    for (int i=0; i<lenght;i++){
        if ((string[i])==' '){
        }
        else {
            nstring[counter]=tolower(string[i]);
            counter++;
        }   
    }
    lenght=strlen(nstring);
    for (int i=0; i<lenght/2;i++){
        if (nstring[i]==nstring[lenght-2-i]){
        }
        else{
            printf("Not a palindrome");
            return 1;   
        }
    }
    printf("Palindrome!!");
    return 0;
}
int main(){
    FILE * entry=fopen("test.txt","w+");
    char input[L];
    printf("Enter a string to check if its a palindrome:\n--> ");
    fgets(input, L-1, stdin);
    char string[L];
    fprintf(entry,"%s ", input);
    rewind(entry);
    fgets(string, 99, entry);
    palindrome(string);
    fclose(entry);
}