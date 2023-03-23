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
int n;
string x, y = "0123456789";
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
ll dp[20][5][2];
ll solve(int idx = 0, int cnt = 0, bool f1 = 0)
{
  if (cnt > 3)return 0;
  if (idx == n)return 1;
  ll &ret = dp[idx][cnt][f1];
  if (~ret)return ret;
  ret = 0;
  int mx = f1? 9: x[idx]-'0';
  for (int i = 0; i <= mx; i++)
  {
    ret = (ret+ solve(idx+1, cnt + (i != 0), (f1 | (i < mx))));
  }
  return ret;
}
int main ()
{
    int t;
    cin >> t ;
    while (t--)
    {
      ll l, r;
      memset(dp, -1, sizeof dp);
      cin >> l >> r;
      convert(r);
      ll ans = solve();
      convert(l-1);
      memset(dp, -1, sizeof dp);
      ans -= solve();
      cout << ans <<"\n";
    }
    return 0;
}
