#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


int main()
{
    int arr[10],rear=-1,front=0,temp=0,choice,n,i,x;

    for(;;)
    {
        // system("cls");
        printf("Front=%d  Rear=%d\n\n",front,rear);
        printf("1. Enqueue Front\n");
        printf("2. Dequeue Front\n");
        printf("3. Enqueue Rear\n");
        printf("4. Dequeue Rear\n");
        printf("5. Display list\n");
        printf("6. Exit\n");
        printf("Enter Choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 3:
                if(temp==10){
                    printf("Queue is full");
                    getch();	// pause the loop to see the message
                }
                else{
                    printf("Enter a number: ");
                    scanf("%d",&n);
                    rear=(rear+1)%10;
                    arr[rear]=n;
                    temp=temp+1;
                }
                break;

            case 4:
                if(temp==0)
                {
                    printf("Queue is empty");
                    getch();	// pause the loop to see the message
                }
                else
                {
                    if(rear==-1)
                    {
                        rear=10-1;
                    }
                    printf("Number Deleted From Rear End = %d",arr[rear]);
                    rear=rear-1;
                    temp=temp-1;
                    getch();	// pause the loop to see the number
                }
                break;

            case 1:
                if(temp==10)
                {
                    printf("Queue is full");
                    getch();	// pause the loop to see the message
                }
                else
                {
                    printf("Enter a number ");
                    scanf("%d",&n);
                    if(front==0)
                    {
                        front=10-1;
                    }
                    else
                    {
                        front=front-1;
                    }
                    arr[front]=n;
                    temp=temp+1;
                }
                break;

            case 2:
                if(temp==0)
                {
                    printf("Queue is empty");
                    getch();	// pause the loop to see the message
                }
                else
                {
                    printf("Number Deleted From Front End = %d",arr[front]);
                    front=(front+1)%10;
                    temp=temp-1;
                    getch();	// pause the loop to see the number
                }
                break;

            case 5:
                if(temp==0)
                {
                    printf("Queue is empty");
                    getch();	// pause the loop to see the message
                }
                else
                {
                    x=front;
                    for(i=1; i<=temp; i++)
                    {
                        printf("%d ",arr[x]);
                        x=(x+1)%10;
                    }
                    getch();	// pause the loop to see the numbers
                }
                break;

            case 6:
                exit(0);
                break;

            default:
                printf("Wrong Choice");
                getch();	// pause the loop to see the message
        }
    }
    return 0;
}