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
const int N = 1e3+9;
int n, m, deg[N][2], root;
vector<pair<int,int>> adj[N];
vector<array<int, 3>> ans;
void dfs(int u, int p, int mx)
{
  if (SZ(adj[u]) == 0)
  {
    ans.pb({root, u, mx});
    return;
  }
  for (auto i: adj[u])
    if (i.f != p)
      dfs(i.f, u, min(mx, i.s));
}
int main()
{
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    int u, v, c;
    cin >> u >> v >> c;
    u--;v--;
    deg[v][0]++;
    deg[u][1]++;
    adj[u].pb({v, c});
  }
  for (int i = 0; i < n; i++)
  {
    if (deg[i][0] == 0 && deg[i][1])
    {
      root = i;
      dfs(i, i, 1e9);
    }
  }
  sort(all(ans));
  cout << SZ(ans) << '\n';
  for (auto i: ans)
    cout << i[0]+1 << ' ' << i[1]+1 << ' ' << i[2] << '\n';
}
