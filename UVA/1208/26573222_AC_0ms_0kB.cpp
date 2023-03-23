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
const int N = 1000+9;
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
  int t ;cin >> t;
  int T = 1;
  while(t--)
  {
    cin >> n;
    for (int i = 0; i < n; i++)par[i] = i;
    edges.clear();
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        int c;
        char ch;
        cin >> c;
        if (j + 1 != n)cin >> ch;
        if (!c)c = 1e9;
        edges.pb({c, i, j});
      }
    }
    sort(all(edges));
    int edges_add = 0;
    vector<int> ans;
    for (int i = 0; i < SZ(edges); i++)
    {
      if (conect(edges[i][1], edges[i][2]))
      {
        ans.pb(i);
      }
    }
    cout <<"Case " << T++ <<":\n";
    for (int i = 0; i < SZ(ans); i++)
    {
      cout << char('A' + edges[ans[i]][1]) << "-" << char('A' + edges[ans[i]][2]) << " " << edges[ans[i]][0] <<"\n";
    }
  }
}
