// Author : Mohamed sameh
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
const int N = 2e5+9;
int n, m;
vector<int> adj[N];
bool vis[N];
bool cyc, two;
void dfs(int u, int prv)
{
  two&=(SZ(adj[u]) == 2);
  vis[u] = 1;
  for (int i : adj[u])
  {
    if (i == prv)continue;
    if (vis[i])
    {
      cyc = 1;
      continue;
    }
    dfs(i, u);
  }
}
int main()
{
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++)
  {
    int u, v;
    scanf("%d%d", &u, &v);
    u--;v--;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    if (!vis[i])
    {
      cyc = 0;
      two = 1;
      dfs(i, i);
      if (cyc&&two)ans++;
    }
  }
  printf("%d\n", ans);
}
