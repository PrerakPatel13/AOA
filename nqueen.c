#include <stdio.h>
#include <stdlib.h>

int place(int box[],int k,int j)
{
    for(int i=0;i<k;i++)
    {
        if(box[i]==j || (abs(box[i]-j)==abs(i-k)))
        {
            return 1;
        }
    }
    return 0;
}

void Nqueens(int box[],int k,int n)
{
    for(int i=0;i<n;i++)
    {
        if(place(box,k,i)==0)
        {
            box[k]=i;
            if(k==n-1)
            {
                for(int a=0;a<n;a++)
                {
                    printf("Queen %d placed in %d column\n",a,box[a]);
                    printf("\n"); 
                }
            }
            else
            {
                Nqueens(box,k+1,n);
            }
            printf("\n");
        }
    }
}


int main()
{
    int box[100],n;
    printf("enter the number of queens in board:");
    scanf("%d",&n);
    Nqueens(box,0,n);
    return 0;
}