#include <stdio.h>
 int main(){
    char st[30];
    gets(st);//The entered string stored in st
    // printf("%s",st);
    puts(st); //puts gives newline
    printf("hey");
    
    // fgets is use over gets->buffer overflow problem
    return 0;
 }
