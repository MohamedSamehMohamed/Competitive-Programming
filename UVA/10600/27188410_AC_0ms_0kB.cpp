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
int t;
int n, m;
const int N = 5e5;
vector<array<int, 3>> edges;
int par[N];
bool seen[N];
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
void clr()
{
  for (int i = 0; i <= n; i++)par[i] = i;
}
int get_mst(int bad, int dum)
{
  clr();
  int ans = 0;
  int edg = 0;
  for (int i = 0; i < SZ(edges); i++)
  {
    if (i == bad)continue;
    if (uni(edges[i][1], edges[i][2]))
    {
      if (dum)seen[i] = 1;
      edg++;
      ans += edges[i][0];
    }
  }
  if (edg != n-1)return -1;
  return ans;
}
int main()
{
  cin >> t;
  while(t--)
  {
    edges.clear();
    memset(seen, 0, sizeof seen);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
      int u, v, c;
      cin >> u >> v >> c;
      edges.pb({c, u, v});
    }
    sort(all(edges));
    int fir_mst = get_mst(-1, 1);
    int sec_mst = -1;
    for (int i = 0; i < SZ(edges); i++)
    {
      if (seen[i])
      {
        int cur = get_mst(i, 0);
        if (cur != -1)
        {
          if (sec_mst == -1)sec_mst = cur;
          sec_mst = min(sec_mst, cur);
        }
      }
    }
    cout << fir_mst <<" " << sec_mst <<"\n";
  }
}
