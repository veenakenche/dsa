#include<stdio.h>

char s[100];
int top=-1;
void push(char ele)
{
 top++;
 s[top]=ele;
}
char pop()
{
return (s[top--]);
}
int pr(char op)
{
switch(op)
{
case '#':return 0;
case '(':
return 1;
case '+':
case '-':
return 2;
case '*':
case '/':
    return 3;
    default:return 0;
}
}
int main()
{

    char infix[100];
    char ch;
    int i=0;

    printf("Enter the infix expression:");
    scanf("%s",infix);
    push('#');
    while(infix[i]!='\0')
    {
        if(isalpha(infix[i])){
        printf("%c",infix[i]);}
        else if(infix[i]=='('){
                    push(infix[i]);}
        else if(infix[i]==')')
        {
            while(s[top]!='('){
                    ch=pop();
                    printf("%c",ch);}
                    pop();
        }
        else{
            while((s[top]!='#')&&(pr(infix[i])<=pr(s[top])))
            {
                  ch=pop();
                    printf("%c",ch);
            }
            push(infix[i]);
        }
       i++;
    }
    while (top > 0) {
        if (s[top] == '(') {
            printf("INVALID EXPRESSION");
            return 1;  // Exit if there's an unmatched '('
        }
        printf("%c", pop());
    }

    return 0;
}
