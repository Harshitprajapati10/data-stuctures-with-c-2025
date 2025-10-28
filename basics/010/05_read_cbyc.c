// reading a file char by char

#include <stdio.h>

int main()
{
    FILE *ptr;
    char ch;
    ptr = fopen("harshit.txt", "r");

    while (1)
    {
        ch = fgetc(ptr); // when all the content of a file has been read break the loop!
        printf("%c", ch);
        if (ch == EOF) // EOF end of file
        {
            break;
        }
       
    }
     return 0;
}