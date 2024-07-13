#include<stdio.h>
void main()
{
    int r_string[30],in_frame[30],f,n,v=0,i,j,flag=0,hit=0,miss=0;
    printf("Enter the number of reference string\n");
    scanf("%d",&n);
    printf("Enter the reference strings\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&r_string[i]);
    }
    printf("Enter the number of frames\n");
    scanf("%d",&f);
    for(i=0;i<f;i++)
    {
        in_frame[i]=-1;
    }
    for(i=0;i<n;i++)
    {
        flag=0;
        for(j=0;j<f;j++)
        {
            if(r_string[i]==in_frame[j])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            miss++;
            in_frame[v]=r_string[i];
            v=(v+1)%f;
            printf("Current frame: ");
        for(j=0;j<f;j++)
        {
            if(in_frame[j]==-1)
            {
                printf(" ");
            }
            else
            {
            printf("%d\t",in_frame[j]);
            }
        }
        printf("\n");
        }
        else
        {
            hit++;
        }
        
    }
    printf("The number of page faults: %d\n",miss);
}