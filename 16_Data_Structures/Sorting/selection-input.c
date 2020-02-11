#include <stdio.h>
#include <string.h>
#define size(x) sizeof(x)/sizeof(x[0])

void flushIn()
{
    char c;
    while ((c = fgetc(stdin)) != '\n' && c != EOF);
}

void swap (int * a, int * b)
{
    if (*a != *b) // this is necessary to ensure that the xor operation doesn't 0 out an equivalent value
    {
        *a ^= *b;
        *b ^= *a;
        *a ^= *b;
    }
}

void selectionSort(int array[], int size)
{
  for (int step = 0; step < size - 1; step++)
  {
    int min_idx = step;
    for (int i = step + 1; i < size; i++)
    {
      if (array[i] < array[min_idx])
        min_idx = i;
    }
    swap(&array[min_idx], &array[step]);
  }
}

void printArray(int array[], int size)
{
  for (int i = 0; i < size; ++i)
  {
    printf("%d  ", array[i]);
  }
  printf("\n");
}


int main()
{
    int data[] = {20, 12, 10, 15, 2, 52, 1, 28, 77}; //Static array for original code
    
    //This section is to get user input into an array
    int num; //declare variable for storage of user input for array size
    puts("How many elements in your array:"); //User prompt for input
    scanf("%d", &num); //input
    flushIn(); //flushing stdin
    //int size = sizeof(data) / sizeof(data[0]); //replaced by macro
    int myArray [num]; //declaring array with size determined by user
    char buffer [128] = {0}; //creating a buffer to store user input string
    puts("Enter numbers separated by spaces:"); // prompt user
    fgets(buffer,127,stdin);// get numbers from user
    char * colData; // Create pointer variable to store pointer for buffered string
    colData = (char *)malloc(sizeof(char)*strlen(buffer)); //allocating memory based on buffer data
    strcpy(colData, buffer); // copy string from buffer to newly allocated space in colData
    char * token = strtok(colData," "); //declaring token variable and setting it to first number in string
    for (int i = 0; i < size(myArray); i++) // looping through each element in the array
    {
        myArray[i] = atoi(token); //setting the element to the converted value of the token string
        token = strtok(NULL, " "); // move token marker to next delimited string
    }

    printArray(myArray, size(myArray)); //Array before
    selectionSort(myArray, size(myArray)); 
    printArray(myArray, size(myArray));  //Array after


    selectionSort(data, size(data));
    printf("Sorted array in Acsending Order:\n");
    printArray(data, size(data));
}