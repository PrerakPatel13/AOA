#include<stdio.h>
#include<time.h>
int partition(int a[],int left,int right)
{
    int pivot,temp,flag=0;
    pivot=left;
    while(flag!=1)
    {
        while(a[pivot]<=a[right] && right!=pivot)
        right--;
        if(pivot==right)
        flag=1;
        else if(a[pivot]>a[right])
        {
            temp=a[pivot];
            a[pivot]=a[right];
            a[right]=temp;
            pivot=right;
        }
        if(flag!=1)
        {
            while(a[pivot]>=a[left] && left!=pivot)
            left++;
            if(pivot==left)
            flag=1;
            else if(a[pivot]<a[left])
            {
                temp=a[pivot];
                a[pivot]=a[left];
                a[left]=temp;
                pivot=left;
            }
        }
    }
    return pivot;
}
void quicksort(int n[],int left,int right)
{
    int piv;
    if(left<right)
    {
    piv=partition(n,left,right);
    quicksort(n,left,piv-1);
    quicksort(n,piv+1,right);
    }
}
void main()
{
    int a[150000],i,j,n;
    double ta,td,tr;
    clock_t t;
    printf("enter no. of elements ");
    scanf("%d",&n);
    //asc sort
    for(i=0;i<n;i++)
    a[i]=i;
    t=clock();
    quicksort(a,0,n-1);
    t=clock()-t;
    ta=(double)t;
    printf("Ascending sort %f\n",ta);
    //desc sort
    for(i=0,j=n;i<n;i++,j--)
    a[i]=j;
    t=clock();
    quicksort(a,0,n-1);
    t=clock()-t;
    td=(double)t;
    printf("descending sort %f\n",td);
    //random
    for(i=0;i<n;i++)
    a[i]=rand();
    t=clock();
    quicksort(a,0,n-1);
    t=clock()-t;
    tr=(double)t;
    printf("random %f\n",tr);
}