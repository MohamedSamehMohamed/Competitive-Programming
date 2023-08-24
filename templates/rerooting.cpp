#include <bits/stdc++.h>
using namespace std;
template <typename Cost>
struct Edge {
  int src, to;
  Cost cost;
  Edge(int s, int t, Cost c = 1) : src(s), to(t), cost(c) {}
  operator int() const { return to; }
};
template <typename Cost>
struct Graph : vector<vector<Edge<Cost>>> {
  Graph(int n) : vector<vector<Edge<Cost>>>(n) {}
  void add_edge(int s, int t, Cost c = 1) { (*this)[s].emplace_back(s, t, c); }
};
template <typename Cost, typename Data, Data (*merge)(Data, Data), Data (*e)(),
          Data (*leaf)(), Data (*apply)(Data, int, int, Cost)>
struct Rerooting : Graph<Cost> {
  vector<Data> dp, memo;
  Rerooting(int n) : Graph<Cost>::Graph(n) {}
  vector<Data> run() {
    memo.resize((*this).size(), e());
    dp.resize((*this).size());
    dfs1(0, -1);
    dfs2(0, -1, e());
    return dp;
  }
  void dfs1(int c, int p) {
    bool upd = false;
    for (Edge<Cost> &d : (*this)[c]) {
      if (d == p) continue;
      dfs1(d, c);
      upd = true;
      memo[c] = merge(memo[c], apply(memo[d], d, c, d.cost));
    }
    if (!upd) memo[c] = leaf();
  }
  void dfs2(int c, int p, const Data &val) {
    vector<Data> ds{val};
    for (Edge<Cost> &d : (*this)[c]) {
      if (d == p) continue;
      ds.push_back(apply(memo[d], d, c, d.cost));
    }
    int n = ds.size(), idx = 1;
    vector<Data> head(n + 1, e()), tail(n + 1, e());
    for (int i = 0; i++ < n;) head[i] = merge(head[i - 1], ds[i - 1]);
    for (int i = n; i-- > 0;) tail[i] = merge(tail[i + 1], ds[i]);
    dp[c] = head[n];
    for (Edge<Cost> &d : (*this)[c]) {
      if (d == p) continue;
      Data sub = merge(head[idx], tail[idx + 1]);
      dfs2(d, c, apply(sub, c, d, d.cost));
      idx++;
    }
  }
};
vector<int> D;
using Data = long long;
using Cost = long long;
Data merge(Data a, Data b) { return max(a, b); }
Data e() { return 0; }
Data leaf() { return 0; }
Data apply(Data a, int c, int, Cost w) { return max<Data>(a, D[c]) + w; }
int main()
{
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  #endif 
  int n; 
  scanf("%d", &n); 
  D.resize(n);
  Rerooting<Cost, Data, merge, e, leaf, apply> g(n);
  
  for(int i = 0; i < n-1; i++)
  {
    int u, v, c; 
    scanf("%d%d%d", &u, &v, &c); 
    u--;v--;
    g.add_edge(u, v, c);
    g.add_edge(v, u, c); 
  }
  for(int i = 0; i < n; i++)
    scanf("%d", &D[i]); 
  auto ans = g.run();
  for(auto& i: ans)
    printf("%lld\n", i);

}   