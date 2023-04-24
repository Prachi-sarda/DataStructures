//Write a code in C, that creates the following menu driven operation on stack.
//(1)Push (2)Pop (3)Peak.
//Here Peak operation just return top most value of stack without deleting it(or without changing top variable value.)
//Use arrays
#include<stdio.h>
int stack[100],choice,n,top,x,i;
void peak(){
    printf("Top value of stack is:%d\n",stack[top]);
}
void push()
{
    if(top>=n-1)
    {
        printf("\n\tSTACK is over flow");
        
    }
    else
    {
        printf(" Enter a value to be pushed:");
        scanf("%d",&x);
        top++;
        stack[top]=x;
    }
}
void pop()
{
    if(top<=-1)
    {
        printf("\n Stack is under flow");
    }
    else
    {
        printf("\n The popped elements is %d",stack[top]);
        top--;
    }
}
void display()
{
    if(top>=0)
    {
        printf("\n The elements in STACK \n");
        for(i=top; i>=0; i--)
            printf("%d->",stack[i]);
    }
    else
    {
        printf("\n The STACK is empty");
    }
   
}

int main()
{
    top=-1;
    printf("Enter size of stack: ");
    scanf("%d",&n);
    printf("\n 1.PEEP\n 2.PUSH\n 3.POP\n 4.DISPLAY\n 5.EXIT: ");
    while(1)
    {
        printf("\n Enter the Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:{
                peak();
                break;
            }
            case 2:
            {
                push();
                break;
            }
            case 3:
            {
                pop();
                break;
            }
            case 4:
            {
                display();
                break;
            }
            case 5:
            {
                printf("\nEXITING ");
                break;
            }
            default:
            {
                printf ("\nPlease Enter a Valid Choice(1/2/3/4/5)");
                break;
            }
                
        }
        if(choice==5){ 
            break;
        }
    }
    return 0;
}
