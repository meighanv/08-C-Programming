#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv){
    double a, b, h;

    printf("Enter the length of the first side: ");
    scanf("%lf", &a);

    printf("Enter the length of the second side: ");
    scanf("%lf", &b);

    h = sqrt(a*a + b*b);

    printf(" The hypotenuse of a triangle with sides %lf and %lf is %lf.\n", a, b, h); 

    return 0;
}