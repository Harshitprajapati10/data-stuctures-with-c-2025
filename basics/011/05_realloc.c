// suppose we allocated using malloc 5 , we use realloc to now aloc to 10

#include <stdio.h>
#include <stdlib.h>

int main(){
    int n = 5;
    int *ptr;
    // scanf("%d", &n);
    ptr = (int*)calloc(n, sizeof (int));

    ptr[0] = 3;
    printf("%d", ptr[0]);


    ptr = (int*)realloc(ptr, 10*sizeof(int));
    return 0;
}