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
const int N = 2e5+9;
int n, m, par[N], size[N];
ll sum[N];
int get_par(int u)
{
  return u == par[u]? u: par[u] = get_par(par[u]);
}
void conect_com(int u, int v)
{
  u = get_par(u);
  v = get_par(v);
  if (u == v)return ;
  par[u] = v;
  sum[v]  += sum[u];
  size[v] += size[u];
}
void conect_node(int u, int v)
{
  int pu = get_par(u);
  int pv = get_par(v);
  if (pu == pv)return;
  sum[pu]-= u;
  sum[pv]+= u;
  size[pu]-=1;
  size[pv]++;
  par[u] = pv;
}
int main()
{
  FAST
  while(cin >> n >> m){
  for (int i = 1; i <= n; i++)
  {
    par[i] = i+n;
    par[i+n] = i+n;
    size[i+n] = 1;
    sum[i+n] = i;
  }
  while(m--)
  {
    int ty, p, q;
    cin >> ty >> p ;
    if (ty != 3)cin >> q;
    if (ty == 1)
    {
      conect_com(p, q);
    }else if (ty == 2)
    {
      conect_node(p, q);
    }else
    {
      p = get_par(p);
      cout << size[p] << " " << sum[p] <<"\n";
    }
  }
}
}
