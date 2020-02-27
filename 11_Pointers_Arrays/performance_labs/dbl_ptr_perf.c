#include <stdio.h>

int main()
{
    // Integer variable
    int num1;

    // Pointer to integer
    int * ptr;
    ptr = &num1;

    // Pointer to integer pointer
    int **dPtr;
    dPtr = &ptr;

    /* Change the value of num directly */
    num1 = 10;
    printf("num1 is %d\n", num1);

    /* Assigns 100 using pointer to integer */
    *ptr = 100;
    printf("num1 is %d\n", num1);

    /* Assigns 1000 using pointer to integer pointer */
    **dPtr = 1000;
    printf("num1 is %d\n", num1);

    return 0;
    
}