// Author : Mohamed Sameh
// created in: 6:15 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 +9;
int a[N], n;
vector<int> adj[N];
long long dp[N];
long long ans[N];
int sz[N];
void dfs(int u, int p){
  sz[u] = 1;
  dp[u] = 0;
  for (int v: adj[u]){
    if (v == p) continue;
    dfs(v, u);
    sz[u] += sz[v];
    dp[u] += dp[v];
    dp[u] += 1LL * (a[u] ^ a[v]) * sz[v];
  }
}
void dfs2(int u, int p){
  long long& need = dp[u];
  if (~p){
    long long pValue = dp[p] - dp[u] - 1LL * (a[p] ^ a[u]) * sz[u];
    int pSz = n - sz[u];
    need += pValue + 1LL * pSz * (a[p] ^ a[u]);
  }
  ans[u] = need;
  for (int v: adj[u]){
    if (v == p) continue;
    dfs2(v, u);
  }
}
void test(){
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    adj[i].clear();
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  for (int i = 0; i < n - 1; i++){
    int u, v;
    scanf("%d%d", &u, &v);
    u--;v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(0, -1);
  dfs2(0, -1);
  for (int i = 0; i < n; i++)
    printf("%lld ", ans[i]);
  printf("\n");
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}