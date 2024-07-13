#include<stdio.h>
#include<stdlib.h>
void deleteend();
void insertbeg();
struct node
{
	int data;
	struct node*link;
}*head,*new,*ptr,*temp,*ptr1,*ptr2;
void main()
{
	int i,count=0;
	int reverse[10];
	char ch;
	do
	{
		insertbeg();
		printf("Do you want to continue?");
		__fpurge(stdin);
		scanf("%c",&ch);
	}
	while(ch=='Y'||ch=='y');
	ptr=head;
	while(ptr!=NULL)
	{
		printf("%d\t",ptr->data);
		count++;
		ptr=ptr->link;
	}
	printf("\n");
	printf("%d\n",count);
	for(i=0;i<count;i++)
	{
		deleteend();
	}
}

void insertbeg()
{
	int item;
	printf("Enter the element\n");
	scanf("%d",&item);
	new=(struct node*)malloc(sizeof(struct node));
	new->data=item;
	new->link=NULL;
	if(head==NULL)
	{
		head=new;
	}
	else
	{
		new->link=head;
		head=new;
	}
}
void deleteend()
{
	int del_node;
	if(head==NULL)
	{
		printf("Linked list is empty/n");
	}
	else
	{
		ptr1=head;
		while(ptr1->link!=NULL)
		{
			ptr2=ptr1;
			ptr1=ptr1->link;
		}
		temp=ptr1;
		del_node=temp->data;
		ptr2->link=NULL;
		free(ptr1);
		printf("%d\t",del_node);
	}
}

