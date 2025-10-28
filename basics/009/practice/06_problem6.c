#include <stdio.h>
//6. Create an array of 5 complex numbers created in Problem 5 and display themwith the help of a display function. The values must be taken as an input from the user
typedef struct c
{
    int real; int imaginary;
}Complex;

void display(Complex c){
    printf("The value of complex no. is %d + %di\n", c.real, c.imaginary);
}
int main(){
    Complex carr[5];
    for (int i = 0; i < 5; i++)
    {
        printf("Enter real part/n");
        scanf("%d",&carr[i].real);
        printf("Enter img part/n");
        scanf("%d",&carr[i].imaginary);
        display(carr[i]);
    }
    
    
    
    Complex v = {1,2};
    printf("The value of complex no. is %d + %di", v.real, v.imaginary);
    return 0;
}