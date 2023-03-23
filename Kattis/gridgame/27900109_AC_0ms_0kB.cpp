// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
const int N = 80, INF = 1e9;
int n;
int a[N][N];
vector<int> adj[N];
int cap[N][N];
int par[N];
int bfs(int src, int des)
{
    memset(par, -1, sizeof par);
    par[src] = -2;
    queue<pair<int, int>> q;
    q.push({src, INF});
    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (par[next] == -1 && cap[cur][next]) {
                par[next] = cur;
                int new_flow = min(flow, cap[cur][next]);
                if (next == des)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }
    return 0;
}
int maxflow(int src, int des)
{
  int flow = 0;
  int new_flow;

  while (new_flow = bfs(src, des))
  {
    flow += new_flow;
    int cur = des;
    while (cur != src) {
        int prev = par[cur];
        cap[prev][cur] -= new_flow;
        cap[cur][prev] += new_flow;
        cur = prev;
    }
  }
  return flow;
}
bool can(int mn)
{
  memset(cap, 0, sizeof cap);
  for (int i = 0; i < N; i++)adj[i].clear();
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (a[i][j] >= mn)
      {
        cap[i+1][j+n+1] = 1;
        adj[i+1].push_back(j+n+1);
        adj[j+n+1].push_back(i+1);
      }
  for (int i = 1; i <= n; i++)
  {
    cap[0][i] = 1;
    adj[0].push_back(i);
  }
  for (int i = n+1; i <= 2 * n; i++)
  {
    cap[i][2*n+1] = 1;
    adj[i].push_back(2*n+1);
  }
  return maxflow(0, 2*n+1) >= n;
}
int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      scanf("%d", a[i] + j);
  int l = 1, r = 1e6, m, ans = 1;
  while(l <= r)
  {
    m = (l+r)>>1;
    if (can(m))
    {
      ans = m;
      l = m + 1;
    }else
    r = m-1;
  }
  printf("%d\n", ans);
}
