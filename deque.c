#include<stdio.h>
#define max 15
int queue[max],front=-1,rear=-1;
void enqueuerear(int item);
void pushDQ(int item);
void dequeuefront();
void eject();
void display();
void main()
{
    int op,item;
    do
    {
        printf("1.Enqueuerear\t2.PushDQ\t3.Dequeuefront\t4.eject\t5.Display\t6.exit\nEnter the choice\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:printf("Enter the element\n");
                    scanf("%d",&item);
                    enqueuerear(item);
                    break;
            case 2:printf("Enter the element\n");
                    scanf("%d",&item);
                    pushDQ(item);
                    break;
            case 3:dequeuefront();
                    break;
            case 4:eject();
                    break;
            case 5:display();
                    break;
            case 6:break;
            default:printf("Invalid choice\n");
                    break;
            
        }
    }while(op!=6);
}
void enqueuerear(int item)
{
    if(front==(rear+1)%max)
    {
        printf("Queue is full");
    }
    else
    {
        if(front==-1)
        {
            front=0;
            rear=0;
            queue[rear]=item;
        }
        else
        {
            rear=(rear+1)%max;
            queue[rear]=item;
        }
    }
}
void dequeuefront()
{
    int del;
    if(front==-1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        del=queue[front];
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
        {
            front=(front+1)%max;
        }
    }
}
void pushDQ(int item)
{
    int temp;
    if(front==-1)
    {
        front=0;
        rear=0;
        queue[front]=item;
    }
    else
    {
        if(front==0)
        {
            temp=max-1;
        }
        else
        {
            temp=front-1;
        }
        if(temp==rear)
        {
            printf("Queue is full\n");
        }
        else
        {
            front=temp;
            queue[front]=item;
        }
    }
 }
void eject()
{
    int del;
    if(front==-1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        del=queue[rear];
        if(rear==front)
        {
            front=-1;
            rear=-1;
        }
        else
        {
            if(rear==0)
            {
                rear=max-1;
            }
            else
            {
                rear=rear-1;
            }
        }
    }
}
void display()
{
    int i;
    if(front==-1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        for(i=front;i!=rear;i=(i+1)%max)
        {
            printf("%d\t",queue[i]);
        }
        printf("%d\n",queue[i]);
    }
}