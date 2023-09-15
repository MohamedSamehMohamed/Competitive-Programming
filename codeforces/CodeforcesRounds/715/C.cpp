#include<bits/stdc++.h>
using namespace std;
const int N = 2001;
int n, a[N];
long long dp[N][N];
long long solve(int l = 0, int r = n-1)
{
  if (l >= r)return 0;
  long long &ret = dp[l][r];
  if (~ret)return ret;
  return ret = a[r] - a[l] + min(solve(l+1, r), solve(l, r-1));
}
int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  sort(a, a+n);
  memset(dp, -1, sizeof dp);
  printf("%lld\n", solve());
}
