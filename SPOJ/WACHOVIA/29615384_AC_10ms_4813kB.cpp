// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 50, MW = 1e3+9; 
int n, wight;
int W[N], V[N]; 
int dp[N][MW]; 
void test()
{
 scanf("%d%d", &wight, &n);
 for (int i = 0; i < n; i++)
  scanf("%d%d", W+i, V+i);
 for (int i = 0; i < MW; i++)
  dp[0][i] = (i < W[0]? 0: V[0]); 
 for (int i = 1; i < n; i++)
  for (int j = 0; j < MW; j++)
  {
   dp[i][j] = dp[i-1][j]; 
   if (j >= W[i])
    dp[i][j] = max(dp[i][j], V[i] + dp[i-1][j-W[i]]); 
  }
 printf("Hey stupid robber, you can get %d.\n", dp[n-1][wight]); 
}
int main()
{
 int t; 
 scanf("%d", &t);
 while(t--)
  test(); 
}
