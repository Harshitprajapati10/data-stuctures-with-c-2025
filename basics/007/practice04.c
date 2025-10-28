//Create an array of size 3 x 10 containing multiplication tables of the numbers 2,7 and 9 respectively

#include <stdio.h>

void tablePrinter(int p, int q, int r){
    int row = 3;int col = 10;
    int tablearray[row][col];
    for(int i = 0;i<10;i++){
        tablearray[0][i]=p*(i+1);
        tablearray[1][i]=q*(i+1);
        tablearray[2][i]=r*(i+1);
    }
    for(int j = 0 ;j<row;j++){
        for(int k=0;k<col;k++){
            printf("| %d ",tablearray[j][k]);
        }
        printf("|\n");
    }
}
int main(){
    printf("Enter first number : ");int first;scanf("%d",&first);
    printf("Enter second number : ");int second;scanf("%d",&second);
    printf("Enter third number : ");int third;scanf("%d",&third);
    tablePrinter(first,second,third);
    return 0;
}