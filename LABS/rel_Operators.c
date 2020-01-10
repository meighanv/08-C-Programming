/*
Name: Vernon Meighan
Date: 20200108
Project: Basic operators and operand usage.
*/

#include <stdio.h>

void main()
{
    int x = 99;
    int y = 0;

    //////// WRITE EACH RESULT ////////
    printf("%d\n", x && y); //0 False
    printf("%d\n",y || x); //1 True
    printf("%d\n",!y); //1 True
    printf("%d\n",y && 0); //0 False
    printf("%d\n",x || 42); //1 True
    printf("%d\n",!x); //0 False
    printf("%d\n",x && x); //1 True
    printf("%d\n",y || y);//0 False
    printf("%d\n",!1);//0 False
    printf("%d\n",1 && 1); //1 True
    printf("%d\n",(0 && 1) || (2 && 3));      // Bonus 1 True
}