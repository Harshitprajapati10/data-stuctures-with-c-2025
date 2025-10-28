// conditional statements

#include <stdio.h>
/*
int main(){
    //1) WAP to check whether a student is passed or failed. to pass a student requires a total of 40% marks and at least 33% in each subject. Assume there are 3 subjects and take input from user.
    int total_one_subject = 100;
    printf("First subject marks: ");int first; scanf("%i",&first);
    printf("second subject marks: ");int second; scanf("%i",&second);
    printf("third subject marks: ");int third; scanf("%i",&third);
    float percentage = (first+second+third)*100/(total_one_subject*3);
    printf("The total percentage is %f\n", percentage);
    if(percentage>40 && first>33 && second>33 && third>33){
        printf("passed");
    }else{
        printf("failed");
    }
}
*/


int main(){
    //Write a program to determine whether a character entered by the user is lowercase or not.
    char ch = 'q';
    printf("The character is %c\n",ch);
    printf("The value of charavter is %d\n",ch);
    if(ch>=97 && ch<=122)printf("lowercase");
    else{printf("uppercase");}
    return 0;
}