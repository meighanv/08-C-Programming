#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
  int data;
  struct node *next;
};

void display(struct node* head)
{
    struct node *temp = head;
    printf("\n\nList elements are - \n");
    while(temp != NULL)
    {
        printf("%d --->",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void printLl(struct node* head)
{
    struct node *temp = head;
    //printf("\n\nList elements are - \n");
    while(temp != NULL)
    {
        putc(temp->data,stdout);
        temp = temp->next;
    }
    printf("\n");
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
    temp->next = newNode;
}

void insertAtFront(struct node** headRef, int value) 
{
    struct node* head = *headRef;
    
    struct node *newNode;
    newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    
    *headRef = head;
}

void insertAtEnd(struct node* head, int value)
{
    struct node *newNode;
    newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    
    struct node *temp = head;
    while(temp->next != NULL)
    {
      temp = temp->next;
    }
    temp->next = newNode;
    
}

void deleteFromFront(struct node** headRef)
{
    struct node* head =  *headRef;
    head = head->next;
    *headRef = head;
}

void deleteFromEnd(struct node* head)
{
    struct node* temp = head;
    while(temp->next->next!=NULL)
    {
      temp = temp->next;
    }
    temp->next = NULL;
}

void deleteFromMiddle(struct node* head, int position)
{
    struct node* temp = head;
    int i;
    for(i=2; i<position; i++) 
    {
        temp = temp->next;
    }

temp->next = temp->next->next;
}

void reverse(struct node* head, struct node** revhead)
{
    struct node *temp = head;
    int data;
    while (temp->data)
    {
        data = temp->data;
        if (data != 0)
        {
            insertAtFront(revhead, data);
        }
        //printf("%d\n",data);
        temp = temp->next;
    }
}

int listlen(struct node* head)
{
    struct node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        if (temp->data != 0)
        {
            printf("%d\n", temp->data);
            count++;
        }
        temp = temp->next;
    }
    return count;
}

int isEqual(struct node* orig, struct node* rev)
{
    struct node *temp1 = orig;
    struct node *temp2 = rev;
    int equal = 1;
    if (listlen(orig)==listlen(rev))
    {
        while (temp1 != NULL)
        {
            if (temp1->data != temp2->data)
            {
                equal = 0;
                break;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    else
    {
        equal = 0;
    }
    
    return equal;
}

int main()
{
    struct node *head;
    struct node *revhead;
    struct node *one;
    struct node *revone;
    one = malloc(sizeof(struct node));
    revone = malloc(sizeof(struct node));
    head = one;
    revhead = revone;
    insertAtEnd(head,'l');
    insertAtEnd(head,'o');
    insertAtEnd(head,'l');
    insertAtEnd(head,'o');
    insertAtEnd(head,'l');
    insertAtEnd(head,'o');
    insertAtEnd(head,'l');
    if (head->data == NULL)
    {
        head = head->next;
    }
    //head = head->next;
    printLl(head);
    reverse(head,&revhead);
    printLl(revhead);
    printf("%d\n",listlen(head));
    printf("%d\n",listlen(revhead));
    printf("%d\n",isEqual(head,revhead));
}