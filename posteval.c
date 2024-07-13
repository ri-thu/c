#include<stdio.h>
#include<math.h>
#include<string.h>
void push(int s);
int pop();
int op(char s,int a,int b);

#define max_size 100
int top=-1; 
int stack[max_size];
void main()
{
	char postfix[max_size],symbol,operator;
	int x,y,result,i,eval_result,s;
	printf("Enter postfix expression\n");
	gets(postfix);
	
	for(i=0;postfix[i]!='\0';i++)
	{
		symbol=postfix[i];
		switch(symbol)
		{
			case'^':
			case'/':
			case'*':
			case'+':
			case'-':
				if(top!=-1)
				{
				operator=symbol;
				y=pop();
				x=pop();
				result=op(operator,x,y);
				push(result);
				}
				break;
			default:
				s=(int)postfix[i]-'0';
				push(s);
				break;
		}

	}
	eval_result=pop();
	printf("The result is %d\n",eval_result);
}
void push(int s)
{
	top=top+1;
	stack[top]=s;
	
}
int pop()
{
int del_item;
del_item=stack[top];
top=top-1;
return(del_item);
}
int op(char s,int a,int b)
{
	int r;
switch(s)
{
	case'^':r=pow(a,b);
		return(r);
		break;
	case'/':r=a/b;
		return(r);
		break;
	case'*':r=a*b;
		return(r);
		break;
	case'+':r=a+b;
		return(r);
		break;
	case'-':r=a-b;
		return(r);
		break;
	default:return(0);
	        break;
}
}
