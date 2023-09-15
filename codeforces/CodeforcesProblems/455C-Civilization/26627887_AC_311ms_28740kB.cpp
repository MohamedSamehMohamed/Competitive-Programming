// Author : Mohamed Sameh
#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define FAST ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
typedef long long ll ;
using namespace std ;
const int N = 3e5+9;
int par[N], rnk[N];
int get_par(int u)
{
  return u == par[u]? u : par[u] = get_par(par[u]);
}
void uni(int u, int v)
{
  u = get_par(u);
  v = get_par(v);
  if (u == v)return;
  par[u] = v;
  int merge = (rnk[u]+1)/2 + (rnk[v]+1)/2 + 1;
  rnk[v] = max({rnk[v], rnk[u], merge});
}
vector<int> adj[N];
int mx_d, node;
bool seen[N];
void dfs(int u, int dp, int p)
{
  if (dp > mx_d)
  {
    mx_d = dp;
    node = u;
  }
  for (int i: adj[u])
    if (i != p)
      dfs(i, dp + 1, u);
}
int n, m, q;
int get_diameter(int u)
{
  node = -1;
  mx_d = 0;
  dfs(u, 0, u);
  if (node == -1)return 0;
  dfs(node, 0, node);
  return mx_d;
}
int main()
{
  FAST
  cin >> n >> m >> q;
  for (int i = 0; i < n; i++)par[i] = i;
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    u--;v--;
    uni(u, v);
    adj[u].pb(v);
    adj[v].pb(u);
  }
  for (int i = 0; i < n; i++)rnk[i] = 0;
  for (int i = 0; i < n; i++)
  {
    int P = get_par(i);
    if (!seen[P])
    {
      rnk[P] = get_diameter(i);
      seen[P] = 1;
    }
  }
  while(q--)
  {
    int ty, u, v;
    cin >> ty >> u;u--;
    if (ty == 2)
    {
      cin >> v;v--;
      uni(u, v);
    }else
    cout << rnk[get_par(u)] <<"\n";
  }

}
