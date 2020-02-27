/*
Name: Vernon Meighan
Date: 20200107
Project: This program will complete the following:
#Student ages
-Declare and zeroize an int array with a dimension equal to the number of students + 1
-Set index 0 with the age* of the instructor
-Fill the elements of the array with the ages* of the students starting with index 1
-Print the array
#Favorite quote
-Declare and initialize a char array with your favorite saying
-Ensure the last index is set to nul ('\0')
-Separate each word in the array with a new line character ('\n' or decimal value 10)
*/

#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[])
{
    printf("[");
    for (int y=0; y<=(int)sizeof(arr)/(int)sizeof(arr[0]); y++)
    {
        printf("%d", arr[y]);
        if (y == (int)sizeof(arr)/(int)sizeof(arr[0]))
        {
            printf("]\n");
        }
        else 
        {
            printf(", ");
        }
    }
}

void main()
{
    // Declaring a 0 initialized array for ages
    int ages [3] = {0};
    // Looping through each element of the array to input an age
    for (int y=0; y<(int)sizeof(ages)/(int)sizeof(ages[0]); y++)
    {
        // Initialize the variable for user input
        int x = 0;
        printf("Please provide the age of person %d:\n", (y+1) );
        // Capture user input
        scanf("%d", &x);
        // Set element to user input
        ages[y] = x;
    }

    printArray(ages);
    
    char phrase [] = {"Know thyself!\0"};
    for (int y=0; y<(int)sizeof(phrase)/(int)sizeof(phrase[0]); y++)
    {
        if((int)phrase[y] == 32)
        {
            printf("\n");
        }
        else if ((int)phrase[y] == 0)
        {
            printf("\n");
        }
        else 
        {
            // print each character
            printf("%c", phrase[y]);
        }
    }

    //printf("%d\n", phrase[4]);
    //printf("%d\n", phrase[13]);


}