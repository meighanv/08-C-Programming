/*
PERFORMANCE LAB: CONTENT COPY (LINE-BY-LINE)
File I/O – fputs()

“Content Copy”

Open an existing file in read mode.
Open a new file in write mode.
Copy the existing file into the new file line-by-line .
Close the existing file.
Close and open the new file in read mode.
Print the new file line-by-line.
*/

#include <stdio.h>

void main(void)
{
    FILE * srcfileptr; //declare file pointer for source file
    FILE * dstfileptr; //declare file pointer for destination file
    char string [256]; // declare variable holder for printing content a line at a time
    if( (srcfileptr = fopen("mmpr.txt", "r") ) == NULL) //If file cannot be read (permissions issue)
    {
        puts("File could not be opened."); // print this message
    }
    else // otherwise
    {
        dstfileptr = fopen("copied2.txt","w");
        while (!feof(srcfileptr)) //whle the file pointer is not at EOF
        {
            fgets(string, 255, srcfileptr); //get 255 characters from the file
            fputs(string,dstfileptr); //print c variable value to the destination file
            
        }
    }
    
}