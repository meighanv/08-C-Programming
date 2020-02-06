#include <stdio.h>
#include <string.h>

void main(void)
{
    char *token;
    char mystring [] = {"My string is this.\0"};
    char username [] = {0};
    //char *copy = (char *)malloc(strlen(mystring)+1);
    //strcpy(copy, mystring);
    token = strtok(mystring, " ");
    //puts(token);
    while (token != NULL)
    {
        char initial;
        char last [20];
        printf("%s\n", token);
        strcpy(last,token);
        initial = token[0];
        printf("%c\n", initial);
        printf("%s\n", last);
        token = strtok(NULL, " ");
        printf("%p\n", token);

    }
}