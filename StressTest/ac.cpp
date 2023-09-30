#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9, N = 301 * 301 + 20;
int n, k, m, vis[N];
map<vector<int>, int> capacity;
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
      if (parent[next] == -1 && capacity[{cur,next}]) {
        parent[next] = cur;
        int new_flow = min(flow, capacity[{cur,next}]);
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
      capacity[{prev,cur}] -= new_flow;
      capacity[{cur,prev}] += new_flow;
      cur = prev;
    }
  }
  return flow;
}
void add_edge(int u, int v, int c){
  adj[u].push_back(v);
  adj[v].push_back(u);
  capacity[{u,v}] = c;
}
int main()
{
  scanf("%d%d%d", &n, &k, &m);
  for(int i = 0; i < m; i++)
  {
    int u, v;
    scanf("%d%d", &u, &v);
    u--;v--;
    for (int j = 0; j < k; j++)
      add_edge(u * k + j, v * k + (j+1)%k, 1);
  }
  // one based
  int src = n*k, dst = src+1;
  for (int i = 0; i < k; i++){
    add_edge(src, i*k+i, 1);
    add_edge((n-1)*k+i, dst, (int)1e9);
  }
  printf("%d\n", maxFlow(src, dst));
}
