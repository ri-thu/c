#include<stdio.h>
#include<string.h>
struct process
{
    char pname[20];
    int at,bt;

}p[10],temp;
struct gantt
{
    char gname[20];
    int ct,tt,wt;
}g[10];
void sort(int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(p[i].at>p[i+1].at)
            {
                temp=p[i];
                p[i]=p[i+1];
                p[i+1]=temp;
            }
        }
    }
}
void main()
{
    int n,i,num=0,k=0,j;
    float avgtt=0.0,avgwt=0.0;
    printf("Enter the number of processes\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the process name\n");
        scanf("%s",&p[i].pname);
        printf("Enter the arrival time\n");
        scanf("%d",&p[i].at);
        printf("Enter the burst time\n");
        scanf("%d",&p[i].bt);
    }
    printf("PROCESS TABLE\n");
    printf("*_________________________________*\n");
    printf("Process|Arrival time|Burst time|\n");
    for(i=0;i<n;i++)
    {
        printf("|%s\t|\t%d\t|\t%d\t|\n",p[i].pname,p[i].at,p[i].bt);
    }   
    printf("*__________________________________*\n");
    sort(n);
    for(i=0,k=0,num=0;i<n;num++)
    {
        if(p[i].at>k)
        {
            strcpy(g[num].gname,"idle");
            g[num].ct=p[i].at;
            k=g[num].ct;
        }
        else
        {
            strcpy(g[num].gname,p[i].pname);
            g[num].ct=k+p[i].bt;
            k=g[num].ct;
            g[num].tt=g[num].ct-p[i].at;
            g[num].wt=g[num].tt-p[i].bt;
            i++;
        }
    }
    printf("MODIFIED PROCESS TABLE\n");
    printf("*_________________________________*\n");
    printf("Process|Completion time|Turnaround time|Waiting time\n");
    for(j=0;j<num;j++)
    {
        avgtt=avgtt+g[j].tt;
        avgwt=avgwt+g[j].wt;
        printf("|%s\t|\t%d\t|\t%d\t|\t%d\t\n",g[j].gname,g[j].ct,g[j].tt,g[j].wt);
    }   
    printf("*__________________________________*\n");
    printf("GANTT CHART\n");
    printf("________________\n|");
    for(i=0;i<num;i++)
    {
        printf("%s\t|",g[i].gname);
    }
    printf("\n");
    printf("________________\n");
    printf("0\t");
    for(i=0;i<num;i++)
    {
        printf("%d\t",g[i].ct);
    }
    printf("\n");
    avgwt=avgwt/n;
    avgtt=avgtt/n;
    printf("Average turnaround time= %f",avgtt);
    printf("Average waiting time= %f",avgwt);
}