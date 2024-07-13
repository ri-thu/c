#include<stdio.h>
void swap();
void heapi(int a[],int n,int i);
void main()
{
    int a[20],i,j,n,k=0;
    printf("Enter the size :\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("The unsorted is\n");
    for(i=1;i<=n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
    for(i=n/2;i>=1;i--)
    {
        heapi(a,n,i);
    }
    for(i=n;i>=1;i--)
    {
        swap(&a[i],&a[1]);
        heapi(a,i-1,1);
        k++;
        printf("Pass no %d :",k);
        for(j=1;j<=n;j++)
        {
            printf("%d\t",a[j]);
        }
        printf("\n");
    }
    printf("The sorted array is :");
    for(i=1;i<=n;i++)
    {
        printf("%d\t",a[i]);
    }
}
void heapi(int a[],int n,int i)
{
    int large,l,r;
    large=i;
    r=(2*i)+1;
    l=2*i;
    while(l<=n&&a[l]>a[large])
    {
        large=l;
    }
    while(r<=n&&a[r]>a[large])
    {
        large=r;
    }
    if(large!=i)
    {
        swap(&a[i],&a[large]);
        heapi(a,n,large);
    }
}
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
