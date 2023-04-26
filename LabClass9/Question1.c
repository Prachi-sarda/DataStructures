// circular queue using arrays
// C program to create double ended queue using arrays\\\\


#include<stdio.h>
#define MAX 5

int queue[MAX];
int front=-1, rear=-1;

void enqueue(int data);
void dequeue();
void display();

int main()
{
    int choice, data;
    do
    {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter the element to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
                break;
        }
    } while (choice != 4);
    return 0;
}

void enqueue(int data)
{
    if((front == 0 && rear == MAX-1) || (front == rear+1))
    {
        printf("\nQueue is full! Enqueue operation failed.\n");
        return;
    }
    else if(front == -1 && rear == -1)
    {
        front = rear = 0;
    }
    else if(rear == MAX-1 && front != 0)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }
    queue[rear] = data;
    printf("\nElement %d enqueued successfully.\n", data);
}

void dequeue()
{
    if(front == -1 && rear == -1)
    {
        printf("\nQueue is empty! Dequeue operation failed.\n");
        return;
    }
    int data = queue[front];
    if(front == rear)
    {
        front = rear = -1;
    }
    else if(front == MAX-1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
    printf("\nElement %d dequeued successfully.\n", data);
}

void display()
{
    if(front == -1 && rear == -1)
    {
        printf("\nQueue is empty!\n");
        return;
    }
    printf("\nThe elements in the queue are: ");
    if(front <= rear)
    {
        for(int i=front; i<=rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
    else
    {
        for(int i=front; i<MAX; i++)
        {
            printf("%d ", queue[i]);
        }
        for(int i=0; i<=rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
    printf("\n");
}