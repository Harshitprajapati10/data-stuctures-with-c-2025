#include <stdio.h>
#include <string.h>
//Write a program to count the occurrence of a given character in a string

int countoccurence(char st[],char c){
    int count = 0;
    for(int i =0;i<strlen(st);i++){
        if(st[i]==c){
            count++;
        }
    }return count;
}

int main(){
    char str[] = "harshitishero";
    printf("%d",countoccurence(str,'h'));
    printf("%d",countoccurence(str,'i'));
    printf("%d",countoccurence(str,'z'));
    printf("%d",countoccurence(str,'a'));
    return 0;
}