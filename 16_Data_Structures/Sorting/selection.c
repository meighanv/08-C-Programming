#include <stdio.h>
#define size(x) sizeof(x)/sizeof(x[0])

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
  int data[] = {20, 12, 10, 15, 2, 52, 1, 28, 77};
  //int size = sizeof(data) / sizeof(data[0]);
  selectionSort(data, size(data));
  printf("Sorted array in Acsending Order:\n");
  printArray(data, size(data));
}