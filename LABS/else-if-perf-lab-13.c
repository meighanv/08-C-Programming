/*
SWAP THE LARGEST NUMBER
- Initialize ONLY three unsigned int variables to 0.
- Safely scan user input into the variable #1 and #2 utilizing a single line.
- Using a single ELSE-IF statement:
    - If variable #1 is equal to variable #2, print an ERROR.
    - Otherwise, exchange the value of the largest variable with variable #3 while 
    preserving the other value. Print the values of all three variables if the SUM 
    of the three variables is greater than 2 regardless of the previous ELSE-IF 
    statement.
*/
#include <stdio.h>
#include <stdint.h>

void xOrSwap(int* x,int* y) // Function to do an integer swap using XOR
{
    if (x != y) // Ensures x not equal to y to save cycles
    {
    *x ^= *y;
    *y ^= *x;
    *x ^= *y;
    }
}

void main()
{
    int num1, num2, num3 = 0;
    printf("Please enter the first number:\n");
    fscanf(stdin, "%d", &num1);
    printf("Please enter the second number:\n");
    fscanf(stdin, "%d", &num2);
   
    if (num1 == num2)
    {
        printf("ERROR. The numbers should not be the same.\n");
    }
    else if (num1 > num2) 
    {
        //using XOR op to switch the var values
        //num3 = num3 ^ num1; 
        //num1 = num1 ^ num3;
        //num3 = num3 ^ num1; 
        xOrSwap(&num1, &num3);  // calling xOrSwap function passing vars by reference 
    }//
    else//
    {
        //using XOR op to switch the var values
        //num3 = num3 ^ num2;
        //num2 = num2 ^ num3;
        //num3 = num3 ^ num2;
        xOrSwap(&num2, &num3);  // calling xOrSwap function passing vars by reference
    }
    if (num1+num2+num3 > 2)
    {
        printf("Num1: %d\nNum2: %d\nNum3: %d\n", num1, num2, num3);
    }
}