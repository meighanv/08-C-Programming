/*
Name: Vernon Meighan
Date: 20200108
Project: 
**Arithmetic
- Write a program to calculate the hypotenuse of a right triangle
- Use the Pythagorean Theorem (a^2 + b^2 = c^2)
- Input the two legs (A and B)
- Output the hypotenuse (C)
- Add this to your code "shell"
- #include <math.h> // Math header contains sqrt()
- NOTE: gcc may require a -lm flag. This tells gcc to link a library (-l), specifically the math library (-m).
**Relational
- Write a relational expression to appropriately test the user input for leg A and then for leg B
**Logical
- Combine the previous Relational expressions with a logical operator so that both must be True
**Error Checking
- Include the Arithmetic, Relational and Logical code in this shell code as indicated by /* insert here 
*/


#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>

double calcHypo(double x, double y) //Function to calculate the hypotenuse of an assumed right triangle given sides represented by x and y
{
    double h = 0;
    /* insert arithmetic hypotenuse calculation here */
    h = sqrt(pow(x,2)+pow(y,2));
    return h; // Return result to main
}

int main(void) 
{
    /* insert initialize variables here */
    double legA, legB = 0;
    
    /* insert input values and assign to variables here */
    printf("Please provide number (integer or float) for Leg A of the right triangle:\n"); // Prompt user for input
    scanf("%lf", &legA); //Read in user input
    printf("Please provide number (integer or float) for Leg B of the right triangle:\n"); // Prompt user for input
    scanf("%lf", &legB); //Read in user input
    if (legA > 0 && legB > 0)/*insert logical combo of relational expressions here */
    {
        /* insert -Print the hypotenuse here */
        printf("The hypotenuse is %lf\n", calcHypo(legA, legB)); 
    }
    else
    {
        printf("Error: A triangle cannot have a side of size 0!\n");
    }
    return 0;
}