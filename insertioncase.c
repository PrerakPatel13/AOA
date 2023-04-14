#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
    int a[50000],b[50000],c[50000],n,i,j,temp,min,key;
    float s,e,t,s1,e1,t1,s2,e2,t2;
    printf("Enter n: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        a[i]=i;
    }
    s=clock();
    for(i=0;i<n;i++)
    {
        j=i-1;
        key=a[i];
        while(key<a[j]&&j>=0)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
    e=clock();
    t=((float)(e-s));
    printf("BEST CASE:%f\n",t);
    
    for(i=0;i<n;i++)
    {
        b[i]=rand();
    }
    s1=clock();
    for(i=0;i<n;i++)
    {
        j=i-1;
        key=b[i];
        while(key<b[j]&&j>=0)
        {
            b[j+1]=b[j];
            j--;
        }
        b[j+1]=key;
    }
    e1=clock();
    t1=((float)(e1-s1));
    printf("AVERAGE CASE:%f\n",t1);

    for(i=0;i<n;i++)
    {
        c[i]=n-i;
    }
    s2=clock();
    for(i=0;i<n;i++)
    {
        j=i-1;
        key=c[i];
        while(key<c[j]&&j>=0)
        {
            c[j+1]=c[j];
            j--;
        }
        c[j+1]=key;
    }
    e2=clock();
    t2=((float)(e2-s2));
    printf("WORST CASE:%f\n",t2);
    
}
