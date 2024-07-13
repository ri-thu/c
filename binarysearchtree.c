#include<stdio.h>
#include<stdlib.h>
void display();
void insert(int item);
struct node* search(int key);
void delete(int value);
struct node* inordersucc(struct node*ptr);
void preorder(struct node*ptr);
void inorder(struct node*ptr);
void postorder(struct node*ptr);

struct node
{
    int data;
    struct node*lptr,*rptr;
}*root=NULL,*ptr,*ptr1,*new,*parent,*succ;
void main()
{
    int op,item,value,key;
    do
    {
        printf("1.insert\t2.search\t3.delete\t4.display\t5.exit\nEnter the choice\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:printf("Enter the element to be inserted\n");
                scanf("%d",&item);
                insert(item);
                break;
            case 2:printf("Enter the element to be searched\n");
                scanf("%d",&key);
                ptr1=search(key);
                if(ptr1==NULL)
                {
                    printf("Node not found\n");
                }
                else
                {
                    printf("Element found\n");
                }
                break;
            case 3:printf("Enter the element to be deleted\n");
                    scanf("%d",&value);
                    delete(value);
                    break;
            case 4:display();
                    break;
            case 5:break;
            default:printf("Invalid choice\n");
                    break;
        }
    } while (op!=5);
    
}
void display()
{
    int d;
    printf("1.preorder\t2.inorder\t3.postorder\nEnter the choice\n");
    scanf("%d",&d);
    switch(d)
    {
        case 1:preorder(root);
                break;
        case 2:inorder(root);
                break;
        case 3:postorder(root);
                break;
        case 4:printf("Invalid choice\n");
                break;
    }
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
struct node* search(int key)
{
    while(ptr!=NULL)
    {
        if(ptr->data==key)
        {
            return(ptr);
        }
        else if(key<ptr->data)
        {
            ptr=ptr->lptr;
        }
        else
        {
            ptr=ptr->rptr;
        }
    }
}
void delete(int value)
{
    int flag=0;
    if(root==NULL)
    {
        printf("Tree is empty\n");
    }
    else
    {
        ptr=root;
        while(ptr!=NULL)
        {
            if(ptr->data==value)
            {
                flag=1;
                break;
            }
            else if(value<ptr->data)
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
        if(flag==0)
        {
            printf("Element not found.Deletion not possible\n");
        }
        else
        {
            if((ptr->lptr==NULL)&&(ptr->rptr==NULL))
            {
                if(ptr->data<parent->data)
                {
                    parent->lptr=NULL;
                }
                else
                {
                    parent->rptr=NULL;
                }
            }
            else if((ptr->lptr!=NULL)&&(ptr->rptr!=NULL))
            {
                succ=inordersucc(ptr);
                ptr->data=succ->data;
                free(succ);
            }
            else
            {
                if(ptr->lptr==NULL)
                {
                    if(ptr->data<parent->data)
                    {
                        parent->lptr=ptr->rptr;
                    }
                    else
                    {
                        parent->lptr=ptr->rptr;
                    }
                }
                else
                {
                    if(ptr->data<parent->data)
                    {
                        parent->rptr=ptr->lptr;
                    }
                    else
                    {
                        parent->rptr=ptr->rptr;
                    }
                }
            }
            free(ptr);
        }

     }
}
struct node *inordersucc(struct node*ptr)
{
    ptr1=ptr->rptr;
    while(ptr1->lptr!=NULL)
    {
        ptr1=ptr1->lptr;
    }
    return(ptr1);

}
void preorder(struct node*ptr)
{
    if(ptr!=NULL)
    {
        printf("%d\t",ptr->data);
        preorder(ptr->lptr);
        preorder(ptr->rptr);    
    }
}
void inorder(struct node*ptr)
{
    if(ptr!=NULL)
    {
        inorder(ptr->lptr);
        printf("%d\t",ptr->data);
        inorder(ptr->rptr);
    }
}
void postorder(struct node*ptr)
{
    if(ptr!=NULL)
    {
        postorder(ptr->lptr);
        postorder(ptr->rptr);
        printf("%d\t",ptr->data);
    }
}
