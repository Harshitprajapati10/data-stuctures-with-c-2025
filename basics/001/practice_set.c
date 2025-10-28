// 1  Area of rectanlge

#include <stdio.h>

/*
int main(){
    printf("Enter the length: ");float length;scanf("%f",&length);
    printf("Enter the breadth: ");float breadth;scanf("%f",&breadth);
    printf("Area of rectangle is %f", length*breadth);
    return 0;
}
*/

// 2 area of a circle

/*
int main(){
    printf("Enter the radius: ");float radius;scanf("%f",&radius);
    float area = 3.14*radius*radius;
    printf("Area of circle with radius %f is %f", radius, area); 
    return 0;
}
 */

// # -> area of a cylinder
/*
int main(){
    printf("Enter the radius: ");float radius;scanf("%f",&radius);
    printf("Enter the height: ");float height;scanf("%f",&height);
    float volume = 3.14*radius*radius*height;
    printf("volume is %f", volume);
    return 0;
}
*/

// 3 calculate simple interest

int main(){
    printf("Enter the principal :");float principal; scanf("%f",&principal);
    printf("Enter the rate :");float rate; scanf("%f",&rate);
    printf("Enter the time :");float time; scanf("%f",&time);
    printf("Simple interest is: %f", (principal*rate*time)/100);
}