/*
Name: Vernon Meighan
Date: 20200108
Project: This program will complete the following:
- Utilizing the functions of getchar() and putchar()
- Testing different types of input
- Added functionality to print the next char in sequence
*/

#include <stdio.h>

void printNext(char input) //This function is used to address the performance lab portion
{
    printf("The next character is: ");   // Prefaces output
    putchar(input + 1); // Adding 1 to the byte value of the input
    printf("\n"); //readability
}


int main(void)
{
    int userInput = 0;                // Will store user input
    printf("Enter a character: ");    // Prompts user
    userInput = getchar();            // Stores user input
    printf("Your character was: ");   // Prefaces output
    putchar(userInput);               // Prints output
    printf("\n"); //readability
    printNext(userInput); // Call printNext()
}
