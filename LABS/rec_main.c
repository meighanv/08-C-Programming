/*
5.40--> (recursive main) 
	Can main be called recursively? Write a program containing a function   (main). 
    Include (static) local variable count initialized to 1. Post-increment and print 
    the value of count each time main is called. What happens when your program runs?
*/

#include <stdio.h>

int main()// this will continue to print numbers until a segmentation fault occurs
{
    static int counter = 0;
    counter++;
    printf("%d ",counter);
    main();
}