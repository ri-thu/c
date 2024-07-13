#include<stdio.h>
#include<stdlib.h>
struct node* insert(struct node*head);
void count(struct node*h1,struct node*h2);
void delete(struct node*h1,struct node*h2);
void display(struct node*h1,struct node*h2);
struct node
{
    int data;
    struct node *next,*prev;
}*new,*head,*tail,*ptr,*ptr1,*temp,*pt1,*pt2;
struct node*h1=NULL;
struct node*h2=NULL;

void main()
{
    int op;
    do
    {
        printf("1.Insert into 1st DLL\t2.Insert into 2nd DLL\t3.count\t4.delete\t5.merge\t6.display\t7.Exit\nEnter the choice\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:h1=insert(h1);
                 break;
            case 2:h2=insert(h2);
                    break;
            case 3:count(h1,h2);
                    break;
            case 4:delete(h1,h2);
                    break;
            /* case 5:merge();
                    break;*/
            case 6:display(h1,h2);
                 break;
            case 7:break;
            default:printf("Invalid choice\n");
        }
    }while(op!=7);
}
struct node* insert(struct node*head)
{
    int item;
    
        printf("Enter the item to be inserted\n");
        scanf("%d",&item);
        new =(struct node*)malloc(sizeof(struct node));
        new->data=item;
        new->next=NULL;
        new->prev=NULL;
        if(head==NULL)
         {
            head=new;
            tail=new;
        }
        else
        {
            tail->next=new;
            new->prev=tail;
            tail=new;
        }
        return head;
}
void count(struct node*h1,struct node*h2)
{
    int count1=0,count2=0;
    ptr=h1;
    while(ptr!=NULL)
    {
        count1++;
        ptr=ptr->next;
    }
    printf("Number of items in first linked list: %d\n",count1);
    ptr=h2;
    while(ptr!=NULL)
    {
        count2++;
        ptr=ptr->next;
    }
    printf("Number of items in second linked lsit: %d\n",count2);
}
void delete(struct node*h1,struct node*h2)
{
    ptr1=h1;
    while(ptr1!=NULL)
    {
        if((ptr1->data)%2==0)
        {
            temp=ptr;
            break;
        }
        ptr1=ptr1->next;
    }
    if(temp->next==NULL)
    {
        (temp->prev)->next=NULL;
        tail=temp->prev;
    }
    else if(temp->prev==NULL)
    {
        ptr1->prev=NULL;
        head=ptr1;
    }
    else
    {
        (temp->prev)->next=temp->next;
        (ptr->next)->prev=temp->prev;
        free(temp);
    }
    ptr2=h2;
    while(ptr2!=NULL)
    {
        if((ptr2->data)%2==0)
        {
            temp=ptr2;
            break;
        }
        ptr2=ptr2->next;
    }
    if(temp->next==NULL)
    {
        (temp->prev)->next=NULL;
        tail=temp->prev;
    }
    else if(temp->prev==NULL)
    {
        ptr2->prev=NULL;
        head=ptr2;
    }
    else
    {
        (temp->prev)->next=temp->next;
        (ptr->next)->prev=temp->prev;
        free(temp);
    }

}
void display(struct node*h1,struct node*h2)
{
    printf("First Linked list:\n");
    ptr=h1;
    while(ptr!=NULL)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
    printf("Second linked list: /n");
     ptr=h2;
    while(ptr!=NULL)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");

}




void delete(struct node** head) {
    struct node* ptr = *head;
    struct node* temp = NULL;

    while (ptr != NULL) {
        if ((ptr->data) % 2 == 0) {
            temp = ptr;
            break;
        }
        ptr = ptr->next;
    }

    if (temp != NULL) {
        if (temp->prev == NULL) {
            *head = temp->next;
            if (temp->next != NULL)
                temp->next->prev = NULL;
        } else if (temp->next == NULL) {
            temp->prev->next = NULL;
        } else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        free(temp);
    }
}
