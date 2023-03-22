//Write a program in C to sort an array using pointers.

#include <stdio.h>

void sort(int n, int* ptr) 
{ 
    int a, b, temp;
    for (a = 0; a < n; a++) {
        for (b = a + 1; b < n; b++) { 
            if (*(ptr + b) < *(ptr + a)) { 
                temp = *(ptr + a); 
                *(ptr + a) = *(ptr + b); 
                *(ptr + b) = temp; 
            } 
        } 
    }
    for (a = 0; a < n; a++) 
        printf("%d ", *(ptr + a)); 
} 
int main(){
    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array:");
    for(int a=0;a<n;a++){
        scanf("%d",&arr[a]);
    }
    sort(n,arr);
}
