#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next,*prev;
}*head=NULL,*ptr,*ptr1,*tail=NULL,*temp,*new;
void main()
{
	int n,item,i,ele,f=0;
	printf("Enter the limit: ");
	scanf("%d",&n);
	ptr=head;
	printf("Enter the elements\n");
	for(i=0;i<n;i++)
	{
		new=(struct node*)malloc(sizeof(struct node));
		printf("Enter the item:");
		scanf("%d",&item);
		new->data=item;
		new->next=NULL;
		if(head==NULL)
		{
			head=new;
			tail=new;
		}
		else
		{
			new->prev=tail;
			tail->next=new;
			tail=new;
		}
	}
	printf("The ll elements are\n");
	ptr=head;
	while(ptr->next!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
	printf("%d\n",ptr->data);
	printf("Enter the element to be checked: ");
	scanf("%d",&ele);
	ptr=head;
	while(ptr->next!=NULL)
	{
		if(ptr->data==ele)
		{
			ptr1=ptr;
			temp=ptr->next;
			(ptr->prev)->next=temp;
			temp->prev=ptr->prev;
			f=1;
		}
		ptr=ptr->next;
	}
	if(f==1)
	{
		head->prev=ptr1;
		ptr1->prev=NULL;
		ptr1->next=head;
		head=ptr1;
		printf("The new ll elements are\n");
		ptr=head;
		while(ptr->next!=NULL)
		{
			printf("%d ",ptr->data);
			ptr=ptr->next;
		}
		printf("%d\n",ptr->data);
	}
}
