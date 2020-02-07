//Modify the source code below and create a second char buffer by using
// a pointer and malloc(). After text is read by the fgets() function, 
//copy that text from the first buffer(input - from the code) into the 
//second buffer, all the text except for the newline character, \n at 
//the end of input.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *input;
    char *second; //second char buffer
    
    input = (char *)malloc(sizeof(char)*1024);
    if(input==NULL)
    {
        puts("Unable to allocate buffer! Oh no!");
        exit(1);
    }
    puts("Type something long and boring:");
    fgets(input,1023,stdin);
    puts("You wrote:");
    //printf("\"%s\"\n",input);
    second = (char *)malloc(sizeof(char) * strlen(input));
    //strcpy(second,input);
    for (int i = 0; i < strlen(input); i++)
    {
        if(input[i]==10)
        {
            break;
        }
        else if (tolower(input[i])==97 || tolower(input[i])==101|| tolower(input[i])==105||tolower(input[i])==111||tolower(input[i])==117)
        {
            second[i]=64;
        }
        else
        {
            second[i]=input[i];
        }
        
    }
    printf("\n\"%s\"\n",second);

    free(input);
    free(second);

    return(0);
}
