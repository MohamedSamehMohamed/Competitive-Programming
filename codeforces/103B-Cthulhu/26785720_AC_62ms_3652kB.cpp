// Author : Mohamed Sameh
#include <bits/stdc++.h>
typedef long long ll ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
using namespace std ;
const int N = 101;
int n, m, c, par[N];
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
  c--;
  return 1;
}
int main()
{
  iota(par, par + N, 0);
  cin >> n >> m;
  bool ok = 0;
  c = n;
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    if (!uni(u, v))ok = 1;
  }
  ok&=(c == 1);
  ok&=(n == m);
  cout << (ok? "FHTAGN!" : "NO") ;
}
