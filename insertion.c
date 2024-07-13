#include<stdio.h>
void main()
{
    int a[10],i,n,j,temp;
        printf("Enter the number of elements in the array\n");
    scanf("%d",&n);
    printf("Enter the elements into the array\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("UnSorted array:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
        temp=a[i];
        for(j=i-1;(j>=0&&temp<a[j]);j--)
        {
            a[j+1]=a[j];

        }
        a[j+1]=temp;
    }
    printf("Sorted array:\n");
        for(i=0;i<n;i++)
        {
         printf("%d\t",a[i]);
         }
         printf("\n");
}
