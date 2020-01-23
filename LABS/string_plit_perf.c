/*
String Splitter

char * split_the_string(char * string_ptr, char delimiter);
    Return value - char pointer to the second string
    Parameters -
        string_ptr - Pointer to a null terminated string
        delimiter - Character that divides the two strings

    Purpose - Split one string into two at a delimiter char
    Requirements
        Only Address Arithmetic is permitted on string_ptr
        string_ptr if delimiter is not found
        Return ERROR_NULL_POINTER if string_ptr has more that one occurrence of delimiter
        Return ERROR_NULL_DELIMITER if the delimiter is '\0' (0x0)

Note- The error codes for this lab are MACROS #defined as: #define ERROR_NULL_POINTER 
((char*)-1) #define ERROR_ABUNDANT_POINTER ((char*)-2) #define ERROR_NULL_DELIMITER ((char*)-3)
*/

#include <stdio.h>
#define ERROR_NULL_POINTER ((char*)"-1") //SEG FAULT is generated if the numbers are not quoted
#define ERROR_ABUNDANT_POINTER ((char*)"-2") 
#define ERROR_NULL_DELIMITER ((char*)"-3")

char * split_the_string(char * string_ptr, char delimiter)
{
    int found = 0; //bool determining if delimeter is found. If >1 then return ERROR_NULL_POINTER
    char * stringStart = string_ptr;
    char * stringSecond;
    while (*string_ptr != '\0')
    {
        if (delimiter == '\0')
        {
            return ERROR_NULL_DELIMITER;
        }
        else if (*string_ptr == delimiter && found !=1)
        {
            stringSecond = string_ptr + 1;
            *string_ptr = '\0';
            found += 1;
        }
        else if (*string_ptr == delimiter && found ==1)
        {
            return ERROR_NULL_POINTER;
        }
        string_ptr++;

    }
    return stringSecond;

}

int main()
{
    char userInput [64] = {"My string.\0"};
    //char my_string2 [64] = {0};
    char delimiter;
    printf("Please enter a string:\n");
    scanf("%63[^\n]s", userInput);
    printf("Please enter a single character as your delimiter:\n");
    getchar();
    delimiter = getchar();


    printf("%s\n", split_the_string(userInput, delimiter));
    

}