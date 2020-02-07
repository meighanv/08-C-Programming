#include <stdio.h>
#include <string.h>
#define arrItems(x) sizeof(x)/sizeof(x[0])

typedef struct 
{
    unsigned int month;
    unsigned int day;
    unsigned int year;
    unsigned int deaths;
    double maxHgt;
    char * name [10];
} tsunami;

int report(tsunami *x, int items)
{
    
    double avgMax = 0;
    double totMax = 0;
    tsunami max = {0, 0, 0, 0, 0, ""};

    for (int i = 0; i <= items; i++)
    {
        totMax += x[i].maxHgt;
        if (x[i].maxHgt > max.maxHgt)
        {
            max = x[i];
        }
                    
    }
        
        avgMax = totMax/items;

    //printf("Name\tYear\tStrength\n-----------------------\n");
    printf("Summary information for tsunamis.\n");
    printf("Maximum wave height (in feet): %.2f\n", max.maxHgt);
    printf("Average wave height (in feet): %.2f\n",avgMax);
    printf("Tsunamis w/ greater than average height:\n");
    for (int i = 0; i < items; i++)
    {
        if (x[i].maxHgt >= avgMax)
        {
            printf("%s",x[i].name);
        } 
    
    }
}

int main()
{
    char line [39] = {0};
    char *item;
    int count = 0;
    tsunami events [11] = {0};
    FILE * fileptr; //declare file pointer for source file
    
    if( (fileptr = fopen("waves2.txt", "r") ) == NULL) //If file cannot be read (permissions issue)
    {
        puts("File could not be opened."); // print this message
    }
    else
    {
        while (fgets(line,40,fileptr))
        {
            if (line[0] != 13)
            {
                //printf("%s", line);

                
                item = strtok(line," ");
                events[count].month = atoi(item);
                //printf("%d ",events[count].year);

                item = strtok(NULL," ");
                events[count].day = atoi(item);
               
                item = strtok(NULL," ");
                events[count].year = atoi(item);
               
                item = strtok(NULL," ");
                events[count].deaths = atoi(item);

                item = strtok(NULL," ");
                events[count].maxHgt = atoi(item);
                //printf("%d \n",events[count].strength);

                item = strtok(NULL," ");
                strcpy(events[count].name, item);
                //printf("%s ",events[count].name);
                count++;
            }
        }
        //printStorm(events);
        
        //int elements = sizeof(events)/sizeof(events[0]);
        //double avgMax = 0;
        //double totMax = 0;
        //tsunami max = {0, 0, 0, 0, 0, ""};

        //for (int i; i < elements; i++)
        //{
        //    totMax += events[i].maxHgt;
        //    if (events[i].maxHgt > max.maxHgt)
        //    {
        //        max = events[i];
        //    }
        //                
        //}
        //    
        //    avgMax = totMax/elements;

        //printf("Name\tYear\tStrength\n-----------------------\n");
        //printf("Summary information for tsunamis.\n");
        //printf("Maximum wave height (in feet): %.2f\n", max.maxHgt);
        //printf("Average wave height (in feet): %.2f\n",avgMax);
        //printf("Tsunamis w/ greater than average height:\n");
        //for (int i = 0; i < elements; i++)
        //{
        //    if (events[i].maxHgt >= avgMax)
        //    {
        //        printf("%s",events[i].name);
        //    } 
        //
        //}

        report(events, arrItems(events));        
    }
}