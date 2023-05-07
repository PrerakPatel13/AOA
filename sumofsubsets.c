#include <stdio.h>
void printSolution(int x[], int w[], int n)
{
for (int i=0; i<n; i++)
printf("%d \t", x[i]);
printf("\n"); 
printf("[ ");
for (int i=0; i<n; i++)
if (x[i] == 1)
printf("%d ", w[i]);
printf("]"); 
printf("\n"); 
}
void sumOfSubset(int w[], int x[], int s, int k, int r, int m, int n)
{
static int count = 0;
x[k] = 1; 
if (s + w[k] == m)
{
count++;
printf("\nSolution %d\n",count);
for (int ct=k+1; ct<n; ct++)
x[ct] = 0;
printSolution(x, w, n);
}
else if (s + w[k] + w[k+1] <= m)
sumOfSubset(w, x, s + w[k] , k+1, r - w[k], m, n);
if ((s + r - w[k] >= m) && (s + w[k+1] <= m)) 
{
x[k] = 0;
sumOfSubset(w, x, s, k+1, r - w[k], m, n); 
}
}
int main() {
int i, k=0, sum=0, rem=0, n, m;
int w[20], x[20];
printf("Enter the number of weights : ");
scanf("%d",&n);
for (i=0; i<n; i++)
{
printf("Enter weight %d : ",i+1);
scanf("%d",&w[i]);
}
for (i=0; i<n; i++)
{
rem += w[i];
x[i] = 0;
} 
printf("\nEnter the sum needed : ");
scanf("%d",&m);
sumOfSubset(w, x, sum, k, rem, m, n); 
return 0;
}