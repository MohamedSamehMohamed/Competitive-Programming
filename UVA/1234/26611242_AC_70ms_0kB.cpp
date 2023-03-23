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
int n, m;
vector<array<int, 3>> edges;
int par[N];
int get_par(int u)
{
  return u == par[u]? u : par[u] = get_par(par[u]);
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
  int t;
  scanf("%d", &t);
  while(t--)
  {
    scanf("%d%d", &n, &m);
    edges.clear();
    for (int i = 0; i < n; i++)par[i] = i;
    for (int i = 0; i < m; i++)
    {
      int u, v, c;
      scanf("%d%d%d", &u, &v, &c);
      u--;v--;
      edges.pb({c, u, v});
    }
    sort(rall(edges));
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
      if (!uni(edges[i][1], edges[i][2]))
      {
        // this edge make a cycle
        // min edge in the cycle
        ans += edges[i][0];
      }
    }
    printf("%d\n", ans);
  }
}
