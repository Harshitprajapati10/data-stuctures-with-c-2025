// file i/o

#include <stdio.h>

int main(){
    FILE *fptr;
    //fptr = fopen("harshit.txt","w");
    fptr = fopen("harshit.txt","a");
    int num = 432;
    fprintf(fptr, "%d", num);
    fclose(fptr);
    return 0;
}