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
const int N = 3 * 5e4+9;
int n, k;
int par[N];
void init()
{
  iota(par, par + (3*n+3), 0);
}
int get_par(int u)
{
  return u == par[u]? u: par[u] = get_par(par[u]);
}
void uni(int u, int v)
{
  u = get_par(u);
  v = get_par(v);
  if (u == v)return;
  if (v > u)swap(u, v);
  par[u] = v;
}
int same(int u, int v)
{
  u = get_par(u);
  v = get_par(v);
  if (u == v)
  {
    uni(u+n, v+n);
    uni(u+2*n, v+2*n);
    return 1;
  }
  int u_to, v_to, u_from, v_from;
  u_to = get_par(u+n);
  v_to = get_par(v+n);
  u_from = get_par(u+2*n);
  v_from = get_par(v+2*n);
  if (v_to == u || u_from == v || v_from == u || u_to == v)return 0;
  uni(u+n, v+n);
  uni(u+2*n, v+2*n);
  uni(u, v);
  return 1;
}
int diff(int u, int v)
{
  u = get_par(u);
  v = get_par(v);
  if (u == v)return 0;
  int u_to, v_to, u_from, v_from;
  u_to = get_par(u+n);
  v_to = get_par(v+n);
  u_from = get_par(u+2*n);
  v_from = get_par(v+2*n);
  if (u_to == v_to || u_from == v_from || v_to == u || u_from == v)return 0;
  uni(u+n,v);
  uni(v+2*n, u);
  uni(v+n, u+2*n);
  return 1;
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
  {
    scanf("%d%d", &n, &k);
    init();
    int ans = 0;
    for (int i = 0; i < k; i++)
    {
      int ty, x, y;
      scanf("%d%d%d", &ty, &x, &y);
      if (max(x, y) > n)
      {
        ans++;
        continue;
      }
      if (ty == 1)
      {
        ans += !same(x, y);
      }
      else
      {
        ans += !diff(x, y);
      }
    }
    printf("%d\n", ans);

  }
}
