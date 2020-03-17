/*
Write the function bitwiseOps that receives two char * strings representing a binary number.
All characters in the string should be either a '1' or '0'. Each string should be exactly
16 characters long.
The function will convert each binary representation to its equivelant integer value. So,
for example, if the string passed is '0000000000001111', this will be converted to 15.

After each string is converted, do the following:
   1. if both values are even numbers, use the bitwise & operator to and the values
      together and return the results.
   2. if both values are odd numbers, use the bitwise | operator to or the values
      together and return the results.
   3. otherwise, if both values are  > 255 then use the bitwise ^ operator to xor the
      values together and return the results.
   4. if none of the above apply, add the two values together and return the results.

If either of the provided strings is less or greater than 16 characters, the function will
return a -1.

If any of the characters in the string is other than a '1' or '0', the function will return
a -2.

*/


#include <stdio.h>
#include <string.h>
#include <math.h>
#include "TestCode.h"

int isBinStr(char *string)
{
   int i = 0;
   while ( i < strlen(string))
   {
      if (string[i] == 48 || string[i] == 49)
		{
			i++;
		}
		else
		{
			return 0;
		}	
   } 
   return 1;
}

int strToBin(char *string)
{
   int tempInt = 0;
   char * s;
   for (s = string; *s != 0; s++)
		{
			if (*s == '0')
			{
				if (*(s+1) == 0)
				{
					break;
				}
            tempInt <<= 1;
			}
			else
			{
				tempInt = tempInt | (*s-48);
				if (*(s+1) == 0)
				{
					break;
				}
				tempInt <<= 1;
				
			}
		}
   return tempInt;
}

int bitwiseOps(char *first, char* second)
{
   if ((isBinStr(first)!=1 || isBinStr(second)!=1))
   {
      return -2;
   }
   else if (strlen(first) != 16 || strlen(second) != 16)
   {
      return -1;
   }
   
   else
   {
      int firstNum = strToBin(first);
      int secondNum = strToBin(second);
      printf("First: %d; Second: %d\n", firstNum, secondNum);
      if (firstNum % 2 == 0 && secondNum % 2 == 0)
      {
         return firstNum & secondNum;
      }
      else if (firstNum % 2 == 1 && secondNum % 2 == 1)
      {
         return firstNum | secondNum;
      }
      else if (firstNum > 255 && secondNum > 255)
      {
         return firstNum ^ secondNum;
      }
      else
      {
         return firstNum + secondNum;
      }
   }
   
}

void main(void)
{
   // printf("%d\n",(bitwiseOps("0000000000001110","0000000111111111")) == 525); 
	// printf("%d\n",(bitwiseOps("0000000000001111","0000000000001111")) == 15);
	// printf("%d\n",(bitwiseOps("0000000001001111","0000000000001111")) == 79);
	// printf("%d\n",(bitwiseOps("0000000000001110","0000000000001110")) == 14);
	// printf("%d\n",(bitwiseOps("1110000000001110","0000000000001110")) == 14);
	// printf("%d\n",(bitwiseOps("0000000100000001","0000000100000000")) == 1);
	// printf("%d\n",(bitwiseOps("000000000000111 ","0000000000001110")) == -2);
	// printf("%d\n",(bitwiseOps("0000000000001110"," 000000000001110")) == -2);
	// printf("%d\n",(bitwiseOps("0000000000002110","0000000000001110")) == -2);
	// printf("%d\n",(bitwiseOps("00000000000011101","0000000000001110")) == -1);
	// printf("%d\n",(bitwiseOps("0000000000001110","000000000001110")) == -1);

   // printf("%d\n",(bitwiseOps("0000000000001110","0000000111111111"))); 
	// printf("%d\n",(bitwiseOps("0000000000001111","0000000000001111")));
	// printf("%d\n",(bitwiseOps("0000000001001111","0000000000001111")));
	// printf("%d\n",(bitwiseOps("0000000000001110","0000000000001110")));
	// printf("%d\n",(bitwiseOps("1110000000001110","0000000000001110")));
	// printf("%d\n",(bitwiseOps("0000000100000001","0000000100000000")));
	// printf("%d\n",(bitwiseOps("000000000000111 ","0000000000001110")));
	// printf("%d\n",(bitwiseOps("0000000000001110"," 000000000001110")));
	// printf("%d\n",(bitwiseOps("0000000000002110","0000000000001110")));
	// printf("%d\n",(bitwiseOps("00000000000011101","0000000000001110")));
	// printf("%d\n",(bitwiseOps("0000000000001110","000000000001110")));
   //printf("%d\n",isBinStr("1 "));
} /////ARRRGHHGHHH!!!
