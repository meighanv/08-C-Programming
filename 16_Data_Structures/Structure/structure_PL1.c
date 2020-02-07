#include <stdio.h>
#include <string.h>
//#define elements(x) sizeof(x)/sizeof(x[0])

typedef struct 
{
    char * name [10];
    unsigned int year;
    unsigned int strength;
} storm;

void printStorm (storm *list)
{
    printf("Name\tYear\tStrength\n-----------------------\n");
    
    int elements = sizeof(list)/sizeof(list[0]);
    for (int i; i < elements; i++)
    {
        if (list[i].year >= 1960 && list[i].year <= 1960)
        {
            printf("%s\t%d\t%d\n",list[i].name, list[i].year, list[i].strength);
        } 
        
    }
}

int main()
{
    char line [99] = {0};
    char *item;
    int count = 0;
    int k;
    storm storms [13];
    FILE * fileptr; //declare file pointer for source file
    
    if( (fileptr = fopen("storms2.txt", "r") ) == NULL) //If file cannot be read (permissions issue)
    {
        puts("File could not be opened."); // print this message
    }
    else
    {
        while (fgets(line,100,fileptr))
        {
            if (line[0] != 13)
            {
                //printf("%s", line);

                item = strtok(line,"\t");
                strcpy(storms[count].name,item);

                //printf("%s ",storms[count].name);
                
                item = strtok(NULL,"\t");
                storms[count].year = atoi(item);
                //printf("%d ",storms[count].year);

                item = strtok(NULL,"\t");
                storms[count].strength = atoi(item);
                //printf("%d \n",storms[count].strength);

                count++;
            }
        }
        //printStorm(storms);
        
        int elements = sizeof(storms)/sizeof(storms[0]);
        
        printf("Name\tYear\tStrength\n-----------------------\n");
        for (int i=0; i < elements; i++)
        {
            if (storms[i].year >= 1960 && storms[i].year <= 1969)
            {
                printf("%s\t%d\t%d\n",storms[i].name, storms[i].year, storms[i].strength);
            } 
        
        }
        
    }
}

