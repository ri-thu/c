#include<stdio.h>
#include<stdlib.h>
struct poly
{
    int exp,coeff;
    struct poly *link;
}*head=NULL,*new,*ptr,*poly1=NULL,*poy2=NULL,*poly3=NULL,*p1,*p2,*p3,*poly2=NULL;
struct poly *readpoly()
{
    head=NULL;
    int i,j,t,c,e;
    printf("Enter the number of terms : ");
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        printf("coefficient (%d) :",i+1);
        scanf("%d",&c);
        printf("exponent(%d) :",i+1);
        scanf("%d",&e);
        new=(struct poly*)malloc(sizeof(struct poly));
        new->coeff=c;
        new->exp=e;
        new->link=NULL;
        if(head==NULL)
        {
            head=new;
            ptr=head;
        }
        else
        {
            ptr->link=new;
            ptr=ptr->link;
        }

    }
    return head;
}
struct poly *mult(struct poly *p1,struct poly *p2)
{
    poly1=p1;
    poly2=p2;
    poly3=head;
    head=NULL;
    while(poly1!=NULL)
    {
        poly2=p2;
        while(poly2!=NULL)
        {
            new=(struct poly *)malloc(sizeof(struct poly));
            new->exp=poly1->exp+poly2->exp;
            new->coeff=poly1->coeff*poly2->coeff;
            new->link=NULL;
            if(head==NULL)
            {
                head=new;
                poly3=head;
            }
            else
            {
                poly3->link=new;
                poly3=poly3->link;
            }
            poly2=poly2->link;
        }
        poly1=poly1->link;
    }
    return head;

}
void display(struct poly* head)
{
    ptr=head;
    if(ptr==NULL)
    {
        printf("polynomial mult not possible\n");
    }
    else
    {
        while(ptr->link!=NULL)
        {
            printf("%dx^(%d)+",ptr->coeff,ptr->exp);
            ptr=ptr->link;
        }
        printf("%dx^(%d)\n",ptr->coeff,ptr->exp);
    }
}
void main()
{
    printf("Enter the first polynomial\n");
    p1=readpoly();
    display(p1);
    printf("\n");
    printf("Enter the second polynomial\n");
    p2=readpoly();
    display(p2);
    printf("\n");
    p3=mult(p1,p2);
    display(p3);
}