#include <stdio.h>
// WAP to illustrate arrow operator
typedef struct employee{
    int salary;
    float score
}Employee;


int main(){
    Employee e1 ;
    Employee* ptr1 = &e1;
    ptr1-> salary = 56;
    ptr1->score = 45.3;
    printf("%d\n",ptr1-> salary);
    printf("%f\n",ptr1->score);
    printf("%.1f\n",ptr1->score);
    return 0;
}