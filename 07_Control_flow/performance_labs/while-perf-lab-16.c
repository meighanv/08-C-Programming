/*
WHILE LOOPS
* Initialize a **NUL** terminated char array with multiple phrases separated by newlines (\n).
* Test the char array with puts().
* Write a WHILE loop that only prints the first line **AND** stops at a **NUL** character
*/
#include <stdio.h>
#include <stdint.h>

void main()
{
    char phrases [256] = {"Hello there.\nHow are you doing?\nFor real though?\n Oh that's so nice!\n\0"};
    int i = 0;
    while (phrases[i] != 0)
    {
        putchar(phrases[i]);
        i++;
    }

}