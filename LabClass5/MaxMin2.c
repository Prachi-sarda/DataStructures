#include <stdio.h>  
#include <stdlib.h> 
struct node{  
    int data;  
    struct node *previous;  
    struct node *next;  
}*a;      
   

struct node *head, *tail = NULL;  

void addNode(int data) {  
    struct node *newNode = (struct node*)malloc(sizeof(struct node));  
    newNode->data = data;  
    if(head == NULL) {  
        head = tail = newNode;  
        head->previous = NULL;  
        tail->next = NULL;  
    }  
    else {  
        tail->next = newNode;  
        newNode->previous = tail;  
        tail = newNode;  
        tail->next = NULL;  
    }  
}  
   




int main()  
{  

    int n;
    printf("Enter size of list: ");
    scanf("%d",&n);
    
    for(int i=1;i<=n;i++){
        int d;
        printf("Enter value of node %d: ",i);
        scanf("%d",&d);
        addNode(d);
    }

      struct node *current = head;  
    ////////////////////////////////
    //TO FIND MIN
    int min;  
    if(head == NULL) {  
        printf("List is empty\n");  
        return 0;  
    }  
    else {  
        min = head->data;  
        while(current != NULL) {  
          
            if(min > current->data)  
                min = current->data;  
            current = current->next;  
        }  
    }  
    free(current);

    ///////////////
    //TO FIND MAX
    int max;  
    current=head;  
    if(head == NULL) {  
        printf("List is empty\n");  
        return 0;  
    }  
    else {  

        max = head->data;  
        while(current != NULL) {  
            if(current->data > max)   
                max = current->data;  
            current = current->next;  
        }  
    }
    ///////////////////////////
    
    printf("Minimum value node in the list: %d\n", min);  
    printf("Maximum value node in the list: %d", max);  
    return 0;  
}