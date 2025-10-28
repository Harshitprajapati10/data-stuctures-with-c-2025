#include <stdio.h>
 int main(){
    //char st[] = "abc";// null character auto added
    // for (int i = 0; i < 3; i++)
    // {
    //     printf("%c",st[i]);
    // }

    //printf("%s",st); //print whole string


    // taking input of string
    char st[4];
    // st is same as &st[0b]
    scanf("%s",st);//enters upto 3 and 4th is null
    printf("%s",st);
    return 0;
 }
