// Write a program to create an array of 10 integers and store multiplication table of some number in it

#include <stdio.h>
/*
int main(){
    printf("Enter a number for some table: ");int num;scanf("%d",&num);
    int table[10];
    for(int i = 0;i<10;i++){
        table[i] = num*(i+1);
    }
    for(int j =0;j<10;j++){
        printf("|%d",table[j]);
    }
    printf("|");
    return 0;
}
*/


// WAF which reverses the array passed to it
// if we to a function then &arr[0] is same as arr

int* revArray(int* nums,int l);
int main(){
    printf("Enter size: ");int size;scanf("%d",&size);
    int arr[size];
    for(int i = 0;i<size;i++){
        printf("Enter the %dth value :", i+1);scanf("%d",&arr[i]);
    }
    for(int i = 0 ;i<size;i++){
        printf("|%d",arr[i]);
    }printf("|\n");
    // int arr[] = {3,8,9,10,4,5,6,7,8};
    // printf("%u\n",arr);
    int* newstart;
    newstart = revArray(arr,sizeof(arr));// same as &arr[0]
    // printf("%u\n",newstart);
    // printf("%d\n",*newstart);
    for(int i = 0; i<sizeof(arr)/4;i++){
        printf("|%u",*newstart);
        newstart++;
    }
    printf("|");
    return 0;
}
int* revArray(int* numpointer,int l){
    int* startptr = numpointer; int* endptr = numpointer+((l-1)/4);int temp;
    // printf("%u\n",startptr);
    // printf("%u\n",endptr);
    while(startptr <= endptr){
        temp = *startptr;*startptr = *endptr;*endptr = temp;
        startptr++;endptr--;
    }
    return numpointer;
}