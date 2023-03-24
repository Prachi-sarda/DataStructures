//Write a C program that takes an array of integers and a search key from the user
//and uses a linear search algorithm to find the key in the array.

#include <stdio.h>

int search(int *arr, int size, int key) {
    int i;
    for (i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n;
    printf("Enter size of array");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array of size %d: ",n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    
    int key, index;
    printf("Enter the search key: ");
    scanf("%d", &key);
    index = search(arr, n, key);
    if (index != -1) {
        printf("Key found at index %d\n", index);
    } else {
        printf("Key not found\n");
    }
    return 0;
}