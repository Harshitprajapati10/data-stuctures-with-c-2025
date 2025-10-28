/*
Write a program to dynamically create an array of size 6 capable of storing 6
integers */
// problem 1,2,3,4

#include <stdio.h>
#include <stdlib.h>

int main(){
    int n = 6;
    int * ptr;
    //ptr = (int *) malloc(n*sizeof(int));
    ptr = (int *) calloc(n,sizeof(int));

    for (int i = 0; i < n; i++)
    {
        ptr[i] = (i+1)*12;
    }
    //free(ptr);
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", ptr[i]);
    }
    
    ptr = (int *) realloc(10,sizeof(int));
    return 0;
}