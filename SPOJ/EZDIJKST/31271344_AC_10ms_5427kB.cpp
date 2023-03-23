#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 9;
int dist[N], vis[N], vid, n, m;
vector<pair<int, int>> adj[N];
void Dijkstra(int from, int to)
{
  dist[from] = 0;
  vis[from] = vid;
  priority_queue<pair<int, int>> pq;
  pq.push({0, from});
  while(!pq.empty())
  {
    int v = pq.top().second;
    pq.pop();
    if (v == to)break;
    for(auto cur: adj[v])
    {
      int u = cur.first;
      int c = cur.second;
      if (vis[u] != vid || dist[u] > dist[v] + c)
      {
        vis[u] = vid;
        dist[u] = dist[v] + c;
        pq.push({-dist[u], u});
      }
    }
  }
}
void test()
{
  vid++;
  scanf("%d%d", &n, &m);
  for(int i = 0; i <= n; i++)adj[i].clear();
  for (int i = 0; i < m; i++)
  {
    int u, v, c;
    scanf("%d%d%d", &u, &v, &c);
    adj[u].push_back({v, c});
  }
  int from, to;
  scanf("%d%d", &from, &to);
  Dijkstra(from, to);
  if (vis[to] == vid)
    printf("%d\n", dist[to]);
  else
    printf("NO\n"); 
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}
