#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "TestCode.h"

/*
  For this task, you will receive two pointers to NULL terminated strings: 
		   a 'sentence', and a 'word'. The objective will be to delete (in place) the first 
		   occurrence of 'word' in the sentence. 

 Expected Return Values:
		- the task is successful: should return ERROR_SUCCESS (0).
		- provided parameters are bad: should return ERROR_INVALID_PARAMETER (87)
		- the provided 'word' is not part of 'sentence': should return ERROR_NOT_FOUND (1168)
*/

int deleteWord(char* sentence, char* word)
{
	char *match;
	char * oldstr;
	char * newstr;
	newstr = (char*)calloc(30, sizeof(char));
	oldstr = (char*)calloc(30, sizeof(char));
    strcpy(oldstr, sentence);
	int len = strlen(word);
    while ((match = strstr(oldstr, word))) {
        *match = '\0';
        strcpy(newstr, strcat(oldstr, match+len));
		printf("%s\n",newstr);
    }

}
