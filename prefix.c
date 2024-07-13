#include<stdio.h>
#include<string.h>
void push(char s);
char pop();
int precedence(char s);
#define max_size 100
int top=-1; 
char stack[max_size];
void main()
{
	char prefix[max_size],infix[max_size],inf_rev[max_size],pre_rev[max_size],symbol,n;
	int i,j;
	printf("Enter the infix expression\n");
	gets(infix);
	for(i=0,j=strlen(infix)-1;j>=0;i++,j--)
	{
	    inf_rev[i]=infix[j];
	}
	puts(inf_rev);
	j=0;
	for(i=0;i<strlen(inf_rev);i++)
	{
		symbol=inf_rev[i];
		switch(symbol)
		{
			case')':
				push(symbol);
				break;
			case'(':
				while((n=pop())!=')')
				{
                    prefix[j]=n;
					j++;
				}
				break;
			case'^':
				while(precedence(top)>=precedence(symbol))
				{
				prefix[j]=pop();
				j++;	
				}
				push(symbol);
				break;
			case'+':
			case'-':
			case'*':
			case'/':
				while(precedence(top)>precedence(symbol))
				{
				prefix[j]=pop();
				j++;
				}
				push(symbol);
				break;
			default:prefix[j]=symbol;
				j++;					
				break;
					
		}
	}
	while(top!=-1)
	{
		prefix[j]=pop();
		j++;
	
	}
	
	for(i=0,j=strlen(prefix)-1;j>=0;i++,j--)
	{
	    pre_rev[i]=prefix[j];
	}
	pre_rev[i]='\0';
printf("The postfix expression is:\n");
puts(pre_rev);
}
void push(char s)
{
	top=top+1;
	stack[top]=s;
}
char pop()
{
	char del_item;
	del_item=stack[top];
	top=top-1;
	return(del_item);
}
int precedence(char s)
{
	switch(s)
	{
		case '^':return 3;
			break;
		case'*':
		case'/':
			return 2;
			break;
		case'+':
		case'-':
			return 1;
			break;
	}
}
