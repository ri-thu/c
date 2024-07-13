#include<stdio.h>
void main()
{
    int n,a[15],i,loc,temp,j,min;
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
    }
    printf("The sorted array is:\n");
    for(i=0;i<n;i++)
    {
     printf("%d\t",a[i]);
    }
    printf("\n");
}  