#include <stdio.h>

#define sizeRows(x) sizeof(x)/sizeof(x[0])
#define sizeCols(x) sizeof(x[0])/sizeRows(x)


int main()
{
    int myArray [4] [6] = {0};
    int rows, cols;
    rows = sizeRows(myArray);
    cols = sizeof(myArray)[0]/rows;
    printf("%d rows, %d columns.\n", sizeRows(myArray), cols);

}