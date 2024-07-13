#include<stdio.h>
#include<stdlib.h>
int a[30],b[20];
struct node
{
    int data;
    struct node *link;
}*head=NULL,*ptr=NULL,*ptr1=NULL,*ptr2=NULL,*ptr3=NULL,*head1=NULL,*head2=NULL,*new,*head3=NULL,*pt2;
struct node* insert()
{
    int item,op;
    head=NULL;
    do
    {
    new=(struct node*)malloc(sizeof(struct node));
    printf("enter the item to insert :");
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
    printf("DO YOU WANT TO CONTINUE (1/0)");
    scanf("%d",&op);
    }while(op==1);
    return head;
}
void display(struct node*ptr)
{
    printf("Entered ll is\n");
    if(ptr==NULL)
    {
        printf("LL is empty\n");
    }
    else
    {
        while(ptr->link!=NULL)
        {
            printf("%d\t",ptr->data);
            ptr=ptr->link;
        }
        printf("%d\n",ptr->data);
    }
}
struct node* merge(struct node* ptr1,struct node* ptr2)
{
    ptr=ptr1;
    while(ptr1->link!=NULL)
    {
        ptr1=ptr1->link;
    }
    ptr1->link=ptr2;
    return ptr;
}
void main()
{
    int i=0,n,j,temp;
    printf("Enter the first ll\n");
    head1=insert();
    display(head1);
    printf("enter the second ll\n");
    head2=insert();
    display(head2);
    head3=merge(head1,head2);
    display(head3);
    ptr3=head3;
    while(ptr3!=NULL)
    {
        a[i++]=ptr3->data;
        ptr3=ptr3->link;
    }
    n=i;
    printf("the unsorted array is\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }

    }
    printf("the sorted array is\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    ptr=head3;
    while(ptr!=NULL)
    {
        pt2=ptr;
        ptr=ptr->link;
    }
    int sum=0;
    for(i=0;i<n;i++)
    {
        sum=a[0]+a[n];
    }
    printf("Sum of last and first tems is %d \n",sum);
    //duplicate
    int k=0,visit;
    for(i=0;i<n;i++)
    {
        visit=0;
        for(j=i+1;j<n;j++)
        {
            if(a[i]==a[j])
            {
                    visit=1;
                    break;
            }
           
        }
        if(!visit)
        {
            b[k]=a[i];
            k++;
        }
       
    }
    for(i=0;i<k;i++)
    {
        printf("%d\t",b[i]);
    }
    printf("\n");
    
}
