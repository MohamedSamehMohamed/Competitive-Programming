// Author : Mohamed Sameh
// created in: 12:49 AM
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
vector<vector<int>> adj[N];
int n, m;
long long dist[N];
bool seen[N];
void dfs(int u){
  seen[u] = 1;
  for (auto cur: adj[u]){
    dist[cur[0]] = dist[u] + cur[1];
    if (seen[cur[0]]) continue;
    dfs(cur[0]);
  }
}
void test(){
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++)
    adj[i].clear();
  memset(dist, -1, sizeof (dist[0]) * n);
  memset(seen, 0, sizeof (seen[0]) * n);

  vector<vector<int>> edges;
  for (int i = 0; i < m; i++){
    int u, v, c;
    scanf("%d%d%d", &u, &v, &c);
    u--;v--;
    edges.push_back({u, v, c});
    adj[u].push_back({v, c});
    adj[v].push_back({u, -c});
  }
  for (int i = 0; i < n; i++){
    if (seen[i]) continue;
    dfs(i);
  }
  for (auto it: edges){
    if (dist[it[1]] != dist[it[0]] + it[2]){
      printf("NO\n");
      return;
    }
  }
  printf("YES\n");
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}