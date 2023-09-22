#include<bits/stdc++.h>
using namespace std;
class LCA {
  // time is not used at all, just in case of needed it
  int N, LG, _time;
  int node_one_far, node_two_far, diameter;
  vector<vector<int>> kth_parent, adj;
  vector<int> time_in, time_out, level;
  void precompute(){
    for (int j = 0; j < N; j++)
      precompute(j);
  }
  void precompute(int node){
    for (int i = 1; i < LG; i++)
        if (~kth_parent[node][i - 1])
          kth_parent[node][i] = kth_parent[kth_parent[node][i - 1]][i - 1];
  }
  void dfs(int k, int par, int lvl) {
    time_in[k] = ++_time;
    kth_parent[k][0] = par;
    level[k] = lvl;
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
    dfs(root, -1, 0);
    precompute();
  }
  void get_farthest_two_nodes(){
    // assume first dfs applied
    node_one_far = 0;
    for (int i = 0; i < N; i++){
      if (level[i] > level[node_one_far])
        node_one_far = i;
    }
    diameter = 0;
    dfs2(node_one_far, -1, 0);
  }
  void update_two_farthest_nodes(int node1, int node2){
    node_one_far = node1;
    node_two_far = node2;
  }
  vector<int> get_two_farthest_nodes(){
    return {node_one_far, node_two_far};
  }
  int get_diameter(){
    return diameter;
  }
  void add_to_tree(int u, int v){
    // u was exists
    // 0 based
    adj[u].push_back(v);
    adj[v].push_back(u);
    dfs(v, u, level[u] + 1);
    precompute(v);
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
int main(){
}