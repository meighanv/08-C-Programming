/*
Name: Vernon Meighan
Date: 20200108
Project: Basic operators and operand usage.
*/

#include <stdio.h>

void main()
{
    int x = 7;
    int y = 4;
    float z = 0;
    //////// WRITE EACH RESULT ////////
    printf("%d\n",x * y); // 28
    z = x / (float)y;
    printf("%f\n", z); // 1.75
    printf("%d\n",x % y); //3
    printf("%d\n",y + x); //11
    printf("%d\n",y - x); //-3
    printf("%d\n",-y); //-4
    printf("%d\n",++x); // 8
    printf("%d\n",y++); // 4
    printf("%d\n",x--); // 8
    printf("%d\n",--y); // 4
    printf("%d\n",1 + 2 * (3 + y) + 5); // 20
}