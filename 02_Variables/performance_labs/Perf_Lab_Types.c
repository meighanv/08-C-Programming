#include <stdio.h>

int main(void)
{
    int integer = 1;
    float singlePrecision = 2.2;
    double doublePrecision = 3.34654;
    char singleChar = '$';
    char singleChar2 = 33;

    printf("size of int %d is %d \n", integer, (int)sizeof(integer));
    printf("size of int %d as a float is %d \n", integer, (int)sizeof((float)integer));
    printf("size of int %d as a char %c is %d \n", integer, integer, (int)sizeof((char)integer));
    printf("size of float is %d \n", (int)sizeof(singlePrecision));
    printf("size of float %f as a double %lf is %d \n", singlePrecision, (double)singlePrecision, (int)sizeof((double)singlePrecision));
    printf("size of double is %d \n", (int)sizeof(doublePrecision));
    printf("size of double %lf as a float %f is %d \n", doublePrecision, (float)doublePrecision, (int)sizeof((float)doublePrecision));
    printf("size of char 1 %c as an int %d is %d \n", singleChar, (int)singleChar, (int)sizeof((int)singleChar));
    printf("size of char 2 %c is %d \n", singleChar2, (int)sizeof(singleChar2));


    return 0;
}
    