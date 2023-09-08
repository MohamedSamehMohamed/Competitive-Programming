// Author : Mohamed Sameh
// created in: 11:34 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int nodes[N][2];
vector<int> adj[N];
int par[N], n, q;
long long C[N];
void dfs(int u, int p){
  par[u] = p;
  for (int v: adj[u]){
    if (v == p) continue;
    dfs(v, u);
  }
}

void dfs2(int u){
  if (par[u] != -1)
    C[u] += C[par[u]];
  for (int v: adj[u]){
    if (v != par[u])
      dfs2(v);
  }
}
void test(){
  scanf("%d", &n);
  for (int i = 0; i < n-1; i++){
    int u, v;
    scanf("%d%d", &u, &v);
    u--;v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
    nodes[i][0] = u;
    nodes[i][1] = v;
  }
  dfs(0, -1);
  scanf("%d", &q);
  while (q--){
    int t, eIdx, x;
    scanf("%d%d%d", &t, &eIdx, &x);
    eIdx--;
    int u = nodes[eIdx][0];
    int v = nodes[eIdx][1];
    if (t == 2) swap(u, v);
    if (u == par[v]){
      C[0] += x;
      C[v] -= x;
    }else {
      C[u]  += x;
    }
  }
  dfs2(0);
  for (int i = 0; i < n; i++){
    printf("%lld\n", C[i]);
  }
}
int main()
{
  test();
}