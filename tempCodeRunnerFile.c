#include<stdio.h>
void insertion(int a[],int n);
void selection(int a[],int n);
void bubble(int a[],int n);
void main()
{
    int n,a[20],op,i;
    char ch;
    printf("Enter the number of elements in the array\n");
    scanf("%d",&n);
    printf("Enter the elements into the array\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("The unsorted array is:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
    do
    {
        printf("1-Bubble sort\t2-Selection sort\t3-Insertion sort\nEnter the choice\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:bubble(a,n);
                    break;
            case 2:selection(a,n);
                    break;
            case 3:insertion(a,n);
                    break;
            default: printf("Invalid option\n");
                    break;
        }
        printf("do you want to continue?\n");
        __fpurge(stdin);
        scanf("%c",&ch);
    }
    while(ch=='y'||ch=='Y');
}

void selection(int a[],int n)
{
    int i,loc,temp,j,min,k;
   for(i=0;i<n-1;i++)
        {
            min=a[i];
             loc=i;
            for(j=i+1;j<n;j++)
             {
                if(a[j]<min)
              {
                     min=a[j];
                    loc=j;
                 }
            }
            if(loc!=i)
             {
             temp=a[i];
             a[i]=a[loc];
             a[loc]=temp;
            }
            printf("pass %d: ",i);
            for(j=0;j<n;j++)
    		{
     			printf("%d\t",a[j]);
    		}
    		printf("\n");
            
   		}
   		
}
void insertion(int a[],int n)
{
    int i,j,temp,k;
   for(i=0;i<n;i++)
    {
        temp=a[i];
        for(j=i-1;(j>=0&&temp<a[j]);j--)
        {
            a[j+1]=a[j];

        }
        a[j+1]=temp;
        printf("pass %d: \n",i);
        for(j=0;j<n;j++)
        {
         printf("%d\t",a[j]);
        }
         printf("\n");
	}
  }
    
   
void bubble(int a[],int n)
{
    int i,j,temp,k;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
        printf("Pass %d : ",i);
        for(k=0;k<n;k++)
       {
          printf("%d ",a[k]);
       }
          printf("\n");
       }
}