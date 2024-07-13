

#include <stdio.h>
#define max 40
struct Term 
{
    int coeff;
    int expo;
}p1[10],p2[10],p3[max];
void main()
{
    int t1, t2, i, j, k = 0;
    printf("Enter the number of terms in 1st polynomial: ");
    scanf("%d",&t1);
    printf("Enter the exponential and coeff values of each term in descending order\n");
    for(i=0;i<t1;i++)
    {
        printf("coeff(%d): ",i+1);
        scanf("%d", &p1[i].coeff);
        printf("expo(%d): ",i+1);
        scanf("%d", &p1[i].expo);
    }
    printf("The entered 1st polynomial is: ");
    for (i=0;i<t1-1;i++)
    {
        printf("%d(x^%d) + ",p1[i].coeff,p1[i].expo);
    }
    printf("%d(x^%d)\n",p1[i].coeff,p1[i].expo);
    printf("Enter the number of terms in 2nd polynomial: ");
    scanf("%d", &t2);
    printf("Enter the exponential and coeff values of each term in descending order\n");
    for (i=0;i<t2;i++)
    {
        printf("coeff(%d): ",i+1);
        scanf("%d", &p2[i].coeff);
        printf("expo(%d): ",i+1);
        scanf("%d", &p2[i].expo);
    }
    printf("The entered 2nd polynomial is: ");
    for (i=0;i<t2-1;i++)
    {
        printf("%d(x^%d) + ",p2[i].coeff,p2[i].expo);
    }
    printf("%d(x^%d)\n",p2[i].coeff,p2[i].expo);
    for(i=0;i<max;i++)
    {
        p3[i].coeff = 0;
        p3[i].expo = 0;
    }
    for(i=0;i<t1;i++)
    {
        for(j=0;j<t2;j++)
        {
            k = p1[i].expo + p2[j].expo;
            p3[k].coeff += p1[i].coeff * p2[j].coeff;
            p3[k].expo = k;
        }
    }
     int max_power = 0;
    for (i = 0; i < max; i++) 
    {
        if (p3[i].coeff != 0) 
        {
            max_power = p3[i].expo;
        }
    }
    printf("Result of polynomial multiplication: ");
    for (i=0;i<max_power;i++)
    {
        if(p3[i].coeff!=0)
        {
            if (i != 0)
            {
                printf(" + ");
            }
            printf("%d(x^%d)", p3[i].coeff, p3[i].expo);
        }
    }
    printf("\n");
}
    


