// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
const int N = 1e3+9, M = 200, mod = 1e9 + 9;
int n, m;
int dp[M][M][N];
int val[M];
int solve(int idx = m-1, int num = 0, int rem = 0)
{
  rem %= n;
  if (idx == -1)
    return (rem == 0? num: 0);
  int &ret = dp[idx][num][rem];
  if (~ret)return ret;
  ret = 0;
  ret = solve(idx-1, num, rem)%mod;
  ret = (ret + solve(idx-1,num+1, rem + val[idx])%mod)%mod;
  return ret;
}
int main()
{
  scanf("%d%d", &n, &m);
  memset(dp, -1, sizeof dp);
  val[0] = 1;
  for (int i = 1; i < M; i++)
  {
    val[i] = (1LL * val[i-1] * 2 )%n;
  }
  printf("%d\n", solve());
}
