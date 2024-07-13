#include<stdio.h>
#define max 20
void mergesort(int low,int high);
void merge(int low,int mid,int high);
int b[max],a[max];
void main()
{
    int l,h,i,n;
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
    mergesort(l,h);
    printf("Sorted array is:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
}

void mergesort(int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergesort(low,mid);
        mergesort(mid+1,high);
        merge(low,mid,high);
    }
}
void merge(int low,int mid,int high)
{
    int k,j,i;
    k=low;
    i=low;
    j=mid+1;
    while(i<=mid&&j<=high)
    {
        if(a[i]<a[j])
        {
            b[k]=a[i];
            i++;
            k++;

        }
        else
        {
            b[k]=a[j];
            j++;
            k++;

        }
    }
    while(i<=mid)
    {
        b[k]=a[i];
        i++;
        k++;

    }
    while(j<=high)
    {
        b[k]=a[j];
        j++;
        k++;

    }
    for(i=low;i<=high;i++)
    {
        a[i]=b[i];
    }

}