#include <stdio.h>
#define MAX 5
#define infinity 999
    void prim(int g[MAX][MAX],int n, int s)
    {
        int i,j,c[MAX][MAX],d[MAX],v[MAX],min,ct,p[MAX],next;
        int prim[MAX][MAX]={0},total=0;
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
        for (i=1;i<n;i++)
        {
         printf("%d - %d \t%d \n",p[i],i,g[i][p[i]]);
	    total+=g[i][p[i]];
	    prim[i][p[i]]=1;
	    prim[p[i]][i]=1;
        }
        printf("Total Cost=%d\n",total);
	    printf("Spanning Matrix\n");
	for(int i=0;i<n;i++)
	{
	    for(int j=0;j<n;j++)
	    printf("%d\t",prim[i][j]);
	    printf("\n");
	}
    }
    int main() 
    {
        int s=0,n=5;
    int g[MAX][MAX]= {{ 0, 2, 0, 6, 0 },
						{ 2, 0, 3, 8, 5 },
						{ 0, 3, 0, 0, 7 },
						{ 6, 8, 0, 0, 9 },
						{ 0, 5, 7, 9, 0 } };
     prim(g,n,s);
    return 0;
}