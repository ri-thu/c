#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct resource
{
    char pname[20];
    int allocation[10],max[10],need[10],flag,seq;
}r;

void main()
{
    int i,j,k,p,b,n,r,g,cnt=0,id,newr,avail[10],o,u;
    printf("enter the number of processes\n");
    scanf("%d",&p);
    printf("enter the number of resources\n");
    scanf("%d",&r);
    for(i=0;i<p;i++)
    {
        printf("enter the p name\n");
        scanf("%s",r[i].pname);
        printf("enter the p allocation\n");
        for(u=0;u<r;u++)
        {
        scanf("%d",&r[i].allocation[u]);
        }
        printf("enter the p maximum \n");
        for(u=0;u<r;u++)
        {
        scanf("%d",&r[i].max[u]);
        }
        r[i].flag=0;

    }

    printf("enter the available\n");
    for(u=0;u<r;u++)
    {
    scanf("%d",&avail[u]);
    }
    printf("enter new request\n");
     for(u=0;u<r;u++)
    {
    scanf("%d",&newr[u]);
    }
    printf("enter the process id\n");
    scanf("%d",&id);
    i=0;
    while(i!=id)
    {
        i++;
    }
    for(u=0;u<r;u++)
    {
    r[i].allocation[u]= r[i].allocation[u]+newr[u];
    }
    for(u=0;u<r;u++)
    {
    avail[u]=avail[u]-newr[u];
    }
    for(i=0;i<n;i++)
    {
        for(u=0;u<r;u++)
        {
        r[i].need[u]=r[i].max[u]-r[i].allocation[u];
        }
    }
    cnt=0;
    fl=0;
    while(cnt>n)
    {
        g=0;
        for(j=0;j<n;j++)
        {
            if(r[j].flag==0)
            {
                b=0;
                for(p=0;p<=r;p++)
                {
                    if(avail[p]>=r[j].need[p])
                    {
                        b++;
                    }
                    else
                    {
                        b--;
                    }
                }
            }
            if(b==r)
            {

                seq[o]=j;
                o++;
                r[j].flag=1;
                for(u=0;u<r;u++)
                {
                avail[u]=avail[u]+r[j].allocation[u];
                }
                cnt++;
                g=1;
            }
        }
    }
    if(g==0)
    {
        printf("not safe\n")
    }
    else 
    {
         printf("process name\t allocation\t max\t need\n");
        for(i=0;i<n;i++)
        {
           
            printf("%s\t%d\t%d\t%d\n",r[i].pname,r[i].allocation,r[i].max,r[i].need);



        }
         for(i=0;i<n;i++)
        {   

           printf("%d\t",seq[i]);
        }
    }
}