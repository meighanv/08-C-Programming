/*
# PERFORMANCE LAB 20

#Return Value - number of characters replaced
Parameters
Pointer to a null-terminated string
Character to find
Character to replace it with
Purpose - replace all occurrences of findThisChar with replaceItWithThis
Use pre-defined return values as indicated in shell cod
*/

#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <string.h>

int replace(char * string, const char findThis, const char replaceWith)
{
    int counter = 0;
    int i = 0;
    while (string[i])
    {
        if (string[i] == findThis)
        {
            string[i] = replaceWith;
            counter += 1;
        }
    i++;
    return counter;
    }
}

void main()
{
    char testStr [30] = {"Who\nWhat\nWhere\nWhen\nWhy\nHow\n\n"};
    char find, replacement;
    printf("%s\n", testStr);
    printf("What character would you like to replace?:\n");
    find = getchar();
    getchar();
    printf("What character would you like to replace it with?:\n");
    replacement = getchar();
    getchar();
    printf("About to replace %c with %c!\n", find, replacement);
    replace(testStr, find, replacement);
    printf("\n\n%s\n\n", testStr);
}