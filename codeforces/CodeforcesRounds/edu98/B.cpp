// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int n, m, a[N], b[N], sz[N], good[N];
vector<int> adj[N];
void dfs(int u = 1, int p = -1)
{
  sz[u] = a[u];
  for (int i: adj[u])
  {
    if (i == p)
      continue;
    dfs(i, u);
    sz[u] += sz[i];
  }
}
bool check(int u = 1, int p = -1)
{
  for (int i: adj[u])
  {
    if (i == p)continue;
    if (!check(i, u)) return 0;
  }
  if ((sz[u]-b[u])%2)return 0;
  good[u] = (sz[u] - b[u]) >> 1;
  int bad = a[u] - good[u];
  return (b[u] == good[u]-bad);
}
void test()
{
  scanf("%d%d", &n, &m);
  for (int i = 0; i <= n; i++)adj[i].clear();
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  for (int i = 0; i < n; i++)
    scanf("%d", b+i);
  for (int i = 0; i < n-1; i++)
  {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs();
  cout << (check()? "YES\n": "NO\n");
}
int main()
{

  int t;scanf("%d", &t);
  while(t--)
  {
    test();
  }
}
