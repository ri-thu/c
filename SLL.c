#include<stdio.h>
#include<stdlib.h>
void insertbeg();
void insertend();
void insertpos();
void deletebeg();
void deleteend();
void deletepos();
void display();
struct node
{
	int data;
	struct node *link;
};
struct node *head,*ptr,*new,*temp,*ptr1;
void main()
{
	int item,op,m;
	char ch;
	do
	{                    
	printf("Enter the choice\n1-Insertion at the beginning\t2-Insertion at the end\t3-Insertion at a particular position\t4-Deletion from the beginning\t5-Deletion from the end\t6-Deletion from a particular position\t7-Display\n");
	scanf("%d",&op);
	switch(op)
	{
		case 1:
			new=(struct node*)malloc(sizeof(struct node));
			printf("Enter the data of new node\n");
			scanf("%d",&m);
			new->data=m;
			new->link=NULL;
			insertbeg();
			break;
		case 2:
			new=(struct node*)malloc(sizeof(struct node));
			printf("Enter the data of new node\n");
			scanf("%d",&m);
			new->data=m;
			new->link=NULL;
			insertend();
			break;
		case 3:
			new=(struct node*)malloc(sizeof(struct node));
			printf("Enter the data of new node\n");
			scanf("%d",&m);
			new->data=m;
			new->link=NULL;
			insertpos();
			break;
		case 4:
			deletebeg();
            break;
        case 5:
            deleteend();
            break;
		case 6:
            deletepos();
            break;
		case 7:
			display();
			break;
		default:
			printf("Invalid option\n");
			break;
	}
	printf("Do you want to continue?\n");
	__fpurge(stdin);
	scanf("%c",&ch);
	}
	while(ch=='Y'||ch=='y');
}
void insertbeg()
{
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
void insertend()
{
	if(head==NULL)
	{
		head=new;
	}
	else
	{
		ptr=head;
		while(ptr->link!=NULL)
		{
			ptr=ptr->link;
			
		}
		ptr->link=new;
		new->link=NULL;
	}
}
void insertpos()
{
	int pos,i;
	printf("Enter the position\n");
	scanf("%d",&pos);
	if(pos==1)
	{
		insertbeg();
	}
	else
	{
		ptr=head;
		for(i=1;i<pos-1;i++)
		{
			ptr=ptr->link;
		}
		new->link=ptr->link;
        ptr->link=new;

		
	}
}
void deletebeg()
{
	int del_item;
	if(head==NULL)
	{
		printf("Linked list empty.Deletion not possible\n");
	}
	else if(head->link==NULL)
	{
	    temp=head;
		del_item=temp->data;
		head=NULL;
	}
	else
	{
	    temp=head;
		del_item=temp->data;
		head=temp->link;
	}
	free(temp);
}
void deleteend()
{
	int del_item;
	if(head==NULL)
	{
		printf("Linked list empty.Deletion not possible\n");
	}
	else if(head->link==NULL)
	{
        temp=head;
		del_item=temp->data;
		head=NULL;
	}
	else
	{
        ptr=head;
        while(ptr->link!=NULL)
        {
            ptr1=ptr;
            ptr=ptr->link;
        }
        temp=ptr;
		del_item=temp->data;
        ptr1->link=NULL;
    }
    free(temp);
}
void deletepos()
{
    int del_item,pos,i;
    if(head==NULL)
    {
        printf("Linked list is empty.Deletion not possible\n");
    }
    else if(head->link==NULL)
    {
        temp=head;
        del_item=temp->data;
        head=NULL;
    }
    else
    {
        printf("Enter the position\n");
        scanf("%d",&pos);
        if(pos==1)
        {
            deletebeg();
        }
        else
        {
            ptr=head;
            for(i=1;i<pos-1;i++)
            {
                ptr=ptr->link;
            }
            temp=ptr->link;
            del_item=temp->data;
            ptr->link=temp->link;
        }
    }
    free(temp);
}

void display()
{
	if(head==NULL)
	{
		printf("Linked list is empty\n");
	}
	else
	{
		ptr=head;
		while(ptr->link!=NULL)
		{
			printf("Data=%d\t",ptr->data);
			ptr=ptr->link;
		}
        printf("Data=%d\t",ptr->data);
        printf("\n");

	}
}



