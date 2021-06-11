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
int n, m, a[N], b[N], par[2*N];
vector<array<int, 3>> edges;
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
  scanf("%d%d", &m, &n);
  for (int i = 0; i < m; i++)
    scanf("%d", a+i);
  for (int i = 0; i < n; i++)
    scanf("%d", b+i);
  ll tot = 0;
  for (int i = 0; i < m; i++)
  {
    int siz;
    scanf("%d", &siz);
    while(siz--)
    {
      int j;
      scanf("%d", &j);
      j--;
      edges.pb({i, j + m, a[i] + b[j]});
      tot += a[i] + b[j];
    }
  }
  vector<int> order(SZ(edges));
  iota(all(order), 0);
  iota(par, par+2*N, 0);
  sort(all(order),[](int i, int j){
    return edges[i][2] > edges[j][2];
  });
  for (int i = 0; i < SZ(edges); i++)
  {
    int idx = order[i];
    int u = edges[idx][0];
    int v = edges[idx][1];
    int cst = edges[idx][2];
    if (uni(u, v))
    {
      tot -= cst;
    }
  }
  printf("%lld\n", tot);
}
