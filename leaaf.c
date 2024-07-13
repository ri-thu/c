#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *lptr,*rptr;
}*ptr=NULL,*root=NULL,*parent=NULL,*new,*insucess;

void insert(int item)
{
    ptr=root;
    new=(struct node *)malloc(sizeof(struct node));
    new->data=item;
    new->lptr=NULL;
    new->rptr=NULL;
    if(ptr==NULL)
    {
        root=new;
    }
    else
    {
        while(ptr!=NULL)
        {
            parent=ptr;
            if(ptr->data>item)
            {
                ptr=ptr->lptr;
            }
            else
            {
                ptr=ptr->rptr;
            }
        }
        if(parent->data>item)
        {
            parent->lptr=new;
        }
        else
        {
            parent->rptr=new;
        }
    }
}
void inorder(struct node *ptr)
{
    if(ptr==NULL)
    {
        return;
    }
    else
    {
        inorder(ptr->lptr);
        printf("%d\t",ptr->data);
        inorder(ptr->rptr);
    }
}
void postorder(struct node *ptr)
{
    if(ptr==NULL)
    {
        return;
    }
    else
    {
        postorder(ptr->lptr);
        postorder(ptr->rptr);
        printf("%d\t",ptr->data);

    }
}
void preorder(struct node *ptr)
{
    if(ptr==NULL)
    {
        return;
    }
    else
    {
        printf("%d\t",ptr->data);
        preorder(ptr->lptr);
        preorder(ptr->rptr);
    }
}
void display()
{
    printf("preorder representation is :");
    preorder(root);
    printf("\n");
    printf("inorder representation is :");
    inorder(root);
    printf("\n");
    printf("postorder representation is :");
    postorder(root);
    printf("\n");
}
struct node *insuc(struct node*ptr)
{
    ptr=ptr->rptr;
    while(ptr->lptr!=NULL)
    {
        ptr=ptr->lptr;
    }
    return ptr;
}
void delete(int item)
{
    int flag=0,sucess;
    ptr=root;
    while(ptr!=NULL)
    {
        if(ptr->data==item)
        {
            break;
        }
        else if(ptr->data>item)
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
    if(ptr==NULL)
    {
        printf("cannot delete\n");
    }
    else
    {
        if(ptr->lptr==NULL&&ptr->rptr==NULL)
        {
            if(parent->lptr==ptr)
            {
                parent->lptr=NULL;
            }
            else
            {
                parent->rptr=NULL;
            }
        }
        else if(ptr->lptr!=NULL&&ptr->rptr!=NULL)
        {
            insucess=insuc(ptr);
            sucess=insucess->data;
            delete(sucess);
            ptr->data=insucess->data;
        }
        else
        {
            if(ptr->rptr==NULL)
            {
                if(ptr==root)
                {
                    root=ptr->lptr;
                }
                else if(parent->lptr==ptr)
                {
                    parent->lptr=ptr->lptr;
                }
                else
                {
                    parent->rptr=ptr->lptr;
                }
            }
            else
            {
                if(ptr==root)
                {
                    root=ptr->rptr;
                }
                else if(parent->lptr==ptr)
                {
                    parent->lptr=ptr->rptr;
                }
                else
                {
                    parent->rptr=ptr->rptr;
                }
            }
        }
    }
    free(ptr);
}
void search(int val)
{
    ptr=root;
    int flag=0;
    while(ptr!=NULL)
    {
        if(ptr->data==val)
        {
            flag=1;
            break;
        }
        else if(ptr->data>val)
        {
            ptr=ptr->lptr;
        }
        else
        {
            ptr=ptr->rptr;
        }
    }
    if(flag==1)
    {
        printf("The node %d is Found\n",ptr->data);
    }
    else
    {
        printf("The node not found\n");
    }
}
void leafnode(struct node*ptr)
{
    if(ptr==NULL)
    {
        return;
    }
    leafnode(ptr->lptr);
    if(ptr->lptr==NULL&&ptr->rptr==NULL)
    {
        printf("%d\t",ptr->data);
    }
    leafnode(ptr->rptr);
}
void nonleaf(struct node *ptr)
{
    if(ptr==NULL)
    {
        return;
    }
    nonleaf(ptr->lptr);
    if(ptr->lptr!=NULL||ptr->rptr!=NULL||(ptr->lptr!=NULL&&ptr->rptr==NULL)||(ptr->lptr==NULL&&ptr->rptr!=NULL))
    {
        printf("%d\t",ptr->data);
    }
    nonleaf(ptr->rptr);
}
int number(struct node*ptr)
{
    int x,y;
    if(ptr==NULL)
    {
        return 0;
    }
    else
    {
        x=number(ptr->lptr);
        y=number(ptr->rptr);
        return(x+y+1);
    }
}
void largest(struct node*ptr)
{
    if(ptr==NULL)
    {
        return;
    }
    while(ptr->rptr!=NULL)
    {
        ptr=ptr->rptr;
    }
    int a=ptr->data;
    printf("%d\t",a);
    //delete(a);
}
void smallest(struct node *ptr)
{
    if(ptr==NULL)
    {
        return;
    }
    while(ptr->lptr!=NULL)
    {
        ptr=ptr->lptr;
    }
    int a=ptr->data;
    printf("%d",a);
    //delete(a);
}
int height(struct node *ptr)
{
    if(ptr==NULL)
    {
        return-1;
    }
    else
    {
        int x=height(ptr->lptr);
        int y=height(ptr->rptr);
        return((x>y?x:y)+1);
    }
}

void main()
{
    int item,op,n,h;
    do
    {
        printf("Enter\t1-insert\t2-delete\t3-search\t4-display\t5-leafnode\t6-nonleafnode\t7-largest\t8-smallest\t9-height of tree\n10-number of nodes\t11-exit\n");
        printf("\nEnter the choice :");
        scanf("%d",&op);
        switch(op)
        {
            case 1 :printf("Enter the item to be inserted :");
                    scanf("%d",&item);
                    insert(item);
                    printf("\n");
                    break;
            case 2 :printf("enter the node to delete :");  
                    scanf("%d",&item);
                    delete(item);
                    printf("\n");
                    break;
            case 3 : printf("Enter the node to ne searched : ");
                    scanf("%d",&item);
                    search(item);
                    printf("\n");
                    break;
            case 4 : display();
                    break; 
            case 5 : leafnode(root);
                    printf("\n");
                     break;
            case 6 : nonleaf(root);
                    printf("\n");
                     break;
            case 7 : largest(root);
                    printf("\n");
                    break;
            case 8 : smallest(root);
                     printf("\n");
                    break;
            case 9 :
                    h=height(root);
                     printf("Height of tree is : %d \n",h);
                     printf("\n");
                     break;
           
            case 10 : n=number(root);
                        printf("Number of nodes is %d\n",n);
                        break; 
            case 11 :break;                                      
            default : printf("Invalid choice entered\n");
                     break;
        }
    }while(op!=11);
}
