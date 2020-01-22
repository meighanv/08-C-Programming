/*
Performance Lab - Memory Operators
"Reference Not Found"
    Declare userInput, tempValue, and input_ptr as the same data type
    Read user input into variable userInput
    Ensure tempValue contains the same value as userInput utilizing one or more memory operators

tempValue = userInput; // NOT PERMITTED... use a memory operator
    
    Print the value and the pointer for each of the three variables in a human readable format

    Locate those addresses in the "memory window"

    Submitt your work to the appropriate location for instructor review

Note "input_ptr" should be a pointer variable
*/

#include <stdio.h>

int main()
{
    int userInput;
    int tempValue;
    int * int_ptr;

    printf("Please enter an integer:\n");
    fscanf(stdin, "%d", &userInput);

    int_ptr = &userInput;
    tempValue = *int_ptr;
    printf("The value of userInput is %d. The address is %p.\n", userInput, &userInput);
    printf("The value of tempValue is %d. The address is %p.\n", tempValue, &tempValue);
    printf("The value of int_ptr is %p. The address is %p.\n", int_ptr, &int_ptr);

}