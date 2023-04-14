#include <stdio.h>
#define MAX 10
#define infinity 999
    void dijkstra(int g[MAX][MAX],int n, int s)
    {
        int i,j,c[MAX][MAX],d[MAX],v[MAX],min,ct,p[MAX],next;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
            if(g[i][j]==0)
            c[i][j]=infinity;
            else
            c[i][j]=g[i][j];
            }
        }
              
        for(i=0;i<n;i++)
        {
            d[i]=c[s][i];
            p[i]=s;
            v[i]=0;
        }
        d[s]=0;
        v[s]=1;
        ct=1;
        
        while(ct<n-1)
        {
        min=infinity;
        for (i=0;i<n;i++)
        {
        if (d[i]<min && v[i]==0) 
        {
        min = d[i];
        next = i;
        }
        }
        v[next]=1;
    
        for(i=0;i<n;i++)
        {
            if(v[i]==0)
            {
            if(d[i]>(min+c[next][i]))
            {
                d[i]=min+c[next][i];
                p[i]=next;
            }
            }
        }
        ct++;
        }
        for (i=0;i<n;i++)
        {
        if (i!=s) 
        {
            printf("\nDistance from source to %d: %d", i, d[i]);
        }
        }
    }
    int main() 
    {
        int s=0,n=9;
    int g[MAX][MAX]={{0,11,0,0,0,0,0,8,0},
                    {11,0,8,0,0,0,0,11,0},
                    {0,8,0,7,0,4,0,0,2},
                    {0,0,7,0,9,14,0,0,0},
                    {0,0,0,9,0,10,0,0,0},
                    {0,0,4,14,10,0,2,0,0},
                    {0,0,0,0,0,2,0,1,6},
                    {8,11,0,0,0,0,1,0,7},
                    {0,0,2,0,0,0,6,7,0}};
     dijkstra(g,n,s);
    return 0;
}