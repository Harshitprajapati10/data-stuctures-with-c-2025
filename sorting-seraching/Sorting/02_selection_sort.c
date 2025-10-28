#include <stdio.h>


void swapeee(int A[], int i,int j){
    if (i == j) return;
    A[i] += A[j];
    A[j] = A[i]- A[j];
    A[i] -= A[j];
    
}

int getMaxIndex(int A[], int end){
    int max = 0;
    for (int i = 1; i < end+1; i++){
        if(A[i] > A[max]){
            max = i;
        }
    }
    return max;
}



void SelectionSort(int A[], int n){
     for (int i = 0; i < n-1; i++)
     {
        /* code */
        int last = n-i-1;
        int maxindex = getMaxIndex(A,last);
        swapeee(A, maxindex, last);
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
    SelectionSort(A,10);
    showArray(A, 10);
}



/*
all time complexity -> N2
in place
not stable
offline
*/