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
string x, y = "0123456789";
int n;
void convert(ll num)
{
  if (num == 0)
  {
    n = 1;
    x = "0";
    return;
  }
  x = "";
  n = 0;
  while (num)
  {
    x += y[num%10];
    num/=10;
  }
  reverse(all(x));
  n = SZ(x);
}
ll dp[30][10][4][2];
ll solve(int i = 0, int lst = 0, int cnt = 0, int fl = 0)
{
  if (cnt > 3)return 0;
  if (i == n) return 1;
  ll &ret = dp[i][lst][cnt][fl];
  if (~ret)return ret;
  int mx = (fl ? 9 : x[i]- '0');
  ret = 0;
  for (int d = 0; d <= mx; d++)
  {
    ret += solve(i+1, d, cnt + (d != 0), (fl | (d < mx)) );
  }
  return ret;
}
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    ll l, r;
    cin >> l >> r;
    l--;
    convert(r);
    memset(dp, -1, sizeof dp);
    ll ans = solve();
    convert(l);
    memset(dp, -1, sizeof dp);
    ans -= solve();
    cout << ans <<"\n";
  }
}
