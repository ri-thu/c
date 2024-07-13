#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *lptr,*rptr;
	int data;
}*root,*new1,*parent;

int count = 0;
int countnodes(struct node *root)
{
    if(root != NULL)
    {
        countnodes(root->lptr);
        count++;
        countnodes(root->rptr);
    }
    return count;
}

struct node* search(int val)
{
	struct node *ptr=root;
	while(ptr!=NULL)
	{
		if(ptr->data==val)
			return ptr;
		else
		{
		    parent=ptr;
		    if(ptr->data>val)
			    ptr=ptr->lptr;
		    else
			    ptr=ptr->rptr;
		}
	}
	return ptr;
}
void insert(int val)
{
	new1=(struct node*)malloc(sizeof(struct node));
	new1->data=val;
	new1->rptr=new1->lptr=NULL;
	if(root==NULL)
		root=new1;
	else
	{
		search(val);
		if(parent->data>val)
			parent->lptr=new1;
		else
			parent->rptr=new1;
	}
}
int height(struct node *ptr)
{
	int x,y;
		x=1,y=1;
		if(ptr->lptr!=NULL)
			x+=height(ptr->lptr);
		if(ptr->rptr!=NULL)
			y+=height(ptr->rptr);
		return x>y?x:y;
}
struct node* insuccesor(struct node *ptr)
{
	ptr=ptr->rptr;
	while(ptr->lptr!=NULL)
		ptr=ptr->lptr;
	return ptr;
}
void delete1(int val)
{
	struct node *insuccess,*ptr=search(val),*ptr1;
	if(ptr==NULL)
		printf("Element not found deletion not possible \n");
	else if(ptr->lptr!=NULL&&ptr->rptr!=NULL)
	{
		insuccess=insuccesor(ptr);
		delete1(insuccess->data);
		ptr->data=insuccess->data;
	}
	else
	{
		if(ptr->lptr==NULL&&ptr->rptr==NULL)
			ptr1=NULL;
		else if(ptr->rptr==NULL)
			ptr1=ptr->lptr;
		else if(ptr->lptr==NULL)
			ptr1=ptr->rptr;
		if(ptr==root)
			root=ptr1;
		else if(parent->lptr==ptr)
			parent->lptr=ptr1;
		else
			parent->rptr=ptr1;
	}
}
void Preorder(struct node *ptr)
{
	if(ptr!=NULL)
	{
		printf(" %d",ptr->data);
		Preorder(ptr->lptr);
		Preorder(ptr->rptr);
	}
}
void Postorder(struct node *ptr)
{
	if(ptr!=NULL)
	{
		Postorder(ptr->lptr);
		Postorder(ptr->rptr);
		printf(" %d",ptr->data);
	}
}
void Inorder(struct node *ptr)
{
	if(ptr!=NULL)
	{
		Inorder(ptr->lptr);
		printf(" %d",ptr->data);
		Inorder(ptr->rptr);
	}
}
void display()
{
	if(root==NULL)
		printf("Tree is empty\n");
	else
	{
	       printf("Preorder representation of tree : ");
	       Preorder(root);
	       printf("\n");
	       printf("Inorder representation of tree : ");
	       Inorder(root);
	       printf("\n");
	       printf("Postorder representation of tree : ");
	       Postorder(root);
	       printf("\n");
	 }
}
void main()
{
	int c,val,number;
	do
	{
		printf("Type 1:Insert 2:Delete 3:Search 4:Display 5:Height 6: Count 7:Exit\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:printf("Enter the value to insert :");
			            scanf("%d",&val);
			            insert(val);
			            break;
			case 2:printf("Enter the value of node to delete : ");
			            scanf("%d",&val);
			            delete1(val);
			            break;
			case 3:printf("Enter the value of node to search : ");
			            scanf("%d",&val);
			            if(search(val)!=NULL)
			                    printf("%d is found\n",val);
			            else
			        	      printf("%d is not found\n",val);
			            break;
			case 4:display();
			            break;
			case 5:val=height(root);
			 				printf("Height = %d\n",val-1);
			case 6: number = countnodes(root);
					printf("%d\n",number);
					break;
			case 7:break;
			default:printf("Invalid input\n");
	 	}
	}while(c!=6);
}
