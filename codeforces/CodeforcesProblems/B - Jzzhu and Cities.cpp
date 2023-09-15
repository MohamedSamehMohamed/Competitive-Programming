// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
const long long inf = 1e18;
int n, m, k;
vector<pair<int, int>> adj[N];  
long long dist[N];
bool train[N]; 
void Dijkstra()
{
 dist[0] = 0;
 priority_queue<pair<long long, int>> pq;
 pq.push({0LL, 0});
 for (int i = 0; i < n; i++)
  if (train[i])
   pq.push({-dist[i], i});
 while(!pq.empty())
 {
  int u = pq.top().second;
  long long d = pq.top().first; 
  pq.pop();
  if (dist[u] < -d)continue; 
  for (auto cur: adj[u])
  {
   int v, c;
   tie(v, c) = cur; 
   if (dist[u] + c < dist[v])
   {
    dist[v] = dist[u] + c; 
    pq.push({-dist[v], v}); 
    train[v] = 0; 
   }else if (dist[u] + c == dist[v])
   train[v] = 0; 
  }
 }
}
int main()
{
 scanf("%d%d%d", &n, &m, &k);
 for (int i = 0; i < m; i++)
 {
  int u, v, c; 
  scanf("%d%d%d", &u, &v, &c);
  u--;v--;
  adj[u].push_back({v, c});
  adj[v].push_back({u, c}); 
 }
 for (int i = 0; i < n; i++)dist[i] = inf; 
 for (int i = 0; i < k; i++)
 {
  int u, c; 
  scanf("%d%d", &u, &c); 
  u--; 
  train[u] = 1; 
  dist[u] = min(1LL*c, dist[u]); 
 }
 Dijkstra();
 int ans = 0;
 for (int i = 0; i < n; i++)ans += train[i]; 
 printf("%d\n", k-ans);  
}
