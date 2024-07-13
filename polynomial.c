#include<stdio.h>

struct poly
{
    int exp;
    int coeff;
}P1[10],P2[10],P3[10];
void main()
{
    int i,j,k,m,n1,n2;
    printf("Enter the number of terms in first polynomial\n");
    scanf("%d",&n1);
    printf("Read the polynomial\n");
    for(i=0;i<n1;i++)
    {
        scanf("%d",&P1[i].coeff);
        scanf("%d",&P1[i].exp);
    }
   
    printf("Enter the number of terms in second polynomial\n");
    scanf("%d",&n2);
    printf("Read the polynomial\n");
    for(i=0;i<n2;i++)
    {
        scanf("%d",&P2[i].coeff);
        scanf("%d",&P2[i].exp);
    }
     printf("1st polynomial\n");
    printf("coefficient:");
    for(i=0;i<n1;i++)
    {
        printf("%d\t",P1[i].coeff);
    }
    printf("\nexponent   :");
    for(i=0;i<n1;i++)
    {
        printf("%d\t",P1[i].exp);
    }
    printf("\n");
     printf("2nd polynomial\n");
    printf("coefficient:");
    for(j=0;j<n2;j++)
    {
        printf("%d\t",P2[j].coeff);
    }
    printf("\nexponent   :");
    for(j=0;j<n2;j++)
    {
        printf("%d\t",P2[j].exp);
    }
    printf("\n");
    i=0;
    j=0;
    k=0;
    while(i<n1&&j<n2)
    {
        if(P1[i].exp==P2[j].exp)
        {
            P3[k].coeff=P1[i].coeff+P2[j].coeff;
            P3[k].exp=P1[i].exp;
            i++;
            j++;
            k++;
        }
        else if(P1[i].exp>P2[j].exp)
        {
            P3[k].coeff=P1[i].coeff;
             P3[k].exp=P1[i].exp;
            i++;
            k++;
        }
        else
        {
            P3[k].coeff=P2[j].coeff;
            P3[k].exp=P2[j].exp;
        
            j++;
            k++;   
        }
    }
    while(i<n1)
    {
       P3[k].coeff=P1[i].coeff;
            i++;
            k++; 
    }
    while(j<n2)
    {
      P3[k].coeff=P2[j].coeff;
            j++;
            k++;    
    }
    printf("The sum is\n");
    printf("coefficient:");
    for(m=0;m<k;m++)
    {
        printf("%d\t",P3[m].coeff);
    }
    printf("\nexponent   :");
    for(m=0;m<k;m++)
    {
        printf("%d\t",P3[m].exp);
    }
}
