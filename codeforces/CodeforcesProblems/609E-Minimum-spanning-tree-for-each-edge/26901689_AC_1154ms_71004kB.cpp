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
const int N = 2e5+9, L = 30;
int n, m;
vector<array<int,4>> edges;
vector<pair<int,int>> adj[N];
int bl[N][L], par[N], h[N], dp[N][L];
bool seen[N];
ll Ans[N];
int get_par(int u)
{
  return u == par[u]? u: par[u] = get_par(par[u]);
}
bool conect(int u, int v)
{
  u = get_par(u);
  v = get_par(v);
  if (u == v)return 0;
  par[u] = v;
  return 1;
}
void dfs(int u = 0, int p = -1, int w = 0)
{
  if (~p)h[u] = h[p]+1; else h[u] = 1;
  bl[u][0] = p;
  dp[u][0]= w;
  for (auto i: adj[u])
    if (p != i.f)
      dfs(i.f, u, i.s);
}
int lca(int u, int v) {
    int ans = -1;
    if (h[u] < h[v]) swap(u, v);

    for (int i = L - 1; i >= 0; i--) {
        if (h[u] - h[v] >= (1 << i)) {
            ans = max(ans, dp[u][i]);
            u = bl[u][i];
        }
    }
    if (u == v) {
        return ans;
    }
    for (int i = L - 1; i >= 0; i--) {
        if (~bl[u][i] && ~bl[v][i] && bl[u][i] != bl[v][i]) {
            ans = max({ans, dp[u][i], dp[v][i]});
            u = bl[u][i];
            v = bl[v][i];
        }
    }
    ans = max({ans, dp[u][0], dp[v][0]});
    return ans;
}
int main()
{
  cin >> n >> m;
  for (int i = 0; i < n; i++)par[i] = i;
  for (int i = 0; i < m; i++)
  {
    int u, v, c;
    cin >> u >> v >> c;
    u--;v--;
    edges.pb({c, u, v, i});
  }
  sort(all(edges));
  ll mst_sum = 0;
  for (int i = 0; i < m; i++)
  {
    if (conect(edges[i][1], edges[i][2]))
    {
      mst_sum += edges[i][0];
      adj[edges[i][1]].pb({edges[i][2], edges[i][0]});
      adj[edges[i][2]].pb({edges[i][1], edges[i][0]});
      seen[edges[i][3]] = 1;
    }
  }
  memset(bl, -1, sizeof bl);
  dfs();
  for (int i = 1; i < L; i++) {
        for (int j = 0; j < n; ++j) {
            if (bl[j][i - 1] != -1) {
                int v = bl[j][i - 1];
                bl[j][i] = bl[v][i - 1];
                dp[j][i] = max(dp[j][i - 1], dp[v][i - 1]);
            }
        }
    }
  for (int i = 0; i < m; i++)
  {
    int idx = edges[i][3];
    if (!seen[idx])
    {
      int mx = lca(edges[i][1], edges[i][2]);
      ll cur = mst_sum + edges[i][0];
      cur -= mx;
      Ans[idx] = cur;
    }else
    Ans[idx] = mst_sum;
  }
  for (int i = 0; i < m; i++)
    cout << Ans[i] << "\n";

}