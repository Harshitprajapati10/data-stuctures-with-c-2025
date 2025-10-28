#include <stdio.h>
int main(){
    //Write your own version of strlen function from <string.h>
    char str[] = "Harshit";
    int i=0,count;
    char c = str[i];
    while(c!='\0'){
        c=str[i];
        i++;
    }
    count = i-1;
    printf("%d",count);
    return 0;
}