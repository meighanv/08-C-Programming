/*
Name: Vernon Meighan
Date: 20200107
Project: This program will complete the following:
- Declare and zeroize a char array with a dimension of 256
- Assign your chosen phrase to the leading elements of that array
- Explicitly verify your string is nul-terminated
- Print your string
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//This acts as a finction that will return the # of array elements
#define dataSize(x)  (sizeof(x)/sizeof(*x))

void main()
{
    //Declare empty string
    char myString [256] = {0};
    //Init my phrase
    char myPhrase [10] = {"My Phrase\0"};
    //For loop to iterate through each array to copy myPhrase to myString
    for (int i = 0; i <= dataSize(myPhrase); i++)
    {
        myString[i] = myPhrase[i];
    }
    printf("%s\n", myPhrase);
    printf("%s\n", myString);
    //verify the null terminater of the string;
    printf("This is the value of my null terminator:\n %d \nIt should be printed on the previous line.\n\n", (int)myString[(int)strlen(myString)]);
    printf("The length of the string stored in myPhrase is %d even though the # of elements is ", (int)strlen(myPhrase));
    printf("%d.\n", (int)dataSize(myPhrase));
    printf("The length of the string stored in myString is %d even though the # of elements is ", (int)strlen(myString));
    printf("%d.\n", (int)dataSize(myString));
}