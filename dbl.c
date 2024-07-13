#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*llink;
    struct node*rlink;
};
struct node *new,*header=NULL;
int item;
void insertf();
void display();
void main()
{
    int op,y;
    do
    {
        printf("Entyer the fun 1.insertf 2.diplsay \n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:insertf();
                break;
            case 2: display();
                break;
        }
        printf("do you want to cntnu 1.yes 2. no \n");
        scanf("%d",&y)
    }while(y==1);
}
void insertf()
{
    new=(struct node*)malloc(sizeof(struct node*));
    printf("Enter the elemt to be inserted \n");
    scanf("%d",&item);
    if(new==NULL)
    {
        printf("insertion not poss \n");
    }
    else
    {
        new->data=item;
        new->rlink=NULL;
        new->llink=NULL;
        if(header==NULL)
        {
            
            header=new;
        }
        else
        {
            new->rlink=header;


        }
    }
}    