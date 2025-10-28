// loops
#include <stdio.h>
int main(){
    // WAP to print multiplication table of given numberber
    printf("Enter the number: ");int number;scanf("%i",&number);
    for(int i=1;i<=10;i++){
        printf("%i X %i = %i\n",number, i, number*i);
    }
    printf("\n");
    for(int j = 10; j>=1; j--){
        printf("%i X %i = %i\n",number, j, number*j);
    }

    // sum of the table numbers
    int sumALL=0;
    for(int k=1;k<=10;k++){
        sumALL += (8*k);
    }
    printf("%d",sumALL);

    int numbergiven = 5;int factorial = 1;
    for(int i =1; i<=5; i++){
        factorial = factorial*i;
    }
    printf("Factorial of the given number is %i",factorial);
}