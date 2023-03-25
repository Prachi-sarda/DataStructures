#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void addNode(struct node** head, int data) {
    struct node* new = (struct node*) malloc(sizeof(struct node));
    new->data = data;
    new->next = *head;
    *head = new;
}

int isPrime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i <= n/2; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

void prime(struct node* head) {
    while (head != NULL) {
        if (isPrime(head->data)) {
            printf("%d ", head->data);
        }
        head = head->next;
    }
}

int main() {
    int n;
    printf("Size of list: ");
    scanf("%d", &n);

    struct node* head = NULL;

    printf("Enter %d integers of list: ", n);
    for (int i = 0; i < n; i++) {
        int n;
        scanf("%d", &n);
        addNode(&head, n);
    }

    printf("The prime numbers in the linked list are: ");
    prime(head);

    return 0;
}