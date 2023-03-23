// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
const int N = 1e4;
vector<int> adj[N];
int n, m;
int vis[N], Tin[N], Low[N], id, tim;
set<pair<int,int>> ans;
void dfs(int u, int p)
{
  vis[u] = id;
  Tin[u] = Low[u] = tim++;
  for (int v : adj[u])
  {
    if (v == p)continue;
    if (vis[v] == id) Low[u] = min(Low[u], Tin[v]);
    else
    {
      dfs(v, u);
      Low[u] = min(Low[u], Low[v]);
      if (Low[v] > Tin[u])
        ans.insert({min(u,v), max(v,u)});
    }
  }
}
int cnt;
bool bad(int i, int u)
{
  if (vis[i] == id)return 1;
  if (i > u)swap(i, u);
  if (ans.find({i, u}) != ans.end())return 1;
  return 0;
}
void dfs1(int u)
{
  cnt++;
  vis[u] = id;
  for (int i: adj[u])
  {
    if (bad(i, u))continue;
    dfs1(i);
  }
}
int main()
{
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++)
  {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  id = 1;
  for (int i = 0; i < n; i++)if (vis[i] != id)dfs(i, -1);
  id++;
  dfs1(0);
  printf("%d\n", cnt);
}
// me