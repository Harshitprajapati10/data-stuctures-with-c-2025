// dynamic memory allocation

#include <stdio.h>
#include <stdlib.h>

int main(){

    int n;
    int *ptr;
    scanf("%d", &n);
    ptr = (int*)malloc(n* sizeof (int));
    // malloc gives NULL pointer
    // (int*)malloc(20)

    // int arr [n]; // not allowed in c


    ptr[0] = 3;
    ptr[1] = 6;
    printf("%d", ptr[0]);
    return 0;
}