#include<stdio.h>
#include<stdlib.h>
struct vertex
{
	char data;
	struct vertex *link;
};
struct node
{
    char data;
    struct node *link;
} *front=NULL,*rear=NULL,*top=NULL;
char visited[20];
char dfsvisited[20];
void push(char item)
{
    struct node *ptr,*new1 = (struct node *)malloc(sizeof(struct node));
    new1->data = item;
    new1->link = NULL;
 	new1->link=top;
 	top=new1;
}
char pop()
{
        char del;
        struct node *temp = top;
        del = temp->data;
        top=top->link;
        free(temp);
    return del;
}
void enqueue(char item)
{
    struct node *new1 = (struct node *)malloc(sizeof(struct node));
    new1->data = item;
    new1->link = NULL;
    if (front == NULL)
        front = new1;
    else
        rear->link = new1;
    rear = new1;
}
char dequeue()
{
        char del;
        struct node *temp = front;
        del = temp->data;
        if (front== rear)
            front =  rear = NULL;
        else
            front = front->link;
        free(temp);
    return del;
}
int search(char c,char visit[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(visit[i]==c)
			return 1;
	}
	return-1;
}
int insertbfs(char c,int i)
{
		visited[i]=c;
		return 1;
}
int insertdfs(char c,int i)
{
		dfsvisited[i]=c;
		return 1;
}
void readedges(struct vertex *p,int n)
{
	int i;
	struct vertex *adj;
	printf("Enter the adjacent vertices :\n");
	for(i=0;i<n;i++)
	{
		adj=(struct vertex*)malloc(sizeof(struct vertex));
		scanf(" %c",&adj->data);
		adj->link=NULL;
		p=p->link=adj;
	}
}
void print(struct vertex *a[],int n)
{
	struct vertex *p;
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d : %c :",i+1,a[i]->data);
		for(p=a[i]->link;p!=NULL;p=p->link)
			printf(" %c",p->data);
		printf("\n");
	}
}
int indexof(struct vertex *a[],int n,char c)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]->data==c)
			return i;
	}
	return -1;
}
void bfs(struct vertex *a[],int n)
{
	int i=0;
	struct vertex *p;
	char u=a[0]->data;
	enqueue(u);
	while(front!=NULL)
	{
		u=dequeue();
		if(search(u,visited,n)==-1)
		{
			i+=insertbfs(u,i);
			if(indexof(a,n,u)!=-1)
			{
				for(p=a[indexof(a,n,u)];p!=NULL;p=p->link)
					enqueue(p->data);
			}
		}
	}
	printf("BFS Visited :");
	for(n=0;n<i;n++)
		printf(" %c",visited[n]);
	printf("\n");
}	
void dfs(struct vertex *a[],int n)
{
	int i=0;
	struct vertex *p;
	char u=a[0]->data;
	push(u);
	while(top!=NULL)
	{
		u=pop();
		if(search(u,dfsvisited,n)==-1)
		{
			i+=insertdfs(u,i);
			if(indexof(a,n,u)!=-1)
			{
				for(p=a[indexof(a,n,u)];p!=NULL;p=p->link)
					push(p->data);
			}
		}
	}
	printf("DFS Visited :");
	for(n=0;n<i;n++)
		printf(" %c",dfsvisited[n]);
	printf("\n");
}
void main()
{
	int n,i,k;
	struct vertex *a[20];
	printf("Enter the number of vertices :");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		a[i]=(struct vertex*)malloc(sizeof(struct vertex));
		printf("Enter vertex %d:",i+1);
		scanf(" %c",&a[i]->data);
	}
	for(i=0;i<n;i++)
	{
		printf("Enter number of adjacent vertices of vertex %d:",i+1);
		scanf("%d",&k);
		readedges(a[i],k);
	}
	printf("Adjacency list :\n");
	print(a,n);
	bfs(a,n);
	dfs(a,n);
}