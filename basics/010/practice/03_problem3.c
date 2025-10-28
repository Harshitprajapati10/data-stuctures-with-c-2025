// Write a program to read a text file character by character and write its content twice in separate file

#include <stdio.h>


int main(){
    FILE *ptr;
    FILE *ptr2;
    char ch;
    ptr = fopen("harshit.txt", "r");
    ptr2 = fopen("harshit2.txt", "a");

    while (1)
    {
        ch = fgetc(ptr);
        if (ch == EOF) 
        {
            break;
        }
        else{
            
            fprintf(ptr2,"%c",ch);
            fprintf(ptr2,"%c",ch);
            printf("%c",ch);
        }
       
    }
     return 0;
}