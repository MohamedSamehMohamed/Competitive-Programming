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
int n, m;
vector<array<int,3>> edges;
int par[N];
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
int main()
{
  while(cin >> n >> m && (n || m))
  {
    edges.clear();
    for (int i = 0; i < m; i++)
    {
      int u, v, c;
      cin >> u >> v >> c;
      u--;v--;
      edges.pb({c, u, v});
    }
    sort(all(edges));
    int mn, mx, ans = 1e9;
    int edges_add =0 ;
    for (int st = 0; st < SZ(edges); st++){
    mn = 1e9;
    mx = -1;
    edges_add  = 0;
    for (int i = 0; i < n; i++)par[i] = i;
    for (int i = st; ;)
    {
      if (conect(edges[i][1], edges[i][2]))
      {
        mn = min(mn, edges[i][0]);
        mx = max(mx, edges[i][0]);
        edges_add++;
      }
      i = (i+1)%SZ(edges);
      if (i == st)break;
    }
    if (edges_add == n-1)ans = min(ans, mx - mn);
    }
    if (edges_add != n-1)
    {
      cout <<"-1\n";
      continue;
    }
    cout << ans <<"\n";

  }
}
