#include<stdio.h>
#include<stdlib.h>
struct node
{
    int coeff,exp;
    struct node *link;
}*head=NULL,*ptr=NULL,*poly=NULL,*polydiff=NULL,*new,*ptr1=NULL,*ptr2=NULL;
struct node* readpoly()
{
    ptr=NULL;
    int t,i,c,e;
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d",&t);
    printf("Enter the coeff and exp of each term in desc order\n");
    for(i=1;i<=t;i++)
    {
        new=(struct node*)malloc(sizeof(struct node));
        printf("coeff(%d)= ",i);
        scanf("%d",&c);
        printf("exp(%d)= ",i);
        scanf("%d",&e);
        new->coeff=c;
        new->exp=e;
        new->link=NULL;
        if(ptr==NULL)
        {
            ptr=new;
            ptr1=ptr;
        }
        else
        {
            ptr->link=new;
            ptr=ptr->link;
        }
    }
    return ptr1;
}
struct node* diff()
{
    ptr=poly;
    ptr1=ptr;
    while(ptr!=NULL)
    {
        ptr->coeff=(ptr->coeff)*(ptr->exp);
        ptr->exp=(ptr->exp)-1;
        if(((ptr->link)!=NULL)&&(((ptr->link)->exp-1)!=-1))
            ptr=ptr->link;
        else
        {
            ptr->link=NULL;
            break;
        }
    }
    return ptr1;
}
void display(struct node* ptr)
{
    if(ptr==NULL)
    {
        printf("No polynomial entered\n");
    }
    else
    {
        while(ptr->link!=NULL)
        {
            if((ptr->coeff!=0)&&(ptr->exp!=-1))
            {
                if(ptr->exp!=0)
                    printf("%d(x)^%d+ ",ptr->coeff,ptr->exp);
                else
                    printf("%d+ ",ptr->coeff,ptr->exp);
            }
            ptr=ptr->link;
        }
        if(ptr->exp!=-1)
        {
            if(ptr->exp!=0)
                printf("%d(x)^%d\n",ptr->coeff,ptr->exp);
            else
                printf("%d\n",ptr->coeff,ptr->exp);
        }
    }
}
void main()
{
    int ch;
    poly=readpoly();
    display(poly);
    polydiff=diff();
    display(polydiff);
}