// Write a program to create an array of size n using calloc where n is an integer entered by the user


// calloc stands for continuous allocation. It initializes each memory block with a default value of 0
#include <stdio.h>
#include <stdlib.h>

int main(){

    int n;
    int *ptr;
    scanf("%d", &n);
    ptr = (int*)calloc(n, sizeof (int));

    ptr[0] = 3;
    ptr[1] = 6;
    printf("%d", ptr[0]);
    return 0;
}