// Author : Mohamed Sameh
// created in: 6:10 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int n, a, b;
vector<int> adj[N];
int vis[N];
stack<int> path;
vector<int> cycle;
bool cycleDetect;
void dfs(int node, int par = -1){
  vis[node] = 1;
  if (cycleDetect) return;
  path.push(node);
  for (int v: adj[node]){
    if (cycleDetect) break;
    if (v == par) continue;
    if (vis[v] == 0){
      dfs(v, node);
    }else {
      while (path.top() != v){
        cycle.push_back(path.top());
        path.pop();
      }
      cycle.push_back(v);
      cycleDetect = 1;
      return;
    }
  }
  if (!path.empty())
    path.pop();
}
void BFS(int src, vector<int>& dist){
  queue<int> q;
  q.push(src);
  for (int i = 0; i < n; i++)
    dist[i] = -1;
  dist[src] = 0;
  while (!q.empty()){
    src = q.front();
    q.pop();
    for (int v: adj[src]){
      if (dist[v] == -1){
        dist[v] = dist[src] + 1;
        q.push(v);
      }
    }
  }
}
void test(){
  scanf("%d%d%d", &n, &a, &b);
  a--;b--;
  while (!path.empty())
    path.pop();
  cycle.clear();
  cycleDetect = 0;
  for (int i = 0; i < n; i++)
  {
    vis[i] = 0;
    adj[i].clear();
  }
  for (int i = 0; i < n; i++){
    int u, v;
    scanf("%d%d", &u, &v);
    u--;v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(0);
  vector<int> dist_a(n), dist_b(n);
  BFS(a, dist_a);
  BFS(b, dist_b);
  if (a == b){
    printf("NO\n");
    return;
  }
  for (int v: cycle){
    if (dist_b[v] < dist_a[v]){
      printf("YES\n");
      return;
    }
  }
  printf("NO\n");
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}