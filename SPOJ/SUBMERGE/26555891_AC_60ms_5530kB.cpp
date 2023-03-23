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
const int N = 1e4 + 9;
vector<int> adj[N];
int n, m;
int vis[N], Tin[N], Low[N], id, tim;
int ans;
void dfs(int u, int p)
{
  vis[u] = id;
  Tin[u] = Low[u] = tim++;
  bool art = 0;
  int chs = 0;
  for (int v : adj[u])
  {
    if (v == p)continue;
    if (vis[v] == id) Low[u] = min(Low[u], Tin[v]);
    else
    {
      dfs(v, u);
      Low[u] = min(Low[u], Low[v]);
      if (Low[v] >= Tin[u] && ~p) art = 1;
      chs++;
    }
  }
  if (chs > 1 && p == -1)art = 1;
  ans += art;
}
int main()
{
  while(cin >> n >> m && (n || m))
  {

    for (int i = 0; i <= n; i++)adj[i].clear();
    id++;
    tim = ans = 0;
    for (int i = 0; i < m; i++)
    {
      int u, v;
      cin >> u >> v;
      adj[u].pb(v);
      adj[v].pb(u);
    }
    for (int i = 0; i < n; i++)if (vis[i] != id)dfs(i, -1);
    cout << ans <<"\n";
  }
}
