#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*next,*prev;
}*ptr,*head,*new,*tail;
void main()
{
    char str[10];
    printf("Enter a string\n");
    gets(str);
    int i=0;
    while(str[i]!='\0')
    {
        new=(struct node*)malloc(sizeof(struct node));
        new->data=str[i];
        new->prev=NULL;
        new->next=NULL;
        if(head==NULL)
        {
            head=new;
            tail=new;
        }
        else
        {
                new->prev=tail;
                tail=new;
        }
    }
    ptr=tail;
    while(ptr->prev!=NULL)
    {
        printf("%c",ptr->data);
        ptr=ptr->prev;
    }
    printf("%c\n",ptr->data);
}