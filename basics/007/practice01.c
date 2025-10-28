// Arrays
//Create an array of 10 numbers. Verify using pointer arithmetic that (ptr+2) points to the third element where ptr is a pointer pointing to the first element of the array.
#include <stdio.h>
int main(){
    int nums[] = {1,2,3,4,5,6,7,8,9,10};
    int* ptr1 = &nums[0];
    printf("Address of nums[0] is %u: \n",ptr1);
    ptr1++;
    printf("Address ++ed is %u: \n",ptr1);
    printf("%d\n",*ptr1);
    ptr1+=2;//4
    printf("%d\n",*ptr1);
    return 0;
}