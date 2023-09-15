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
const int N = 201;
const ll MX = -1e18;
ll dp[N][N];
int n, x, k;
int a[N];
ll solve(int i = 0, int rm = x)
{
  if (rm == 0)return (n - i >= k ? MX : 0);
  if (i >= n)return MX;
  ll &ret = dp[i][rm];
  if (~ret)return ret;
  ret = a[i] + solve(i+1, rm-1);
  int sk = 1;
  while (sk < k && i + sk < n)
  {
    ret = max(ret, a[i+sk] + solve(i+sk+1, rm-1));
    sk++;
  }
  return ret;
}
int main()
{
  scanf("%d%d%d", &n, &k, &x);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  memset(dp, -1, sizeof dp);
  ll ans = solve();
  if (ans < 0)ans = -1;
  printf("%lld\n", ans);
}
