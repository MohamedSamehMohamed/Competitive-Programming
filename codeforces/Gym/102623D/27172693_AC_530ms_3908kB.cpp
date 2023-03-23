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
int par[N];
int deg[N];
vector<array<int, 2>> edges;
int get_par(int u)
{
  return u == par[u]? u: par[u] = get_par(par[u]);
}
bool uni(int u, int v)
{
  u = get_par(u);
  v = get_par(v);
  if (u == v)return 0;
  par[u] = v;
  return 1;
}
int main()
{
  cin >> n >> m;
  for (int i = 0; i < n; i++)par[i] = i;
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    u--;v--;
    if (u < v)swap(u, v);
    edges.pb({u, v});
  }
  sort(all(edges));
  for (int i = 0; i < m; i++)
  {
    if (uni(edges[i][0], edges[i][1]))
    {
      deg[edges[i][0]]++;
      deg[edges[i][1]]++;
    }
  }
  int ans = *max_element(deg, deg+n);
  cout << ans << '\n';
}
