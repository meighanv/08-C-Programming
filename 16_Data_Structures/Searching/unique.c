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

int unique(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        int found = 0;
        int current = arr[i];
        for (int j = 0; j < len; j++)
        {
            if (current == arr[j])
            {
                found++;
                if (found > 1)
                {
                    break;
                }
            }
        }
        if (found < 2)
        {
            printf("%d ", current);
        }
    }
}

int main(void)
{
    int arrLen;
    int myArray1 [] ={0,1,2,1,0};
    int myArray2 [] ={0,1,4,4,6,7};
    char c;

    
    printArr(myArray1,size(myArray1));
    printArr(myArray2,size(myArray2));
    //diff(myArray1,myArray2,size(myArray1),size(myArray2));
    unique(myArray1,size(myArray1));
    printf("\n");
    unique(myArray2,size(myArray2));
    printf("\n");
    return 0;        
}