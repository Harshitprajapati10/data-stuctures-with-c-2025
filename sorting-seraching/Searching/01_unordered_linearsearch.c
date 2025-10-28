#include <stdio.h>

//search in an unsorted array -> linear search
// return index if element is found else return -1;

int UnorderedLS(int A[], int n ,int data){
    for (int i = 0; i < n; i++){
        if(A[i]==data){
            return i;
        }
    }return -1;
    
}
int main(){
    int A[] = {2,42, 1, 54,6,7,87,66};
    printf("%d\n",UnorderedLS(A,8,87));
    printf("%d\n",UnorderedLS(A,8,2));
    printf("%d\n",UnorderedLS(A,8,56));
    printf("%d\n",UnorderedLS(A,8,562));
    return 0;
}