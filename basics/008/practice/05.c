#include <stdio.h>
#include <string.h>
// function to copy string
void mystrcpy(char target[],char source[]){
    for(int i = 0; i<strlen(source);i++){
        target[i] = source[i];
    }
    target[strlen(source)] = '\0';
}
int main(){
    //make strcpy
    char source[] = "harshit";
    char target[30];
    mystrcpy(target,source);
    printf("%s %s",source,target);
    return 0;
}