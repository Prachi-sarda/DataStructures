//Input linked list
//ERRORRRRRRRRRRR in ISPRIME

#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*head=NULL;


void add(int data){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=NULL;
    struct node *temp=head;
    if(head==NULL){
        head=newNode;
    }

    else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
}

void display(){
    struct node *temp;
    temp=head;
    if(temp==NULL) printf("Empty node");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

void scan(){
    int data;
    printf("enter data for new node: ");
    scanf("%d",&data);
    add(data);
}

void isPrime(int n){
    if(n<=1) printf("invalid");
    int count;
    for(int i=1;i<n;i++){
        if(n%i==0) count++;
    }
    if(count==2) printf("%d is Prime\n",n);
    else printf("%d is Composite\n",n);
}

void swap(){
    struct node *temp;
    temp=head->next;
    head->next=head->next->next;
    temp->next=head;
    head=temp;
    printf("Swapped");
}

void deleteDups(){
    struct node *temp=head;
    struct node *temp1=temp;
    while(temp->next!=NULL && temp1!=NULL){
        while(temp1->next!=NULL){
            if(temp->data=temp1->data){
                int duplicate=temp1->next->data;
                temp1->next=temp1->next->next;
                printf("%d is duplicated. deleting",temp1->next->data);
            }
        }
    }
}

void min(){
    struct node *temp=head;
    int min=temp->data;
    while(temp!=NULL){
        if(temp->data<min) min=temp->data;
        temp=temp->next;
    }
    printf("%d is minimum\n",min);

}

void max(){
    struct node *temp=head;
    int max=temp->data;
    while(temp!=NULL){
        if(temp->data>max) max=temp->data;
        temp=temp->next;
    }
    printf("%d is max\n",max);
}

int main(){
    printf("1.Add node\n2.display list\n3.exit\n4.Is prime\n5.Swap node 1&2\n");
    int choice;
    while(1){
        printf("ENter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                scan();
                break;
            }
            case 2:{
                display();
                break;
            }
            case 3:{
                printf("Exiting");
                break;
            }
            case 4:{
                struct node *temp=head;
                while(temp!=NULL){
                    isPrime(temp->data);
                    temp=temp->next;
                }
                break;
            }
            case 5:{
                swap();
                break;
            }
            case 6:{
                deleteDups();
                break;
            }
            case 7:{
                min();
                break;
            }
            case 8:{
                max();
                break;
            }
            default:printf("Enter values from 1-6");
        }
        if(choice==3){
            break;
        }
    }
}