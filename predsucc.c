#include<stdio.h>
#include<stdlib.h>
void insert(int item);
struct node* search(struct node*ptr,int key);

struct node
{
    int data;
    struct node*lptr,*rptr;
}*root=NULL,*ptr,*ptr1,*new,*parent,*ptr2,*rchild,*lchild;
void main()
{
    int op,item,value,key;
    do
    {
        printf("1.insert\t2.predecessor\t3.successor\nEnter the option\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:printf("Enter the element\n");
                scanf("%d",&item);
                insert(item);
                break;
            case 2:printf("Enter the element\n");
                    scanf("%d",&key);
                ptr1=search(root,key);
                if(parent==NULL)
                {
                    printf("No immediate predecessor\n");
                }
                else
                {
                    printf("Immediate predecessor: %d\n",parent->data);
                }
                break;
            case 3:printf("Enter the element\n");
                scanf("%d",&key);
                ptr2=search(root,key);
                if((rchild==NULL)&&(lchild==NULL))
                {
                    printf("No immediate successor\n");
                }
                else if((rchild!=NULL)&&(lchild!=NULL))
                    {
                     printf("Immediate successors: %d %d\n",rchild->data,lchild->data);

                    }
                else
                {
                    if((rchild!=NULL)&&(lchild==NULL))
                    {
                        printf("Immediate successor: %d\n",rchild->data);
  
                    }
                    else
                    {
                        printf("Immediate successor: %d\n",lchild->data);
  
                    }
                }
                break;
            case 4:break;
            default:printf("Invalid choice\n");
                    break;
        }
    }while(op!=4);
}
void insert(int item)

{
    new=(struct node*)malloc(sizeof(struct node));
    new->data=item;
    new->lptr=NULL;
    new->rptr=NULL;
    if(root==NULL)
    {
        root=new;
    }
    else
    {
        ptr=root;
        while(ptr!=NULL)
        {
            parent=ptr;
            if(item<ptr->data)
            {
                ptr=ptr->lptr;
            }
            else
            {
                ptr=ptr->rptr;
            }
        }
            if(item<parent->data)
            {
                parent->lptr=new;
            }
            else
            {
                parent->rptr=new;
            }
        }
    }
    struct node* search(struct node*ptr,int key)
    {
        if(ptr==NULL)
        {
            return 0;
        }
        else
        {
            while(ptr!=NULL)
            {
                if(ptr->data==key)
                {
                    break;
                }
                else if(key<ptr->data)
                {
                    parent=ptr;
                    ptr=ptr->lptr;
                }
                else
                {
                    parent=ptr;
                    ptr=ptr->rptr;
                }
            }
            if((ptr->lptr==NULL)&&(ptr->rptr==NULL))
            {
                rchild=NULL;
                lchild=NULL;
            }
            else if((ptr->lptr!=NULL)&&(ptr->rptr!=NULL))
            {
                lchild=ptr->lptr;
                rchild=ptr->rptr;
            }
            else
            {
                if((ptr->lptr!=NULL)&&(ptr->rptr==NULL))
                {
                    lchild=ptr->lptr;
                    rchild=NULL;
                }
                else
                {
                    lchild=0;
                    rchild=ptr->rptr;
                }
            }

        }
    }