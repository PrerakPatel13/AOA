#include<stdio.h>
void main()
{
    int a[100],i,j,n,pos,min,temp;
    printf("enter no. of elements ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("enter a no. ");
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        min=a[i];
        pos=i;
        for(j=i;j<n;j++)
        {
            if(a[j]<min)
            {
            min=a[j];
            pos=j;
            }
        }
        temp=a[i];
        a[i]=a[pos];
        a[pos]=temp;
    }
     printf("\nSorted Array\n");
    for(i=0;i<n;i++)
    printf("%d",a[i]);
}