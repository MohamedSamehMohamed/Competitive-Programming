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
const int N = 1e5;
int n, m, t;
vector<array<int, 3>> edges;
int par[N];
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
map<string, int> mp;
int get_int(string x)
{
  if (mp.find(x) == mp.end())mp[x] = SZ(mp);
  return mp[x];
}
int main()
{
  cin >> t;
  while(t--)
  {
    cin >> n >> m;
    edges.clear();
    mp.clear();
    for (int i = 0; i < n; i++)par[i] = i;
    for (int i = 0; i < m; i++)
    {
      int u, v, c;
      string x, y;
      cin >> x >> y >> c;
      u = get_int(x);
      v = get_int(y);
      edges.pb({c, u, v});
    }
    sort(all(edges));
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
      if (uni(edges[i][1], edges[i][2]))
      {
        ans += edges[i][0];
      }
    }
    cout << ans <<"\n";
    if (t)cout <<"\n";
  }
}
