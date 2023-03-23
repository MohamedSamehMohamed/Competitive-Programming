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
set<int> chSt[N];
int id_P;
int get_par(int u)
{
  return u == par[u] ? u: get_par(par[u]);
}
void conect(int u, int v)
{
  u = get_par(u);
  v = get_par(v);
  if (u == v)return;
  if (size[u] < size[v])swap(u, v);
  size[u] += size[v];
  sum[u] += sum[v];
  par[v] = u;
  chSt[u].insert(v);
}
void conect1(int u, int v)
{
  int p = get_par(u);
  int q = get_par(v);
  if (p == q)return;
  int dp = par[u];
  if (p != u){
  // u not the root
  for (int i: chSt[u])
  {
    par[i] = dp;
    chSt[dp].insert(i);
  }
  chSt[dp].erase(u);
  chSt[u].clear();
  while(dp != p)
  {
    sum[dp]-=u;
    size[dp]--;
    dp = par[dp];
  }
  sum[dp]-=u;
  size[dp]--;
}else
{
  for (int i: chSt[u])
  {
    par[i] = id_P;
    size[id_P] += size[i];
    sum[id_P] += sum[i];
    chSt[id_P].insert(i);
  }
  id_P++;
  chSt[u].clear();
}
  sum[u] = u * (u <= n);
  size[u] = 1 * (u <= n);

  size[q] += size[u];
  sum[q]  += sum[u];
  par[u]=q;
  chSt[q].insert(u);
}
int main()
{
  while(cin >> n >> m){
  for (int i = 1; i < N; i++){
    par[i] = i;
    chSt[i].clear();

    size[i] = 1 * (i <= n);
    sum[i] = i * (i <= n);
  }
  id_P = n+1;
  while(m--)
  {
    int ty, p, q;
    cin >> ty >> p ;
    if (ty != 3)cin >> q;
    if (ty == 1)
    {
      conect(p, q);
    }else if (ty == 2)
    {
      conect1(p, q);
    }else
    {
      p = get_par(p);
      cout << size[p] << " " << sum[p] <<"\n";
    }
  }
}
}
