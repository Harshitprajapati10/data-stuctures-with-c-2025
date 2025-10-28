// Quick Quiz: Write a program to create a dynamic array of 5 floats using malloc().


#include <stdio.h>
#include <stdlib.h>

int main(){

    float n =5;
    float *ptr;
    ptr = (float*)malloc(n* sizeof (float));
    

    ptr[0] = 3.2597;
    ptr[1] = 6.2597;
    ptr[2] = 76.2597;
    ptr[3] = 66.2597;
    ptr[4] = 56.2597;
    printf("%.2f\n", ptr[0]);
    printf("%.2f\n", ptr[1]);
    printf("%.2f\n", ptr[2]);
    printf("%.2f\n", ptr[3]);
    printf("%.2f\n", ptr[4]);
    return 0;
}