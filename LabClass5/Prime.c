#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node {
  int value;
  struct Node *prev;
  struct Node *next;
} Node;

Node* createNode(int value) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->value = value;
  newNode->prev = NULL;
  newNode->next = NULL;
  return newNode;
}

void addNode(Node** head, Node** tail, int value) {
  Node* newNode = createNode(value);
  if (*head == NULL) {
    *head = newNode;
    *tail = newNode;
  } else {
    (*tail)->next = newNode;
    newNode->prev = *tail;
    *tail = newNode;
  }
  (*tail)->next = *head;
  (*head)->prev = *tail;
}

int isPrime(int n) {
  if (n <= 1) {
    return 0;
  }
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      return 0;
    }
  }
  return 1;
}

void findPrimeNumbers(Node* head) {
    Node* current = head;
    do {
    if (isPrime(current->value)) {
        printf("%d is a prime number\n", current->value);
    }
    current = current->next;
    } while (current != head);
}

int main() {
  Node* head = NULL;
  Node* tail = NULL;
  int n;
  printf("ENter size of list");
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
        int d;
        printf("Enter data of node %d: ",i);
        scanf("%d",&d);
        addNode(&head,&tail,d);
  }

  findPrimeNumbers(head);
  return 0;
}