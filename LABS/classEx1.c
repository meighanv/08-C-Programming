#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
    double a, b, c;
    printf("Enter a number: ");
    scanf("%lf", &a); //The & is necessary so that scanf stores input at memory address of variable

    printf("Enter a number: ");
    scanf("%lf", &b);

    printf("Enter a number: ");
    scanf("%lf", &c);

    double average = (a+b+c) / 3; //Must either divide by a double or cast vars as floats

    printf("The average of %d, %d, and %d is %f\n", (int)a, (int)b, (int)c, average);

    return 0;
}