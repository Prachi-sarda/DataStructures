#include <stdio.h>
#include <stdlib.h>
 
struct node{
    int data;
    struct node *ptr;
}*front,*rear,*temp,*temp2;
 
int frontelement();
void enqueue(int data);
void dequeue();
void display();
void create();
// void queuesize();
 
int count = 0;
 
void main()
{
    int no, choice, e;
 
    printf("\n 1 - Enqueue");
    printf("\n 2 - Dequeue");
    printf("\n 3 - Front element");
    printf("\n 4 - Exit");
    printf("\n 5 - Display");
    create();
    while (1)
    {
        printf("\n Enter choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf(" Enter data : ");
            scanf("%d", &no);
            enqueue(no);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            e = frontelement();
            if (e != 0)
                printf("\tFront element : %d", e);
            else
                printf("\n No front element in Queue as queue is empty");
            break;
       
        case 4:
            exit(0);
        case 5:
            display();
            break;
        default:
            printf("Wrong choice, Please enter number between 1-5: ");
            break;
        }
    }
}
 
void create()
{
    front = rear = NULL;
}
 
void enqueue(int data)
{
    if (rear == NULL)
    {
        rear = (struct node *)malloc(sizeof(struct node));
        rear->ptr = NULL;
        rear->data = data;
        front = rear;
    }
    else
    {
        temp=(struct node *)malloc(sizeof(struct node));
        rear->ptr = temp;
        temp->data = data;
        temp->ptr = NULL;
 
        rear = temp;
    }
    count++;
}
 
void display()
{
    temp2 = front;
 
    if ((temp2 == NULL) && (rear == NULL))
    {
        printf("Queue is empty");
        return;
    }
    while (temp2 != rear)
    {
        printf("%d ", temp2->data);
        temp2 = temp2->ptr;
    }
    if (temp2 == rear)
        printf("%d", temp2->data);
}
 
void dequeue()
{
    temp2 = front;
 
    if (temp2 == NULL)
    {
        printf("\n Error: Empty queue");
        return;
    }
    else
        if (temp2->ptr != NULL)
        {
            temp2 = temp2->ptr;
            printf("\n Dequeued value : %d", front->data);
            free(front);
            front = temp2;
        }
        else
        {
            printf("\n Dequeued value : %d", front->data);
            free(front);
            front = NULL;
            rear = NULL;
        }
        count--;
}

int frontelement()
{
    if ((front != NULL) && (rear != NULL))
        return(front->data);
    else
        return 0;
}
 
