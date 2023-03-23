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
const int N = 3e4+ 9;
int par[N], n, m;
int get_par(int u)
{
  return u == par[u]? u: par[u] = get_par(par[u]);
}
void uni(int u, int v)
{
  u = get_par(u);
  v = get_par(v);
  if (u == v)return;
  par[u] = v;
}
bool same(int u, int v)
{
  return get_par(u) == get_par(v);
}
int main()
{
  while(cin >> n >> m && (n || m))
  {
    for (int i = 0; i < n; i++)par[i] = i;
    for (int i = 0; i < m; i++)
    {
      int k, u, v;;
      cin >> k;
      if (k){cin >> u;k--;}
      while(k--)
      {
        cin >> v;
        uni(u, v);
      }
    }
    int ans = 0;
    for (int i = 1; i < n; i++)ans += same(0, i);
    cout << ans + 1<<"\n";
  }
}
