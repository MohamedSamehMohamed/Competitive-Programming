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
const int N = 800;
int par[N], p[N][2], n, m;
vector<pair<double, array<int,2>>> edges;
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
double dist(int i, int j)
{
  return sqrt(pow(p[i][0]- p[j][0], 2) + pow(p[i][1] - p[j][1], 2));
}
void solve()
{
  edges.clear();
  iota(par, par+N, 0);
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 2; j++)
      cin >> p[i][j];
  cin >> m;
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    uni(u-1, v-1);
  }
  for (int i = 0; i < n; i++)
    for (int j = i+1; j < n; j++)
    {
      edges.pb({dist(i, j),{i, j}});
    }
  sort(all(edges));
  vector<pair<int,int>> ans;
  for (int i = 0; i < SZ(edges); i++)
  {
    if (uni(edges[i].s[0], edges[i].s[1]))
    {
      ans.pb({edges[i].s[0], edges[i].s[1]});
    }
  }
  if (SZ(ans) == 0)
  {
    cout <<"No new highways need\n";
  }
  for (auto i: ans)
    cout << i.f + 1<< " " << i.s + 1<<"\n";
}
int main()
{
  int t;
  cin >> t;
  while(t--){
    solve();
    if (t)cout <<"\n";
  }
}
