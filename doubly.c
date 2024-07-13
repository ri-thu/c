#include <stdio.h>
#include <stdlib.h>
void insertbeg();
void display();
//void insertend();
//void insertkey();
struct node
{
    int data;
    struct node *llink;
    struct node *rlink;
}*HEADER=NULL,*new,*ptr;
void main()
{
    int n,op;
    do
    {
        printf("1.insertion at front\n2.display\n");
        scanf("%d",&n);
         switch(n)
        {
            case 1:insertbeg();
                    break;
            case 2:display();
                    break;
            default:printf("invalid operator\n");
                break;
        }
        printf("do you want to continue\n1.yes\n2.no\n");
        scanf("%d",&op);
    } while(op==1);
    
}
void insertbeg()
{
    int item;
    printf("enter the element to enter\n");
    scanf("%d",&item);
    new=(struct node*)malloc(sizeof(struct node));
    if(new==NULL)
    {
        printf("insertion not possible\n");
    }
    else
    {
        new->data=item;
        new->llink=NULL;
        new->rlink=NULL;
        if(HEADER==NULL)
        {
            HEADER=new;
        }
        else
        {
            HEADER->llink=new;
            new->rlink=HEADER;
            HEADER=new;
        }
    }
}
void display()
{
    if(HEADER==NULL)
    {
        printf("linked list is empty\n");
    }
    else
    {
        ptr=HEADER;
        while(ptr->rlink!=NULL)
        {
            printf("%d\t",ptr->data);
            ptr=ptr->rlink;
        }
        printf("%d\t",ptr->data);
    }
}