#include<stdio.h>
void main()
{
    int a[100],n,s,high,mid,low,i,flag=-1;
    printf("Enter no.of numbers ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter no. ");
        scanf("%d",&a[i]);
    }
    printf("Enter search element ");
    scanf("%d",&s);
    low=0;
    high=n-1;
    while(low<=high)
    {
        mid=(high+low)/2;
        if(s==a[mid])
        {
            flag=mid;
            break;
        }
        else if(s<a[mid])
        {
            high=mid-1;
        }
        else
        low=mid+1;
    }
    if(flag==-1)
    printf("element not found");
    else
    printf("element found at pos %d ",flag+1);
}