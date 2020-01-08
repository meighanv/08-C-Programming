#define _CRT_SECURE_NO_WARNINGS 1            // Disables warning
#include <stdio.h>                           // Standard IO header

int main(void)
{
    char buff[10];                        // Will store string
    printf("Enter string: ");            // Prompts user
    fgets(buff, sizeof(buff), stdin);    // Stores user string
    printf("Your string was: ");         // Prefaces output
    fputs(buff, stdout);                 // Writes to stdout (puts() appears to include a newline at end of output)
    printf("\n");
}