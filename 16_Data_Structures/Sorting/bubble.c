#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size(x) sizeof(x)/sizeof(x[0])

int flushIn()
{
    char c;
    while ((c = fgetc(stdin)) != '\n' && c != EOF);
}

void swap (int * a, int * b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

void bubbleSort(int * list, int last)
{
    while (1==1)
    {
        int swapped = 0;
        for (int i = 0;i < last-1; i++)
        {
            if (list[i] > list[i+1])
            {
                swap(&list[i],&list[i+1]); // since pointers are expected, addresses (&) must be passed as args
                swapped = 1;
            }
        }
        if (swapped == 0)
        {
            break;
        }
    }
}

int main()
{
    int elements [5] = {4,2,3,7,1};
    // start bubble sort
    bubbleSort(elements, size(elements));
    
    for (int i = 0; i < size(elements); i++)
    {
        printf("%d ", elements[i]);
    }
    printf("\n");
}