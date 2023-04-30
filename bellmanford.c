#include <stdio.h>
#define MAX 5
#define INFINITY 9999


int g[MAX][MAX] = {
    {0, 6, 0, 7, 0},
    {0, 0, 5, 8, -4},
    {0, -2, 0, 0, 0},
    {0, 0, -3, 0, 9},
    {2, 0, 7, 0, 0},
};
int checkarr(int a[], int b[], int n)
{
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == b[i])
        {
            flag++;
        }
    }
    if (flag == n)
    {
        return -1;
    }
    return 0;
}
void mindist(int d[], int par[], int u, int v)
{

    if (g[u][v] != 0 && d[v] > d[u] + g[u][v])
    {
        d[v] = d[u] + g[u][v];
        par[v] = u;
    }
    return u;
}
void main()
{
    int d1[MAX], d2[MAX],par1[MAX],par2[MAX],c=0;
    d1[0] = 0;
    d2[0] = 0;
    par1[0] = -1;
    par2[0] = -1;
    for (int i = 1; i < MAX; i++)
    {
        d1[i] = INFINITY;
        d2[i] = INFINITY;
    }
    do
    {
    for(int i=0;i<MAX;i++)
    {
        for(int j=0;j<MAX;j++)
        {
            mindist(d1,par1,i,j);
        }
    }
    printf("\n");
    if(checkarr(d1,d2,MAX)==-1)
        {break;}
    for(int k=0;k<MAX;k++)
        {
            d2[k]=d1[k];
            par2[k]=par1[k];
        }
    c++;
    }while(c <MAX);
    printf("\nVertex\tDistance from source\tParent");
for(int i=0;i<MAX;i++)
{
   printf("\n%d\t\t%d\t\t%d",i,d1[i],par1[i]);
}
}

