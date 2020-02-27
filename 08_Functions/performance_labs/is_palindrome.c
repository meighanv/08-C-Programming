/*
Write a recursive function that returns a value of 1 if its 
string argument is a palindrome, 0 otherwise. Notice that in 
palindromes such as level, deed, sees, and madam...the first
letter matches the last.
*/

#include <stdio.h>
#include <string.h>

int is_palindrome(char *string, int start, int end) //end should be the count of elements and start should always be input as 0
{
    if (start == end)// base case 1
    {
        return 1;
    }
    if (string[start] != string[end]) // base case 2
    {
        return 0;
    }
    if (start < end + 1)// checks the positions of the probes start and end to see if recursion needs to go in the middle
    {
        return is_palindrome(string, start + 1, end - 1); // recursive call for function
    }
}

int main(int argc, char **argv)
{
    char string [256] = {0}; 
    strcpy(string, argv[1]); //strcpy argc to string 
    //printf("Please type a single word:\n"); // Prompt user
    //fscanf(stdin, "%255s", string); // limit input to 19 real characters plus null char

    int start = 0; // starting point for recursive palindrome detection
    int end = strlen(string) - 1; // endpoint for string
    
    if (is_palindrome(string, start, end) == 1) // calling simulated boolean function to determine if it's a palindrone
    {
        printf("Your string '%s' is a palindrome.\n", string); // if boolean function returns as true, notifies user that it is a palindrome
    }
    else
    {
        printf("Your string '%s' is NOT a palindrome.\n", string); // if boolean function returns as true, notifies user that it is a NOT palindrome
    }
    
}