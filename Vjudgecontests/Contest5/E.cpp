// Author : Mohamed Sameh
// created in: 6:20 PM
#include <bits/stdc++.h>
using namespace std;
class LCA {
  // time is not used at all, just in case of needed it
  int N, LG, _time;
  int node_one_far, node_two_far, diameter;
  vector<vector<int>> kth_parent, adj;
  vector<int> time_in, time_out, level;
  void precompute(int node){
    for (int i = 1; i < LG; i++)
      if (~kth_parent[node][i - 1])
        kth_parent[node][i] = kth_parent[kth_parent[node][i - 1]][i - 1];
  }
  void dfs(int k, int par, int lvl) {
    time_in[k] = ++_time;
    kth_parent[k][0] = par;
    level[k] = lvl;
    precompute(k);
    for (auto it: adj[k]) {
      if (it == par)
        continue;
      dfs(it, k, lvl + 1);
    }
    time_out[k] = _time;
  }
  void dfs2(int k, int par, int lvl) {
    if (lvl > diameter){
      node_two_far = k;
      diameter = lvl;
    }
    for (auto it: adj[k]) {
      if (it == par)
        continue;
      dfs2(it, k, lvl + 1);
    }
  }
public:
  LCA(vector<vector<int>>& edges, int n){
    // edges 0 based
    assert(n > 0);
    N = n;
    LG = 0;
    while ((1<<LG) < N)
      LG++;
    LG++;
    adj = vector<vector<int>>(N);
    kth_parent = vector<vector<int>>(N, vector<int>(LG, -1));
    time_in = vector<int>(N);
    time_out = vector<int>(N);
    level = vector<int>(N);
    _time = 0;
    for (auto it: edges){
      adj[it[0]].push_back(it[1]);
      adj[it[1]].push_back(it[0]);
    }
  }
  void run_dfs(int root = 0){
    level[root] = 0;
    kth_parent = vector<vector<int>>(N, vector<int>(LG, -1));
    _time = 0;
    dfs(root, -1, 0);
  }
  vector<int> get_farthest_two_nodes(){
    // assume first dfs applied
    node_one_far = 0;
    for (int i = 0; i < N; i++){
      if (level[i] > level[node_one_far])
        node_one_far = i;
    }
    diameter = 0;
    dfs2(node_one_far, -1, 0);
    return {node_one_far, node_two_far};
  }
  int get_diameter(){
    return diameter;
  }
  int get_kth_parent(int u, int h) {
    for (int i = LG - 1; i >= 0; i--) {
      if ((h >> i) & 1)
        u = kth_parent[u][i];
    }
    return u;
  }
  int get_lca(int u, int v) {
    if (level[u] < level[v])
      swap(u, v);
    int diff = level[u] - level[v];
    for (int i = LG - 1; i >= 0; i--) {
      if ((1 << i) & diff) {
        u = kth_parent[u][i];
      }
    }
    if (u == v)
      return u;
    for (int i = LG - 1; i >= 0; i--) {
      if (kth_parent[u][i] && kth_parent[u][i] != kth_parent[v][i]) {
        u = kth_parent[u][i];
        v = kth_parent[v][i];
      }
    }
    return kth_parent[u][0];
  }
  int dist(int u, int v) {
    return level[u] + level[v] - 2 * level[get_lca(u, v)];
  }
};
void test(){
  int n, q;
  vector<vector<int>> edges;
  scanf("%d", &n);
  for (int i = 0; i < n-1; i++){
    int u, v;
    scanf("%d%d", &u, &v);
    u--;v--;
    edges.push_back({u, v});
  }
  LCA lca(edges, n);
  LCA lca2(edges, n);
  lca.run_dfs();
  auto two_nodes = lca.get_farthest_two_nodes();
  int diameter = lca.get_diameter();
  lca.run_dfs(two_nodes[0]);
  lca2.run_dfs(two_nodes[1]);

  scanf("%d", &q);
  while (q--){
    int u, h;
    scanf("%d%d", &u, &h);
    u--;
    if (h > diameter){
      printf("-1\n");
      continue;
    }
    bool ok = 0;
    for (int i = 0; i < 2; i++)
    {
      int dist = (i== 0? lca.dist(u, two_nodes[i]): lca2.dist(u, two_nodes[i]));
      if (dist < h) continue;
      ok = 1;
      if (i == 0){
        printf("%d\n", 1 + lca.get_kth_parent(u, h));
      }else {
        printf("%d\n", 1 + lca2.get_kth_parent(u, h));
      }
      break;
    }
    if (!ok)
      printf("-1\n");
  }
}
int main()
{
  test();
}