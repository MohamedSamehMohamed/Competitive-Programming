#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9, Lg = 19;
int a[N], spt[N][Lg][2], Log[N], n, s, lim;
int dp[N];
int diff(int l, int r)
{
  int sz = Log[r-l+1];
  int mn = min( spt[l][sz][0], spt[r-(1<<sz)+1][sz][0] );
  int mx = max( spt[l][sz][1], spt[r-(1<<sz)+1][sz][1] );
  return mx - mn;
}
void build()
{
  for (int i = 2; i < N; i++)
    Log[i] = Log[i>>1] + 1;
  for (int i = 0; i < n; i++)
    spt[i][0][0] = spt[i][0][1] = a[i];
  for (int j = 1; j < Lg; j++)
    for (int i = 0; i + (1<<j) <= n; i++)
      {
        spt[i][j][0] = min(spt[i][j-1][0], spt[i+(1<<(j-1))][j-1][0]);
        spt[i][j][1] = max(spt[i][j-1][1], spt[i+(1<<(j-1))][j-1][1]);
      }
}
int solve(int i = 0)
{
  if (i == n)return 0;
  if (n - i < lim)return 2 * N;
  int &ret = dp[i];
  if (~ret)return ret;
  ret = 2 * N;
  int l = i + lim - 1, r = n-1, m, idx = -1;
  while(l <= r)
  {
    m = (l+r) >> 1;
    int cur = diff(i, m);
    if (cur <= s)
      idx = m, l = m + 1;
    else
      r = m-1;
  }
  if (idx - i + 1 < lim)
    return ret = 2 * N;
  int rm = n - idx - 1;
  if (rm < lim && rm)
  {
    int need = lim - rm;
    if ( (idx-i+1) - need < lim)
      return ret = 2 * N;
    idx -= need;
  }
  int mnIdx = i + lim - 1, mxIdx = idx;

  while(ret > n && mnIdx <= mxIdx)
  {
    ret = min(ret, 1 + solve(mxIdx + 1));
    mxIdx--; 
  }
  return ret;
}
int main()
{
  scanf("%d%d%d", &n, &s, &lim);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  build();
  memset(dp, -1, sizeof dp);
  int ans = solve();
  if (ans > n)ans = -1;
  printf("%d\n", ans);
}
