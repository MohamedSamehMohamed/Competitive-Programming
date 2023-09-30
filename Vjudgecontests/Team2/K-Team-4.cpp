#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9, N = 311;
int n, k, m, capacity[N][N], vis[N];
vector<int> adj[N], g[N];
int bfs(int s, int t, vector<int>& parent) {
  fill(parent.begin(), parent.end(), -1);
  parent[s] = -2;
  queue<pair<int, int>> q;
  q.push({s, INF});

  while (!q.empty()) {
    int cur = q.front().first;
    int flow = q.front().second;
    q.pop();
    for (int next : adj[cur]) {
      if (parent[next] == -1 && capacity[cur][next]) {
        parent[next] = cur;
        int new_flow = min(flow, capacity[cur][next]);
        if (next == t)
          return new_flow;
        q.push({next, new_flow});
      }
    }
  }

  return 0;
}
int maxFlow(int s, int t) {
  int flow = 0;
  vector<int> parent(N);
  int new_flow;

  while (new_flow = bfs(s, t, parent)) {
    flow += new_flow;
    int cur = t;
    while (cur != s) {
      int prev = parent[cur];
      capacity[prev][cur] -= new_flow;
      capacity[cur][prev] += new_flow;
      cur = prev;
    }
  }
  return flow;
}
set<int> paths[N][N];
vector<int> path;
void add_path(){
  for (int i = 1; i < path.size(); i++)
    paths[path[i-1]][path[i]].insert(path[0] + i - 1);
}
bool dfs(int src, int dst){
  if (src == dst)
    return 1;
  vis[src] = 1;
  path.push_back(src);
  for (int v: g[src]){
    if (vis[v]) continue;
    if (dfs(v, dst)){
      // reached
      path.push_back(dst);
      add_path();
      path.pop_back();
    }
  }
  path.pop_back();
  vis[src] = 0;
  return 0;
}
void add_edge(int u, int v, int c){
  adj[u].push_back(v);
  adj[v].push_back(u);
  cout << u <<" " << v <<" " << c <<"\n";
  capacity[u][v] = c;
}
int main()
{
  scanf("%d%d%d", &n, &k, &m);
  for(int i = 0; i < m; i++)
  {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
  }
  // one based
  int src = 0, dst = n+1;
  for (int i = 1; i <= k; i++){
    add_edge(0, i, 1);
  }
  add_edge(n, n+1, k);
  // building the graph
  for (int i = 1; i <= k; i++)
    dfs(i, n);
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= n; j++){
      if (paths[i][j].size() != 0)
      {
        add_edge(i, j, (int)paths[i][j].size());
        cout << i <<"->" << j <<"\n";
        for(auto it: paths[i][j]) cout << it <<" ";
        cout <<"\n";
      }
    }
  }
  printf("%d\n", maxFlow(src, dst));
}
