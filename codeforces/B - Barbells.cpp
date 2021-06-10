// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
const int N = 15;
int n, m;
int a[N], b[N];
set<long long> W;
int msk;
long long need;
map<pair<int,long long>,int> dp;
int can(int idx = 0, long long cur = 0)
{
  if (idx == m)
    return (cur == need? 1: 0);
  if (!(msk&(1<<idx)))return can(idx+1, cur);
  //if (dp.find({idx, cur}) != dp.end())return dp[{idx, cur}];
  int ret = max(can(idx+1, cur),can(idx+1, cur + b[idx]));
  dp[{idx, cur}] = ret;
  return ret;
}
void solve()
{
  for (int i = 1; i < (1<<m); i++)
  {
    long long sum = 0;
    for (int j = 0; j < m; j++)
    {
      if ( i & (1<<j) )
      {
        sum += b[j];
      }
    }
    if (sum % 2)continue;
  //  dp.clear();
    msk = i;
    need = sum/2;
    if (can())
      W.insert(sum);
  }
}
int main()
{
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  for (int i = 0; i < m; i++)
    scanf("%d", b+i);
  solve();
  set<long long> ans;
  for (int i = 0; i < n; i++)
  {
    ans.insert(a[i]);
    for (long long j: W)
      ans.insert(a[i] + j);
  }
  for (long long i: ans)
    printf("%d\n", i);
}
