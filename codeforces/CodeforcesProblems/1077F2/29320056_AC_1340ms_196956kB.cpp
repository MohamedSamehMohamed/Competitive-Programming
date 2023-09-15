// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
const int N = 5e3 + 9, Lg = 13;
int a[N], Log[N], n, x, k;
long long dp[N][N],  spt[N][Lg], inf = 1e14;
long long range(int l, int r)
{
  int sz = Log[r-l+1];
  return max(spt[l][sz], spt[r-(1<<sz)+1][sz]);
}
void buildSparse(int l)
{
  for (int i = 0; i < n; i++)
    spt[i][0] = dp[i][l];
  for (int j = 1; j < Lg; j++)
    for (int i = 0; i + (1<<j) <= n; i++)
      spt[i][j] = max(spt[i][j-1], spt[i+(1<<(j-1))][j-1]);
}
int main()
{
  for (int i = 2; i < N; i++)Log[i] = Log[i>>1] + 1;
  scanf("%d%d%d", &n, &k, &x);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      dp[i][j] = -inf;
  for (int i = 0; i < k; i++)
    dp[i][1] = a[i];
  for (int j = 1; j <= x; j++)
  {
    buildSparse(j-1);
    for (int i = 1; i < n; i++)
      dp[i][j] = max(dp[i][j], range(max(0,i-k), i-1) + a[i]);
  }
  long long ans = -1;
  for (int i = n-k; i < n; i++)
    ans = max(ans, dp[i][x]);
  printf("%lld\n", ans);
}
