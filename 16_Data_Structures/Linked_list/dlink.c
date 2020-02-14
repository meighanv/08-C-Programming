#include <stdio.h>
#include <stdlib.h>

struct node 
{
   int data;
   struct node *prev;
   struct node *next;
};

struct node *head = NULL;
struct node *last = NULL;

struct node *current = NULL;

//display the list
void display() 
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
void displayBackward() 
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
void add(int data)
{
   // Allocate memory for new node;
   struct node *link = (struct node*) malloc(sizeof(struct node));

   link->data = data;
   link->prev = NULL;
   link->next = NULL;

   // If head is empty, create new list
   if(head==NULL) 
   {
      head = link;
      last = link;
      return;
   }

   //current = head;
   current = last;
   
   // move to the end of the list
//    while(current->next!=NULL)
//       current = current->next;

   // Insert link at the end of the list
   current->next = link;
   last = link;
   link->prev = current;
}

int main() 
{
   add(1);
   add(2);
   add(3);
   add(4);
   add(5);
   add(6); 

   display();
   displayBackward();
   
   return 0;
}