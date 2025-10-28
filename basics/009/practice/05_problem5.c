#include <stdio.h>
// 5. Write a program with a structure representing a complex number
typedef struct c
{
    int real; int imaginary;
}Complex;

int main(){
    Complex v = {1,2};
    printf("The value of complex no. is %d + %di", v.real, v.imaginary);
    return 0;
}