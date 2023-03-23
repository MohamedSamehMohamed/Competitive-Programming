// Author : Mohamed sameh
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
int par[N], sz[N], n, m;
int get_par(int u)
{
  return par[u] == u? u : get_par(par[u]);
}
void conect(int u, int v)
{
  u = get_par(u);
  v = get_par(v);
  if (u == v)return;
  par[u] = v;
  sz[v]+=sz[u];
}
int main()
{
  for (int i = 0; i < N; i++)
  {
    par[i] = i;
    sz[i] = 1;
  }
  scanf("%d%d", &n, &m);
  int tk = 0;
  for (int i = 0; i < m; i++)
  {
    int u, v;
    scanf("%d%d", &u, &v);
    u--;v--;
    u = get_par(u);
    v = get_par(v);
    if (u == v)
    {
      if (sz[u]&1)tk++;
    }else
    conect(u, v);
  }
  if ( (n - tk)&1 )tk++;
  printf("%d\n", tk);

}
