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
const int N = 101;
int n, m;
vector<array<int, 3>> edges;
vector<int> mst;
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
int ret, bad;
bool Find_Mst(bool ft)
{
  ret = 0;
  int edges_added  = 0;
  for (int i = 0; i < n; i++)par[i] = i;
  for (int i = 0; i < SZ(edges); i++)
  {
    if (i == bad)continue;
    if (conect(edges[i][1], edges[i][2]))
    {
      edges_added++;
      if (ft)mst.pb(i);
      ret += edges[i][0];
    }
  }
  if (edges_added != n-1)ret = -1;
  if (~ret)return 1;
  return 0;
}
int main()
{
  int t;
  cin >> t;
  int T = 1;
  while(t--)
  {
    edges.clear();
    mst.clear();
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
      int u, v, c;
      cin >> u >> v >> c;
      u--;v--;
      edges.pb({c, u, v});
    }
    cout <<"Case #" << T++ <<" : ";
    sort(all(edges));
    bad = -1;
    if (!Find_Mst(1))
    {
      cout << "No way\n";
      continue;
    }
    int ans  = ret;
    int ans1 = 1e9;
    for (int i = 0; i < SZ(mst); i++)
    {
      bad = mst[i];
      Find_Mst(0);
      if (~ret)
      ans1 = min(ans1, ret);
    }
    if (ans1 != 1e9)
      cout << ans1 <<"\n";
    else
      cout <<"No second way\n";
  }
}
