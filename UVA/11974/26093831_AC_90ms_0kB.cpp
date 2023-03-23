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
const int N = 100, M = 15, Mx = 1e9;
int n, m, Msk[N], dp[(1<<M)];
int solve(int msk = (1<<n)-1)
{
  if (!msk)return 0;
  int &ret = dp[msk];
  if (~ret) return ret;
  ret = Mx;
  for (int i = 0; i < m; i++)
  {
    ret = min (ret,1 + solve(Msk[i] ^ msk));
  }
  return ret;
}
void test()
{
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++)
  {
    Msk[i] = 0;
    for (int j = 0; j < n; j++)
    {
      int x;
      scanf("%d", &x);
      Msk[i]|=(x<<j);
    }
  }
  memset(dp, -1, sizeof dp);
  int ans = solve();
  if (ans == Mx)
  {
    printf("IMPOSSIBLE\n");
    return;
  }
  printf("%d\n", ans);
}
int main()
{
  int t;
  scanf("%d", &t);
  for (int i = 1; i <= t; i++)
  {
    printf("Case %d: ", i);
    test();
  }
}
