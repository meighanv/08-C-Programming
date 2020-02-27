/*
5.39--> (recursive greatest common divisor) 
	The greatest common divisor of integers (x) and (y) is the largest integer
    that evenly divides both (x) and (y). Write a function (gcd) that returns 
    the greatest common divisor of (x) and (y). 
	The (gcd) of (x) and (y) is defined recursively as follows: if (y) is equal 
    to 0, then (gcd(x, y)) is (x); otherwise (gcd (x) and (y)) is (gcd (y, x % y)),
    where % is the remainder operator.
5.40--> (recursive main) 
	Can main be called recursively? Write a program containing a function   (main). 
    Include (static) local variable count initialized to 1. Post-increment and print 
    the value of count each time main is called. What happens when your program runs?
*/
#include <stdio.h>

int gcd(int x, int y)
{
    if (y == 0)
    {
        return x;
    }
    else
    {
        return gcd(y, x%y);
    }
    
}

void main()
{
    int x, y;
    printf("Please two integers separated by a space:\n");
    scanf("%d %d", &x, &y);

    printf("The greatest common divisor of %d and %d is %d.\n", x, y, gcd(x, y));
}