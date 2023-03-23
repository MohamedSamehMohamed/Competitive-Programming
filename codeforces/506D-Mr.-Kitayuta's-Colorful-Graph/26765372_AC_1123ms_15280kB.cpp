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
const int N = 2e5+9;
int n, m, q;
int par[N];
vector<int> adj[N];
map<pair<int,int>,int> dp;
int pre[N];
int get_par(int u)
{
  return par[u] == u? u: par[u] = get_par(par[u]);
}
void uni(int u, int v)
{
  u = get_par(u);
  v = get_par(v);
  if (u == v)return;
  par[u] = v;
}
bool same(int u, int v)
{
  return get_par(u) == get_par(v);
}
void solve(int u, int v)
{
  if (u > v)swap(u, v);
  if (dp.find({u, v}) != dp.end())
  {
    printf("%d\n", dp[{u, v}]);
    return;
  }
  int &ret = dp[{u, v}];
  if (SZ(adj[u]) > SZ(adj[v]))swap(u, v);
  int idx = -1;
  for (int i: adj[u])
  {
    idx++;
    auto it = lower_bound(all(adj[v]), i);
    if (it != adj[v].end() && (adj[v][it - adj[v].begin()] == i))
    {
      if (same(pre[u] + idx, pre[v] + (it - adj[v].begin())))
        ret++;
    }
  }
  printf("%d\n", ret);
}
int main()
{
  for (int i = 0; i < N; i++)par[i] = i;
  scanf("%d%d", &n, &m);
  vector<array<int,3>> dumy;
  for (int i = 0; i < m; i++)
  {
    int u, v, c;
    scanf("%d%d%d", &u, &v, &c);
    u--;v--;
    dumy.pb({u, v, c});
    adj[u].pb(c);
    adj[v].pb(c);
  }
  for(int i = 0; i < n; i++) {
    sort(all(adj[i]));
    adj[i].erase(unique(adj[i].begin(),adj[i].end()),adj[i].end());
    pre[i+1] = pre[i] + SZ(adj[i]);
  }
  for (int i = 0; i < m; i++)
  {
    int u = dumy[i][0];
    int v = dumy[i][1];
    int c = dumy[i][2];
    u = pre[u] + (lower_bound(all(adj[u]), c) - adj[u].begin());
    v = pre[v] + (lower_bound(all(adj[v]), c) - adj[v].begin());
    uni(u, v);
  }
  scanf("%d", &q);
  while(q--)
  {
    int u, v;
    scanf("%d%d", &u, &v);
    solve(--u, --v);
  }
}
