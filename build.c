#include<stdio.h>
#include<math.h>
void buildtree(int a[],int i,int val);
void display();
size_t max_size;
void main()
{
    
	int h,root_val;
	printf("Enter the height of the tree\n");
	scanf("%d",&h);
	max_size=(pow(2,h+1))-1;
	int a[max_size];
	printf("Enter the value of the root node\n");
	scanf("%d",&root_val);
	buildtree(a,1,root_val);
	display();
}
void buildtree(int a[],int i,int val)
{
	int lval,rval;
	char ch;
	if(i==0)
	{
		return;
	}
	else
	{
		a[i]=val;
		if(2*i<=max_size)
		{
			printf("Do you want a left child for %d",a[i]);
			__fpurge(stdin);
			scanf("%c",&ch);
			if(ch=='y'||ch=='Y')
			{
			printf("Enter the value to be inserted\n");
			scanf("%d",&lval);
			buildtree(a,2*i,lval);
			}
			else
			{
				buildtree(a,0,0);
			}
		}
		if((2*i)+1<=max_size)
		{
			printf("Do you want a right child for %d",a[i]);
			__fpurge(stdin);
			scanf("%c",&ch);
			if(ch=='y'||ch=='Y')
			{
				printf("Enter the value to be inserted\n");
				scanf("%d",&rval);
				buildtree(a,(2*i)+1,rval);
			}
			else
			{
				buildtree(a,0,0);
			}
		}	
	}	
}
void display()
{
	int i,a[max_size];
	printf("The array representation of the tree is:\n");
	for(i=1;i<=max_size;i++)
	{
		if(a[i]==0)
		{
			printf("_");
			
		}
		else
		{
			printf("%d",a[i]);
		}
		
	}
	printf("\n");
	
}