// Author : Mohamed Sameh
#include <bits/stdc++.h>
typedef long long ll ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
using namespace std ;
const int N = 16;
const ll MN = -1e9*N;
int n;
int a[N][N];
ll dp[(1<<N)];
ll value[(1<<N)];
int arr[N];
ll solve(int msk = (1<<n)-1)
{
  if (!msk)return 0;
  ll &ret = dp[msk];
  if (~ret)return ret;
  ret = MN;
  for (int cur_msk = msk; cur_msk; cur_msk=(cur_msk-1)&msk)
  {
    ret = max(ret, value[cur_msk] + solve(msk^cur_msk));
  }
  return ret;
}
ll get_cost(int sz)
{
  ll ret = 0;
  for (int i = 0; i < sz; i++)
    for (int j = i+1; j < sz; j++)
      ret += a[arr[i]][arr[j]];
  return ret;
}
int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      scanf("%d", a[i]+ j);
  memset(dp, -1, sizeof dp);
  for (int i = 0; i < (1<<n); i++)
  {
    int idx = 0;
    for (int j = 0; j < n; j++)
    {
      if (i & (1<<j))arr[idx++] = j;
    }
    value[i] = get_cost(idx);
  }
  printf("%lld\n", solve());
}
