// Author : Mohamed Sameh
// created in: 8:18 AM
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int n, m, k;
vector<int> adj[N];
int A[N], B[N];
void dijkstra(int src, vector<int>& dist){
  int inf = 1e9;
  dist = vector<int>(n, inf);
  dist[src] = 0;
  priority_queue<vector<int>> pq;
  pq.push({0, src});
  while (pq.size() > 0){
    src = pq.top()[1];
    pq.pop();
    for (int v: adj[src]){
      if (dist[v] > dist[src] + 1){
        dist[v] = dist[src] + 1;
        pq.push({-dist[v], v});
      }
    }
  }
}
int maxSub[N][2];
vector<int> dist[2];
int vis[N], vid;
void walk(int st, int j, int add, int index, int par = -1){
  vid++;
  queue<int> bfs;
  bfs.push(st);
  vis[st] = vid;
  for (int i = 0; i < n; i++)
    maxSub[i][index] = 0;

  maxSub[st][index] = A[st] == B[j];
  while (!bfs.empty()){
    st = bfs.front();
    bfs.pop();
    bool first = true;
    for (int v: adj[st]){
      if (dist[index][v] == dist[index][st] - 1){
        assert(vis[v] == vid);
        // v is my parent in the path to end
        //printf("node %d %d\n", st + 1, v + 1);
        int cur = maxSub[v][index];
        if (add == 1)
        {
          if (cur < k && B[cur] == A[st])
            cur++;
        }else {
          if (cur < k && B[k-cur-1] == A[st] )
            cur++;
        }
        if (first)
          maxSub[st][index] = cur;
        first = 0;
        maxSub[st][index] = min(cur, maxSub[st][index]);
      }
      if (vis[v] != vid)
      {
        bfs.push(v);
        vis[v] = vid;
      }
    }
  }
}
void test(){
  scanf("%d%d%d", &n, &m, &k);
  vector<vector<int>> edges;
  for (int i = 0; i < m; i++){
    int u, v;
    scanf("%d%d", &u, &v);
    edges.push_back({u-1, v-1});
    adj[u-1].push_back(v-1);
    adj[v-1].push_back(u-1);
  }
  for (int i = 0; i < n; i++){
    scanf("%d", A+i);
    A[i]--;
  }
  for (int i = 0; i < k; i++){
    scanf("%d", B+i);
    B[i]--;
  }
  dijkstra(0, dist[0]);
  dijkstra(n-1, dist[1]);
  // int st, int j, int add, int index, int par = -1
  walk(0, 0, 1, 0);
  walk(n-1, k-1, -1, 1);

  bool ok = 1;
  for (int i = 0; i < edges.size(); i++){
    int u = edges[i][0];
    int v = edges[i][1];
    //printf("edge: %d - %d\n", u+1, v+1);
    for (int _ = 0; _ < 2; _++){
      //printf("%d %d %d\n", dist1[u], dist2[v], dist1[n-1]);
      if (dist[0][u] + dist[1][v] + 1 == dist[0][n-1]){
        //printf("%d %d\n", maxSub[u][0], maxSub[v][1]);
        if (maxSub[u][0] + maxSub[v][1] < k)
          ok = 0;
      }
      swap(u, v);
    }
  }
  if (ok)
    printf("Yes\n");
  else
    printf("No\n");
}
int main()
{
  test();
}