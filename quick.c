#include<stdio.h>
#define max 20
void quicksort(int low,int high);
void swap(int *a,int *b);
int a[max];
void main()
{
    int n,i,l,h;
     printf("Read the number of elements in the arrays\n");
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
     l=0;
    h=n-1;
    quicksort(l,h);
    printf("Sorted array is:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
}





void quicksort(int low,int high)
{
    int pivot,i,j,temp;
    if(low<high)
    {
        pivot=a[low];
        i=low;
        j=high;
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
 void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b; 
    *b=temp;
}
