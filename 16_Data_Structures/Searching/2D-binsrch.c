#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int flushIn()
{
    char c;
    while ((c = fgetc(stdin)) != '\n' && c != EOF);
}

int binarySearch(const int *arr, int l, int r, int k){
	if(l >r){
		return -1;
	} else{
		int m = (l + r) / 2;

	if(arr[m] == k){
		return m;
	}else if (k < arr[m]){
		return binarySearch(arr, l , m-1, k);
	} else if(arr[m] < k) {
		return binarySearch(arr, m+1, r, k);
	}
    }
}

const int row_max = 10;
const int col_max = 10;

int main()
{
    
    int elements [5][6] = {0};
    
    int rows;
    int cols;
    char string [256] = {0};
    FILE * fileptr;
    if( (fileptr = fopen("numbers.txt", "r") ) == NULL) //If file cannot be read (permissions issue)
    {
        puts("File could not be opened."); // print this message
    }
    else // otherwise
    {
        
        rows = 0;
        while (NULL != fgets(string,255,fileptr))
        {
            cols = 0;
            const char *colData = string;
            char * token = strtok(colData, " ");
            while (cols < 6 && token != NULL)
            {
                elements[rows][cols++] = atoi(token);
                token = strtok(NULL, " ");

            }
            rows++;
        }
    }

    //int rowTrack = 0;
    int find = 0;
    fputs("Provide an integer to find in the matrix:",stdout);
    scanf("%d", &find);
    flushIn();

    for (int i = 0; i<row_max; i++)
    {
        int found = binarySearch(elements[i], 0, 5,find);
        if (found != -1)
        {
            printf("%d was found at %d, %d.\n",find, i, found);
            break;
        }
        //rowTrack++;

    }


}