// file i/o

#include <stdio.h>

int main(){
    FILE *ptr;
    ptr = fopen("harshit.txt","a");

    // char c = fgetc(ptr); // used to read a character from file
    // printf("%c",c);

    fputc('c', ptr); // put a char
    
    return 0;
}