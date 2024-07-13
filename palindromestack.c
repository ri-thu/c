#include<stdio.h>
#include<string.h>

#define max 10
int stack[max];
int top=-1;
void push(char item);
char pop();
void main()
{
    char s[max],s1[max];
    int i;
    printf("Enter the string\n");
    gets(s);
    for(i=0;s[i]!='\0';i++)
    {
        push(s[i]);
    }
    for(i=0;i<strlen(s);i++)
    {
        s1[i]=pop();
    }
    s1[i]='\0';
    int flag=0;
    for(i=0;s[i]!='\0';i++)
    {
        if(s[i]!=s1[i])
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("Palindrome\n");
    }
    else
    {
        printf("Not a palindrome\n");
    }
}
void push(char item)
{
        top++;
        stack[top]=item;
    }

char pop()
{
        char del;
        del=stack[top];
        top--;
        return del;
    }
