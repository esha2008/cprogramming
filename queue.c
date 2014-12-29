/* Write a program to implement a Queue using Linked List
 * Queue should support the following operations
 * void enqueue(int number): Queues an element at the end of the queue
 * int dequeue(): Removes an element from the front of the queue
 */
 
#include <stdio.h>
#include <stdlib.h>

struct node{
    int element;
    struct node *next;
};

struct node * head=NULL;

void enqueue(int number)
{
    struct node* newnode=(struct node *)malloc(sizeof(struct node));
    newnode->element=number;
    if(head==NULL)
    {
        newnode->next=NULL;
        head=newnode;
    }
    else
    {
        newnode->next=head;
        head=newnode;
    }
}

int dequeue()
{
    struct node *current=head;
    while(current->next->next!=NULL)
    {
        current=current->next;
    }
    int dequeued_element = current -> next -> element;
    current -> next = NULL;
    return(dequeued_element);
}

void print(struct node * head)
{
    struct node * current = head;
    while(current!=NULL)
    {
        printf("\n %d \n",current->element);
        current=current->next;
    }
}

int main()
{
    printf("\n Enqueue elements:");
    enqueue(10);
    enqueue(20);
    enqueue(30);
    print(head);
    printf("\n Dequeue elements:");
    dequeue();
    print(head);
    return 0;
}
