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
const int N = 1e5+9;
int n, a, b, da, db, t;
vector<int> adj[N];
int dep[N];
int mx;
int dfs(int u, int p)
{
  int len = 0;
  for (int i: adj[u])
    if (i != p)
      {
        dep[i] = dep[u] + 1;
        int local = 1 + dfs(i, u);
        mx = max(mx, len + local);
        len = max(len, local);
      }
  return len;
}
int main()
{
  FAST
  cin >> t;
  while(t--)
  {
    cin >> n >> a >> b >> da >> db;
    for (int i = 0; i < n; i++)adj[i].clear();
    a--;b--;
    for (int i = 1; i < n; i++)
    {
      int u, v;
      cin >> u >> v;
      u--;v--;
      adj[u].pb(v);
      adj[v].pb(u);
    }
    mx = 0;
    dep[a] = 0;
    dfs(a, a);
    if (2 * da >= min(mx,db) || dep[b] <= da)
      cout <<"Alice\n";
    else
      cout <<"Bob\n";
  }
}
