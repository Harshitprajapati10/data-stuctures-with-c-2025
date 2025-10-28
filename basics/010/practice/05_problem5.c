/*

Write a program to modify a file containing an integer to double its value.
 */


#include <stdio.h>

int main(){
    FILE *fptr;
    int num = 4;
    fptr = fopen("int.txt","r");
    fscanf(fptr, "%d", &num);

    fclose(fptr);
    fptr = fopen("int.txt","w");
    fprintf(fptr, "%d", 2*num);
    fclose(fptr);
    
    return 0;
}