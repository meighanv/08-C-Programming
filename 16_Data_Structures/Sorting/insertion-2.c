#include <stdio.h>
#define cMax_Ary_Size 15

//	Constants
//const int cMax_Ary_Size = 15;

/*	Prototype Declarations */
int insertionSort (int* list, int last);
	
int main ( void ) 
{
/*	Local Declarations */
	int countExch;
	int	ary[cMax_Ary_Size] = {89, 72, 3,  15, 21, \
	                           57, 61, 44, 19, 98, \
	                            5,  77, 39, 59, 61};

/*	Statements */
	printf( "Unsorted array: ");
	for (int i = 0; i < cMax_Ary_Size; i++ )
		printf( "%3d", ary[ i ] );
		
	countExch = insertionSort ( ary, cMax_Ary_Size - 1);

	printf( "\nSorted array:   " );
	for (int i = 0; i < cMax_Ary_Size; i++)
		printf( "%3d", ary[ i ] );
	printf( "\n" );
	
	printf("Total exchanges: %d\n", countExch);
	return 0;
}	/* main */

/*	================== insertionSort ==================== 
	Sort list using Insertion Sort. The list is divided 
	into sorted and unsorted lists. With each pass,  
	first element in unsorted list is inserted into 
	sorted list.
	   Pre    list must contain at least one element
	          last is index to last element in the list
	   Post   list rearranged, exchange counted
	   Return count of exchanges
*/
int insertionSort (int* list, int last) // last is expected to be the last index
{
    int count = 0; // counter for num of exchanges
    for (int step = 1; step < last+1; step++)
    {
        int key = list[step]; // This step is counted as an exchange. Sets the key to the current element, but works it's way to the end of array.
        count++;
        int j = step - 1; //setup j as index of previous element
        while (key < list[j] && j >= 0) //as long as value of key is less than the current element at index j and j >= 0
        {
            // For descending order, change key<array[j] to key>array[j].
            list[j + 1] = list[j]; // set element after list[j] to next element
            count++;// This step is counted as an exchange
            --j; // decrement j to run while check again
        }
        list[j + 1] = key; //once complete the element after the most recently moved becomes the key
        count++;// This step is counted as an exchange
        }
        return count;
}	// insertionSort

/*
Results:
Unsorted array:  89 72  3 15 21 57 61 44 19 98  5 77 39 59 61
Sorted array:     3  5 15 19 21 39 44 57 59 61 61 72 77 89 98
Total exchanges: 76
*/