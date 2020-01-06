/*
Name: Vernon Meighan
Date: 20200106
Project: This is meant to declare 4 different var types: 
	int, float, double, and char
Once declared we are printing them out to the console.
*/

#include <stdio.h>

int main(void)
{
	int integer = 1;
	float floating = 129857.245;
	double doubling = 4.543261609285187;
	char character = 'C';

	
	printf("Your integer is %d with a size of %d \n", integer, (int)sizeof(integer));
	printf("Your float is %lf with a size of %d \n", floating, (int)sizeof(floating));
	printf("Your double is %lf with a size of %d \n", doubling, (int)sizeof(doubling));
	printf("Your first is %c with a size of %d \n", character, (int)sizeof(character));

	
	return 0;
}
