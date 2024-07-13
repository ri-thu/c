#include<stdio.h>
#define max 15
int queue[max],front=-1,rear=-1;
void enqueue(int item);
void dequeue();
void display();
void main()
{
    int op,item;
    do
    {
        printf("1.Enqueue\t2.Dequeue\t3.Display\t4.exit\nEnter the choice\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:printf("Enter the element\n");
                    scanf("%d",&item);
                    enqueue(item);
                    break;
            case 2:dequeue();
                    break;
            case 3:display();
                    break;
            case 4:break;
            default:printf("Invalid choice\n");
                    break;
        }
    } while (op!=4);
    
}
void enqueue(int item)
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
        }
            rear=(rear+1)%max;
            queue[rear]=item;
        }
    }

void dequeue()
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
    printf("\n");
}
}