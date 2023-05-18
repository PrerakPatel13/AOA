#include<stdio.h>
#include<string.h>
#include<math.h>
int checkFrame(char t[100],char p[100],int s,int e)
{
    int flag=1,i,j;
    for(i=s,j=0;i<=e;i++,j++)
    {
        if(t[i]!=p[j])
        flag=0;
    }
    return flag;
}
void main()
{
    char txt[] = "abcbcdabc";
    char pat[] = "abc";
    int pathash=0,i,j,k,txthash=0,flag=0;
    for(i=0;i<strlen(pat);i++)
    {
        pathash+=pat[i]*pow(10,strlen(pat)-i-1);
        txthash+=txt[i]*pow(10,strlen(pat)-i-1);
    }
    if(txthash==pathash)
    {
        printf("String Matched at index 0\n");
        flag=1;
    }
    for(i=strlen(pat);i<strlen(txt);i++)
    {
        txthash=(txthash-((txt[i-strlen(pat)])*pow(10,strlen(pat)-1)))*10+txt[i];
        if(txthash==pathash)
        {
            if(checkFrame(txt,pat,i-strlen(pat)+1,i))
            {
                flag=1;
                printf("String Matched at index %d\n",i-strlen(pat)+1);
            }
        }
    }
    if(flag==0)
    printf("String not matched");
}