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
const int N = 60;
int n, m;
bool mat[N][N];
vector<int> adj[N];
int par[N];
int get_par(int u)
{
  return u == par[u] ? u: par[u] = get_par(par[u]);
}
bool conect(int u, int v)
{
  u = get_par(u);
  v = get_par(v);
  if (u == v)return 0;
  par[u] = v;
  return 1;
}
vector<pair<int,int>> ans;
void PrintAnswer()
{
  cout <<"YES\n";
  cout << SZ(ans) <<"\n";
  for (auto i: ans)
    cout << i.f <<" " << i.s <<"\n";
}
int main()
{
  bool mul = 0;
  for (int i = 0; i < N; i++)par[i] = i;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++)
  {
    int u, v;
    scanf("%d%d", &u, &v);
    if (mat[u][v])mul=1;
    mat[u][v] = mat[v][u] = 1;
  }
  if (n == 1 && m <= 1)
  {
    if (m)
    cout <<"YES\n0\n";
    else
    cout <<"YES\n1\n1 1\n";
    return 0;
  }
  if (mul)
  {
    if (n == 2)
    {
      if (mat[1][2] && (!mat[1][1] && !mat[2][2]))
      {
        cout <<"YES\n";
        cout <<"0\n";
        return 0;
      }
    }
    cout <<"NO\n";
    return 0;
  }
  for (int i = 1; i <= n; i++)
  {
    for (int j = i; j <= n; j++)
      if (mat[i][j])
      {
        adj[i].pb(j);
        adj[j].pb(i);
      }
  }
  for (int i = 1; i <= n; i++)
    for (int j = i; j <= n; j++)
      if (mat[i][j])
        conect(i, j);
  for (int i = 1; i <= n; i++)
    for (int j = i+1; j <= n; j++)
      {
        if (SZ(adj[i]) == 2)break;
        if (SZ(adj[j]) == 2)continue;
        if (conect(i, j))
        {
          ans.pb({i, j});
          adj[i].pb(j);
          adj[j].pb(i);
        }
      }
  int idx1, idx2;
  idx1 = idx2 = -1;
  bool more = 0;
  bool ok = 1;
  bool bad = 0;
  for (int i = 1; i <= n; i++)
  {
    bad |= (mat[i][i]); 
    bad |= (SZ(adj[i]) > 2);
    ok&=(SZ(adj[i]) == 2);
    if (SZ(adj[i]) == 1)
    {
      if (idx1 == -1)idx1 = i;
      else if (idx2 == -1)idx2 = i;
      else
      more = 1;
    }
  }
  if (bad||more)
  {
    cout <<"NO\n";
    return 0;
  }
  if (ok)
  {
      PrintAnswer();
  }else
  {
    if (idx1 != -1 && idx2 != -1)
    {
      ans.pb({idx1, idx2});
      PrintAnswer();
    }else if (idx1 == idx2 && idx1 == -1)
    {
      PrintAnswer();
    }else
    {
      cout <<"NO\n";
    }
  }
}
