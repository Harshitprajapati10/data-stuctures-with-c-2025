// linear search in sorted array
// if A[i] > data , return -1

#include <stdio.h>

int orderedLS(int A[], int n , int data){
    for (int i = 0; i < n; i++)
    {
        /* code */
        if(A[i] == data){
            return i;
        }
        else if(A[i] > data){
            return -1;
        }
    }return -1;
    
}

int main(){
    int A[] = {1,5,7,12,14,34,55,78};
    printf("%d\n",orderedLS(A,8,55));
    printf("%d\n",orderedLS(A,8,1));
    printf("%d\n",orderedLS(A,8,78));
    printf("%d\n",orderedLS(A,8,0));
    return 0;
}