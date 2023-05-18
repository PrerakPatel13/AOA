#include<stdio.h>
void main()
{
    float p[100],w[100],pw[100],kn[100],tp=0,tw,max=0;
    int i,j,n,v[100],maxInd;
    printf("Enter no. of elements ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter profit and wt of element%d ",i+1);
        scanf("%f %f",&p[i],&w[i]);
        pw[i]=p[i]/w[i];
        v[i]=0;
    }
    printf("Enter total weight ");
    scanf("%f",&tw);
    while(tw!=0)
    {
        max=0;
        for(j=0;j<n;j++)
        {
            if(v[j]==0 && pw[j]>max)
            {
                max=pw[j];
                maxInd=j;
            }
        }
        v[maxInd]=1;
        if(w[maxInd]<=tw)
        {
            tw-=w[maxInd];
            kn[maxInd]=1;
        }
        else
        {
            kn[maxInd]=tw/w[maxInd];
            tw=0;
        }
        tp+=kn[maxInd]*p[maxInd];
    }
    printf("\nprofit\t\tweight\t\tp/w\t\t\tknapsack\n");
    for(i=0;i<n;i++)
    printf("%f\t%f\t%f\t%f\n",p[i],w[i],pw[i],kn[i]);
    printf("max profit is %f",tp);
}