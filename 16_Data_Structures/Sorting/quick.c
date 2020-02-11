#include <stdio.h>
#include <stdlib.h>
/*
1. Select an element pivot from the array elements. 
2. Rearrange the elements in the array in such a way that all elements 
that are less than the pivot appear before the pivot and all elements 
greater than the pivot element come after it (equal values can go either 
way). After such a partitioning, the pivot is placed in its final 
position. This is called the partition operation.•3. Recursively sort 
the two sub-arrays thus obtained. (One with sub-list of values smaller 
than that of the pivot element and the other having higher value elements.)
*/
void swap (int * a, int * b)
{
    if (*a != *b) // this is necessary to ensure that the xor operation doesn't 0 out an equivalent value
    {
        *a ^= *b;
        *b ^= *a;
        *a ^= *b;
    }
}

/* This function takes last element as pivot, places 
the pivot element at its correct position in sorted 
    array, and places all smaller (smaller than pivot) 
to left of pivot and all greater elements to right 
of pivot */
int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high]; // pivot 
    int i = (low - 1); // Index of smaller element 

    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than the pivot 
        if (arr[j] < pivot) 
        { 
            i++; // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 

/* The main function that implements QuickSort 
arr[] --> Array to be sorted, 
low --> Starting index, 
high --> Ending index */
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
        at right place */
        int pi = partition(arr, low, high); 

        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 

/* Function to print an array */
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 

// Driver program to test above functions 
int main() 
{ 
    int arr[] = {10, 7, 4, 3, 9, 1, 5}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    quickSort(arr, 0, n-1); 
    printf("Sorted array: \n"); 
    printArray(arr, n); 
    return 0; 
}