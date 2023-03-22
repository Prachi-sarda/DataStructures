//Swap node 1 & 2
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
void display(struct node *head){
    struct node *current = head;
    if(current==NULL) printf("Empty list");
    else{
        while(current!=NULL){
            printf("%d ",current->data);
            current=current->next;
        }
        printf("\n");
    }
}
struct node *head=NULL;
void addNode(int data){
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data= data;
    newNode->next=NULL;

    if(head==NULL){
        head=newNode;
    }
    else{
        struct node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next = newNode;
    }
}
void scanList(int n){
    for(int i=1;i<=n;i++){
        printf("Enter data for node %d: ",i);
        int data;
        scanf("%d",&data);
        addNode(data);

    }
}
void swapNodes(struct node **head){
    struct node *temp;
    struct node *a=*head;
    struct node *b=(*head)->next;
    a->next=b->next;
    b->next=a;
    *head=b;
  
}
int main(){
    int n;
    printf("enter size of list: ");
    scanf("%d",&n);
    scanList(n);
    swapNodes(&head);
    display(head);
}