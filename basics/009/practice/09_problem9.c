#include <stdio.h>

//  Write a structure capable of storing date. Write a function to compare those dates.

typedef struct Date{
    int mm;
    int dd;
    int yyyy;
}date;

int compare(date d1, date d2){
    // if d1 in future return 1
    if(
        (d1.yyyy == d2.yyyy) &&
        (d1.mm == d2.mm) && 
        (d1.dd == d2.dd)
    ){
        return 0;
    }
    if(d1.yyyy > d2.yyyy){
        return 1;
    }
    else if(d1.yyyy < d2.yyyy){
        return 0;
    }
    else if (d1.mm > d2.mm){
        return 1;
    }
    else if(d1.mm < d2.mm){
        return 0;
    }
    else if(d1.dd>d2.dd){
        return 1;
    }
    else if(d1.dd < d2.dd){
        return 0;
    }
}

int main(){
    date d1 = {12,4,2004};
    date d2 = {11,4,2024};
    printf("%d",compare(d1, d2));
    return 0;
}