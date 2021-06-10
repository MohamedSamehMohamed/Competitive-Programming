// Author : Mohamed sameh
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int n, m, st, steps, k, ans;
map<pair<int,int>,bool> mp;
vector<pair<int,int>> adj[N];
void init()
{
  for (int i = 0; i < n; i++)adj[i].clear();
  mp.clear();
}
bool exist(int u, int v)
{
  if (mp.find({u, v}) != mp.end())
    return 1;
  mp[{u,v}]=1;
  return 0;
}
void BFS()
{
  queue<array<int,3>> q;
  q.push({st, 0, 0});
  while(!q.empty())
  {
    array<int, 3> cur = q.front();
    q.pop();
    ans = max(ans, cur[1]);
    if (cur[2] == k)
      continue;
    for (auto u: adj[cur[0]])
      if (!exist(cur[0], u.first))
        q.push({u.first, u.second, cur[2]+1});
  }
}
void test()
{
  scanf("%d%d%d%d%d", &n, &m, &st, &steps, &k);
  init();
  st--;
  for (int i = 0; i < m; i++)
  {
    int u, v, c;
    scanf("%d%d%d", &u, &v, &c);
    u--;v--;
    adj[u].push_back({v, c});
    adj[v].push_back({u, c});
  }
  ans = 0;
  BFS();
  printf("%d\n", ans);
}
int main()
{
  freopen("path.in", "r", stdin);
  int t;
  scanf("%d", &t);
  while(t--)test();
}
