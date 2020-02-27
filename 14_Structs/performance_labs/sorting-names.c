//https://gitlab.com/90COS/public/evaluation-prep/basic-dev-prac-env
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXNAME 60

struct node // This is a node that currently holds only a string for a name
{
    char *name[MAXNAME-1];
    struct node *next;//forward pointer for duobly linked list
    struct node *prev;//backward pointer for duobly linked list
};

void swapNode(struct node** head, struct node** tail, int place) 
/* this will switch the current node at place (position) with the one after it*/
{
    struct node *current;
    struct node *after;
    struct node *farPrev;
    struct node *farNext;
    current = *head;
    int i = 1;
    while (i < place && current->next != NULL)
    {
        current = current->next;
        i++;
    }
    if (current->next == NULL)
    {
        printf("No node after to swap with...");
        return;
    }

    after = current->next;
    if (current->prev == NULL)
    {
        *head = after;
    }
    if (after->next == NULL)
    {
        *tail = current;
    } 
    if (after->next == NULL)
    {
        farNext = NULL;
    }
    else
    {
        farNext = after->next;
        farNext->prev = current;
    }
    
    
    if (current->prev == NULL)
    {
        farPrev = NULL;
    }
    else
    {
        farPrev = current->prev;
        farPrev->next = after;
    }
    
    current->prev = after;
    current->next = farNext;
    after->next = after->prev;
    after->prev = farPrev;
    

}

char *getInput(char *outputString)
// gathers input and returns a string 
{
	char *userInput = NULL;
	size_t inputBuffer = 0;
	int inputCount = 0;

	//allocate the userInput
	//userInput = (char *)malloc(inputBytes+1);
	//not needed with the getline function since it
	//automatically calls realloc to manage the memory

	printf("%s", outputString);
	inputCount = getline(&userInput, &inputBuffer, stdin);

	//remove the newline character from the string
	userInput[inputCount-1] = '\0';

	//return the user input
	return userInput;
}

void flushIn()
// Used to flush stdin
{
    char c;
    while ((c = fgetc(stdin)) != '\n' && c != EOF);
}

void display(struct node* head) 
//This will display the nodes in forward order
{
   struct node *ptr = head;

   printf("\n[head] <=>");
   //start from the beginning
   while(ptr != NULL) 
   {        
      printf(" %s <=>",ptr->name);
      ptr = ptr->next;
   }

   printf(" [last]\n");
}


void displayBackward(struct node* last) 
// Displays the nodes from last to first
{
   struct node *ptr = last;

   printf("\n[head] <=>");
   //start from the beginning
   while(ptr != NULL) 
   {        
      printf(" %s <=>",ptr->name);
      ptr = ptr->prev;
   }

   printf(" [last]\n");
}

void add(struct node** head, struct node** last)
//Create Linked List( Adds a node to the end of a doubly linked list) or creates one if empty
{
    // Allocate memory for new node;
    struct node *link = (struct node*) malloc(sizeof(struct node));
    struct node *current; //Create current pointer for probe

    strcpy(link->name, getInput("Please enter the name:")); //calls getInput() to store returned string in node->name
    link->prev = NULL; //initialize prev and next pointers to NULL
    link->next = NULL;

    // If head is empty, create new list
    if(*head==NULL) 
    {
        *head = link;//For the first node the head and tail are the same node
        *last = link;
        return;
    }

    //current = head;
    current = *last; //since we are adding the current pointer is set to the tail instead of iterating through each node
    
    // move to the end of the list
    // while(current->next!=NULL)
    // {
    //     current = current->next;
    // }
    // Insert link at the end of the list
    current->next = link; //setting the next of tail node to new node
    *last = link; //changing the pointer of tail to the last node added
    link->prev = current; //changing the prev pointer of new node to current node (previously tail)
}

void bubSortNode(struct node** head, struct node** tail) 
//This is meant to performa a bubble sort on a linked list
{
    while (1==1)
    {
        int swapped = 0; //Bool tracker for if a swap was made
        struct node *current = *(head); //creat new pointer probe starting at head
        int position = 1; //track position of current to pass into swap function
        while (current != *(tail) && current != NULL) //checks to ensure that current != tail and current isnt NULL
        {
            struct node *after = current->next; //Creating a pointer for node after current
            if (strcmp(current->name,after->name) > 0) //using strcmp to determine which name is greater alphabetically
            {
                //If its greater than 0 then current->name is later than after and nodes must swap
                swapNode(head,tail,position); // since pointers are expected, addresses must be passed as args
                swapped = 1; // marking that a swap occurred
            }
            current = current->next; //moves the probe forward
            position++; //increments the swap position
        }
        if (swapped == 0) //if nothing was swapped then it's time to break from the "while True" loop
        {
            break;
        }
    }
}




int main()
{
    struct node *head = NULL; //creating node pointer for head and tail
    struct node *tail = NULL;
    
    int num = 11; //current number of nodes to fill
    
    int count = 0; //nodes counter
    while (count < num)
    {
        add(&head,&tail);
        count++;
    }

    display(head);
    displayBackward(tail);

    //swapNode(&head, &tail, 10);
    bubSortNode(&head, &tail);

    display(head);
    displayBackward(tail);

    //string = getInput("Give me a NAME: ");
    //printf("%s\n",string);

}