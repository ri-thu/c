#include<stdio.h>
#include<string.h>
struct process
{
    char name[20];
    int at,bt;
}p[10],temp;
struct gantt
{
    char gname[20];
    int st,ct,tt,wt;
}d[10];
void main()
{
    int i,n,j,idle,k,num,sumtt=0,sumwt=0;
    float att=0.0,awt=0.0;
    printf("Enter the number of processes\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the process name\n");
        scanf("%s",&p[i].name);
        printf("Enter the arrival time\n");
        scanf("%d",&p[i].at);
        printf("Enter the burst time\n");
        scanf("%d",&p[i].bt);
    }
     printf("_______________________________________\n");
    printf("|Process|Arrival time|Burst time|\n");
    for(i=0;i<n;i++)
    {
        printf("|%s\t|\t%d\t|\t%d\t|\n",p[i].name,p[i].at,p[i].bt);
    }
    printf("__________________________________________\n");
    for(i=0;i<n;i++) //Sort according to arrival time
    {
        for(j=0;j<n-i-1;j++)
        {
            if(p[j].at>p[j+1].at)
            {
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
    idle=0;
    for(i=0,k=0,num=0;k<n;)
    {
        if(p[k].at<=i)
        {
            if(idle==1)
            {
                d[num].ct=i;
                num++;
            }
            strcpy(d[num].gname,p[k].name);
            d[num].st=i;
            d[num].ct=i+p[k].bt;
            d[num].tt=d[num].ct-p[k].at;
            d[num].wt=d[num].tt-p[k].bt;
            i=d[num].ct;
            num++;
            k++;
            idle=0;
        }
        else if(idle==0)
        {   
            strcpy(d[num].gname,"idle");
            d[num].st=i;
            i++;
            idle=1;
        }
        else
        {
            i++;
        }

    }
   
    printf("________________________________________________________________\n");
    printf("|Process|Completion time|Turn around time|Waiting time|\n");
    for(i=0;i<num;i++)
    {
        printf("|%s\t|\t%d\t|\t%d\t|\t%d\t|\n",d[i].gname,d[i].ct,d[i].tt,d[i].wt);
    }
    printf("________________________________________________________\n");
    printf("GANTT CHART\n");
    printf("_______________________________________________\n");
    for(i=0;i<num;i++)
    {
        printf("|%s",d[i].gname);
    }
    printf("|\n");
    for(i=0;i<num;i++)
    {
       printf("%d  ",d[i].st);
        sumtt=sumtt+d[i].tt;
        sumwt=sumwt+d[i].wt;
    }
    printf("%d",d[num-1].ct);
    printf("_______________________________________\n");
    att=sumtt/n;
    awt=sumwt/n;
    printf("Average turn around time=%f",att);
    printf("Average waiting time=%f",awt);
}