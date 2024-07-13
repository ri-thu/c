#include<stdio.h>
#include<string.h>
struct pocess
{
    char name[10];
    int at,bt,rt,status;
}p[10];
struct gantt
{
    char gname[10];
    int ct,st,tt,wt;
}g[10];
int q[50],f=-1,r=-1;
void enqueue(int item)
{
    if(f==-1)
    {
        f=0;
    q[++r]=item;
}
}
int dequeue()
{
    int item;
    if(f==-1&&r==-1)
    {
        return -1;
    }
    else if(f==r)
    {
        item=q[f];
        f=-1;
        r=-1;
        return item;
    }
    else
    {
        return(q[f++]);
    }
}
void main()
{
    int ls=0,n,t,i,j,idle=0,num,m,k;
    printf("Enter the number of processes\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the name of the process\n");
        scanf("%s",&p[i].name);
        printf("Enter the arrival time\n");
        scanf("%d",&p[i].at);
        printf("Enter the burst time\n");
        scanf("%d",&p[i].bt);
        p[i].rt=p[i].bt;
        p[i].status=0;
    }
    printf("Enter the time quantum\n");
    scanf("%d",&t);
    printf("________________________________\n");
    printf("|Process|Arrival time|Burst time|\n");
    for(i=0;i<n;i++)
    {
        printf("|%s\t|\t%d\t|\t%d\t|\n",p[i].name,p[i].at,p[i].bt);
    }
    printf("________________________________\n");
    i=0;
    while(ls<n)
    {
        for(j=0;j<n;j++)
        {
            if((p[j].status==0)&&(p[j].at<=i))
            {
                enqueue(j);
                p[j].status=1;
            }
        }
        if((idle==0)&&(f==-1))
        {
            strcpy(g[num].gname,"idle");
            g[num].st=i;
            idle=1;
            i++;
        }
        else if (f!=-1)
        {
            if(idle==1)
            {
                idle=0;
                g[num].ct=i;
                num++;
            }
            k=dequeue();
            strcpy(g[num].gname,p[k].name);
            if(p[k].rt<=t)
            {
                g[num].st=i;
                g[num].ct=i+p[k].rt;
                i=g[num].ct;
                g[num].tt=g[num].ct-p[k].at;
                g[num].wt=g[num].tt-p[k].bt;
                p[k].status=1;
                ls++;
                num++;
            }
            else
            {
                g[num].st=i;
                g[num].ct=i+t;
                i=i+t;
                p[k].rt=p[k].rt-t;
                num++;
                for(m=0;m<n;m++)
                {
                    if((p[m].status==0)&&(p[m].at<=i))
                    {
                        enqueue(m);
                        p[m].status=1;
                    }
                }
                enqueue(k);            
            }
        }
        else
        {
            i++;
        }
    }
    printf("_______________________________________________________\n");
    printf("|Process|Completion time|Turn around time|Waiting time|\n");
    for(i=0;i<num;i++)
    {
        printf("|%s\t|\t%d\t|\t%d\t|\t%d\t|\n",g[i].gname,g[i].ct,g[i].tt,g[i].wt);
    }
    printf("________________________________________________________\n");
    printf("GANTT CHART\n");
    printf("______________________________________\n");
    printf("|");
    for(m=0;m<num;m++)
    {
        if(strcmp(g[m].gname,g[m+1].gnam))
        {
            continue;
        }
        else
        {
            printf("%s\t",g[num].gname);
        }
    }
    printf("_______________________________________\n");
    printf("%d\t",g[0].st);
    for(m=0;m<num;m++)
    {
        if(strcmp(g[m].gname,g[m+1].gname))
        {
            continue;
        }
        else
        {
            printf("%d\t",g[m].ct);
        }
    }
}

