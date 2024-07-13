#include<stdio.h>
int a[10],b[10];
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b; 
    *b=temp;
}
void quicksort(int low,int high)
{
    int pivot,i,j;
    if(low<high)
    {
        pivot=a[low],i=low,j=high;
    
        while(i<j)
        {
            while(a[i]<pivot)
            {
                i++;
            }
            while(a[j]>pivot)
            {
                j--;
            }
            if(i<j)
            {
                swap(&a[i],&a[j]);
            }
        }
        swap(&a[j],&pivot);
        quicksort(low,j-1);
        quicksort(j+1,high);
    }
}
void main()
{
    int n,i;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("The entered array is\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    
    quicksort(0,n-1);
    printf("The sorted array is\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
