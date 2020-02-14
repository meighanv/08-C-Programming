#include <stdio.h>
#include <stdlib.h>

struct node 
{
   int data;
   struct node *prev;
   struct node *next;
};

void display(struct node* head) 
{
   struct node *ptr = head;

   printf("\n[head] <=>");
   //start from the beginning
   while(ptr != NULL) 
   {        
      printf(" %d <=>",ptr->data);
      ptr = ptr->next;
   }

   printf(" [last]\n");
}

//display the list
void displayBackward(struct node* last) 
{
   struct node *ptr = last;

   printf("\n[head] <=>");
   //start from the beginning
   while(ptr != NULL) 
   {        
      printf(" %d <=>",ptr->data);
      ptr = ptr->prev;
   }

   printf(" [last]\n");
}

//Create Linked List
void add(struct node** head, struct node** last, int data)
{
    // Allocate memory for new node;
    struct node *link = (struct node*) malloc(sizeof(struct node));
    struct node *current;

    link->data = data;
    link->prev = NULL;
    link->next = NULL;

    // If head is empty, create new list
    if(*head==NULL) 
    {
        *head = link;
        *last = link;
        return;
    }

    //current = head;
    current = *last;
    
    // move to the end of the list
    // while(current->next!=NULL)
    // {
    //     current = current->next;
    // }
    // Insert link at the end of the list
    current->next = link;
    *last = link;
    link->prev = current;
}

void insertAtFront(struct node** headRef, int value) 
{
    struct node* head = *headRef;
    
    struct node *link;
    link = malloc(sizeof(struct node));
    link->data = value;
    link->next = head;
    link->prev = NULL;

    head->prev = link;
    head = link;
    
    *headRef = head;
}

void insertAtMiddle(struct node *head, int position, int value) {
    struct node *temp = head;
    struct node *newNode;
    newNode = malloc(sizeof(struct node));
    newNode->data = value;
    
    int i;
    for(i=2; i<position; i++) 
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

void deleteFromMiddle(struct node* head, int position)
{
    struct node* temp = head;
    int i;
    for(i=2; i<position; i++) 
    {
        temp = temp->next;
    }
temp->next->next->prev = temp;
temp->next = temp->next->next;
}

int main() 
{
    struct node *head = NULL; //consider trying to make these declarations non-pointers to eliminate the need for double pointers for front based functions
    struct node *tail = NULL;
    //struct node *one = NULL;
    //one = malloc(sizeof(struct node));   
    //head = one;
    //tail = one;
    add(&head,&tail,1);
    add(&head,&tail,2);
    add(&head,&tail,3);
    add(&head,&tail,4);
    add(&head,&tail,5);
    add(&head,&tail,6); 
    insertAtFront(&head,32);
    insertAtMiddle(head,4,36);
    deleteFromMiddle(head,2);

    display(head);
    displayBackward(tail);
    
    return 0;
}