// Functions
#include <stdio.h>

float average(int a, int b, int c);

int nthFibonacci(int n);

void printpattern(int n);

int main(){
    //printf("%f",average(32,42,53));
    // printf("%i",nthFibonacci(0));
    // printf("%i",nthFibonacci(1));
    // printf("%i",nthFibonacci(2));
    // printf("%i",nthFibonacci(5));
    // printf("%i",nthFibonacci(11));
    int a = 4;
    printf("%d %d %d \n", a, ++a, a++);//6 6 4
    printpattern(25);
    return 0;
}

float average(int a, int b, int c){
    return (a+b+c)/3.0;
}

int nthFibonacci(int n){
    if(n<2){
        return n;
    }
    return nthFibonacci(n-1)+nthFibonacci(n-2);
}

void printpattern(int n){
    /*
    *
    **
    ***
    */
    for(int i = 1;i<=n;i++){
        for (int j =0; j<i;j++){
            printf("* ");
        }
        printf("\n");
    }
}