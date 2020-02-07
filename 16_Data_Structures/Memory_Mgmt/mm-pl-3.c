#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//kelvin = celsius + 273.15
//kelvin = (fahrenheit + 459.67) * (5.0/9.0);

float kelvin(float *temp, char * selection)
{
    float kelvin = 0.0;
    if (tolower(*selection) == 'c')
    {
        printf("Your temperature of %f Celcius in Kelvin is:\n ",*temp);
        return (*temp + 273.15); 
    }
    else if (tolower(*selection) == 'f')
    {
        printf("Your temperature of %f Fahrenheit in Kelvin is:\n ",*temp);
        return (*temp + 459.67) * (5.0/9.0);
    }
    else
    {
        printf("Invalid Input for temp type.\n");
        return 0.0;
    }
    
}


int main(void)
{
    float *temp;
    char *selection;
    char buffer [120] = {0};
    char c;
    printf("Please provide the temperature outside:\n");
    temp = (float *)malloc(sizeof(float));
    fscanf(stdin, "%f", temp);
    while ((c = fgetc(stdin)) != '\n' && c != EOF); /* Flush stdin */
    printf("Was the temperature Celcius or Fahrenheit; type C or F:\n");
    selection = (char *)malloc(sizeof(char));
    fgets(buffer,119,stdin);
    strcpy(selection,buffer);
    
    printf("%f\n",kelvin(temp,selection));
    free(selection);
    free(temp);
    
}