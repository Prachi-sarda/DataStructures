#include <stdio.h>
#include <stdbool.h>
//Find the largest contigous subarray of even numbers, and output its size
//Example in 1 2 3 4 4 5 2 6 8 the largest subarray is of size 3. (2 6 8)
int max(int num1,int num2){
    return(num1>num2)?num1:num2;
}
int main(){
    int t;
    printf("Enter t:");
	scanf("%d",&t);
	int n;
	for(int j=1;j<=t;j++){
        int count=0,ans=0;
        printf("Enter n:");
	    scanf("%d",&n);

	    int arr[n];
        printf("Enter array: ");
	    for(int i=0;i<n;i++){
	        scanf("%d",&arr[i]);
        }
	    
        for(int i=0;i<n;i++){
            if(arr[i]%2==0){ 
                count++;
            }
            else count=0;
            ans=max(count,ans);
        }
	    
	   printf("%d",ans);  
	} 
	return 0;
}