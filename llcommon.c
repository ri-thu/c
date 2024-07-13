#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev,*next;
} *head=NULL,*temp=NULL,*ptr=NULL,*ptr1=NULL,*ptr2=NULL,*new,*new1,*head1=NULL,*head2=NULL,*head3=NULL,*ptr3=NULL,*ptr4=NULL;
struct node* insert()
{
    head=NULL;
	int item,op;
    do{
	printf("enter the element to be inserted: ");
	scanf("%d",&item);
	new=(struct node*)malloc(sizeof(struct node));
	new->data=item;
	new->prev=NULL;
	new->next=NULL;
    if(head==NULL)
	{
		head=new;
	}
	else
	{
		head->prev=new;
		new->next=head;
		head=new;
	}
    printf("Do you want to continue(1/0): ");
    scanf("%d",&op);
    }while(op==1);
    return head;
}
void display(struct node* ptr)
{
    printf("Entered LL is\n");
    if(ptr==NULL)
    {
        printf("LINKEDLIST IS EMPTY!!!\n");

    }
    else
    {
        //ptr=head;
        while(ptr->next!=NULL)
        {
            printf("%d\t",ptr->data);
            //count++;
            ptr=ptr->next;
        }
         printf("%d\n",ptr->data);
         //printf("no of nodes=%d\n",count);
    }
}
struct node* common(struct node*ptr1,struct node*ptr2)
{
    ptr4=ptr2;
    while(ptr1!=NULL)
    {
        ptr2=ptr4;
        while(ptr2!=NULL)
        {
            if(ptr1->data==ptr2->data)
            {
                new1=(struct node*)malloc(sizeof(struct node));
                new1->data=ptr1->data;
                new1->next=NULL;
                new1->prev=NULL;
                if(ptr3==NULL)
                {
                    ptr3=new1;
                }
                else
                {
                    ptr3->prev=new1;
		            new1->next=ptr3;
		            ptr3=new1;
                }
            }
            ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
    }
    return ptr3;
}
void main()
{
    printf("Enter the first ll\n");
    head1=insert();
    display(head1);
    printf("Enter the second ll\n");
    head2=insert();
    display(head2);
    printf("Elements common are\n");
    head3=common(head1,head2);
    display(head3);
}
