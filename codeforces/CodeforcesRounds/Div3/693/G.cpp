// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
const int N = 2e5 + 9;
int n, m;
vector<int> adj[N];
int dist[N], best[N];
void BFS()
{
  queue<int> q;
  q.push(0);
  dist[0] = best[0] = 0;
  while(!q.empty())
  {
    int cur = q.front();
    q.pop();
    for (int i: adj[cur])
    {
      if (dist[i] == -1 || dist[cur] + 1 < dist[i])
      {
        dist[i] = dist[cur] + 1;
        q.push(i);
      }
    }
  }
}
// if i did the second opration i will stop after it
// because all i can do after is to go to distance grater than me
// best[i] -> min dist I can get If I used the second opration
void init()
{
  for (int i = 0; i < n; i++)adj[i].clear(), best[i] = dist[i] = -1;
}
int dfs(int u)
{
  if (~best[u])
    return best[u];
  best[u] = dist[u];
  for (int i: adj[u])
    best[u] = min(best[u], (dist[u] < dist[i]? dfs(i): dist[i]));
  return best[u];
}
void test()
{
  scanf("%d%d", &n, &m);
  init();
  for (int i = 0; i < m; i++)
  {
    int u, v;
    scanf("%d%d", &u, &v);
    u--;v--;
    adj[u].push_back(v);
  }
  BFS();
  for (int i = 0; i < n; i++)
    printf("%d%c", dfs(i), (i+1==n? '\n': ' '));
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}
