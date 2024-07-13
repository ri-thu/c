#include<stdio.h>
void first()
{
    
}
void main()
{
    int 
    printf("Enter the number of partitions\n");
    scanf("%d",&num_partitions);
    printf("Enter the partitions\n");
    for(i=0;i<num_partitions;i++)
    {
        scanf("%d",&partitions[i]);
    }
    printf("Enter the number of requests\n");
    printf("%d",&r);
    printf("Enter the requests\n");
    for(i=0;i<r;i++)
    {
        scanf("%d",&request[i]);
    }
    do
    {
        printf("1.First fit\t2.Best fir\t3.Worst fit\t4.Exit\nEnter the choice\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1: first();
                    break;
            case 2: best();
                    break;
            case 3: worst();
                    break;
            case 4:break;
        }
        printf("Do you want to continue?\n");
        scanf("%c",&ch);
    } while (ch=='Y'||ch=='y');

    
}