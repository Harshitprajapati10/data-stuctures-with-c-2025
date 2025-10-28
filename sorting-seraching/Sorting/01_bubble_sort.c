/*
What	is	Sorting?
 Sorting	is	an	algorithm	that	arranges	the	elements	of	a	list	in	a	certain	order	[either	ascending	or
 descending].	The	output	is	a	permutation	or	reordering	of	the	input.


 Classification of sorting algorithms
 -on number of coparisons
 - by number of swaps
 - by memory usage
 - by recursion
 - by adaptability


 -Internal sort
 - external sort
                                                                     
*/


#include <stdio.h>

void BubbleSort(int A[], int n){
    int temp; 
    int swapped = 1;
    for (int i = 0; i < n && swapped; i++){
        swapped = 0;
        for (int j = 0; j < n-i; j++){
            if(A[j] > A[j+1]){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                swapped = 1;
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
    BubbleSort(A,10);
    showArray(A, 10);
}

/* 
PERFORMANCE
-> best  -> N -> already sorted
-> worst -> N^2 -> reverse sorted
-> in place -> no extra space required
-> offline
-> stable
*/