/*
SWITCH STATEMENT
Write a program that will evaluate a simple math formula.
Input the formula with two integers separated by an arithmetic operator from one line.
Example: 1 + 1, (-8) - 3, 2 * (-7), (-15) / (-4)
 - Use a switch statement to print the correct value using the operators as cases.
 - Set the default condition to an error.
 - Ensure any division provides a double answer with a precision of two decimal places.
*/
#include <stdio.h>
#include <stdint.h>

void main()
{
    int a, b = 0;
    char selection = 0;
    
    printf("Type your basic math operation, then press enter (ex: 2 + 4 <Enter>):\n");
    scanf("%d%*c%c%*c%d", &a, &selection, &b);
    
    switch ((int)selection)
    {
        case 43: 
            printf("The sum of %d %c %d is %d\n", a, selection, b, a+b );
            break;
        case 45: 
            printf("The difference between %d %c %d is %d\n", a, selection, b, a-b );
            break;
        case 42: 
            printf("The product of %d %c %d is %d\n", a, selection, b, a*b );
            break;
        case 47: 
            printf("The quotient of %d %c %d is %.2lf\n", a, selection, b, (double)a/b );
            break;
        default: 
            printf("This was an invalid operation.\n");
    }
    
    //char plus = "+";
    //char sub = "-";
    //char mult = "*";
    //char div = "/";
    //printf("%d, %d, %d, %d\n", plus, sub, mult, div );
}