/*
IF STATEMENT
- Initialize a char array to zero.
- Safely store a user-input string in the char array.
- Safely print the string IF the following conditions are both true:
    The first element greater than or equal to decimal value 32.
    The first element is less than decimal value 126.
*/

#include <stdio.h>
#include <stdint.h>

void clearstdin()
{
    int c;
    while ((c = fgetc(stdin)) != '\n' && c != EOF); /* Flush stdin */
}

void main(void)
{
    char string [256] = {0}; // zero init char string variable
    fscanf(stdin, "%255s", string); //receive user input safely 
    clearstdin();
    char badString [20] = " badString"; // Var to check if false  conditional statement works 
    badString [0] = 13; // modifying var first character outside of good range
    if ((int)string[0] >= 32 && (int)string[0] < 126) // check if string contains printable ascii 
    {
        fprintf(stdout, "%s\n", string); // Safer print
    }
    /*if ((int)badString[0] >= 32 && (int)badString[0] < 126)
    {
        fprintf(stdout, "%s\n", badString);
    }
    //fprintf(stdout, "%s has been printed outside the 'if' statement.\n", badString);
    //fprintf(stdout, "%d is the first value (integer) in the string.\n", badString[0]);*/
}