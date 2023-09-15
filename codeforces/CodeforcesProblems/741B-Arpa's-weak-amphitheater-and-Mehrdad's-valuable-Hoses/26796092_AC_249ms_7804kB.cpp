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
const int N = 1001;
int n, m, w, par[N], W[N], B[N], dp[N][N];
vector<int> v[N];
void init()
{
  memset(dp, -1, sizeof dp);
  iota(par, par + N, 0);
}
int get_par(int u)
{
  return u == par[u]? u: get_par(par[u]);
}
void uni(int u, int v)
{
  u = get_par(u);
  v = get_par(v);
  if (u == v)return;
  par[u] = v;
}
int solve(int idx = 0, int rem = w)
{
  if (rem < 0)return -1e9;
  if (idx == n)return 0;
  int &ret = dp[idx][rem];
  if (~ret)return ret;
  ret = solve(idx+1, rem);
  int cb, cw;
  cb = cw = 0;
  for (int i : v[idx])
  {
    ret = max(ret, B[i] + solve(idx+1, rem - W[i]));
    cb += B[i];
    cw += W[i];
  }
  ret = max(ret, cb + solve(idx+1, rem - cw));
  return ret;
}
int main()
{
  init();
  cin >> n >> m >> w;
  for (int i = 0; i < n; i++) cin >> W[i];
  for (int i = 0; i < n; i++) cin >> B[i];
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    u--;v--;
    uni(u, v);
  }
  m = 0;
  for (int i = 0; i < n; i++)
  {
    int p = get_par(i);
    v[p].pb(i);
    m = max(p+1, m);
  }
  n = m;
  cout << solve() << '\n';
}
