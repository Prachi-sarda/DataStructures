#include<stdio.h>
#include<stdlib.h>
//Create a linked list of size n and find prime number in list
struct node{
    int data;
    struct node *next;
}*a;

int scan(int n){
    typedef struct node NODE;
    struct node *fn, *t;
    int data,i;
    a=(NODE*)malloc(sizeof(NODE));
    if(a==NULL) printf("No memory");
    else{
            printf("Input for node 1:");
            scanf("%d",&data);
            a->data = data;
            a->next = NULL;
            t=a;
            for(int i=2;i<=n;i++){
                fn = (NODE*)malloc(sizeof(NODE));
                if(fn==NULL) printf("No memory");
                else{
                    // printf("Data for node %d:",i);
                    scanf(" %d",&data);
                    fn -> data = data;
                    fn -> next = NULL;
                    t -> next = fn;
                    t = t -> next;
                }
            }
    }
}
void displayList()
{
    struct node *t;
    if(a == NULL)
    {
        printf(" List is empty.");
    }
    else
    {
        t = a;
        while(t != NULL)
        {
            printf("%d -> ", t->data);       // prints the data of current node
            t = t->next;                     // advances the position of current node
        }
    }
} 

int main(){

    printf("ENter size of list:");
    int n;
    scanf("%d",&n); 
    scan(n);
    printf("the list: ");
    displayList();
}