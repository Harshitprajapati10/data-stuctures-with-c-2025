#include <stdio.h>

/*
int main(){
    printf("hello world");
    int marks[32];
    for(int i=0;i<32;i++){
        marks[i] = i;
    }
    for(int i=0;i<32;i++){
        printf("%d\n" ,marks[i]);
    }
}
*/

// WAP to to accept marks of five student in an array and print them

int main(){

    // int marks[5];
    // for(int i = 0;i<5;i++){
    //     printf("Enter marks of %dth subject: ",i+1);scanf("%d", &marks[i]);
    // }
    // for(int j = 0; j<5; j++){
    //     printf("Marks of %dth subject is : %d\n",j+1, marks[j]);
    // }
    

    int cgpa[] = {2,3,4,5,6};
    printf("%d\n",cgpa[0]);
    printf("%d\n",cgpa[4]);

    int arr[] = {2,3,4,1};
    int* ptr = &arr[0];
    printf("%u\n",ptr);
    ptr++;
    printf("%u\n",ptr);
    printf("%d\n",*ptr);

    //Create a 2-d array by taking input from the user. Write a display function to print the content of this 2-d array on the screen.
    printf("Enter the no of rows: ");int rows;scanf("%i",&rows);
    printf("Enter the no of columns: ");int columns;scanf("%i",&columns);
    int grid[rows][columns];
    for(int i=0; i<rows;i++){
        for(int j = 0; j<columns;j++){
            printf("Enter value at row: %d, column: %d -->",i,j);
            scanf("%i",&grid[i][j]);// gives default newline
        }
    }
    for(int i=0; i<rows;i++){
        for(int j = 0; j<columns;j++){
            printf("| %d  ",grid[i][j]);
        }
        printf("|\n");
    }

    return 0;
}