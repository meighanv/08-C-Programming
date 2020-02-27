/*
# PERFORMANCE LAB 18
### CONTINUE

* Input an unsigned integer "x".
* Print the first 10 to 20 positive integers that x is divisible by utilizing the **mod** operator (not the most efficient)
* Repeat this process.
* Immediately stop this process when the user inputs an integer above 999.
* Ignore any "divide by 0" errors using *continue*.
*/

#include <stdio.h>
#include <stdint.h>
#include <math.h>

void main()
{
    int userInput = 0;
    int resultCount = 0;
    int i = 1;
    printf("Please enter a number less than 1000:\n");
    fscanf(stdin, "%d", &userInput);
    while (i <= sqrt(userInput) && resultCount < 20)
    {
        if (userInput > 999)
        {
            printf("The number input was too large.\n");
            break;
        }
        if (userInput % i == 0)
        {
            printf("%d, %d, ", i, userInput/i);
        }
        i++;
        resultCount += 2;
    }
    printf("\n");
}