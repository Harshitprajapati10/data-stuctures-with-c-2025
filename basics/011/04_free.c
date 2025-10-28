#include <stdio.h>
#include <stdlib.h>

// free takes a pointer and free all the memory taken by the pointer

int main(){
    int n;
    int *ptr;
    scanf("%d", &n);
    //ptr = (int*)calloc(n, sizeof (int));

    ptr = (int*)malloc(n*sizeof (int)); // malloc gives garbage value by deafault

    ptr[0] = 3;
    free(ptr);// gives garbage value
    printf("%d", ptr[0]);
    // free(ptr);
    return 0;
}