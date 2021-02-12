// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5, MxO = 22, MxN = 80; 
int n, m, k, inf = 1e9; 
int a[N][3], dp[N][MxO][MxN]; 
void init()
{
  for (int j = 0; j < MxO; j++)
   for (int k = 0; k < MxN; k++)
    dp[0][j][k] = (j+k==0? 0: inf); 
}
void test()
{
 scanf("%d%d%d", &n, &m, &k);
 
 for (int i = 0; i < k; i++)
  for (int j = 0; j < 3; j++)
   scanf("%d", a[i] + j);
 init(); 
 for (int i = 0; i <= a[0][0]; i++)
  for (int j = 0; j <= a[0][1]; j++)
   dp[0][i][j] = (i+j==0? 0: a[0][2]); 
  
 for (int i = 1; i < k; i++)
  for (int j = 0; j < MxO; j++)
   for (int k = 0; k < MxN; k++)
   {
    dp[i][j][k] = dp[i-1][j][k];
    
    if (a[i][0] >= j && a[i][1] >= k)
     dp[i][j][k] = min(dp[i][j][k], a[i][2]); 
    else 
     dp[i][j][k] = min(dp[i][j][k], a[i][2] + dp[i-1][max(0, j-a[i][0])][max(0, k-a[i][1])]); 
   }
 printf("%d\n", dp[k-1][n][m]); 
}
int main()
{
 int t; 
 scanf("%d", &t);
 while(t--)
  test(); 
}
