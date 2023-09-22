// Author : Mohamed Sameh
// created in: 7:51 PM
#include <bits/stdc++.h>
using namespace std;

class Counting
{
public:
  int mod;
  bool has_mod = false;
  Counting(int _mod): mod(_mod), has_mod(true){}
  Counting(){}
  vector<int> fact, inv;
  long long take_mod(long long x)
  {
    x %= mod;
    if (x < 0) x += mod;
    return x;
  }
  long long mul(long long x, long long y)
  {
    if (!has_mod)
      return x * y;
    x = take_mod(x);
    y = take_mod(y);
    return take_mod(x * y);
  }
  long long sub(long long x, long long y)
  {
    if (!has_mod)
      return x - y;
    x = take_mod(x);
    y = take_mod(y);
    return take_mod(x - y);
  }

  long long add(long long x, long long y)
  {
    if (!has_mod)
      return x + y;
    x = take_mod(x);
    y = take_mod(y);
    return take_mod(x + y);
  }
  long long fast(long long b, long long p)
  {
    if (p == 0)return 1;
    if (p&1)return mul(b, fast(b, p-1));
    long long cur = fast(b, p/2);
    return mul(cur, cur);
  }
  void Prepare(int n)
  {
    if (fact.empty())fact.push_back(1);
    if (inv.empty())inv.push_back(fast(1, mod - 2));
    int sz = fact.size();
    while(sz <= n)
    {
      fact.push_back(mul(sz, fact.back()));
      inv.push_back(fast(fact.back(), mod - 2));
      sz++;
    }
  }
  long long Fact(int n)
  {
    Prepare(n);
    return fact[n];
  }
  long long nPr(int n, int r)
  {
    if (n < r)return 0;
    Prepare(n);
    return mul(fact[n], inv[n-r]);
  }
  long long nCr(int n, int r)
  {
    if (n < r)
      return 0;
    Prepare(n);
    return mul(mul(fact[n], inv[n-r]), inv[r]);
  }
  long long div(int a, int b){
    return mul(a, fast(b, mod - 2));
  }
};
const int N = 2e5 + 9, mod = 998244353;
vector<int> adj[N], adj_rev[N], order, component;
int used[N], n;
int par[N], input[N];
int get_par(int u){
  return par[u] == u? u: par[u] = get_par(par[u]);
}
void con(int u, int v){
  u = get_par(u);
  v = get_par(v);
  if (u == v) return;
  par[u] = v;
}
bool same_par(int u, int v){
  return get_par(u) == get_par(v);
}
void dfs1(int v) {
  used[v] = true;
  for (auto u : adj[v])
    if (!used[u])
      dfs1(u);
  order.push_back(v);
}
void dfs2(int v) {
  used[v] = true;
  component.push_back(v);
  for (auto u : adj_rev[v])
    if (!used[u])
      dfs2(u);
}
void SplitComponent()
{
  memset(used, 0, sizeof used);
  for (int i = 0; i < n; i++)
    if (!used[i])
      dfs1(i);
  memset(used, 0, sizeof used);
  reverse(order.begin(), order.end());
  Counting c(mod);
  map<int, int> mp;
  int ans = 1;
  for (auto v : order)
  {
    if (used[v])continue;
    dfs2(v);
    // component contain cur SCC
    bool take = 1;
    if (component.size() == 1){
      if (input[component[0]] != component[0])
      {
        take = 0;
      }
    }
    component.clear();
    if (take)
      ans = c.mul(ans, 2);
  }
  ans = c.sub(ans, 1);
  printf("%d\n", ans);
}
void test(){
  //iota(par, par + N, 0);
  scanf("%d", &n);
  //vector<vector<int>> same_out(n+1);
  for (int i = 0; i < n; i++){
    int to;
    scanf("%d", &to);
    input[i] = to-1;
    //same_out[to].push_back(i);
    // i -> to-1
    adj[i].push_back(to-1);
    adj_rev[to-1].push_back(i);
  }
  //for (int i = 1; i <= n; i++)
    //for (int j = 1; j < same_out[i].size(); j++)
      //con(same_out[i][j], same_out[i][j-1]);

  SplitComponent();
}
int main()
{
  test();
}