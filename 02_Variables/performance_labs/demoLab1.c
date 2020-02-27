#include <stdio.h>

int main(void)
{
    int integer = 1;
    /* floats only go to a precision of 6 decimal spaces; specifying 
    more in print statements interprets adjacent spaces in memory as 
    numbers to fill in those numbers beyond 6
    */
    float singlePrecision = 3.14159265359;
    double doublePrecision = 3.14159265359;
    char singleChar = '$';
    char singleChar2 = 33;

    printf("Your integer is %d \n", integer);
    printf("Your float is %f \n", singlePrecision);
    printf("Your double is %.9lf \n", doublePrecision);
    printf("Your First Char is %c \n", singleChar);
    printf("Your 2nd Char is %c \n", singleChar2);

    return 0;
}