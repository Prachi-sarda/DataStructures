//Write a code in C to count the number of vowels and consonants in a string
#include <stdio.h>
#include <string.h>

int main(){
char string[1000];  
    printf("Enter string: ");
    scanf("%string",&string);
    int i,vowels=0,consonants=0;
	for(i=0;string[i];i++)  
    {
    	if((string[i]>=65 && string[i]<=90)|| (string[i]>=97 && string[i]<=122))
    	{
		 if(string[i]=='a'|| string[i]=='e'||string[i]=='i'||string[i]=='o'||string[i]=='u'||string[i]=='A'||string[i]=='E'||string[i]=='I'||string[i]=='O' ||string[i]=='U')
		      vowels++;
            else
             consonants++;}
    }
    printf("vowels = %d\n",vowels);
    printf("consonants = %d\n",consonants);
}