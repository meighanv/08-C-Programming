#include <stdio.h>
#include <stdlib.h>
#include "TestCode.h"
#define size(x) sizeof(x)/sizeof(x[0])
/*


Write the function arrayManipulate that receives two parameters:
arr - a pointer to an array of integer 
size - an int indicating the size of the array

The function must iterate over the array using an integer pointer and pointer 
arithmetic (required) to access each element of the array and to possibly change 
the contents of the array. The contents will be changed according to the following:

If the value in the element is an even number and greater than six (6), then 
square the contents of the element.  For example, if the element originally contained 
a 12, it will now contain 144.

Otherwise, if the value in the element is an odd number or it is greater than two (2), 
then double the contents in the element. For example if the element originally 
contained a 5, it will now contain 10.

Once the array has been updated and fully iterated, sort the array in ascending order 
using any sorting algorithm.

Lastly, after sorting: 
	if the array has an even number of elements, the function should return the sum 
    of the middle two elements.  For example, if the array has eight (8) elements, 
    return the sum of the contents of element three(3) and four(4). 
    
	If the array has an odd number of elements, return the contents of just the middle element.

If the size passed to the array is less than 2, the function should return a -1.

*/

// Defining swap function used for bubbleSort()
void swap (int * a, int * b)
{
    // performs xor swap on the dereferenced pointers passed into swap()
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

// defining bubbleSort function; 'last' arg is array size
void bubbleSort(int * list, int last)
{
    //while True 
    while (1==1)
    {
        // set swapped tracker to 0; if any element is swapped this flag is turned on
        int swapped = 0;
        // Loop through each element in the array
        for (int i = 0;i < last-1; i++)
        {
            // if current element is greater than next element
            if (list[i] > list[i+1])
            {
                // Call swap() to exchange the elements at those locations
                swap(&list[i],&list[i+1]); // since pointers are expected, addresses (&) must be passed as args
                // turn swapped flag on 
                swapped = 1;
            }
        }
        // inside of the while loop sort is complete if no items were swapped (i.e. swapped == 0)
        if (swapped == 0)
        {
            break;
        }
    }
}

//define the arrayManipulate function
int arrayManipulate(int *arr, int size)
{
    // Checking for appropriate size of array
    if (size < 2)
    {
        return -1; // If less than two return -1
    }
    // Otherwise ...
    int * arrPtr = arr; // setting a new pointer variable to iterate through array
    for (int i = 0; i < size; i++ ) //iterating through array elements based on size
    {
        if (*arrPtr % 2 == 0 && *arrPtr > 6) //checking for even number > 6
        {
            *arrPtr = *arrPtr * *arrPtr; //squaring the value at the dereferenced pointer
        }
        else if(*arrPtr % 2 != 0 || *arrPtr > 2)//checking for odd num or number > 2
        {
            *arrPtr *= 2; //doubling the dereferenced pointer value
        }
        arrPtr++; // moving pointer to next value
    }
    bubbleSort(arr,size); //calling bubble sort on manipulated array
    int midSum = 0;// setting a variable for return value of middle element(s)
    
    if (size%2 == 0) // checking for an even size
    {
        midSum = arr[size/2] + arr[(size/2)-1]; //setting midSum to the sum of the two middle elements
    }
    else // otherwise, assuming the size is odd...
    {
        midSum = arr[size/2]; // setting midSum to middle element
    }
    
    
    return midSum;//returning midSum to calling function
}

// Below is used for test cases since the environment Tasks were unavailable
// void main(void)
// {
//     int size = 9;
//     int a [] = {22, 15, 6, 7, 8, 9, 12, 3, 18};
//     int b [] = {6, 12, 14, 18, 30, 64, 144, 324, 484};
//     int x [] = {2, 5, 6, 7, 8, 9, 12, 3, 1, 18};
//     int y [] = {2, 2, 6, 10, 12, 14, 18, 64, 144, 324};
//     int c [] = {22, 0};
//     int z = arrayManipulate(c, 2);

//     for(int i = 0; i < size; i++)
//     {
//         printf("%d ", x[i]);
//     }
//     printf("\n%d\n", z);

// }
