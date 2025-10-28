#include <stdio.h>
#include <string.h>
 int main(){
    char st[] = "tony ";
    printf("%d\n",strlen(st));// gives length excluding null character

    char target[30];
    strcpy(target,st); // target is now tony
    printf("%s %s\n\n", st, target);
    


    //concatenating
    char a1[56] = "harshit";
    char a2[56] = " bhai";
    strcat(a1,a2);//a1 now contain harshitbhai
    printf("%s %s\n\n",a1,a2);

   //strcmp
   // compare two strings
   // if equal prints 0
   // if first>second(ascii order) prints -ve
   // else positive

   int a = strcmp("deep","joke");//-ve, dj<0
   int b = strcmp("far","ajoke");//+ve
   int c = strcmp("fat","fat");// 0
   printf("%d %d %d",a,b,c);

    return 0;
 }
