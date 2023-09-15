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
const int N = 50;
int par[N], size[N], n, m;
void init()
{
  for (int i = 0; i < N; i++)par[i] = i,size[i] = 1;
}
int get_par(int u)
{
  return par[u] == u? u: par[u] = get_par(par[u]);
}
void uni(int u, int v)
{
  u = get_par(u);
  v = get_par(v);
  if (u == v)return;
  par[u] = v;
  size[v] += size[u];
}
int main()
{
  init();
  cin >> n >> m;
  while(m--)
  {
    int u, v;
    cin >> u >> v;
    u--;v--;
    uni(u, v);
  }
  set<int> tk;
  ll ans = 1;
  for (int i = 0; i < n; i++)
  {
    int p = get_par(i);
    if (tk.find(p) != tk.end())continue;
    tk.insert(p);
    ans *= (1LL << (size[p]-1));
  }
  cout << ans << '\n';
}