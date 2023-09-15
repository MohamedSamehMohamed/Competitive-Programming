// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
const int N = 1e4 + 9, INF = 1e8;
vector<pair<int,int>> adj[N];
int n, m;
int dist[N][2];
vector<array<int, 3>> edges;
void read()
{
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++)
  {
    int u, v, c;
    scanf("%d%d%d", &u, &v, &c);
    adj[u].push_back({v,c});
    adj[v].push_back({u,c});
    edges.push_back({u, v, c});
  }
  memset(dist, -1, sizeof dist);
}
void dijkstra(int src, int idx)
{
  priority_queue<pair<long long, int>> pq;
  pq.push({0, src});
  dist[src][idx] = 0;
  while(!pq.empty())
  {
    auto cur = pq.top();
    pq.pop();
    cur.first *= -1;
    for (auto node: adj[cur.second])
    {
      int v   = node.first;
      int cst = node.second;
      if (dist[v][idx] == -1 || dist[v][idx] > (cst + cur.first))
      {
        dist[v][idx] = cst + cur.first;
        pq.push({-dist[v][idx], v});
      }
    }
  }
}
long long solve()
{
  read();
  dijkstra(0, 0);
  dijkstra(n-1, 1);
  long long ans = 0;
  for (auto node: edges)
  {
    int u = node[0];
    int v = node[1];
    int c = node[2];
    for (int i = 0; i < 2; i++)
    {
      if (dist[u][0] + dist[v][1] + c == dist[n-1][0])
      {
        ans += c;
        break;
      }
      swap(u, v);
    }
  }
  return ans;
}
int main()
{
  printf("%lld\n", 2LL * solve());
}
