//Menu driven data operations in Linear queue using arrays
//1.Enqueue, 2,Dequeue

#include<stdio.h>
#include<stdlib.h>
// #define MAX 10

int queue_arr[10];
int rear=-1;
int front=-1;

void insert(int item);
int del();
int peek();
void display();
int full();
int empty();

int main()
{
        int choice,item;
        while(1)
        {
                printf("\n1.Enqueue(Insert)\n");
                printf("2.Dequeue(Delete)\n");
                printf("3.Display element at the front\n");
                printf("4.Display all elements of queue\n");
                printf("5.Exit\n");
                printf("\nEnter your choice : ");
                scanf("%d",&choice);

                switch(choice)
                {
                case 1:
                        printf("\nInput the element: ");
                        scanf("%d",&item);
                        insert(item);
                        break;
                case 2:
                        item=del();
                        printf("\nDeleted element is  %d\n",item);
                        break;
                case 3:
                        printf("\nElement at the front is %d\n",peek());
                        break;
                case 4:
                        display();
                        break;
                case 5:
                        exit(1);
                default:
                        printf("\nWrong choice\n");
                }
        }

        return 0;

}

void insert(int item)
{
        if( full() )
        {
                printf("\nQueue Overflow\n");
                return;
        }
        if( front == -1 )
                front=0;
        rear++;
        queue_arr[rear]=item ;
}

int del()
{
        int item;
        if( empty() )
        {
                printf("\nQueue Underflow\n");
                exit(1);
        }
        item=queue_arr[front];
        front=front+1;
        return item;
}

int peek()
{
        if( empty() )
        {
                printf("\nQueue Underflow\n");
                exit(1);
        }
        return queue_arr[front];
}

int empty()
{
        if( front==-1 || front==rear+1 )
                return 1;
        else
                return 0;
}

int full()
{
        if( rear==9 )
                return 1;
        else
                return 0;
}

void display()
{
        int i;
        if ( empty() )
        {
                printf("\nQueue is empty\n");
                return;
        }
        printf("\nQueue is :\n\n");
        for(i=front;i<=rear;i++)
                printf("%d  ",queue_arr[i]);
        printf("\n\n");
}