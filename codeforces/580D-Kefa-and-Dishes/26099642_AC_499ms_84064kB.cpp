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
const int N = 19;
int n, m, k, a[N], Raise[N][N], cnt[(1<<N)];
ll dp[N][(1<<N)];
ll solve(int lst = 18, int msk = 0)
{
  if (cnt[msk] == m)return 0;
  ll &ret = dp[lst][msk];
  if (~ret)return ret;
  for (int i = 0; i < n; i++)
  {
    if ( (msk & (1<<i)) )continue;
    ret = max(ret, a[i] + Raise[lst][i] + solve(i, (msk | (1<<i))));
  }
  return ret;
}
int main()
{
  for (int i = 0; i < (1<<N); i++)
  {
    int c = 0;
    for (int j = 0; j < N; j++)
    {
      c += ( (i & (1<<j)) != 0 );
    }
    cnt[i] = c;
  }
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; i++)scanf("%d", a+i);
  for (int i = 0; i < k; i++)
  {
    int x, y, c;
    scanf("%d%d%d", &x, &y, &c);
    x--;y--;
    Raise[x][y] = c;
  }
  memset(dp, -1, sizeof dp);
  printf("%lld\n", solve());
}
