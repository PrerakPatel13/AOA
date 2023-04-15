#include<stdio.h>
void insertion(int a[], int n)
{
int j;
for(int i =1;i<n;i++)
{
int temp = a[i];
j=i-1;
while(a[j]> temp && j>=0)
{
a[j+1]=a[j];
j--;
}
a[j+1]= temp;
}
}
int small(int a[],int p, int n)
{
int small = a[p],pos=p;
for(int i = p+1 ;i<n;i++)
{
if(a[i]<small)
{
small=a[i];
pos=i;
}
}
return pos;
}
void select(int a[],int n)
{
int pos,temp;
for(int i=0;i<n;i++)
{
pos = small(a,i,n);
temp = a[i];
a[i] = a[pos];
a[pos] = temp;
}
}
void main()
{
int arr[100],n,i,c=0;
printf("Enter size : ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("\nEnter : ");
scanf("%d",&arr[i]);
}
while (c<3)
{
printf("Enter choice : ");
scanf("%d",&c);
switch (c)
{
case 1 : {
select(arr,n);
printf("selection sort : ");
for(i=0;i<n;i++)
{printf("%d\t",arr[i]);}
break;
}
case 2 : {
insertion(arr,n);
printf("insertion sort : ");
for(i=0;i<n;i++)
{printf("%d\t",arr[i]);}
break;
}
default:
break;
}
}
}