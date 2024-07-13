#include<stdio.h>
#include<stdlib.h>
int a[50],count,large=0;
int item;
struct node
{
    int data;
    struct node *link;
};
struct node *head=NULL,*ptr,*new,*head1=NULL,*ptr1=NULL,*temp;
struct node *insert()
{
    int op;
    do
    {
        new=(struct node*)malloc(sizeof(struct node));
        printf("Enter the item to insert\n");
        scanf("%d",&item);
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
        printf("do you want to comntinue(1/0) :");
        scanf("%d",&op);
    }while(op==1);
    return head;
}
void display(struct node *ptr)
{
        while(ptr!=NULL)
        {
            printf("%d\t",ptr->data);
            ptr=ptr->link;
        }
        printf("\n");
}
int freq(struct node *head)
{
    int max;
    ptr=head;
    ptr1=head->link;
    while(ptr!=NULL)
    {
        count=1;
        while(ptr1!=NULL)
        {
            if(ptr->data==ptr1->data)
            {
                count++;
            }
            ptr1=ptr1->link;
        }
        if(count>large)
        {
            large=count;
            max=ptr->data;
        }
        ptr=ptr->link;
    }
    return max;
        
}
   

void deletee(int pos)
{
    
    if(pos==1)
    {
        if(head->link==NULL)
        {
            head=NULL;
        }
        else
        {
            head=head->link;
            
        }
    }
    else
    {
         ptr=head;
        for(int i=1;i<pos-1;i++)
        {
            ptr=ptr->link;
        }
        temp=ptr->link;
        ptr->link=temp->link;
        
    }
    
}
void main()
{
    int i=0,j,n,count1=1,occ;
    head1=insert();
    printf("the ll is \n");
    display(head1);
    printf("occurance\n");
    occ=freq(head1);
    printf("most occured element occur is %d ",occ);
    printf("\n");
    ptr=head;
    while(ptr!=NULL)
    {
        if(ptr->data==occ)
        {
            deletee(count1);
        }
        else
        {
            count1++;
        }
        ptr=ptr->link;
    }
    printf("after deletion\n");
    display(head);
    
}