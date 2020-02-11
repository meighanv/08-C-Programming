#include <stdio.h>
#define size(x) sizeof(x)/sizeof(x[0])

int search(int * arr, int len, int num)
{
    
    for (int i = 0; i < len; i++ )
    {
        if(*arr == num)
        {
            //printf("%d is located at position %d.\n", num, i );
            return 0;
        }
        else
        {
            arr++;
        }
        
    }
    return -1;
}

int diff(int *arr1, int *arr2, int len1, int len2)
{
    printf("The difference between the two arrays is:\n");
    for (int i = 0; i < len1; i++)
    {
        if (search(arr2,len2,arr1[i]) == -1)
        {
            printf("%d ",arr1[i]);
        }        
    }

    printf("\n");
    for (int i = 0; i < len2; i++)
    {
        if (search(arr1,len1,arr2[i]) == -1)
        {
            printf("%d ",arr2[i]);
        }        
    }
    printf("\n");
}

int printArr(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
        
    }
    printf("\n");
}

int main(void)
{
    int arrLen;
    int myArray1 [] ={0,1,2,3,4};
    int myArray2 [] ={0,1,4,5,6,7};
    char c;

    // printf("Enter the length of the 1st integer array:\n");
    // scanf("%d", &arrLen);
    // while ((c = fgetc(stdin)) != '\n' && c != EOF); /* Flush stdin */
    //myArray1 = (int *)malloc(sizeof(int)*arrLen);
    
    // for (int i = 0; i < arrLen; i++)
    // {
    //     printf("Enter the integer for position %d:\n", i);
    //     scanf("%d", &myArray1[i]);
    //     while ((c = fgetc(stdin)) != '\n' && c != EOF); /* Flush stdin */

    // }

    // printf("Enter the length of the 2nd integer array:\n");
    // scanf("%d", &arrLen);
    // while ((c = fgetc(stdin)) != '\n' && c != EOF); /* Flush stdin */
    // //myArray2 = (int *)malloc(sizeof(int)*arrLen);
    
    // for (int i = 0; i < arrLen; i++)
    // {
    //     printf("Enter the integer for position %d:\n", i);
    //     scanf("%d", &myArray2[i]);
    //     while ((c = fgetc(stdin)) != '\n' && c != EOF); /* Flush stdin */

    // }
    printArr(myArray1,size(myArray1));
    printArr(myArray2,size(myArray2));
    diff(myArray1,myArray2,size(myArray1),size(myArray2));
    
    return 0;        
}