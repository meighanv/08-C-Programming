#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAXSIZE 128
//int MAXSIZE = 20;       
char stack[MAXSIZE+1] = {0};     
int top = -1;            

int isempty() 
{
    if(top == -1) //if top (global) is -1 then nothing has been pushed to it
        return 1;
    else
        return 0; //otherwise it is not empty
}
   
int isfull() 
{
    if(top == MAXSIZE) // if top == MAXSIZE no more can be added
        return 1;
    else
        return 0;
}

int peek() 
{
    return stack[top]; //takes a look at the top item of stack
}

int pop() 
{
    int data;
	
    if(!isempty()) //checks if stack is empty, if not...
    { 
        data = stack[top]; //sets data to value of the top of stack
        top = top - 1;   //moves down the stack for top value
        return data; //returns the top item  
    } else {
        printf("Could not retrieve data, Stack is empty.\n");
    }
}

int push(int data) 
{
    if(!isfull()) //checks for full stack,; if not full then... 
    {
        top = top + 1; //moves top index up one
        stack[top] = data; //sets the top item to value of arg
    } else {
        printf("Could not insert data, Stack is full.\n");
    }
}

int isPalindrome(char * orig, char * rev) // checking if two strings are equal
{
    int pal = 1; //assuming it is a palindrom until it isn't
    int i = 0; // starting index
    while (orig[i]!=0) // looping until encountering a null termination
    {
        if (orig[i]!=rev[i]) // if the characters at index i are !=
        {
            pal = 0;// proven to not be a palindrome
            break; //break from loop b/c there is no reason to continue
        }
        i++; //increment index
    }
    return pal; //return bool state; if it made it through entire word then true returned
}

int main()
{
    char buffer [MAXSIZE] = {0}; //creating input buffer
    fgets(buffer,MAXSIZE,stdin); // getting user input
    char temp [MAXSIZE] = {0};//setting a variable to store the buffer input
    strcpy(temp,buffer);//copying string 
    char *token = strtok(temp,"\n"); //using strtok to get rid of newline char
    strcpy(temp,token);//copying to temp 
    for (int i = 0; i<strlen(temp);i++)//iterate through temp chars...
    {
        push(temp[i]); // pushing chars to stack
    }

    char palTest [MAXSIZE] = {0}; //creating a character array same size as temp
    int i = 0; //initalize index counter
    while(!isempty()) //while stack is not empty
    {
        char last = pop(); //pops character from stack
        palTest[i] = last; //adds to current index
        printf("%c",last);// printing as we go along
        i++;//increment index
    }
    printf("\n");
    if (isPalindrome(temp,palTest)==1 && \
        strlen(temp)==strlen(palTest) && \
        strlen(palTest)%2==1) //checks the length to be the same, an odd # of chars, and palindrome condition
    {
        printf("The phrase is a palindrome.\n");
    }
    else
    {
        printf("The phrase is NOT a palindrome.\n");
    }
    
}