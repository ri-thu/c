#include<stdio.h>
#define max_size 3
void enqueuerear(int m);
void pushDQ(int m);
void dequeuefront();
void eject();
void display();
int queue[max_size],front=-1,rear=-1;
void main()
{
int op,m;
char ch;
do
{
	printf("1--pushDQ\t2--enqueuerear\t3--dequeuefront\t4--eject\t5--display\nEnter the choice\n");
	scanf("%d",&op);
	switch(op)
	{
		case 1:printf("Enter the element to be pushed\n");
			scanf("%d",&m);
			pushDQ(m);
			break;
		case 2:printf("Enter the element to be pushed\n");
			scanf("%d",&m);
			enqueuerear(m);
			break;
		case 3:dequeuefront();
			break;
		case 4:eject();
			break;
		case 5:display();
			break;
		default:printf("Invalid option\n");
			break;
	}
	printf("DO YOU WANT TO CONTINUE\n");
	__fpurge(stdin);
	scanf("%c",&ch);
}
while(ch=='Y'||ch=='y');
}
void enqueuerear(int m)
{
		if(front==-1)
		{
		front=0;
		rear=0;
		queue[rear]=m;
		}
		else if(front==(rear+1)%max_size)
		{
			printf("Queue is full.Insertion not possible\n");
		}
		else
		{
		rear=(rear+1)%max_size;
		queue[rear]=m;
	
	}
}
	
void pushDQ(int m)
{
	int temp;
	if(front==-1)
	{
		front=0;
		rear=0;
		queue[front]=m;
	}
	else if(front==0)
	{
		temp=max_size-1;
		if(temp==rear)
		{
			printf("Stack is full.Insertion not possible\n");
			
		}
		else
		{
			front=temp;
			queue[front]=m;
		}
	}
	else
	{
		temp=front-1;
		if(temp==rear)
		{
			printf("Stack is full.Insertion not possiblr\n");
		}
		else
		{
			front=temp;
			queue[front]=m;
		
		}
		
	}

	}


void dequeuefront()
{
	int del_item;
	if(front==-1)
	{
		printf("Queue is empty.Deletion not possible\n");
	}
	else
	{
		del_item=queue[front];
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		else
		{
		front=(front+1) % max_size;
		}
	}
}


void eject()
{
	int del_item;
	if(front==-1)
	{
		printf("Stack is empty\n");
	}
	else
	{
		del_item=queue[rear];
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		else if(rear==0)
		{
			rear=max_size-1;
			
		}
		else
		{
		rear=rear-1;
		}
		
	}
}
void display()
{
	int i;
	if(front==-1)
	{
		printf("Queue is empty\n");
	}
	else
	{
		for(i=front;i!=rear;i=(i+1)%max_size)
		{
			printf("%d\t",queue[i]);
		}
		printf("%d\t",queue[i]);
		printf("\n");
	}
}
