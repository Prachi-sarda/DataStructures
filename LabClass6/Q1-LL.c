//Write a code in C, that creates the following menu driven operation on stack.
//(1)Push (2)Pop (3)Peak.
//Here Peak operation just return top most value of stack without deleting it(or without changing top variable value.)
//Use LLs
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
}*top=NULL,*temp;

void peep(){
    printf("top element is %d",top->data);
}

void push(int data){
    if(top==NULL){
        top=(struct node*)malloc(sizeof(struct node));
        top->data=data;
        top->next=NULL;
    }
    else{
        temp=(struct node*)malloc(sizeof(struct node));
        temp->next=top;
        temp->data=data;
        top=temp;
    }
    printf("Inserted");
}

int pop(){
    temp=top;
    if(top==NULL){
        printf("Stack underflow");
        return -1;
    }
    else{
        temp=temp->next;
        int popped=top->data;
        top=temp;
        printf("%d is popped",popped);
    }
}

void display(){
    temp=top;
    if(top==NULL){
        printf("Stack underflow");
        return;
    }
    else{
        while(temp!=NULL){
            printf("%d->",temp->data);
            temp=temp->next;
        }
        printf("NULL");
    }
}

int main() {
    int choice, value;
    int i=1;
    while (1) {
        printf("\n\nCommand %d\nChoose:\n1. Push\n2. Peak\n3. Pop\n4. Display\n5. Exit\n",i);
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("\nEnter the value to insert: ");
            scanf("%d", &value);
            push(value);
            break;
        case 3:
            pop();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("End.\n");
            exit(0);
            break;
        case 2:
            peep();
            break;
        default:
            printf("\nChoose 1/2/3/4/5\n");
        }
        i++;
    }
}