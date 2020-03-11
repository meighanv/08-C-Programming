#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>


/* Write the function extractAndAddNumbers that receives a string of text as a parameter. The
string of text contains one or more series of digits embedded within it. The function will
locate each series of digits, convert each series of digits to a number, and add all the numbers
together and return the total value.

For example, as string may contain:  abc1307sfaskfsjadfja34kdsfljakfslkjflksjf902

The function will return the integer: 2243 for this example

if the string is empty or there are no digits in the string, the function should return 0



  */


int extractAndAddNumbers(char *text)
{
	if (text == NULL)
  {
    return 0;
  }
  
  char *ptr = text;
  char *numbuffer;
  numbuffer = calloc(32, sizeof(char));
  int total = 0;
  int startnum = 0;
  int i = 0;
  while (*ptr)
  {
    if (isdigit(*ptr))
    {
      startnum = 1;
      numbuffer[i] = *ptr;
      i++;
    }
    else
    {
      if (startnum = 1)
      {
        total += atoi(numbuffer);
        startnum = 0;
        numbuffer = calloc(32, sizeof(char));
        i=0;
      }
    }
    ptr++;
  }
  if (atoi(numbuffer)>0)
  {
    total += atoi(numbuffer);
  }
  free(numbuffer);
	return total;
}

// void main()
// {
//   char * string = {"abc1307sfaskfsjadfja34kdsfljakfslkjflksjf902"};
//   printf("%d\n",extractAndAddNumbers(string));
//   char * string2 = {""};
//   printf("%d\n",extractAndAddNumbers(string2));
//   char * string3 ={"sakjhkjdhkjfhskjhdfkj"};
//   printf("%d\n",extractAndAddNumbers(string3));
// }