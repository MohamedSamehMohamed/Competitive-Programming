#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int n, k, c;
vector<int> adj[N];
int dist[N], farest[N][2], best[N];
void init(){
  for (int i = 0; i < n; i++)
    adj[i].clear();
}
void dfs(int u, int p = -1){
  farest[u][0] = farest[u][1] = 0;
  if (~p)
    dist[u] = dist[p] + 1;
  for (int v: adj[u]){
    if (v == p)
      continue;
    dfs(v, u);
    int currentFar = 1 + farest[v][0];
    if (currentFar > farest[u][0]){
      farest[u][1] = farest[u][0];
      farest[u][0] = currentFar;
    }else if(currentFar > farest[u][1])
      farest[u][1] = currentFar;
  }
}
void dfs2(int u, int p = -1, int len = 0){
  best[u] = len;
  if (~p){
    int pFar = farest[p][0];
    if (pFar == farest[u][0] + 1)
      pFar = farest[p][1];
    best[u] = max(best[u], 1 + pFar);
    best[u] = max(best[u], best[p] + 1);
  }
  for (int v: adj[u]){
    if (v == p) continue;
    dfs2(v, u, len + 1);
  }
}
void solve(){
  scanf("%d%d%d", &n, &k, &c);
  init();
  for (int i = 1; i < n; i++){
    int u, v;
    scanf("%d%d", &u, &v);
    u--;v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(0);
  dfs2(0);
  long long ans = 0;
  for (int i = 0; i < n; i++){
    long long needToReRoot = 1LL * dist[i] * c;
    long long maxPathCost = 1LL * max(farest[i][0], best[i]) * k;
    ans = max(ans, maxPathCost - needToReRoot);
  }
  printf("%lld\n", ans);
}
int main(){
  int t;
  scanf("%d", &t);
  while (t--){
    solve();
  }
}