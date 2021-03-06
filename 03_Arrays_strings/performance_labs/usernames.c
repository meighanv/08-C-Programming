/*
PERFORMANCE LAB: USERNAMES
File I/O – fprintf()

“Usernames”

Prompt the user for the number of students.

Read the first, middle, and last name for each student.

Remove any newline characters from all strings.

Append each name to a “class roster” file in the following format:

For George Herbert Dubya Bush, write the following to the the file...George H. Dubya Bush has a username of ghdbush.
BUILD THOSE SAFETY CHECKS!!!!!
*/

#include <stdio.h>
#include <string.h>
#define dataSize(x)  (sizeof(x)/sizeof(*x))

void main(void)
{
    char c;
    int stuCount;
    FILE * filePtr;
    printf("How many students?\n");
    fscanf(stdin, "%d", &stuCount);
    while ((c = fgetc(stdin)) != '\n' && c != EOF); /* Flush stdin */

    if( (filePtr = fopen("classRoster.txt", "w") ) == NULL) //If file cannot be read (permissions issue)
    {
        puts("File could not be opened."); // print this message
    }
    else // otherwise
    {
        for (int i = 1; i <= stuCount; i++)
        {
            char name [64] = {0};
            
            printf("Please enter the name:\n");
            fgets(name, 64, stdin);
            while ((c = fgetc(stdin)) != '\n' && c != EOF); /* Flush stdin */
            fputs(name, filePtr);
        }
    }
}