/*
PERFORMANCE LAB 20.1       (Rounding Numbers) Function floor may be used to round a number to a specific decimal place.
The statement rounds x to the tenths position (the first position to the right of the decimal point).
y = floor(x * 10 + .5) /10;
The statement rounds x to the hundredths position (the second position to the right of the decimal point).
y = floor(x * 10 + .5) /100;
Write a program that defines four functions to round a number x in various ways:
roundToInteger( number )
roundToTenths( number )
roundToHundreths( number )
roundToThousandths( number )
*/

#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <string.h>

double roundToTenths(double x)
{
    double y;
    y = floor(x * 10 + .5) /10;
    return y;
}

double roundToHundredths(double x)
{
    double y;
    y = floor(x * 100 + .5) /100;
    return y;
}

double roundToThousandths(double x)
{
    double y;
    y = floor(x * 1000 + .5) /1000;
    return y;
}

void main()
{
    double inputNum = 3.141592653589793;
    printf("%lf\n", roundToTenths(inputNum));
    printf("%lf\n", roundToHundredths(inputNum));
    printf("%lf\n", roundToThousandths(inputNum));
}
