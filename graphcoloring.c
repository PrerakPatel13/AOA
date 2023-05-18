#include<stdio.h>
#define v 5
int g[v][v] ={
        {0, 0, 1, 0, 1},
        {0, 0, 1, 1, 1},
        {1, 1, 0, 1, 0},
        {0, 1, 1, 0, 1},
        {1, 1, 0, 1, 0}
    };
int color[v] = {0};
int issafe()
{
    for(int i=0;i<v;i++)
    {
        for(int j=i+1;j<v;j++)
        {
            if(g[i][j] ==1 && color[i] == color[j])
                return 0;
        }
    }
    return 1;
}

int gcolor(int m, int i)
{
    if(i == v)
    {
        if(issafe() == 1)
        {
            for(int j=0;j<v;j++)
            {
                printf("vertex %d : %d \n",j,color[j]);
            }
            return 1;
        }
        return 0;
    }
    
    for(int j=1;j<=m;j++)
    {
        color[i] = j;
        if(gcolor(m,i+1)==1)
            return 1;
        color[i] =0;
    }
    return 0;
}

void main()
{
    gcolor(3,0);
}