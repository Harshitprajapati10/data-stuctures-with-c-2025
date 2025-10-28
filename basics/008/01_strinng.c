// string

// /0-> is a null character
// char and null takes one byte

 // create a string using double quotes and print its content using as loop

 #include <stdio.h>
 int main(){
    // char st[] = {'a','b','c','\0'};
    char st[] = "abc";// null character auto added
    for (int i = 0; i < 3; i++)
    {
        printf("character is %c \n",st[i]);
    }
    return 0;
 }
