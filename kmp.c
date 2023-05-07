#include<stdio.h>
#include<string.h>
char s[100],s1[100];
int m ,n ,pi[100],j=0,i=0;
void prefix()
{
  int l=0,i;
  pi[0] = 0;
  i = 1;
  while(i<m)
  {
   if(s1[i] == s1[l])
   {
   l++;
   pi[i] = l;
   i++;
   }
   else
   {
   if(l != 0 )
     l = pi[l-1];
   else
   {
     pi[i] = 0;
     i++;
   }
   }
  }
}
void kmp()
{
  int j=0,i=0;
  m = strlen(s1);
  n = strlen(s);
  prefix();
  while(i<n)
  {
  if(s1[j] == s[i])
  {
    j++;
    i++;
  }

  if(j==m)
  {
    printf("Found substring at index %d \n", i-j);
    j = pi[j-1];
  }
  else if(s1[j]!=s[i])
  {
    if(j!=0)
   j = pi[j-1];
    else
   i = i+1;
  }
  }
}

int main()
{
 printf("\n enter string: ");
 gets(s);
 printf("\n enter substring: ");
 gets(s1);
 kmp();
 return 0;
}
