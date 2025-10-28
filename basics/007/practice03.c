//Write a program containing functions which counts the number of positive integers in an array

#include <stdio.h>
int countpositive(int nums[], int size){
    int positives=0;
    for(int i = 0;i<size;i++){
        if(nums[i]>0){positives++;}
    }
    return positives;

}
int main(){
    int nums[] = {2,3,4,-1,0,-5,-7,2,5,6,-9,6};
    int positives;
    positives = countpositive(nums,12);
    printf("%d",positives);
}