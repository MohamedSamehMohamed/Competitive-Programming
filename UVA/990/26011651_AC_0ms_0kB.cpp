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
const int N = 40, M = 1009;
ll dp[N][M];
vector<pair<int, int>> ori, v, ans;
int n;
ll solve(int i , int rm)
{
  if (rm < 0)return -1e9;
  if (i == n || rm == 0)return 0;
  ll &ret = dp[i][rm];
  if (~ret)return ret;
  return ret = max(solve(i+1, rm), v[i].f + solve(i+1, rm - v[i].s));
}
void build (int i , int rm)
{
  if (rm < 0 || i == n || rm == 0)return ;
  ll ret = dp[i][rm];
  ll p1 = solve(i+1, rm);
  ll p2 = v[i].f + solve(i+1, rm - v[i].s);
  if (ret == p1)
  {
    build(i+1, rm);
  }else
  {
    ans.pb(ori[i]);
    build(i+1, rm - v[i].s);
  }
}
int main()
{
    int t, w;
    bool ok = 0;
    while (cin >> t >> w)
    {
      if (ok)
      cout <<"\n";
      ok = 1;
      v.clear();
      ans.clear();
      ori.clear();
      memset(dp, -1, sizeof dp);
      cin >> n;
      for (int i = 0; i < n; i++)
      {
        int d, vi;
        cin >> d >> vi;
        ori.pb({d, vi});
        d = 3 * w * d;
        v.pb({vi, d});
      }
      cout << solve(0, t) << "\n";
      build(0, t);
      cout << SZ(ans) << "\n";
      for (auto i : ans)
        cout << i.f <<" " << i.s <<"\n";
    }
}
