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
  int T = 1;
  while(cin >> n >> m && (n || m))
  {
    for (int i = 0; i < n; i++)par[i] = i;
    edges.clear();
    for (int i = 0; i < m; i++)
    {
      int u, v, c;
      cin >> u >> v >> c;
      u--;v--;
      edges.pb({c, u, v});
    }
    int st, en, tot;
    cin >> st >> en >> tot;
    st--;en--;
    sort(rall(edges));
    int ans = 1e9;
    for (int i = 0; i < SZ(edges) && get_par(st) != get_par(en); i++)
    {
      if (conect(edges[i][1], edges[i][2]))
      {
        ans = min(ans, edges[i][0] - 1);
      }
    }
    cout <<"Scenario #" << T++ << "\n";
    cout <<"Minimum Number of Trips = ";
    cout << (tot+ans-1)/ans <<"\n";
    cout <<"\n";


  }
}
