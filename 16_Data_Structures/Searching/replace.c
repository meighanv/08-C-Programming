#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int flushIn()
{
    char c;
    while ((c = fgetc(stdin)) != '\n' && c != EOF);
}

int main()
{
    FILE * fileptr;
    char string [256]; // declare variable holder for printing content a line at a time
    char input [256];
    char * find;
    char * replace;
    char * token;
    if( (fileptr = fopen("replace.txt", "r") ) == NULL) //If file cannot be read (permissions issue)
    {
        puts("File could not be opened."); // print this message
    }
    else // otherwise
    {
        puts("Enter the word you would like to find:");
        scanf("%s",&input);
        flushIn();
        find = (char *)calloc(strlen(input)+1,sizeof(char));
        strcpy(find,input);

        puts("Enter the word you would like to replace it with:");
        scanf("%s",&input);
        flushIn();
        replace = (char *)calloc(strlen(input)+1,sizeof(char));
        strcpy(replace,input);

        while (!feof(fileptr)) //whle the file pointer is not at EOF
        {
            fgets(string, 255, fileptr); //get 255 characters from the file
            token = strtok(string, " ");
            while (token != NULL)
            {
                
                if (strcmp(token,find))
                {
                    printf("%s ",replace);
                    token = strtok(NULL, " "); //
                }
                else
                {
                    printf("%s ", token);
                    token = strtok(NULL, " ");
                }
                
            }
            
            
        }
    }
}