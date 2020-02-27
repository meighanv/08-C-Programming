/*
Name: Vernon Meighan
Date: 20200107
Project: This is meant to complete demo lab 1 for arrays
*/

#include <stdio.h>
// This was an attempt to create a function to get the length (# of Elements) of an array 
int len(int intArray, int arrSize)
{
    //printf("%d\n", intArray[1]);
    //printf("%d\n", (int)sizeof(intArray));  
    //printf("%d\n\n", (int)sizeof(intArray[0]));
    int x = (arrSize / sizeof(intArray[0]) ); 
    return x;
}

int main(void)
{
    int myIntArray [10] = {100};
    float myFloatArray [5] = {1,2,3,4,5};
    char myCharArray [256] = {0};

    //printf("The size of myIntArray is %d\n\n", (int)sizeof(myIntArray));
    //printf("The size of myFloatArray is %d\n\n", (int)sizeof(myFloatArray));
    //printf("The size of myCharArray is %d\n\n", (int)sizeof(myCharArray));

    //printf("The number of elements in myIntArray is %d\n\n", (int)sizeof(myIntArray)/sizeof(myIntArray[0]));
    //printf("The number of elements in myFloatArray is %d\n\n", (int)sizeof(myFloatArray)/sizeof(myFloatArray[0]));
    //printf("The number of elements in myCharArray is %d\n\n", (int)sizeof(myCharArray)/sizeof(myCharArray[0]));
    //printf("%d\n", myIntArray[2]);
    //printf("%f\n", myFloatArray[2]);
    //printf("%c\n", myCharArray[2]);

    for (int y=0; y<10; y++)
    {
        int x = (y+1) * 10;
        myIntArray[y] = x;
        //printf("%d\n", myIntArray[y]);
    }
    
    printf("%d\n", len(myIntArray, (int)sizeof(myIntArray)));
    
    for (int y=0; y<5; y++)
    {
        float x = y * 1.1;
        myFloatArray[y] = x;
        //printf("%f\n", myFloatArray[y]);
    }
    //printf("%d\n", len(myFloatArray));
    //printf("%d\n", len(myFloatArray, (int)sizeof(myFloatArray)));

    char inputStr [7] = {"Meighan"};
    int lenString = (int)sizeof(inputStr)/sizeof(inputStr[0]);
    for (int y=0; y<lenString; y++)
    {
        myCharArray[y] = inputStr[y];
        //printf("%c\n", myCharArray[y]);
    }

    //return 0;
}