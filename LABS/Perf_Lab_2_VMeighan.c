/*
Name: Vernon Meighan
Date: 20200106
Project: This program will take input of an amount of days and 
convert to the number of years, weeks, and days
*/

#include <stdio.h>

int main(void)
{
    int days, weeks, years, remDays = 0;

    printf("Please provide the amount of days:\n");
    scanf("%d", &days);

    years = days / 365;
    remDays = days - (years * 365);
    weeks = remDays / 7;
    remDays = remDays - (weeks * 7);

    printf("%d days = %d years, %d weeks, and %d days. \n ", days, years, weeks, remDays);

    return 0;

}