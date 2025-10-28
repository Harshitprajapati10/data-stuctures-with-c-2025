#include <stdio.h>

void print_address(int n){
    printf("address of %d is %d\n", n, &n);
}
void print10X(int n){
    printf("Ten times %d is %d\n",n,n*10);
}
void swap(int a, int b){
    int temp = a;
    a = b;
    b = temp;
    printf("swapped a: %d, b: %d\n", a, b);
}
void swap_by_ref(int* x,int* y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int* sum(int a, int b){
    int sumis = a+b;
    int * sumptr = &sumis;
    printf("sum is %d \n", sumis);
    return sumptr;
}
float* average(int a, int b){
    float avgis = (a+b)/2.0;
    float * avgptr = &avgis;
    printf("average is %f\n", avgis);
    return avgptr;
}
int main(){
    /*
    int i = 25;
    int* k = &i;
    printf("%d\n",&i);
    printf("%d\n",k);
    printf("%d\n",*k);
    printf("%d\n",*(&i));
    print_address(i);
    */

   /*
    int a = 12;
    print10X(a);
    printf("%d\n",a);
    int p =3;int q = 5;
    printf("p is %d, q is %d\n", p, q);
    swap(p,q);
    printf("p is %d, q is %d\n", p, q);
    swap_by_ref(&p,&q);
    printf("p is %d, q is %d\n", p, q);
    */

    /*
    int x = 32;
    int y = 3;
    int * ptr1;
    float * ptr2;
    ptr1 = sum(x,y);
    ptr2 = average(x,y);
    printf("%u %u\n",ptr1,ptr2);
    printf("%i %f",*ptr1,*ptr2);
    */

    int i =2;
    int* ptr1 = &i;
    int ** ptr2 = &ptr1;//& addressof, * value of
    int *** ptr3 = &ptr2;
    printf("The address of i is %u\n",&i);
    printf("The value of i is %d\n",*ptr1);
    printf("The value of i is %d\n",**ptr2);
    printf("The value of i is %d\n",***ptr3);
    
}

// putting a varible to a function and printing its address is not same;
// Write a program to change the value of a variable to ten times of its current value

