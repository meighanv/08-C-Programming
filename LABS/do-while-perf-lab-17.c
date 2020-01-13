/*
DO-WHILE LOOP

* Initialize a 26 element *int* array to 0.
* Initialize a *char* variable to 0.
* Use a DO-WHILE loop to input, *but not store*, a string one character at a time from stdin **without** scanf()!!
* Each time a character is entered:
    * convert the character to upper case using *toupper()*
    * increment the corresponding array element if the user input is a letter
    * Ensure non-letters (i.e. Ctrl-D, tab) are safely handled
* End the loop when a *newline* is read.
* Print the results using a for loop ()
*/
#include <stdio.h>
#include <stdint.h>
#include <string.h>

void main()
{
    int elements [26] = {0};
    char letter = 0;
    int i = 0;
    do 
    {
        letter = getchar();
        elements[i] = toupper(letter);
        i++;
    }
    while(i<26 || letter != "\n");

    for (i=0; i<26; i++)
    {
        printf("%c\n",elements[i]);
        if (!elements[i])
        {
            break;
        }
    }
}