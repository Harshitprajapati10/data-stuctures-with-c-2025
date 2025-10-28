#include <stdio.h>
int main(){
    //Write a program to take string as an input from the user using %c and %s confirm that the strings are equal.

    char str[6];
    for (int i = 0; i < 5; i++)
    {
        scanf("%c",&str[i]);
        fflush(stdin);// cant read enter as a character
    }
    str[5] = '\0';
    
    // scanf("%s",str);
    printf("%s",str);
    return 0;
}