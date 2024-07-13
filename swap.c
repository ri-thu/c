#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*link;
}*new,*h1=NULL,*h2=NULL,*ptr1,*ptr2,*head,*ptr;
void display(struct node*head);
struct node* insert(struct node*head,int item);
void swap(struct node*h1,struct node*h2,int m,int n);
void main()
{
    int op,item,n,m;
    do
    {
        printf("1.Insert to 1st LL\t2.Insert to second LL\t3.swap\t4.display\t5.exit\nEnter the choice\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1: printf("Enter the value\n");
                    scanf("%d",&item);
                    h1=insert(h1,item);
                    break; 
            case 2: printf("Enter the value\n");
                    scanf("%d",&item);
                    h2=insert(h2,item);
                    break; 
            case 3:printf("Enter the element in the first LL\n");
                    scanf("%d",&m);
                    printf("Enter the element in the seconjd LL\n");
                    scanf("%d",&n);
                    swap(h1,h2,m,n);
                    break;
            case 4:printf("1st LL:\n");
                    display(h1);
                    printf("2nd LL: \n");
                    display(h2);
                    break;
            case 5: break;
            default:printf("Invalid choice\n");
                    break;
        }
    } while (op!=5);
    
}
struct node* insert(struct node*head,int item)
{
    new=(struct node*)malloc(sizeof(struct node));
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
    return(head);
}
void swap(struct node*h1,struct node*h2,int m,int n)
{
    int temp,flag=0;
    ptr1=h1;
    while(ptr1!=NULL)
    {
        if(ptr1->data==m)
        {
            flag=1;
            break;
        }
        ptr1=ptr1->link;
    }
    int d=0;
    ptr2=h2;
    while(ptr2!=NULL)
    {
        if(ptr2->data==n)
        {
            d=1;
            break;
        }
        ptr2=ptr2->link;
    }
    if((flag!=0)&&(d!=0))
    {
        temp=ptr1->data;
        ptr1->data=ptr2->data;
        ptr2->data=temp;
    }
    else
    {
        printf("Swapping not possible\n");
    }
}
void display(struct node*head)
{
    if(head==NULL)
    {
        printf("LL empty\n");
    }
    else
    {
        ptr=head;
        while(ptr!=NULL)
        {
            printf("%d\t",ptr->data);
            ptr=ptr->link;
        }
        printf("\n");
    }
}
