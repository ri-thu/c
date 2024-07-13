#include<stdio.h>
#include<string.h>
struct process
{
    char pname[20];
    int at,bt,rt;

}p[10],temp,temp1,temp2,temp3;
struct gantt
{
    char gname[20];
    int ct,tt,wt;
}g[10]; 
void sort(int n)
{
    int i,count,j;
    for(i=0;i<n;i++)
    {
        if(p[i].at==0)
        {
            count++;
        }
    }
    if(count==n)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n-i-1;j++)
            {
                if(p[j].bt>p[j+1].bt)
                {
                    temp=p[j];
                    p[j]=p[j+1];
                    p[j+1]=temp;
                }
            }
        }
    }
    else
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n-i-1;j++)
            {
                if(p[j].at>p[j+1].at)
                {
                    temp1=p[j];
                    p[j]=p[j+1];
                    p[j+1]=temp1;
                }
                else if((p[j].at==p[j+1].at)&&(p[j].bt>p[j+1].bt))
                {
                    temp2=p[j];
                    p[j]=p[j+1];
                    p[j+1]=temp2;
                }
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
        p[i].rt=p[i].bt;
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
     for(i=0,k=0,num=0;i<n;)
     {
        if(p[i].at<k)
        {
            strcpy(g[num].gname,"idle");
            g[num].ct=p[i].at;
            k=g[num].ct;
            num++;
        }
        else
        {
            if(p[i].rt<p[t].rt)
            {
                strcpy(g[num].gname,p[i].pname)
                g[num].ct=p[i+1].at;
                p[i].rt=p[i].rt-(p[i+1].at-p[i].at);
                k=g[num].ct;
                if(p[i].rt!=0)
                {
                    t=i;
                }
            num++;
            i++;
        }


        
     }
}