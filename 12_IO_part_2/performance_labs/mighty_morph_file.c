/*File I/O – getc() “Mighty Morphin”

Save the lyrics for the Mighty Morphin' Power Rangers theme song into a text file.

Write a C program to:

Open the file in read-only mode
Read it char-by-char
Print each char as it is read
Close the file at the end*/

#include <stdio.h>

void main(void)
{
    FILE * myfileptr; //declare file pointer 
    char c; // declare variable holder for printing content a char at a time
    if( (myfileptr = fopen("mmpr.txt", "r") ) == NULL) //If file cannot be read (permissions issue)
    {
        puts("File could not be opened."); // print this message
    }
    else // otherwise
    {
        while (!feof(myfileptr)) //whle the file pointer is not at EOF
        {
            c = getc(myfileptr); //get character from the file
            putc(c,stdout); //print c variable value to the screen (stdout)
        }
    }
    
}