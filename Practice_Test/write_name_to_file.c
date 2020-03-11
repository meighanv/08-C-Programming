/*

Write the function writeNames that receives four (4) parameters:
   1. fnames (char ** array)  - represents char * strings of people's first names
   2. lnames (char ** array)  - represents char * strings of people's last names
   3. sz (int) - the size of both arrays (both arrays will be same length)
   4. fileName - the name of the file to write data to.

The writeNames function will process the arrays and write each person's last name
and first name to the file name passed. Each line of the file should contain 
a person's last name, followed by a comma and a space, then the first name such as:

Smith, John
Jones, Sally

The first names and last names align to the same index in each array.  For example, a person's first
name will be in fnames[0] and their last name in lnames[0].

Ensure when you write the names out to the files, the first letter of each name is capitalized like
the example above.

Ensure that the last line of the file does NOT contain a newline char (\n) at the end.

If the sz is 0 or less, or if the length of any of the names are zero (0), the function 
should return 0 without creating a file.
Otherwise, the function should return 1.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "TestCode.h"

int writeNames(char ** fnames, char ** lnames, int sz, char *fileName)
{
	FILE * dstfileptr;
   
   char * comma = {", "};
   char * end = {"\n"};
   char * newstring;
   char * first;
   char * last;
   int buffer = 32;
   for(int i = 0; i < sz; i++)
   {
      newstring = calloc(buffer, sizeof(char));
      first = calloc(strlen(fnames[i]), sizeof(char));
      last = calloc(strlen(lnames[i]), sizeof(char));
      if (strlen(fnames[i]) == 0 || strlen(lnames[i]) == 0 || sz <= 0)
      {
         return 0;
      }
      strcpy(last, lnames[i]);
      last[0] = toupper(last[0]);
      strcpy(first, fnames[i]);
      first[0] = toupper(first[0]);
      strcat(newstring, last);
      strcat(newstring, comma);
      strcat(newstring, first);
      if (i+1 != sz)
      {
         strcat(newstring, end);
      }
      if (!dstfileptr)
      {
         dstfileptr = fopen(fileName, "w");
      }
      fputs(newstring, dstfileptr);
   }
   fclose(dstfileptr);
   return 1;
}

// void main(void)
// {
//    char * fnames[] = {"george","john","millard","Theodore"};
//    char * lnames[] = {"Washington", "adams","Filmore","roosevelt"};
//    int res = writeNames(fnames, lnames, sizeof(fnames) / sizeof(*fnames), "names.txt");
// }
