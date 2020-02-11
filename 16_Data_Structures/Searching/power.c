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

int arrTotal (int *arr, int rows, int cols)
{
    int total = 0;
    for (int row = 0; row < rows; row++ )
    {
        for (int col = 0; col < cols; col++)
        {
            total += *((arr+row*cols) +col);
        }
    }
    return total;
}

float calcAvg (int sum, int rows, int cols)
{
    float avg = 0.0; 
    avg = (float)sum/(rows*cols);
    return avg;
}

int overAvg (int *arr, int rows, int cols, float avg)
{
    int total = 0;
    for (int row = 0; row < rows; row++ )
    {
        for (int col = 0; col < cols; col++)
        {
            if (*((arr+row*cols)+col) > avg)
            {
                total++;
            }
        }
    }
    return total;
}

// Setting the size of the dimensions
const int NROWS = 8;
const int NCOLS = 7;

int main()
{    
    int elements [NROWS][NCOLS];//Declaring elements table with dimensions
    
    int rows;//setting dimension counters
    int cols;
    char string [256] = {0}; //Setting char string buffer - Zeroed out

    FILE * fileptr; //Setting file pointer
    if( (fileptr = fopen("power1.txt", "r") ) == NULL) //If file cannot be read (permissions issue)
    {
        puts("File could not be opened."); // print this message
    }
    else // otherwise
    {
        rows = 0; //initializing row counter
        while (NULL != fgets(string,255,fileptr))//Until we reach the end of the file
        {
            cols = 0;//initialize column counter
            const char *colData = string; //initializing the colData and storing the first line 
            char * token = strtok(colData, " "); //setting token with " " as delimeter
            while (cols < NCOLS && token != NULL) //Loop to get the expected number of elements in the row
            {
                elements[rows][cols++] = atoi(token);// converting the current token to an int to be stored as a single element
                token = strtok(NULL, " ");//move token to next delimeter
            }
            rows++; // move to next row
        }
    }
    fclose(fileptr);//closing file

    int periodTot = arrTotal(elements,NROWS,NCOLS); //Call periodTot to return the total wattage used
    float average = calcAvg(periodTot,NROWS,NCOLS); // call calcAvg to return average
    int over = overAvg(elements,NROWS,NCOLS,average);

    printf("The total power output over 8 weeks was %d.\n",periodTot);
    printf("The total days with greater than average output was %d\n",over);


}