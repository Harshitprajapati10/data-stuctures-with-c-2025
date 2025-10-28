#include <stdio.h>
struct employee
{
    int code;
    float salary;
    char name[10];
};

int main(){
    struct employee e1;
    e1.code=32;
    struct employee *ptr;
    ptr = &e1;
    // now we can print structure elements using:
    // derefrence ptr and print ptr.code
    printf("%d", (*ptr).code);
    // arrow operator is also used
    printf("%d", ptr->code);
}