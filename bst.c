#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *lptr,*rptr;
}*ptr,*parent,*new,*ptr1;
struct node*root=NULL;
struct node*parent=NULL;
void build(int value);
struct node* search(struct node*ptr,int key);
void delete_bst(struct node*root,int nvalue);
void preorder(struct node*ptr);
void inorder(struct node*ptr);
void postorder(struct node*ptr);
int succ(struct node*ptr1);
void display();
void main()
{
	int op,nvalue,key,t,item;
	char ch;
	do
	{
    	printf("1-Insertion\t2-Deletion\t3-Search\t4-Display\nEnter the choice\n");
    	scanf("%d",&op);
    	switch(op)
    	{
    		case 1:root=(struct node*)malloc(sizeof(struct node));
    				printf("Enter the value to be inserted\n");
    				scanf("%d",&item);
    				build(item);
    				break;
    		case 2:printf("Enter the value of the node to be deleted\n");
    				scanf("%d",&nvalue);
    				delete_bst(root,nvalue);
    				break;
    		case 3:printf("Enter the value to be searched\n");
    				scanf("%d",&key);
    				search(root,key);
    				break;
    		case 4:display();
    				break;
    		case 5:printf("Invalid choice\n");
    				break;
  	  }	
	printf("Do you want to continue?");
	__fpurge(stdin);
	scanf("%c",&ch);
	}
	while(ch=='Y'||ch=='y');
}

void build(int item)
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
struct node* search(struct node*ptr,int key)
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
void delete_bst(struct node*root,int nvalue)
{
	int flag=0,suc;
	if(root==NULL)
	{
		printf("Deletion not possible\n");
	}
	else
	{
		flag=0;
		ptr=root;
		while(ptr!=NULL)
		{
			parent=ptr;
			if(ptr->data==nvalue)
			{
				flag=1;
				break;
			}
			else if(nvalue<ptr->data)
			{
				ptr=ptr->lptr;
			}
			else
			{
				ptr=ptr->rptr;
			}
		}
		if(flag==0)
		{
			printf("Node not found.Deletion not possible\n");
		}
		else
		{
			if((ptr->lptr==NULL)&&(ptr->rptr==NULL))
			{
				parent->lptr=NULL;
				parent->rptr=NULL;
				free(ptr);
			}
			else if((ptr->lptr!=NULL)&&(ptr->rptr!=NULL))
			{
				suc=succ(ptr);
				ptr->data=suc;
			}
			else
			{
				if(ptr->data<parent->data)
				{
					if(ptr->rptr==NULL)
					{
						parent->lptr=ptr->lptr;
					}
					else
					{
						parent->lptr=ptr->rptr;
					}
					
					}
				else
				{
					if(ptr->rptr==NULL)
					{
						parent->lptr=ptr->lptr;
					}
					else
					{
						parent->lptr=ptr->rptr;
					}
				}
				free(ptr);
			}
		}
		
	}
}
int succ(struct node*ptr1)
{
	ptr1->rptr;
	while(ptr1!=NULL)
	{
		if((ptr1->lptr==NULL)&&(ptr1->rptr==NULL))
		{
			return(ptr1->data);
		}
	}	
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
void display()
{
	int t;
	printf("Choose the method of traversal\n1-Preorder\t2-Inorder\t3-Postorder\n");
    scanf("%d",&t);

	switch(t)
    {
    	case 1:printf("Preorder representation:\n");
  					preorder(root);
  					break;
    	case 2:printf("Inorder representation:\n");
    			inorder(root);
    			break;
    	case 3:printf("Postorder representation:\n");
    			postorder(root);
    			break;
    	case 4:printf("Invalid choice\n");
    			break;
    }
   }
