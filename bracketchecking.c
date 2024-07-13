#include<stdio.h>
#include<string.h>

#define max 10
int stack[max];
int top=-1;
void push(char item);
char pop();
void main()
{
    char n,s[max];
    printf("Enter the expression\n");
    gets(s);
    int i;
    int flag=0;
    for(i=0;s[i]!='\0';i++)
    {
        if((s[i]=='(')||(s[i]=='[')||(s[i]=='{'))
        {
            push(s[i]);
        }
         else if(s[i]==')')
        {
            if(stack[top]!='(')
            {
                flag=1;
                break;
            }
            else
            {
                pop();
            }
        }
        else if(s[i]==']')
        {
            if(stack[top]!='[')
            {
                flag=1;
                break;
            }
            else
            {
                pop();
            }
        }
        else if(s[i]=='}')
        {
            if(stack[top]!='{')
            {
                flag=1;
                break;
            }
            else
            {
                pop();
            }
        }
        
         else
         {
            flag=1;
            break;
            
         }

    }
    if(flag==0)
    {
        int d=0;
        while(top!=-1)
         {
            n=pop();
            if(n=='('||n==')'||n=='['||n==']'||n=='{'||n=='}')
            {
                d=1;
                break;
            }
        }
        if(d==0)
        {
            printf("Brackets balanced\n");
        }
        else
        {
            printf("Brackets not balanced\n");
        }
    }
    else
    {
        printf("Brackets not balanced\n");
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