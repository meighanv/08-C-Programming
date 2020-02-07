#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Write a program that allocates space for three int values-- an array. 
//You need to use only one malloc() function to accomplish this task. 
//Assign 100, 200, and 300 to each int, and then display all three values.

int main()
{
    int *values;
    int size = 3;
    values = (int *)malloc(size*sizeof(int));
    values[0] = 100;
    values[1] = 200;
    values[2] = 300;
    for (int i = 0; i < size; i++)
    {
        printf("Value %d is %d.\n",i+1,values[i]);
    }
    free(values);
}