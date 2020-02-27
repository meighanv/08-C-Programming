
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "TestCode.h"


/*
Write a function that receives a char array of text representing a paragraph with invalid
spacing between sentences. Each sentene ends in a period . or question mark ?.  After each
period or question mark there could be zero to many spaces. The function should build a new
paragraph ensuring there are exactly two (2) spaces after each period or question mark. The
last period/question mark in the paragraph should not have spaces after it.

The function should return the correctly formated paragraph.

Assume all paragraphs will be 200 characters or less. **DONE**

Assume no leading spaces before paragraph start.

- If text passed to the function is empty or NULL, return an empty string "".
*/



char * spaceFixer(char *text) // Provided by test
{

	char *para; // Provided by test
	char *temp; //temp var to store 'text' string
	para = (char*)calloc(201, sizeof(char)); //assuming max length is 200 characters
	
	if (text == NULL) //checking for edge condition if text pointer is NULL
	{
		return ""; //Just returns an empty string
	}

	else if (strcmp("",text) == 0) //if "" is passed as arg...
	{
		return text;//it just returns itself since there is no action
	}
	else //Otherwise situation is normal
	{
		
	
		temp = (char*)calloc(201, sizeof(char)); //assuming max length is 200 characters
		strcpy(temp,text); //coppying text to temp to leave original text untouched
		int j = 0; //setting an itterator counter to track place in new array
		for (int i=0; i < strlen(temp); i++) //looping through temp characters
		{
			char c = temp[i]; // setting current char to c
			char next = temp[i+1]; //setting next char for end of string check
			if (c == '\0') //if we are currently on a null char (should never happen)
			{
				break; //get out of for loop
			}
			else if (next == '\0') // if the next char is '\0'
			{
				para[j] = temp[i]; //simply copy the current char for the current places in para and temp
				break; // then break the for loop since end of string is reached
			}
			else if ((c == 46 || c == 63)) //otherwise look for ? or . chars
			{
				para[j] = c; //when found copy the current char
				if (next != '\0') // check if next is '\0'
				{
					int t = 1; // if it's not, then set a counter variable to track the # of space from current in temp
					while ( temp[i+t] == 32 ) //checking successive locations that have a space
					{
						if (temp[i+t+1] == '\0') //looking for end of string
						{
							break; // when found break from while loop
						}
						else // otherwise increment t to next space
						{
							t++;
						} //loop ends when a non-space character is present in temp[i+t]
					}
					if (temp[i+t+1] == 0) // if the next character after temp[i+t] is null then break from for loop
					{
						break;
					}
					else //otherwise 
					{
						i += t-1; // move the counter to the space prior to next letter since for loop will increment
					}
					//i++;
					j++; //move the tracker for the para array
					para[j] = 32; // add a space
					j++; // move right again
					para[j] = 32; // add a space char
				}
			}
			else // in all normal char cases simply copy current temp char to current para place
			{
				para[j] = temp[i];
			}
			
			j++; //move the para place marker
		}
	}

	return para; // Provided by test
}


// void main()
// {
// 	//char *sentence = "yes.   ";
// 	char *sentence = "Yesterday, all my trouble seemed so far away.Now they are here to stay.      Do I believe in yesterday? Suddenly, yes.   ";
// 	char *fixed = "Yesterday, all my trouble seemed so far away.  Now they are here to stay.  Do I believe in yesterday?  Suddenly, yes.";
// 	char *res1 = spaceFixer(sentence);
// 	printf("%d\n", strcmp(fixed,res1));
// }

