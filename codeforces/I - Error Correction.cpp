// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
const int N = 505, INF = 1e5;
int n, sz;
string x[N];
vector<int> adj[2 * N];
int cap[2*N][2*N];
int par[2*N];
void add(int u, int v, int c)
{
  adj[u].push_back(v);
  adj[v].push_back(u);
  cap[u][v] = c;
}
int count(int idx)
{
  int cnt = 0;
  for (int i = 0; i < sz; i++)
    for (int j = i+1; j < sz; j++)
      cnt += (x[idx][i] > x[idx][j]);
  return cnt;
}
int diff(int u, int v)
{
  int dif = 0;
  for (int i = 0; i < sz; i++)
    dif += (x[u][i] != x[v][i]);
  return dif;
}
int bfs(int src, int sink)
{
  memset(par, -1, sizeof par);
  par[src] = -2;
  queue<pair<int,int>> q;
  q.push({src, INF});
  while(!q.empty())
  {
    int cur = q.front().first;
    int cst = q.front().second;
    q.pop();
    for (int v: adj[cur])
    {
      if (par[v] == -1 && cap[cur][v])
      {
        par[v] = cur;
        int new_flow = min(cst, cap[cur][v]);
        if (v == sink)
          return new_flow;
        q.push({v, new_flow});
      }
    }
  }
  return 0;
}
int maxflow(int src, int sink)
{
  int flow = 0;
  int cur_flow;
  while(cur_flow = bfs(src, sink))
  {
    flow += cur_flow;
    int cur = sink;
    while(cur != src)
    {
      int prv = par[cur];
      cap[prv][cur] -= cur_flow;
      cap[cur][prv] += cur_flow;
      cur = prv;
    }
  }
  return flow;
}
int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> x[i];
  sz = x[0].size();
  vector<int> left, right;
  for (int i = 0; i < n; i++)
  {
    if (count(i) % 2)
      left.push_back(i);
    else
      right.push_back(i);
  }
  int src = left.size() + right.size();
  int sink= src + 1;
  for (int i = 0; i < left.size(); i++)
    add(src, i, 1);
  for (int i = 0; i < right.size(); i++)
    add(i+left.size(), sink, 1);
  for (int i = 0; i < left.size(); i++)
    for (int j = 0; j < right.size(); j++)
      if (diff(left[i], right[j]) == 2)
        add(i, j + left.size(), 1);
  cout << n - maxflow(src, sink) << '\n';
}
