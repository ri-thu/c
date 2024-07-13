#include<stdio.h>
#include<stdlib.h>
void insertend();
void display();
void sum();
void delete();
void swap();
struct node
{
    int data;
    struct node *link;
}*head,*new,*ptr,*temp,*ptr1,*ptr2;
void main()
{
    int op;
    do
    {
        printf("1.Insert\t2.sum\t3.delete\t4.swap\t5.display\t6.Exit\nEnter the choice\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1: insertend();
                break;
            case 2: sum();
                 break;
            case 3: delete();
                break;
            case 4:swap();
                break;
            case 5:display();
                    break;
            case 6:break;
            default: printf("Invalid choice\n");
                    break;
        }
    }while(op!=6);
}
void insertend()
{
    int item;
    
        printf("Enter the item to be inserted\n");
        scanf("%d",&item);
        new =(struct node*)malloc(sizeof(struct node));
        new->data=item;
        new->link=NULL;
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
        }
}
void display()
{
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->link;
    }
    printf("\n");
}
void sum()
{
    int sumpo=0;
    int sumne=0;
    ptr=head;
    while(ptr!=NULL)
    {
        if((ptr->data)>=0)
        {
            sumpo=sumpo+(ptr->data);
        }
        else
        {
            sumne=sumne+(ptr->data);
        }
        ptr=ptr->link;
       }
        printf("Sum of positive numbers= %d \n",sumpo);
        printf("Sum of negative numbers= %d\n",sumne);
}
void delete()
{
    int count=0;
    int i,co,del_item;
    ptr=head;
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->link;
    }
    co=count/2;
    ptr=head;
    for(i=1;i<co;i++)
    {
        ptr=ptr->link;
    }
    temp=ptr->link;
    del_item=temp->data;
    ptr->link=temp->link;
    free(temp);
}
void swap()
{
    int t,m,n;
    printf("Enter the elements to be swapped\n");
    scanf("%d%d",&m,&n);
    ptr=head;
    while(ptr!=NULL)
    {
        if(ptr->data==m)
        {
            ptr1=ptr;
        }
        if(ptr->data==n)
        {
            ptr2=ptr;
        }
        ptr=ptr->link;
    }
    t=ptr1->data;
    ptr1->data=ptr2->data;
    ptr2->data=t;
}