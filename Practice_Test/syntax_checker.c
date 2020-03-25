
#include <stdio.h>
#include <string.h>
#include "TestCode.h"
#define MAXSIZE 50

/*
Correct syntax in computer programming requires all opening container characters such as parenthesis '(', braces '{', brackets '[ have a closing
 matching container character ')','}', ']'. For valid syntax, when a closing character is encoutered, it means a matching opening container
character exists. There cannot be any other opening container characters between the closing and opening one.

There must be also the same number of opening container character types as closing container character types.

The following is valid syntax example:

if (x == y) { scores[(x + 1)] = 50; }

The following is an invalid syntax example:

if (x == y) { scores[(x + 1]) = 50; }  // for the ] there is a previous ( before the matching [

The following is an invalid syntax example:

if (x == y) { scores[(x + 1)] = 50;   // there is no matching } for the opening {

Write a function called validateSyntax that receives a string of code and an empty char array. 
The function should use the passed char array to implement a rudimentary stack that 
keeps track of the opening/closing container characters. 

if the code string received is empty, the function should return ERROR_INVALID_DATA

If the code string received has valid syntax, the function should return ERROR_SUCCESS, 

if the code string received has invalid, the function should return ERROR_INVALID_BLOCK

*/
int top = -1;

void push(char data, char stack[]) 
{
    if(top < MAXSIZE - 1) {
        top = top + 1;   
        stack[top] = data;
    } else {
        printf("Could not insert data, Stack is full.\n");
    }
}

char pop(char stack[]) 
{
    char data;
	
    if(top > -1) {
        data = stack[top];
        top = top - 1;   
        return data;
    } else {
        printf("Could not retrieve data, Stack is empty.\n");
    }
}

char * validateSyntax(char * code, char stack[])
{
	char * probe;
	probe = code;
	if (*probe == 0)
	{
		return "ERROR_INVALID_DATA";
	}
	
	while (*probe != 0)
	{
		if(*probe == 40 || *probe == 91 ||*probe == 123 )
		{
			push(*probe, stack);
		}
		else if (*probe == 41 || *probe == 93 ||*probe == 125 )
		{
			char temp = pop(stack);
			if (temp == 40 && *probe != 41)
			{
				return "ERROR_INVALID_BLOCK";
			}
			else if (temp == 91 && *probe != 93)
			{
				return "ERROR_INVALID_BLOCK";
			}
			else if (temp == 123 && *probe != 125)
			{
				return "ERROR_INVALID_BLOCK";
			} 
		}
		probe++;
	}
	if (top != -1)
	{
		return "ERROR_INVALID_BLOCK";
	}
	else
	{
		return "ERROR_SUCCESS";
	}
	
	return "";
}
