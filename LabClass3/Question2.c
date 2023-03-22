//Assign values to 5 nodes, and creare linked list without malloc function 
//Find number of even and odd nodes
#include <stdio.h>
// Define a struct for the nodes in the linked list
struct node {
    int data;
    struct node *next;
};

int main() {
    // Create the linked list nodes
    struct node node1, node2, node3, node4, node5,node[5];
    
    // Set the data values for each node
    node1.data = 1;
    node2.data = 2;
    node3.data = 3;
    node4.data = 4;
    node5.data = 5;

    //Link the nodes together
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = NULL;

    // Traverse the linked list and count the even and odd nodes
    int even_count = 0;
    int odd_count = 0;
    struct node *current = &node1;
    while (current != NULL) {
        if (current->data % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
        current = current->next;
    }
    
    // Print the results
    for(int i=1;i<=5;i++){
    printf("%d ",node[i]);}
    printf("Number of even nodes: %d\n", even_count);
    printf("Number of odd nodes: %d\n", odd_count);
    
    return 0;
}