#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAXSIZE 128
//int MAXSIZE = 20;       
char stack[MAXSIZE+1] = {0};     
int top = -1;            

int isempty() 
{
    if(top == -1)
        return 1;
    else
        return 0;
}
   
int isfull() 
{
    if(top == MAXSIZE)
        return 1;
    else
        return 0;
}

int peek() 
{
    return stack[top];
}

int pop() 
{
    int data;
	
    if(!isempty()) {
        data = stack[top];
        top = top - 1;   
        return data;
    } else {
        printf("Could not retrieve data, Stack is empty.\n");
    }
}

int push(int data) 
{
    if(!isfull()) {
        top = top + 1;   
        stack[top] = data;
    } else {
        printf("Could not insert data, Stack is full.\n");
    }
}

int main()
{
    char buffer [MAXSIZE] = {0};
    fgets(buffer,MAXSIZE,stdin);
    char temp [MAXSIZE] = {0};
    strcpy(temp,buffer);
    for (int i = 0; i<strlen(temp);i++)
    {
        push(temp[i]);
    }

    while(!isempty())
    {
        char last = pop();
        printf("%c",last);
    }
    printf("\n");

}