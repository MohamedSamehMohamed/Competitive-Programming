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
const int N = 150+9, M = 15009, Mod = 1e9 + 7;
int a[N], b[N], n, m, k, w;
ll dp1[N][M], dp2[N][M];
ll solve1(int i = 0, int rm = 0)
{
  if (rm < 0)return 0;
  if (i == n || rm == 0)return rm == 0;
  ll &ret = dp1[i][rm];
  if (~ret)return ret;
  ret = solve1(i+1, rm)%Mod + solve1(i+1, rm - a[i])%Mod;
  return ret % Mod;
}
ll solve2(int i = 0, int rm = 0)
{
  if (rm < 0)return 0;
  if (i == m || rm == 0)return rm == 0;
  ll &ret = dp2[i][rm];
  if (~ret)return ret;
  ret = solve2(i+1, rm)%Mod + solve2(i+1, rm - b[i])%Mod;
  return ret % Mod;
}
void test()
{
  cin >> n >> m >> k >> w;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < m; i++)
    cin >> b[i];
  memset(dp1, -1, sizeof dp1);
  memset(dp2, -1, sizeof dp2);
  ll ans = 0;
  for (int i = 0; i <= w; i++)
  {
    int c1, c2;
    c1 = i;
    c2 = w - i;
    if ( abs(c1 - c2) > k )continue;
    ans = (ans + solve1(0, c1) * solve2(0, c2))%Mod;
  }
  cout << ans <<"\n";
}
int main()
{
  int t;
  cin >> t;
  while (t--)test();
}
