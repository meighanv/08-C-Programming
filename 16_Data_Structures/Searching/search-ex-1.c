#include <stdio.h>

int search(int * arr, int len, int num)
{
    
    for (int i = 0; i < len; i++ )
    {
        if(*arr == num)
        {
            printf("%d is located at position %d.\n", num, i );
            return 0;
        }
        else
        {
            arr++;
        }
        
    }
    return -1;
}

int main(void)
{
    int arrLen;
    int * myArray;
    char c;

    printf("Enter the length of the integer array:\n");
    scanf("%d", &arrLen);
    while ((c = fgetc(stdin)) != '\n' && c != EOF); /* Flush stdin */
    myArray = (int *)malloc(sizeof(int)*arrLen);
    
    for (int i = 0; i < arrLen; i++)
    {
        printf("Enter the integer for position %d:\n", i);
        scanf("%d", &myArray[i]);
        while ((c = fgetc(stdin)) != '\n' && c != EOF); /* Flush stdin */

    }

    int find;
    printf("What number would you like to find in you array?:\n");
    scanf("%d", &find);
    while ((c = fgetc(stdin)) != '\n' && c != EOF); /* Flush stdin */
    search(myArray,arrLen,find);

    return 0;        
}