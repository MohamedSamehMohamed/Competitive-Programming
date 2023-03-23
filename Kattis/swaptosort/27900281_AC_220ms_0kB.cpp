// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
const int N = 1e6 + 9;
int par[N];
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
int main()
{
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i <= n; i++)par[i] = i;
  for (int i = 0; i < m; i++)
  {
    int u, v;
    scanf("%d%d", &u, &v);
    uni(u, v);
  }
  for (int i = 1, j = n; i < j; i++, j--)
  {
    int u = get_par(i);
    int v = get_par(j);
    if (u != v)
    {
      printf("No\n");
      return 0;
    }
  }
  printf("Yes\n");
}
// me