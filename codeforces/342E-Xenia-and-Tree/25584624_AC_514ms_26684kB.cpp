// Author : Mohamed Sameh
#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define MP make_pair
#define Flush fflush(stdout);
typedef long long ll ;
using namespace std ;
const int N = 1e5 + 9, Lg = 20 ;
int minD[N], dep[N], color[N], tour[2*N], st[N], spt[2*N][Lg], Log[2*N], n, m, idx;
vector<int> adj[N], Red;
void dfs (int u = 1, int p = 1)
{
  st[u] = idx ;
  tour[idx++] =u;
  dep[u] = dep[p] + 1;
  for (int i : adj[u])
    if (i != p)
    {
      dfs(i, u);
      tour[idx++] = u;
    }
}
void buildSpt()
{
  for (int i = 2 ;i <= idx ;i++)Log[i] = Log[i/2] + 1;
  for (int i =0 ; i < idx ;i++)spt[i][0] = i;
  for (int j = 1; j < Lg ;j++)
  {
    for (int i =0; i + (1<<j) <= idx ;i++)
    {
      int a = spt[i][j-1];
      int b = spt[i+(1<<(j-1))][j-1];
      spt[i][j] = dep[tour[a]] < dep[tour[b]] ? a : b ;
    }
  }
}
int mquery(int l, int r)
{
  int sz = Log[r - l + 1];
  int a = spt[l][sz];
  int b = spt[r-(1<<sz)+1][sz];
  return dep[ tour[a] ] < dep[ tour[b] ] ? a : b ;
}
int lca (int u, int v)
{
  u = st[u];
  v = st[v];
  if (u > v )swap(u, v);
  return tour[mquery(u, v)];
}
void BFS ()
{
  queue<int> q ;
  for (int i = 1; i <= n ; i++)
  {
    if (color[i]){
    q.push(i);
    minD[i]=0;
    }
  }
  while (!q.empty())
  {
      int cur = q.front();
      q.pop();
      for (auto i : adj[cur])
      {
        if (minD[cur]+1 < minD[i])
        {
          minD[i] = minD[cur]+1;
          q.push(i);
        }
      }
  }
}
int dist (int u, int v)
{
  return dep[u] + dep[v] - 2 * dep[lca(u,v)];
}
int query(int u)
{
  int ans = minD[u];
  for (int i : Red)
  ans = min (ans, dist(u, i));
  return ans ;
}
int main()
{
  memset(minD, 63, sizeof minD);
  scanf("%d%d", &n, &m);
  for (int i =0; i < n-1 ;i++)
  {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].pb(v);
    adj[v].pb(u);
  }
  color[1] = 1;
  dfs();
  buildSpt();
  BFS();
  int sq = sqrt(m);
  int bl =0 ;
  for (int i =0; i < m ;i++)
  {
    int ty, u ;
    scanf("%d%d", &ty, &u);
    if (i / sq == bl)
    {
      bl++;
      BFS();
      Red.clear();
    }
    if (ty == 1 )
    {
      Red.pb(u);
      color[u]=1;
    }else
    {
      printf("%d\n", query(u));
    }
  }

}
