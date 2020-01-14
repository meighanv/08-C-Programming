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
    int userChar [26] = {0};
    char letter = 0;
    int i = 0;
    printf("Please enter a phrase in lowercase one character at a time. Press enter twice to end input:\n");
    do 
    {
        letter = getchar();
        
        if (letter > 97 && letter <= 122) 
        {
            userChar[i] = toupper(letter);
            //printf("%d %d %d\n",letter, i, userChar[i]); // rudimentary debug statement
        }
        else
        {
            userChar[i] = letter;
        }
        i++;
        getchar(); //clears the newline created by <Enter>
        //printf("%d %d %d\n",letter, i, userChar[i]); // rudimentary debug statement
    }
    while(i<26 && letter != 10);

    for (i=0; i<26; i++)
    {
        printf("%c\n",userChar[i]);
        if (!userChar[i])
        {
            break;
        }
    }
}