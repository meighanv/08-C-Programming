/*
Name: Vernon Meighan
Date: 20200108
Project: 
Formatted Input (Strings)
- Read a string into a char array
- Specify a field-width to protect against buffer overflow
- Ensure the field-width leaves room for the nul-terminator
- Stop reading at the first capital letter or new line

Formatted Input (Numbers)
- Read three ints, representing the date, from one line
- Format the input so the integers are separated by a dash (-) as <mm>-<dd>-<yyyy>
- Output the results as a date with leading zeros <mm>/<dd>/<yyyy>
- Specify the field width of the output appropriately

Perf Lab 8
Formatted Input (strings)
- Read a first, middle and last name as input into separate char arrays
- Specify a field-width to protect against buffer overflow
- Ensure the field-width leaves room for a nul-terminator
- Specify a ("\t") as a delimitating character
- Print the full name, separating each string with a tab and newline ("\t\n")

Formatted Input (numbers)
- Read two integers from one line
- Format the input so that the integers are separated by an asterisk (*) x*y (e.g., 2*3, 11*14)
- Reprint the two integers and result as if the answer were being read by a human
*/

#include <stdio.h>

void miniPhrase(void) //Demo Lab 4
{
    char myString [10] = {0}; //set empty string
    printf("Please enter a string of 9 or less characters:\n"); //prompt user
    scanf("%9[^A-Z]s", &myString); // Stops reading at Capital letters; had to leverage regex to make this work
    printf("%s\n", myString); //Prints input
}

void getDate(void) //Demo Lab 5
{
    int month = 0; // Setting vars for date parts
    int day = 0;
    int year = 0;
    printf("Please enter a date in the format <mm>-<dd>-<yyyy> :\n"); //prompting user input with format instructions
    scanf("%d%*c%d%*c%d", &month, &day, &year); // Formatting the input to skip non-digit characters and move to next var
    printf("%02d/%d/%d\n", month, day, year); // Printing back input as different format
}

void getName(void) //Perf Lab 8 part I
{
    char first [10] = {0}; // Setting vars for name parts
    char middle [10] = {0};
    char last [10] = {0};
    printf("Please enter full name using TABs after each part:\n"); //prompting user input with format instructions
    scanf("%s\t%s\t%s", &first, &middle, &last); // Formatting the input to use tabs as delimeter
    printf("%s\t\n%s\t\n%s\n", first, middle, last); // Printing back input in different format
}

void multiply(void) //Perf Lab 8 part II
{
    double x = 0; // Setting vars for multiplication
    double y = 0;
    double product = 0; // Init var to store the result of the math operation

    printf("Please enter a multiplication problem (Ex: x*y):\n"); //prompting user input with format instructions
    scanf("%lf*%lf", &x, &y); // Formatting the input to use * as delimeter
    product = x * y;
    printf("%lf times %lf equals %lf.\n", x, y, product); // Printing back English description of the math and result
}




void main(void)
{
    //miniPhrase(); //demo lab 4
    getDate(); //demo lab 5
    //getName(); //perf lab 8
    //multiply(); //perf lab 8
}
