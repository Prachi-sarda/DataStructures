//Next greatest element
//Array + Stack

// with array
// next =-1
// for 1,<n,++
// if i<j 
// next = aj
// break
// Print next
// loop

#include <stdio.h>
void next_greater_element(int arr[], int n) {
    int ans[n];
    for(int i = 0; i < n; i++) {
        int next = -1;
        for(int j = i+1; j < n; j++) {
            if(arr[i] < arr[j]) {
                next = arr[j];
                break;
            }
        }
        ans[i] = next;
    }
    printf("Next greatest elements: ");
    for(int i = 0; i < n; i++) {
        printf("%d->%d\n",arr[i], ans[i]);
    }
}

int main() {
    int arr[5];
    printf("Enter array of size 5: ");
    for(int i=0;i<5;i++){
        scanf("%d",&arr[i]);
    }
    int n = sizeof(arr) / sizeof(arr[0]);
    next_greater_element(arr, n);
    return 0;
}