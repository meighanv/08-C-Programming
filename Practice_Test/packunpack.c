
#include <stdio.h>
#include <stdlib.h>
#include "TestCode.h"

/*
The function packCharacters packs four character values into a four-byte unsigned int variable.
The first character will be placed in the first byte of the int variable, the second character in the second byte,
the third character in the third byte, and the fourth character in the fourth byte 
So for ch1=a, ch2=b, ch3=c, ch4=d, the returning int = abcd

The function char* unpackCharacters(unsigned int pack) to unpack characters from a four-byte unsigned int.
The unpackCharacters function returns a pointer the unpacked characters.
The first character in the array will contain the fourth byte of the unsigned int
so for int pack = abcd, the returning char * = {d,c,b,a}

*/


unsigned int packCharacters(char ch4, char ch3, char ch2, char ch1) // Provided by test
{
	unsigned int packed; //Provided by test
	packed = ch4; //setting the 4 byte int = 1 byte char 

	packed <<= 8; //shifting existing bits 8 to the right, making space for next char 

	packed |= ch3; //setting the vacated byte = next char

	packed <<= 8; //shifting existing bits 8 to the right, making space for next char

	packed |= ch2; //setting the vacated byte = next char

	packed <<= 8; //shifting existing bits 8 to the right, making space for next char

	packed |= ch1; //setting the vacated byte = next char

   	
	return packed; //return the integer to calling function
}


char* unpackCharacters(unsigned int pack) // Provided by test
{

	char * temp;// Provided by test
	
	if (pack == 0) // Checking to see if the passed integer is NULL ...
	{
		temp = NULL; //...because this is the expected response
	}
	else
	{
		temp = (char*)calloc(5, sizeof(char)); //allocation 0 initialized space for temp w/ size of 5 so that string is NULL terminated
		for (int i = 3; i >= 0; i--) // working backwards through the byte array...
		{
			*(temp +i) = pack & 255; //setting current char array element position to the AND result of current pack and 255
			pack >>= 8;	// shifting right the bytes to get to next 8 bits (char)
		}
	}
	
	return temp;// Provided by test; returns the pointer (without the above allocation the data would not survive out of func)
   
}


