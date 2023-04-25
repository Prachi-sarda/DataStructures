#include <stdio.h>
#include <ctype.h>
#include<string.h>

int stack[50];
int top = -1;
void push(int temp)
{
    if (top >= 50 - 1) {
        printf("stack over flow");
        return;
    }
    else {
        top = top + 1;
        stack[top] = temp;
    }
}
int pop()
{
    int temp;
    if (top < 0) {
        printf("stack under flow");
    }
    else {
        temp = stack[top];
        top--;
        return temp;
    }
}

int main()
{

    int i,a,b,c;
    char postfix[50];
    char ch;
    printf("Enter postfix: ");
    gets(postfix);

    for (i = 0; i <= strlen(postfix); i++) {
//         if (isdigit(ch)) {
//             push(ch - '0');
//         }
//         else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
//             /* we saw an operator
// * pop top element a and next-to-top elemnet b
// * from stack and compute b operator a
// */
//             a = pop();
//             b = pop();

//             switch (ch) /* ch is an operator */
//             {
//             case '*':
//                 c = b * a;
//                 break;

//             case '/':
//                 c = b / a;
//                 break;

//             case '+':
//                 c = b + a;
//                 break;

//             case '-':
//                 c = b - a;
//                 break;
//             }

            // /* push the value obtained above onto the stack */
            // push(c);
            if(postfix[i]=='+')
		{
			a=pop();
            b=pop();
            c=a+b;
			push(c);
		}
		else if(postfix[i]=='-')
		{
			a=pop();
			b=pop();
			c=b-a;
			push(c);
		}
		else if(postfix[i]=='*')
		{	a=pop();
		b=pop();
		c=b*a;
		push(c);
		}
		else if(postfix[i]=='/')
		{
			a=pop();
			b=pop();
			c=b/a;
			push(c);
		}
		else
		{
			push(postfix[i]);
		}
        }
    }
    printf(" \n Result of expression evaluation : %d \n", pop());
}




