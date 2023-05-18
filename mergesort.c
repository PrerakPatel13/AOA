#include<stdio.h>
#include<time.h>
#define MAX 150000
void merge(int a[],int beg,int mid,int end)
{
    int i,j,k,temp[MAX],index;
    i=beg;
    j=mid+1;
    index=beg;
    while(i<=mid && j<=end)
    {
        if(a[i]<a[j])
        {
            temp[index]=a[i];
            i++;
        }
        else
        {
            temp[index]=a[j];
            j++;
        }
        index++;
    }
    if(i>mid)
    {
        while(j<=end)
        {
            temp[index]=a[j];
            j++;
            index++;
        }
    }
    else
    {
        while(i<=mid)
        {
            temp[index]=a[i];
            i++;
            index++;
        }
    }
    for(k=beg;k<index;k++)
    a[k]=temp[k];
}
void mergesort(int a[],int beg,int end)
{
    int mid;
    if(beg<end)
    {
        mid=(beg+end)/2;
        mergesort(a,beg,mid);
        mergesort(a,mid+1,end);
        merge(a,beg,mid,end);
    }
}
void main()
{
    int i,a[MAX],n,j;
    double ta,td,tr;
    clock_t t;
    printf("Enter number of terms ");
    scanf("%d",&n);
    //asc sort
    for(i=0;i<n;i++)
    a[i]=i;
    t=clock();
    mergesort(a,0,n-1);
    t=clock()-t;
    ta=(double)t;
    printf("asc sort %f\n",ta);
    //desc sort
    for(i=0,j=n;i<n;i++,j--)
    a[i]=j;
    t=clock();
    mergesort(a,0,n-1);
    t=clock()-t;
    td=(double)t;
    printf("desc sort %f\n",td);
    //random
    for(i=0;i<n;i++)
    a[i]=rand();
    t=clock();
    mergesort(a,0,n-1);
    t=clock()-t;
    tr=(double)t;
    printf("random %f\n",tr);
}