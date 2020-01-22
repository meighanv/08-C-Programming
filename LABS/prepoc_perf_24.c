/*
Description:
PREPROCESSOR DIRECTIVES
    Write a C program with preprocessor directives to:
        Combine two string literals
        Wrap those string literals in quotes
        Define a constant buffer size of 64
    Define an array:
        Of standard buffer size
        Assign the wrapped string literals to the array
    Print the array
*/

#include <stdio.h>
#include <string.h>
#define STR1 This1
#define STR2 This2
#define CONCAT(x,y) x##y
#define CAT(x,y) CONCAT(x,y)
#define STRCAT(x) #x
#define STRINGIT(x) STRCAT(x)
#define BUFSIZE 64

int main()
{
    //char str1 [] = {};
    //char str2 [] = {" is not 2"};
    char catted [256] = {};
    //TESTING(str1);
    printf(STRINGIT(CAT(STR1, STR2)));
    printf("\n");
    strcpy(catted, STRINGIT(CAT(STR1, STR2)));
    puts(catted);
    printf("\n");
}