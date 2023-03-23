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
const int N = 100;
int n, m;
vector<array<int, 3>> edges;
int par[N];
bool vis[N*N];
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
void init()
{
  memset(vis, 0, sizeof vis);
  for (int i = 0; i < n; i++)par[i] = i;
  edges.clear();
}
int solve(int bad)
{
  for (int i = 0; i < n; i++)par[i] = i;
  int cost = 0;
  int con = n;
  for (int i = 0; i < m; i++)
  {
    if (i == bad)continue;
    if (uni(edges[i][1], edges[i][2]))
    {
      con--;
      cost += edges[i][0];
      if (bad == -1)vis[i] = 1;
    }
  }
  if (con != 1)cost = 1e9;
  return cost;
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
  {
    scanf("%d%d", &n, &m);
    init();
    for (int i = 0; i < m; i++)
    {
      int u, v, c;
      scanf("%d%d%d", &u, &v, &c);
      edges.pb({c, u-1, v-1});
    }
    sort(all(edges));
    int cost1, cost2;
    cost1 = solve(-1);
    cost2 = 1e9;
    for (int i = 0; i < m; i++)
    {
      if (vis[i])
      {
        cost2 = min(cost2, solve(i));
      }
    }
    printf("%d %d\n", cost1, cost2);
  }
}
