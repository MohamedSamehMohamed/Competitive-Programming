// Author : Mohamed Sameh
// created in: 9:39 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int n, m;
vector<int> adj[N];
int edgeId[N][N];
int rules[N][2];
int par[N];
vector<vector<int>> rulePath;
void dfs(int u, int p){
  par[u] = p;
  for (int v: adj[u]){
    if (par[v] == -1)
      dfs(v, u);
  }
}
void calcPath(int ruleId){
  int from = rules[ruleId][0];
  int to = rules[ruleId][1];
  memset(par, -1, sizeof par);
  dfs(from, from);
  vector<int> path;
  while (par[to] != to){
    int id = edgeId[to][par[to]];
    path.push_back(id);
    to = par[to];
  }
  rulePath.push_back(path);
}
int frq[N];
long long calcWays(int msk){
  memset(frq, 0, sizeof frq);
  for (int i = 0; i < m; i++){
    if ((msk & (1<<i)) == 0) continue;
    for (int j = 0; j < rulePath[i].size(); j++)
      frq[rulePath[i][j]]++;
  }
  int badEdges = 0;
  for (int i = 0; i < n-1; i++){
    if (frq[i])
      badEdges++;
  }
  return (1LL << (n-1-badEdges));
}
void test(){
  scanf("%d", &n);
  for (int i = 0; i < n-1; i++){
    int u, v;
    scanf("%d%d", &u, &v);
    u--;v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
    edgeId[u][v] = edgeId[v][u] = i;
  }
  scanf("%d", &m);
  long long total = 0;
  for (int i = 0; i < m; i++){
    scanf("%d%d", rules[i] + 0, rules[i]+1);
    rules[i][0]--;
    rules[i][1]--;
    calcPath(i);
  }
  for (int msk = 0; msk < (1<<m); msk++){
    int cnt = 0;
    for (int i = 0; i < m; i++)
      cnt += (msk & (1<<i)) != 0;
    long long ways = calcWays(msk);
    if (cnt % 2)
      ways *= -1;
    total += ways;
  }
  printf("%lld\n", total);
}
int main()
{
  test();
}