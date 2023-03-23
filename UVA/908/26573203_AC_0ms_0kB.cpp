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
const int N = 1e6+9;
int n, m, nn;
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
ll Mst()
{
  for (int i = 0; i < nn; i++)par[i] = i;
  ll ans = 0;
  for (int i = 0; i < SZ(edges); i++)
  {
    if (conect(edges[i][1], edges[i][2]))
    {
      ans += edges[i][0];
    }
  }
  return ans;
}
int main()
{
  bool FT = 1;
  while(cin >> n)
  {
    if (!FT)cout <<"\n";
    FT = 0;
    nn = n;
    edges.clear();
    for (int i = 0; i < n-1; i++)
    {
      int u, v, c;
      cin >> u >> v >> c;
      u--;v--;
      edges.pb({c, u, v});
    }
    sort(all(edges));
    ll ans = Mst();
    bool ft = 1;
    cin >> n;
    while(n--)
    {
      int u, v, c;
      cin >> u >> v >> c;
      u--;v--;
      edges.pb({c, u, v});
      if (n == 0 && ft)
      {
        cin >> n;
        ft = 0;
      }
    }
    sort(all(edges));
    cout << ans <<"\n";
    ans = Mst();
    cout << ans <<"\n";
  }
}
