#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char buffer [120] = {0}; //creating an input buffer
    char *output; // creating a pointer to a char array
    fgets(buffer,20, stdin); // Getting input from stdin to store in buffer
    output = (char *)malloc(strlen(buffer)*sizeof(char)); //allocating memory to char array ptr based on length of string in buffer
    strcpy(output,buffer); //calling strcpy to copy buffer string to dynamically allocated memory
    fputs(output,stdout); //printing copied string to screen
    output = realloc(output, 0); //freeing up memory by reallocating size to 0; could also use free(ptr)
    return 0; //return 0 to exit main()
}