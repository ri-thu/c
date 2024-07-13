/* GRAPH REPRESENTATION */
#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int vertex;
    struct node* link;
};
struct node* GPTR[20];
struct node* ptr = NULL;
int n, i, j, m, v, ch, top = -1, dfs[20], bfs[20], s[20], q[20], df, bf;
int front = -1, rear = -1;
void DFS(int);
void BFS(int);
void push(int m);
int pop();
void enqueue(int it);
int dequeue();
int search(int m[], int size, int o);
int main() {
    printf("Enter the number of vertices: ");
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        GPTR[i] = NULL;
    }
    for (i=1;i<=n;i++) 
    {
        printf("Enter the number of ADJACENT vertices for vertex %d: ", i);
        scanf("%d", &m);
        ptr = GPTR[i];
        for (j=1;j<=m;j++) {
            printf("Enter the vertex: ");
            scanf("%d", &v);
            struct node* p=(struct node*)malloc(sizeof(struct node));
            p->vertex=v;
            p->link=NULL;
            if(ptr==NULL) 
            {
                GPTR[i]=p;
                ptr=p;
            } else 
            {
                ptr->link=p;
                ptr=p;
            }
        }
    }
    do {
        printf("\n1: DFS\n2: BFS\n");
        printf("Enter the choice: ");
        scanf("%d",&ch);

        switch (ch) 
        {
        case 1:
            printf("Enter the vertex from which traversal is to begin: ");
            scanf("%d",&df);
            DFS(df);
            break;
        case 2:
            printf("Enter the vertex from which traversal is to begin: ");
            scanf("%d",&bf);
            BFS(bf);
            break;
        default:
            printf("Invalid input\n");
        }
    } while(ch>=1 && ch<=2);
    return 0;
}
void DFS(int v)
 {
    int u=v,j=0;
    push(u);
    while(top!=-1)
     {
        u=pop();
        if(search(dfs,j,u)==0)
         {
            dfs[j]=u;
            j++;
            ptr=GPTR[u];
            while(ptr!=NULL) 
            {
                push(ptr->vertex);
                ptr=ptr->link;
            }
        }
    }
   for(i=0;i<n;i++)
        {
         if(dfs[i]!=0)
         {
         printf("%d \t",dfs[i]);
         }
        }
}
void BFS(int v) 
{
    int u=v,j=0;
    enqueue(u);
    while(front!=-1)
     {
        u=dequeue();
        if(search(bfs,j,u)==0) 
        {
            bfs[j]=u;
            j++;
            ptr=GPTR[u];
            while(ptr!= NULL)
             {
                enqueue(ptr->vertex);
                ptr=ptr->link;
            }
        }
    }
   for(i=0;i<n;i++)
        {
         if(bfs[i]!=0)
         {
         printf("%d \t",bfs[i]);
        }
}}

void push(int m) 
{
    top++;
    s[top]=m;
}

int pop() 
{
    int h;
    h=s[top];
    top--;
    return h;
}

int dequeue() 
{
    int it;
    if(front==rear) 
    {
      it=q[front];
      front=-1;
      rear=-1;
    } 
    else
    {
      it=q[front];
      front++;
    }

 return it;
}

void enqueue(int it) 
{
    if (front == -1 && rear == -1) 
    {
     rear++;
     q[rear] = it;
     front++;
    } 
    else 
    {
     rear++;
     q[rear] = it;
    }
}

int search(int m[],int size,int o) 
{
    int k;
    for (k=0;k<size;k++)
     {
        if (m[k]==o)
         {
          return 1;
        }
    }
 return 0;
}



