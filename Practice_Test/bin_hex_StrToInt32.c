#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "TestCode.h"

/*

Write a function bin_hex_StrToInt32 that receives a string containing either a binary or hex number. 
The function must return the string�s integer value. 

Note that a string that contains ONLY '1' and '0' can be considered as a binary or a hex string. 
For eaxmple, "10" can be a binary number equivalent to 2 or a hex number equivalent to 16.
If the string is containg ONLY '1' and '0', the default will be ***binary***.

If the input parameter is empty or invalid value, the function should return ERROR_INVALID_PARAMETER

Note: Do not call built-in library functions that accomplish these tasks automatically.
*/

int bin_hex_StrToInt32(char * s)
{
	int binary = 1; // Flag set to o'on' assuming string is binary until proven otherwise
	int hex = 0; //Flagset to 'off' assuming the string s is not hex 
	int length = strlen(s); //getting size of the string
	const char hexDigits [] = {"0123456789abcdefABCDEF"}; //establishing valid hex characters
	const char binDigits [] = {"01"}; //establishing valid binary characters
	unsigned long rtotal = 0; // variable to store the total
	
	for (int i = 0; i < length; i++) //looping through each element of s
	{
		if (!strchr(binDigits,s[i])) //using the string library to determine if s[i] is missing from the valid binary characters
		{
			binary = 0; //setting binary to 0 if above true
			break; // breaking from the loop because we know it cannot be a binary string
		}
		else //if s[i] is present in the valid strings then it increments to next element
		{
			i++;
		}	
		
	}
	
	if (binary != 1) //If the string is not binary then we check if it is hex
	{
		for (int i = 0; i < length; i++)// looping through the elements of s
		{
			if (!strchr(hexDigits,s[i])) checking to see if current char is invalid per hexDigits
			{
				printf("ERROR_INVALID_PARAMETER"); //if it is invalid the function prints this message and returns -1
				return -1; //"ERROR_INVALID_PARAMETER";
			}
			else
			{
				i++; //otherwise it continues to move through the s characters (elements)
			}
			hex	= 1; //assuming it gets all the way through the string s hex will be flagged to 'on'
		}
	}
	if (binary == 1) //if the string is indeed binary ...
	{
		for (int i = 0; i < length; i++) //loops through each element of s
		{
			if (s[i] == '0') //if s[i] is 0 then we simply shift left one bit
			{
				rtotal <<= 1;
			}
			else // otherwise 
			{
				rtotal = rtotal | (s[i]-48); //we subtract 48 from the ascii value of the character which makes it equal to its decimal value then or the value of rtotal
				if (i+1 == length) //check to see if this is the last character
				{
					break; // If yes, then break because we are done
				}
				rtotal <<= 1; //if we havent broken out it will bit shift left once then loop
			}
		}
	}
	
	else if (hex == 1) //but if it is hex
	{
		
		for (int i = 0; i < length; i ++) // iterate through s
		{
			if (s[i] >= '0' && s[i] <= '9') if the character is 0-9
			{
				rtotal = rtotal | (s[i]-48); // subtract 48 to get equivalent decimal value then OR with rtotal
				if (i+1 == length) // checking if last char
				{
					break; // if so break
				}
				rtotal <<= 4; // If break didnt occur then shift left 4 times, the equivalent of a nibble represented by a single character
			}
			else if(toupper(s[i]) >= 'A' && toupper(s[i]) <= 'F') // if its A-F
			{
				rtotal = rtotal | (toupper(s[i]-55)); //similar process to above except we subtract 55 to get the decimal value represented by the character
				if (i+1 == length)
				{
					break;
				}
				rtotal <<= 4;
			}
		}
	}
	

	


	return rtotal; // return rtotal to main
}

void main(void)
{
	char myString [] = {"01AE101"};
	char mybinString [] = {"111001101"};
	char mybadString [] = {"01AE10Z"};
	printf("%d\n",bin_hex_StrToInt32(myString));
	printf("%d\n",bin_hex_StrToInt32(mybinString));
	printf("%d\n",bin_hex_StrToInt32(mybadString));
	
}
