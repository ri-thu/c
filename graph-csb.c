#include<stdio.h>
# define l 3
int a[10][10],visited[10],rear=-1,front=-1,q[3],n,stack[3],top=-1;

void bfs();
void dfs();

void push(int x)
{
 if(top==l-1)
 {
          printf("stack full\n");
 }
 else
 {
          top++;
          stack[top]=x;

 }
}

void pop()
{
         top--;
}

void enqueue(int x)
{
    if(rear==(l-1))
    {
             printf("queue is full\n");

    }
    else
    {
        if(front ==-1 && rear==-1)
        {
                 front=0;
                 rear=0;
                 q[rear]=x;
        }
        else
        {
                 rear++;
                 q[rear]=x;
        }
    }
}

int  dequeue()
{ int k;
         if(front==-1 && rear==-1)
         {
                  printf("queue is empty\n");
         }
         else
         {
             k=q[front];
            if(front==rear)
            {
                 front =-1;
                 rear=-1;

            }
            else
            {
                front++;
            }
         }
         return k;
}
void main()
{
 int i,j,op;
 printf("enter the number of vertices\n");
 scanf("%d",&n);

 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
  {
  printf("enter 1 if %d is adjacent to %d ,else enter 0\n",i,j);
  scanf("%d",&a[i][j]);
  }
 }
  printf("the adjacency matrix is:\n");
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
  {
  printf("%d\t",a[i][j]);
  }
  printf("\n");
 }
 do
 {
printf("enter the option 1.bfs 2.dfs 3.exit\n");
scanf("%d",&op);
switch(op)
{
     case 1: bfs();
             break;
     case 2: dfs();
           break;
     default: break;
}

 }while(op!=3);
}

void bfs()
{
   int i,w,y,s;
  for(i=0;i<=n;i++)
  {
      visited[i]=0;

  }
  printf("enter the starting vertex\n");
  scanf("%d",&s);
  enqueue(s);
  visited[s]=1;
  printf("%d\t ",s);

  while(front!=-1 && rear!=-1)
  {
      w=dequeue();
      //printf("%d",w);
      for(i=1;i<=n;i++)
      {
          if(a[w][i]==1&& visited[i]==0)
          {
                   enqueue(i);
                   visited[i]=1;
                   printf("%d\t",i);

          }
          /*else
          {
                  printf("not all vertices are reachable\n");
          }*/
      }

  }


}
void dfs()
{
  int i,w,y,s;
  for(i=0;i<=n;i++)
  {
      visited[i]=0;

  }
  printf("enter the starting vertex\n");
  scanf("%d",&s);
  push(s);
  visited[s]=1;
  printf("%d\t ",s);

  while(top!=-1)
  {
      w=stack[top];
      //printf("%d",w);
      for(i=1;i<=n;i++)
      {
          if(a[w][i]==1&& visited[i]==0)
          {
                   push(i);
                   visited[i]=1;
                   printf("%d\t",i);
                   break;
          }
          else
          {
                   pop();
          }

      }

  }

}
