

// time complexit = logN
// recurrence relation -> T(n) = T,n/2 + O(1)
// for iterative alogo-> space is O(1)


#include <stdio.h>

int BinarySearch(int A[], int n , int data){
    int start = 0;
    int end = n-1;
    int mid = 0;
    while (start <= end){
        mid = start + (end-start) / 2;
        if(A[mid] == data){
            return mid;
        }
        else if(A[mid] < data){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return -1;
}

int BinarySearchRecursive(int A[],int start,int end , int data){
    int mid = start + (end-start)/2;
    if(start>end){
        return -1;
    }
    if(A[mid] == data){
        return mid;
    }
    else if(A[mid] > data){
        return BinarySearchRecursive(A, start, mid-1,data);
    }
    else{
        return BinarySearchRecursive(A, mid +1, end, data);
    }
    return -1;
}

int main(){
    int A[] = {2,3,4,6,8,10,13,32};
    printf("%d\n",BinarySearch(A,8,8));
    printf("%d\n",BinarySearch(A,8,2));
    printf("%d\n",BinarySearch(A,8,32));
    printf("%d\n",BinarySearch(A,8,543));
    printf("%d\n",BinarySearchRecursive(A,0,7,8));
    printf("%d\n",BinarySearchRecursive(A,0,7,2));
    printf("%d\n",BinarySearchRecursive(A,0,7,32));
    printf("%d\n",BinarySearchRecursive(A,0,7,543));
    return 0;
}
