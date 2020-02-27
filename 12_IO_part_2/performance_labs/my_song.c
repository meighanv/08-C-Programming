/*File I/O – fgets() “Your Song”

Save your favorite song into a text file.

Write a C program to:

Open the file in read-only mode
Read it line-by-line
Print each line as it is read
Close the file at the end
*/
#include <stdio.h>

void main(void)
{
    FILE * myfileptr; //declare file pointer 
    char string [256]; // declare variable holder for printing content a line at a time
    if( (myfileptr = fopen("mmpr.txt", "r") ) == NULL) //If file cannot be read (permissions issue)
    {
        puts("File could not be opened."); // print this message
    }
    else // otherwise
    {
        while (!feof(myfileptr)) //whle the file pointer is not at EOF
        {
            fgets(string, 255, myfileptr); //get 255 characters from the file
            puts(string); //print string variable value to the screen (stdout)
        }
    }
    
}