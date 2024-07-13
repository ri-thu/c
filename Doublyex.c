#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data1;
    struct node *llink1;
    struct node *rlink1;
    int data2;
    struct node *llink2;
    struct node *rlink2;
}*HEADER1=NULL,*HEADER2=NULL,*new,*ptr,*temp,*ptr2,*ptr3;
void inser1()
{
    int item;
    printf("Enter the element to enter\n");
    scanf("%d",&item);
    new=(struct node*)malloc(sizeof(struct node));
    if(new==NULL)
    {
        printf("INSERTION NOT POSSIBLE\n");
    }
    else
    {
        new->data1=item;
        new->llink1=NULL;
        new->rlink1=NULL;
        if(HEADER1==NULL)
        {
            HEADER1=new;
        }
        else
        {
            ptr=HEADER1;
            while(ptr->rlink1!=NULL)
            {
                ptr=ptr->rlink1;
            }
            ptr->rlink1=new;
            new->llink1=ptr;
        }
    }
}
void display1()
{
    //int count1=0;
    ptr=HEADER1;
    while(ptr->rlink1!=NULL)
    {
        //count1++;
        printf("%d\t",ptr->data1);
        ptr=ptr->rlink1;
    }
    //count1++;
    printf("%d\t",ptr->data1);
    //printf("The total number of linked list is %d",count1);
}
void inser2()
{
    int item;
    printf("Enter the element to enter\n");
    scanf("%d",&item);
    new=(struct node*)malloc(sizeof(struct node));
    if(new==NULL)
    {
        printf("INSERTION NOT POSSIBLE\n");
    }
    else
    {
        new->data2=item;
        new->llink2=NULL;
        new->rlink2=NULL;
        if(HEADER2==NULL)
        {
            HEADER2=new;
        }
        else
        {
            ptr=HEADER2;
            while(ptr->rlink2!=NULL)
            {
                ptr=ptr->rlink2;
            }
            ptr->rlink2=new;
            new->llink2=ptr;
        }
    }
}
void display2()
{
    //int count2=0;
    ptr=HEADER2;
    while(ptr->rlink2!=NULL)
    {
        //count2++;
        printf("%d\t",ptr->data2);
        ptr=ptr->rlink2;
    }
    //count2++;
    printf("%d\t",ptr->data2);
    //printf("The total sum of items in sec linked list is %d",count2);
}
void totalsum()
{
    printf("aaaa");
    ptr=HEADER1;
    int count1=0,count3=0;
    while(ptr->rlink1!=NULL)
    {
        count1++;
        ptr=ptr->rlink1;
    }
    count1++;
    printf("The total num in dl1 is %d\n",count1);
    ptr=HEADER2;
    int count2=0;
    while(ptr->rlink2!=NULL)
    {
        count2++;
        ptr=ptr->rlink2;
    }
    count2++;
    printf("The total num in dl1 is %d\n",count2);
    count3=count1+count2;
    printf("The total num in both linked list is %d\n",count3);
}
void evenin()
{
    ptr=HEADER1;
    int x,y,flag=0;
    while(ptr->rlink1!=NULL)
    {
        if(ptr->data1%2==0)
        {
            flag=1;
            x=ptr->data1;
            deleted1(x);
            break;
        }
        ptr=ptr->rlink1;
    }
    if(flag==0)
    {
        if(ptr->data1%2==0)
        {
            x=ptr->data1;
            deleted1(x);
        }
    }
    else
    {
        printf("No even integer in dl1\n");
    }
    ptr=HEADER2;
    flag=0;
    while(ptr->rlink2!=NULL)
    {
        if(ptr->data2%2==0)
        {
            flag=1;
            y=ptr->data2;
            deleted2(y);
            break;
        }
        ptr=ptr->rlink2;
    }
    if(flag==0)
    {
        if(ptr->data2%2==0)
        {
            y=ptr->data2;
            deleted2(y);
        }
    }
    else
    {
        printf("No even integer in dl2\n");
    }
}
void deleted1(int item)
{
    ptr=HEADER1;
    while(ptr->data1!=item)
    {
        ptr=ptr->rlink1;
    }
    if(ptr->llink1==NULL)
    {
        HEADER1=HEADER1->rlink1;
        HEADER1->llink1=NULL;
    }
    else if(ptr->rlink1==NULL)
    {
        temp=ptr->llink1;
        temp->rlink1=NULL;
    }
    else
    {
        ptr2=ptr->llink1;
        ptr3=ptr->rlink1;
        ptr2->rlink1=ptr3;
        ptr3->llink1=ptr2;
    }
}
void deleted2(int item)
{
    ptr=HEADER2;
    while(ptr->data2!=item)
    {
        ptr=ptr->rlink2;
    }
    if(ptr->llink2==NULL)
    {
        HEADER2=HEADER2->rlink2;
        HEADER2->llink2=NULL;
    }
    else if(ptr->rlink2==NULL)
    {
        temp=ptr->llink2;
        temp->rlink2=NULL;
    }
    else
    {
        ptr2=ptr->llink2;
        ptr3=ptr->rlink2;
        ptr2->rlink2=ptr3;
        ptr3->llink2=ptr2;
    }
}
void merge()
{
    ptr=HEADER1;
    while(ptr->rlink1!=NULL)
    {
        ptr=ptr->rlink1;
    }
    ptr->rlink1=HEADER2;
    HEADER2->llink2=ptr;
    //free(HEADER2);
    ptr=HEADER1;
    while(ptr->rlink1!=NULL)
    {
        printf("%d\t",ptr->data1);
        ptr=ptr->rlink1;
    }
    printf("%d\t",ptr->data1);
}
void main()
{
    int ch;
    do
    {
        printf("\n1.insertion in first doubly\n2.insertion in second doubly\n3.display in first doubly\n4.display in second doubly\n5.total sum of items in linkedlist\n6.Delete even integer from both list\n7.Merge two linked list\n8.exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:inser1();
            break;
            case 2:inser2();
            break;
            case 3:printf("Doubly linked list 1:\n");
                display1();
                break;
            case 4:printf("Doubly linked list 2:\n");
                display2();
            break;
            case 5:totalsum();
            break;
            case 6:evenin();
            break;
            case 7:merge();
            break;
            case 8:printf("EXITED\n");
            break;
            default:printf("INVALID CHOICE\n");
            break;
        }
    } while (ch!=8);
    
}