#include <stdio.h>
#include <string.h>
#define MAX 9999
int g[MAX][MAX], b[MAX][MAX];
void LCS(char x[], char y[])
{
    int l1 = strlen(x);
    int l2 = strlen(y);
    for(int i=1;i<l1;i++)
    {
        g[i][0]=0;
        
    }
    for(int j=0;j<=l2;j++)
    {
        g[0][j]=0;
    }

    for(int i=1;i<=l1;i++)
    {
        for(int j=1;j<=l2;j++)
        {
            if(x[i-1]==y[j-1])
            {
                g[i][j]=g[i-1][j-1]+1;
                b[i][j]=-1;
            }
            else if(g[i-1][j]>g[i][j-1])
            {
                g[i][j]=g[i-1][j];
                b[i][j]=-2;
            }
            else
            {
                g[i][j]=g[i][j-1];
                b[i][j]=-3;
            }
        }
    }
}


void print(char x[],int i,int j,int n, char a[])
{
    if(b[i][j]==-1)
    {
        a[n-1]=x[i-1];
        print(x,i-1,j-1,n-1,a);
    }
    else if(b[i][j]==-3)
    {
        print(x,i,j-1,n,a);}
    else if(b[i][j]==-2)
    {
        print(x,i-1,j,n,a);}
    else
    {
        return ;
    }
}
int main()
{
    char s1[1000], s2[1000];
    char ans[1000];
    int n;
    printf("Enter string 1 : ");
    scanf("%s",s1);
    printf("Enter string 2 : ");
    scanf("%s",s2);
    LCS(s1,s2);
    n = g[strlen(s1)][strlen(s2)];
    print(s1,strlen(s1),strlen(s2),n,ans);
    printf("lcs:");
    for(int i=0;i<n;i++)
    {
        printf("%c",ans[i]);
    }
    printf("\nmatrix\n");
    for(int i=1;i<=strlen(s1);i++)
    {
        for(int j=1;j<=strlen(s2);j++)
        {
            printf("%d ",g[i][j]);
        }
        printf("\n");
    }
    return 0;
}
