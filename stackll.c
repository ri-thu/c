#include<stdio.h>
#define max_size 5
int stack[max_size],top=-1;
void push(int m);
void pop();
void display();
void main()
{
int op,m,n;
char ch;
    do
    {
        printf("1-Push\t2-Pop\t3-Display\nEnter an option\n");
        scanf("%d",&op);   
        switch(op)
        {
            case 1:printf("Enter the element to be inserted\n");
                    scanf("%d",&m);
                    push(m);
                    break;
            case 2:pop();
                    break;
            case 3:display();
                    break;
            default:printf("Invalid option\n");
                    break;
        } 
        printf("DO YOU WANT TO CONTINUE\n");
        __fpurge(stdin);
        scanf("%c",&ch);
    } 
    while (ch=='Y'||ch=='y');
    
}
void push(int m)
{
    if(top>=max_size)
    {
        printf("Stack overflow\n");
    }
    else
    {
        top=top+1;
        stack[top]=m;
    }
}
void pop()
{
    int del_item;
    if(top==-1)
    {
        printf("Stack underflow\n");
    }
    else
    {
        del_item=stack[top];
        top=top-1;
    }
}
void display()
{
    int i;
    if(top==-1)
    {
        printf("The stack is empty\n");
    }
    else
    {
        for(i=0;i<=top;i++)
        {
            printf("%d\t",stack[i]);
        }
        printf("\n");
    }
}