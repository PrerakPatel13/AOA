#include <stdio.h>
#include <stdlib.h>

int place(int box[],int k,int j)
{
    for(int i=0;i<k;i++)
    {
        if(box[i]==j || (abs(box[i]-j)==abs(i-k)))
        {
            // printf("%d",j);
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
                    printf("queen placed at %d\n",box[a]);
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
    int box[100];
    // int n=4;
    Nqueens(box,0,4);
    return 0;
}