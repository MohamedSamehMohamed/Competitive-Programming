// Author : Mohamed Sameh
// created in: 5:21 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
vector<int> adj[N];
int vis[N], c[N], vid, n, k;
void dfs(int u){
  vis[u] = vid;
  long long cost = (adj[u].size() > 0? 0: c[u]);
  for (int v: adj[u]){
    if (vis[v] != vid)
      dfs(v);
    cost += c[v];
  }
  c[u] = min(1LL * c[u], cost);
}
void test(){
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++)
    adj[i].clear();
  vid++;

  for (int i = 0; i < n; i++){
    scanf("%d", c + i);
  }
  for (int i = 0; i < k; i++){
    int id;
    scanf("%d", &id);
    c[id-1] = 0;
  }
  for (int i = 0; i < n; i++){
    int m, id;scanf("%d", &m);
    while (m--){
      scanf("%d", &id);
      adj[i].push_back(id - 1);
    }
  }
  for (int i = 0; i < n; i++){
    if (vis[i] != vid)
      dfs(i);
  }
  for (int i = 0; i < n; i++)
  {
    printf("%d ", c[i]);
  }
  printf("\n");
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}