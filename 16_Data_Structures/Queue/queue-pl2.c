#include<stdio.h>
#define SIZE 5
void enQueue(int);
void deQueue();
void display();
void flushIn();
int items[SIZE], front = -1, rear = -1;
int main()
{
    int num = 0;
    for (int i = 0;i < SIZE; i++)
    {
        puts("Enter a number to enqueue:");
        scanf("%d", &num);
        enQueue(num);
    }    
    
    for (int i = 0;i < SIZE; i++)
    {
        deQueue();
        display();
    }


        

}

void enQueue(int value){
    if(rear == SIZE-1)
        printf("\nQueue is Full!!");
    else {
        if(front == -1)
            front = 0;
        rear++;
        items[rear] = value;
        printf("\nInserted -> %d\n", value);
    }
}

void deQueue(){
    if(front == -1)
        printf("\nQueue is Empty!!");
    else{
        printf("\nDeleted : %d\n", items[front]);
        front++;
        if(front > rear)
            front = rear = -1;
    }
}

void display(){
    if(rear == -1)
        printf("\nQueue is Empty!!!");
    else{
        int i;
        printf("\nQueue elements are:\n");
        for(i=front; i<=rear; i++)
            printf("%d\t",items[i]);
    }
}

void flushIn()
{
    char c;
    while ((c = fgetc(stdin)) != '\n' && c != EOF);
}
