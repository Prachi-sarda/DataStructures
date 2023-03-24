#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

void display(struct Node *head) {
    struct Node *curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    int n, d;
    struct Node *head, *tail, *curr;

    // read the number of elements in the doubly linked list
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);

    //------------------------------------------------------------------//
    //SCAN LIST
    head = NULL;
    tail = NULL;
    for (int i = 1; i <= n; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &d);

        curr = (struct Node *) malloc(sizeof(struct Node));
        curr->data = d;
        curr->prev = tail;
        curr->next = NULL;

        if (tail != NULL) {
            tail->next = curr;
        }
        tail = curr;

        if (head == NULL) {
            head = curr;
        }
    }
    //---------------------------------------------------------------------------------------------------

    struct Node *temp, *temp2, *duplicate;
    temp = head;

    // Pick elements one by one 
    while (temp != NULL && temp->next != NULL) {
        temp2 = temp;

        // Compare the picked element with rest of the elements 
        while (temp2->next != NULL) {
            // If duplicatelicate then delete it 
            if (temp->data == temp2->next->data) {
                /Delete the duplicatelicate node 
                duplicate = temp2->next;
                temp2->next = duplicate->next;
                if (duplicate->next != NULL) {
                    duplicate->next->prev = temp2;
                }
                free(duplicate);
            } else {
                temp2 = temp2->next;
            }
        }
        temp = temp->next;
    }
    

    // print the resulting list
    printf("List after removing duplicatelicates: ");
    display(head);

    return 0;
}