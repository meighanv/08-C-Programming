/*
Name: Vernon Meighan
Date: 20200108
Project: Basic assignment operators and operand usage.
*/

#include <stdio.h>

void main()
{
    int x = 9;
    int y = 3;
    //////// WRITE EACH VALUE OF X ////////

    //printf("x is %d and y is %d\n", x, y);
    printf("x *- y is %d\n", x *- y); // -27
     x = 9;
     y = 3;
    //printf("x is %d and y is %d\n", x, y);
    printf("x /= y is %d\n", x /= y);// 3
    x = 9;
    y = 3;
    //printf("x is %d and y is %d\n", x, y);
    printf("x %%= y is %d\n", x %= y);// 0
    x = 9;
    y = 3;
    //printf("x is %d and y is %d\n", x, y);
    printf("x += y is %d\n", x += y);// 3
    x = 9;
    y = 3;
    //printf("x is %d and y is %d\n", x, y);
    printf("x -= y is %d\n", x -= y);// 
    x = 9;
    y = 3;
    //printf("x is %d and y is %d\n", x, y);
    printf("x *= ++y is %d\n", x *= ++y);// 
    x = 9;
    y = 3;
    //printf("x is %d and y is %d\n", x, y);
    printf("x /= y-- is %d\n", x /= y--);// 
    x = 9;
    y = 3;
    //printf("x is %d and y is %d\n", x, y);
    printf("x %%= --x is %d\n", x %= --x);// 
    x = 9;
    y = 3;
    //printf("x is %d and y is %d\n", x, y);
    printf("x += --y is %d\n", x += --y);// 
    x = 9;
    y = 3;
    //printf("x is %d and y is %d\n", x, y);
    printf("x -= y++ is %d\n", x -= y++);// 
    x = 9;
    y = 3;
    printf("x is %d and y is %d\n", x, y);
    
    printf("(y %%= y) || (x /= x--) is %d\n", (y %= y) || (x /= x--) ); //      // Bonus
    printf("%d\n",x);
    
}
