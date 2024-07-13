#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next,*prev;

}*ptr1,*temp,*head,*tail,*ptr,*new;
void main()
{
    int item,c,m,i,pos,del_item;
    do
    {
        new=(struct node*)malloc(sizeof(struct node));
        printf("Enter the element\n");
        scanf("%d",&item);
        new->data=item;
        new->next=NULL;
        new->prev=NULL;
        if(head==NULL)
        {
            head=new;
        }
        else
        {
            ptr=head;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=new;
            new->prev=ptr;
            tail=new;
        }
        printf("Do you want to continue. press 1");
        scanf("%d",&c);
    }
    while(c==1);
    ptr=head;
    while(ptr->next!=NULL)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
    printf("%d\n",ptr->data);
    printf("Enter the value to be searched\n");
    scanf("%d",&m);
    ptr=head;
    while(ptr->next!=NULL)
    {
        if(ptr->data==m)
        {
            ptr1=ptr;
            ptr=ptr->next;
            temp=ptr;
            del_item=temp->data;
            if(temp==tail)
            {
                ptr1->next=NULL;
                tail=ptr1;

            }
        }
        else
        {
            ptr1->next->prev=ptr1;
            temp->prev=NULL;
            temp->next=NULL;

        }
        temp->next=ptr;
        head=temp;

        }
    }



