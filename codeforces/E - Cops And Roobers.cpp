// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
const int N = 35;
long long INF = 1e11;
int n, m, c;
string g[N];
int cost[N];
long long cap[2*N*N][2*N*N];
int par[2*N*N];
vector<int> adj[2*N*N];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
void addEdge(int u, int v, long long c = INF)
{
  adj[u].push_back(v);
  adj[v].push_back(u);
  cap[u][v] = c;
}
long long bfs(int s, int t) {
    memset(par, -1, sizeof par);
    par[s] = -2;
    queue<pair<int, long long>> q;
    q.push({s, INF});
 
    while (!q.empty()) {
        int cur = q.front().first;
        long long flow = q.front().second;
        q.pop();
        for (int next : adj[cur]) {
            if (par[next] == -1 && cap[cur][next]) {
                par[next] = cur;
                long long new_flow = min(flow, cap[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }
    return 0;
}
 
long long maxflow(int s, int t) {
    long long flow = 0;
    long long new_flow;
    while (new_flow = bfs(s, t)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = par[cur];
            cap[prev][cur] -= new_flow;
            cap[cur][prev] += new_flow;
            cur = prev;
        }
    }
 
    return flow;
}
int main()
{
  cin >> m >> n >> c;
  for (int i = 0; i < n; i++)
    cin >> g[i];
  int src, sink = 2 * n * m;
  for (int i = 0; i < c; i++)
  cin >> cost[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
    {
      int u = i * n + j;
      int v = u + n*m;
      if (g[i][j] == 'B') src = v;
      if (i == 0 || i == n-1 || j == 0 || j == m-1)
        addEdge(v, sink);
      if (g[i][j] == '.')
        addEdge(u, v);
      else if (g[i][j] != 'B'){
        addEdge(u, v, cost[g[i][j] - 'a']);
      }
      for (int k = 0; k < 4; k++)
      {
        int nx = dx[k] + i;
        int ny = dy[k] + j;
        if (min(nx, ny) < 0 || nx >= n || ny >= m)continue;
        addEdge(v, nx * n + ny);
      }
    }
  long long ans = maxflow(src, sink);
  if (ans >= INF)
    ans = -1;
  printf("%lld\n", ans);
}
