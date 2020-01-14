/*
# PERFORMANCE LAB 19

### NESTED CONTROL FLOW

* Print all the even or odd numbers from 0 to 100.
* Prompt the user for input to indicate odds or evens.
* Loop from 0 to 100 and print all indicated numbers.
* Use and IF statement to check if *even* or *odd*.

#### BONUS: Ask the user to continue with a DO-WHILE loop
    * write a version with the counting loop written as a FOR loop, and a WHILE loop version.
*/

#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <string.h>

void evenOrOdd (int start, int fin, int select) // function for printing odd or even numbers
{
    do
    {
        if (start % 2 == select) // start is also the incrementor and select is what determines if odd or even are being printed
        {
            printf("%d ", start); // if start mod 2 is 0 then it is even. if result is 1 then it's odd. 
        }
        start++; // increment counter
    } while (start <= fin); // loop condition counter < fin
    
}

void main()
{
    char userInput = 0; // setting userInupt buffer
    int i = 0; // setting start point

    printf("Please select 'o' for odd and 'e' for even numbers:\n"); //prompt user for odd or even
    
    while (1==1) // Input validation
    {
        // printf("%d", toupper(userInput)); //debug statement
        userInput = getchar(); //get user input
        getchar(); //clear stdin of newline chars
        if (toupper(userInput) == 79 || toupper(userInput) == 69) // only valid selections
        {break;}
        else 
        {
            printf("Invalid Selection.\n"); // to cover invalid input selections
        }
    }
        

    if (toupper(userInput) == 79) //conditions to match 'o' or 'O' for odd
    {
        evenOrOdd(i, 100, 1); // call function to show user odd numbers with select argument set to 1
    }
    else if (toupper(userInput) == 69) //conditions to match 'e' or 'E' for even
    {
        evenOrOdd(i, 100, 0); // call function to show user even numbers with select argument set to 0
    }
    
    printf("\n\n");
}
