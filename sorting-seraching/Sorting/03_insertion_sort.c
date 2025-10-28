#include <stdio.h>


void swap(int A[], int i,int j){
    if (i == j) return;
    A[i] += A[j];
    A[j] = A[i]- A[j];
    A[i] -= A[j];
    
}
void InsertionSort(int A[], int n){
    for (int i = 0; i < n-1; i++){
        for (int j = (i+1); j > 0; j--){
            if(A[j] <A[j-1]){
                swap(A,j,j-1);
            }
            else{
                break;
            }
        }   
    }
    
}

void showArray(int A[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d|", A[i]);
    }
    printf("\n");
}

int main(){
    int A[] = {2,31,2,1,34,5,9,8,7,6};
    showArray(A, 10);
    InsertionSort(A,10);
    showArray(A, 10);
}


/*
stable
online
adaptive 
best -> N ->  alerady sorted
worst -> N2 -> reverse sorted
*/