#include<bits/stdc++.h>
using namespace std;
long long m;
int k;
long long dp[65][65][2];
long long solve(long long msk, int i = 63, int b = 0, bool flag = 0)
{
  if (i < 0)
    return b == k;
  long long &ret = dp[i][b][flag];
  if (~ret)return ret;
  bool st = ((msk & (1LL<<i))? 1: 0);
  ret = solve(msk, i-1, b, flag | st);
  if (flag || st) ret += solve(msk, i-1, b+1, flag);
  return ret;
}
long long solveHelper(long long n)
{
  memset(dp, -1, sizeof dp);
  return solve(n);
}
long long count(long long n)
{
  return solveHelper(n * 2) - solveHelper(n);
}
int main()
{
  cin >> m >> k;
  long long l = 1, r = 1e18, ans = -1;
  while(l <= r)
  {
    long long mid = (l+r) >> 1LL;
    long long c = count(mid);
    if (c == m)
    {
      ans = mid;
      break;
    }
    if (count(mid) < m)
      l = mid + 1;
    else
      r = mid - 1;
  }
  printf("%lld\n", ans);
}
