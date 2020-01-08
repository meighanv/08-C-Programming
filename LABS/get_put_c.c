/*
Name: Vernon Meighan
Date: 20200108
Project: This program will complete the following:
- Utilizing the functions of getchar() and putchar()
- Testing different types of input
- Added functionality to print the next char in sequence
*/

#include <stdio.h>

void printPrev(char input) //This function is used to address the performance lab portion
{
    printf("The previous character is: ");   // Prefaces output
    putc(input - 1, stdout); // Subtracting 1 to the byte value of the input
    printf("\n"); //readability
}

void main()
{
    int userInput = 0;                // Will store input
    printf("Enter a character: ");    // Prompts user
    userInput = getc(stdin);          // Stores stream input
    printf("Your character was : ");  // Prefaces output
    putc(userInput, stdout);          // Writes to stdout
    printf("\n");
    printPrev(userInput);
}