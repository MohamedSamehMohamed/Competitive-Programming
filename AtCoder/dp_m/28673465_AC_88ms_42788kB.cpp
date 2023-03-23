// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
const int N = 101, M = 1e5+1, mod = 1e9+7;
int n, k, a[N], dp[N][M];
int main()
{
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  for (int i = 0; i <= k; i++)
    dp[0][i] = (i <= a[0]? 1: 0);
  for (int i = 1; i < n; i++)
    for (int j = 0; j <= k; j++)
    {
      if (j == 0)
        dp[i][j] = dp[i-1][j];
      else
        dp[i][j] = (1LL*dp[i][j-1] + dp[i-1][j] - (j - a[i] - 1 >= 0? dp[i-1][j-a[i]-1]:0) + mod) % mod;
    }
  printf("%d\n", dp[n-1][k]);
}
