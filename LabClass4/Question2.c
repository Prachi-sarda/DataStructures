//IsPrime?

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

int isPrime(int n){
    if(n<=1) return 0;
    int count=0;
    for(int i=2;i<=n/2;i++){
        if(n%i == 0) return 0;
        else return 1;
    }
}

int countPrimes(struct node *head){
    int count = 0;
	struct node *ptr = head;

	while (ptr != NULL) {
		if (isPrime(ptr->data)) {
			count++;
            printf("%d ",ptr->data);
		}
		ptr = ptr->next;
	}
    printf("\n");
	return count;
}

int main(){
    int n;
    printf("enter size of list: ");
    scanf("%d",&n);
    scanList(n);
    int answer= countPrimes(head);
    // display(head);
    printf("%d",answer);
}