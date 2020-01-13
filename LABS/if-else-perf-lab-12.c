/*
IF-ELSE STATEMENT
- Initialize a signed int to 0.
- Input a number from the user and store it in the signed int.
- Determine if the number is negative or positive utilizing a bitwise operator.
- Utilizing an IF-ELSE statement:
    INDICATE if the number is negative
    Otherwise, print the original value in binary, and use a bitwise operation to flip one bit to make it negative
    Print the binary
*/

#include <stdio.h>
#include <stdint.h>
void printBin(int userInput)
{
    /*Lab 10: Bitwise Shift Right
    Input a uint32_t userInput from stdin utilizing fscanf()
    Initialize another uint32_t bitChecker to 0x01
    Use a Bitwise Shift Left on bitChecker to ensure only the left most bit is turned on
    Print the binary representation of userInput to stdout using only the following:
        fprintf()
        Bitwise Shift Right >>
        Bitwise AND &
        Relational Operator (e.g., >)
    */
    //uint32_t userInput = 0; // init user input var
    //printf("Please provide an integer:\n"); //
    //fscanf(stdin, "%d", &userInput); // read in user's number
    uint32_t bitChecker = 0x01; // init bitChecker to 1
    bitChecker = bitChecker << 31; //bit shift to the left-most point of the 32-bit integer
    for (int i = 31; i >= 0; i--) 
    {
        fprintf(stdout, "%d", (userInput & bitChecker) ? 1 : 0); //Prints 1 if the result of anding is not 0, otherwise it prints 0
        bitChecker >>= 1 ; //bit shift right
    }
    printf("\n"); // readability
    //return 0;
}

void main(void)
{
    int userNum = 0; // initializing signed int called userNum
    printf("Please enter a number.\n"); // prompting user for input
    fscanf(stdin, "%d", &userNum); // receiving user input to store in userNum

    if (1+(userNum>>31)-(-1>>31) == 1)
    {
        printf("%d is a negative number\n", userNum);
    }
    else 
    {
        printf("The number is positive, but making it negative would be %d\n", ~userNum + 1); //using two's compliment to make a negative number w/ bitwise ops
    }

    printBin(~userNum + 1);


}