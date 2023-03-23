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
using namespace std;
const int N = 1e5+9;
ll ans[N];
int color[N];
vector<int> adj[N];
int n;
int par[N];
int get_par(int u)
{
  return u == par[u]? u : par[u] = get_par(par[u]);
}
ll mX[N];
map<pair<int,int>,ll> mp, dp;
set<int> seg[N];
set<pair<int,int>> st;
void merge(int p, int u)
{
  p = get_par(p);
  u = get_par(u);
  bool sw = 0;
  if (SZ(seg[u]) > SZ(seg[p]))
  {
    sw = 1;
    swap(u, p);
  }
  for (int i: seg[u])
  {
    mp[{p, i}] += mp[{u, i}];
    seg[p].insert(i);
    mX[p] = max(mX[p], mp[{p, i}]);
    dp[{p, mp[{p, i}]}] += i;
  }
  if (sw)
  {
    par[u] = p;
  }
}
void solve(int u)
{
  int p = get_par(u);
  ans[u] = dp[{p, mX[p]}];
}
void dfs(int u = 0, int p = 0)
{
  seg[u].insert(color[u]);
  mp[{u, color[u]}]++;
  mX[u] = max(mX[u], mp[{u, color[u]}]);
  dp[ {u , mp[{u, color[u]}]} ] += color[u];
  for (int i: adj[u])
  {
    if (i != p)
    {
      dfs(i, u);
      merge(u, i);
    }
  }
  solve(u);
}
int main()
{
  iota(par, par + N, 0);
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> color[i];
  }
  for (int i = 1; i < n; i++)
  {
    int u, v;
    cin >> u >> v;
    u--;v--;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  dfs();
  for (int i = 0; i < n; i++)
    cout << ans[i] << ' ';
  cout << '\n';
}
