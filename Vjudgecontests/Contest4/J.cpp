// Author : Mohamed Sameh
// created in: 11:34 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
vector<int> adj[N];
int n;
long long ans;
int sz[N];
long long total[N];
void dfs(int u, int p = -1){
  sz[u] = 1;
  for (int v: adj[u]){
    if (v == p) continue;
    dfs(v, u);
    sz[u] += sz[v];
    total[u] += total[v];
  }
  total[u] += sz[u];
}
void walk(int u, int p = -1){
  if (~p){
    total[u] += total[p] - total[u] - sz[u] - sz[u] + n;
  }
  ans = max(ans, total[u]);
  for (int v: adj[u]){
    if (v == p) continue;
    walk(v, u);
  }
}
void test(){
  scanf("%d", &n);
  for (int i = 1; i < n; i++){
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u-1].push_back(v-1);
    adj[v-1].push_back(u-1);
  }
  ans = 0;
  dfs(0);
  walk(0);
  printf("%lld\n", ans);
}
int main()
{
  test();
}