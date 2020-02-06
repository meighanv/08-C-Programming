/*
PEFORMANCE LAB: CONTENT COPY CHAR-BY-CHAR
File I/O – putc()

“Content Copy”

Open an existing file in read mode.
Open a new file in write mode.
Copy the existing file into the new file char-by-char.
Close the existing file.
Close and open the new file in read mode.
Print the new file char-by-char.
*/

#include <stdio.h>

void main(void)
{
    FILE * srcfileptr; //declare file pointer for source file
    FILE * dstfileptr; //declare file pointer for destination file
    char c; // declare variable holder for printing content a char at a time
    if( (srcfileptr = fopen("mmpr.txt", "r") ) == NULL) //If file cannot be read (permissions issue)
    {
        puts("File could not be opened."); // print this message
    }
    else // otherwise
    {
        dstfileptr = fopen("copied.txt","w");
        while (!feof(srcfileptr)) //whle the file pointer is not at EOF
        {
            c = getc(srcfileptr); //get character from the file
            putc(c,dstfileptr); //print c variable value to the destination file
        }
    }
    
}