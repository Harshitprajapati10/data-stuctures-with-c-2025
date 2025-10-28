#include <stdio.h>
#include <string.h>

/*
typedef struct employee
{
    int code;
    float salary;
    char name[10];
} Emp;
int main(){
   Emp e1;
   e1.code = 234;
    strcpy(e1.name,"harshit");
    e1.salary = 433.4;
    printf("%d %f %s",e1.code,e1.salary,e1.name);
    return 0;
}
    */
struct employee
{
    int code;
    float salary;
    char name[10];
};
int main(){
    typedef struct employee Emp;
    Emp e1;
    Emp* ptr1 = &e1;
    e1.code = 234;
    strcpy(e1.name,"harshit");
    e1.salary = 433.4;
    printf("%d %f %s",e1.code,e1.salary,e1.name);
    printf("%d %f %s",ptr1->code,ptr1->salary,ptr1->name);
    return 0;
}