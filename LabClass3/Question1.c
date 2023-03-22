//write the C program to read roll.no, name, and marks of 'N' 
//students in structure and display the records of students 
//merit vice
#include <stdio.h>
#include<string.h>

 struct student {
    int rno;
    char name[50];
    float marks;
};

int main(){
    int n;
    struct student s[100],temp;
    printf("Enter no.of students: \n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the the roll.no, name and marks:");
        scanf("%d %s%f",&s[i].rno,s[i].name,&s[i].marks);
    }
    for(int i=0;i<n;i++){
    printf("%d %s %f\n",s[i].rno,s[i].name,s[i].marks);}
    for(int i=0;i<n+1;i++){
        for(int j=0;j<n;j++){
            if(s[i].marks>s[j].marks){
                temp=s[i];
                s[i]=s[j];
                s[j]=temp;
            }
        }
    }
    printf("The Merit list:\n");
    for(int i=0;i<n;i++){
        printf("Roll.No: %d, Name: %s, Marks: %.2f \n",s[i].rno,s[i].name, s[i].marks);
    }
    return 0;
}