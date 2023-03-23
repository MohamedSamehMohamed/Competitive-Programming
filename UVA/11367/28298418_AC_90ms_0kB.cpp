// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
const int N = 1e3 + 9, M = 101;
int n, m;
int a[N];
vector<pair<int,int>> adj[N];
int dist[N][M];
int dijkstra(int src, int des, int cap)
{
  memset(dist, -1, sizeof dist);
  priority_queue<array<int, 3>> pq;
  dist[src][0] = 0;
  pq.push({0, src, 0});
  while(!pq.empty())
  {
    auto cur = pq.top();
    pq.pop();
    int u = cur[1];
    int rem = cur[2];
    if (dist[u][rem] < -cur[0])continue;
    if (u == des)return dist[u][rem];
    if (rem < cap)
    {
      if (dist[u][rem+1] == -1 || dist[u][rem+1] > dist[u][rem] + a[u])
      {
        dist[u][rem + 1] = dist[u][rem] + a[u];
        pq.push({-dist[u][rem+1], u, rem + 1});
      }
    }
    for (auto i: adj[u])
    {
      int v = i.first;
      int c = i.second;
      if (rem < c)continue;
      if (dist[v][rem-c] == -1 || dist[v][rem-c] > dist[u][rem])
      {
        dist[v][rem-c] = dist[u][rem];
        pq.push({-dist[v][rem-c], v, rem - c});
      }
    }
  }
  return -1;
}
int main()
{
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < m; i++)
  {
    int u, v, c;
    cin >> u >> v >> c;
    adj[u].push_back({v, c});
    adj[v].push_back({u, c});
  }
  int q;cin >> q;
  while(q--)
  {
    int src, des, cap;cin >> cap >> src >> des;
    int ans = dijkstra(src, des, cap);
    if (ans == -1)
      cout << "impossible\n";
    else
      cout << ans << "\n";
  }

}
