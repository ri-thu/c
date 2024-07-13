#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *prev,*next;
}*head,*new,*ptr,*temp;
void insbeg(int item)
{
	new=(struct node*)malloc(sizeof(struct node));
	new->data=item;
	new->prev=NULL;
	new->next=NULL;
	if(head==NULL)
	{
		head=new;
	}
	else
	{
		new->next=head;
		head->prev=new;
		head=new;
	}
}
void display()
{
	printf("The queue is\n");
	if(head==NULL)
		printf("Empty Queue,Deletion not possible\n");
	else{
	ptr=head;
	while(ptr->next!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
	printf("%d\n",ptr->data);
	}
}
void main()
{	
	int op=0,ch,item,elmnt;
	do{
	printf("Enter your choice\n");
	printf("1.Insert element\n2.search element\n3.Display\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: printf("Enter the item to be inserted\n");
			scanf("%d",&item);
			insbeg(item);
			break;
	 	case 2: printf("Enter the element to be searched\n");
	 		scanf("%d",&elmnt);
	 		ptr=head;
	 		while(ptr->next!=NULL)
	 		{	  
	 		   	ptr=ptr->next;
	 		    	if(ptr->data==elmnt)
				{	
					temp=ptr;
					ptr->prev->next=temp->next;
					insbeg(temp->data);
					free(temp);
				 }
				  
	 		  }
	 		  break; 		  
	 	case 3: display();
	 		    break;
	}
}while(op==0);
}
