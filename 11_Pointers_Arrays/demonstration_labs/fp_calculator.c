#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define ERROR_CODE ((double)98245.1653)

double add(double firstNumber, double secondNumber); //prototype for add function
double subtract(double firstNumber, double secondNumber); //prototype for add function
double multiply(double firstNumber, double secondNumber); //prototype for add function
double divide(double firstNumber, double secondNumber); //prototype for add function

int main(void)
{
	double(*mathFun_ptr)(double x, double y); //create function pointer for math function
	double num1 = 0; //initializing double num1
	char mathOperator = 0; //initializing mathOperator variable
	double num2 = 0; //initializing double num1
	double returnValue = 0; //initializing returnValue 
 
	printf("Enter two ints and/or doubles separated by a math operator\n"); //User prompt and instructions 
	printf("e.g., 1.2 + 3.4, 5.6 - 7.8, 9.10 * 2.3, 4.5 / 6.7\n"); //User prompt and instructions
	_flushall(); //attempting to clear stdin may have to change on *nix
	scanf("%lf %c %lf", &num1, &mathOperator, &num2); // receiving user input for num1, num2, and operator
	
	if (mathOperator == '+') //if the operator is '+'...
	{
		mathFun_ptr = &add; //set pointer to address of function add
	}
	else if (mathOperator == '-')//if the operator is '-'...
	{
		mathFun_ptr = &subtract;//set pointer to address of function subtract
	}
	else if (mathOperator == '*')//if the operator is '*'...
	{
		mathFun_ptr = &multiply;//set pointer to address of function multiply
	}
	else if (mathOperator == '/')//if the operator is '/'...
	{
		mathFun_ptr = &divide;//set pointer to address of function divide
	}
	else
	{
		puts("Something went wrong!"); // for invalid characters display error message to user
		return -1; //return error code
	}

	if (mathFun_ptr) // if the function pointer is set ... 
	{
		returnValue = mathFun_ptr(num1, num2); //..set returnValue to the result of the referenced function
		printf("The result is:\t%lf\n", returnValue); // print the returnValue to the user
	}
	else
	{
		puts("Something went wrong!");
		return -1; //return error code
	}

	getchar(); getchar(); //clearing stdin of random chars
	return 0; // returning 0 for a proper exit
}

double add(double firstNumber, double secondNumber) //define math function for addition
{
	return firstNumber + secondNumber; //return the result of the operation to main
}

double subtract(double firstNumber, double secondNumber) //define math function for subtraction
{
	return firstNumber - secondNumber; //return the result of the operation to main
}

double multiply(double firstNumber, double secondNumber) //define math function for multiplication
{
	return firstNumber * secondNumber; //return the result of the operation to main
}

double divide(double firstNumber, double secondNumber) //define math function for division
{
	if (secondNumber) //checking for a non-zero denominator
	{
		return firstNumber / secondNumber; //return the result of the operation to main
	}
	else
	{
		return ERROR_CODE; // if secondNumber is 0 then return the error code
	}
}
