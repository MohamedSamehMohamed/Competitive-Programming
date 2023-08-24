#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int n;
bool vis[N];
vector<int> adj[N];
void init(){
  for (int i = 0; i < n; i++)
  {
    adj[i].clear();
    vis[i] = 0;
  }
}
bool hasOneDegree;
void dfs(int u){
  hasOneDegree|= (adj[u].size() == 1);
  vis[u] = 1;
  for (int v: adj[u]){
    if (vis[v]) continue;
    dfs(v);
  }
}
void solve(){
  scanf("%d", &n);
  init();
  for (int i = 0; i < n; i++){
    int v;
    scanf("%d", &v);
    adj[i].push_back(v-1);
    adj[v-1].push_back(i);
  }
  for (int i = 0; i < n; i++){
    sort(adj[i].begin(), adj[i].end());
    adj[i].erase(unique(adj[i].begin(), adj[i].end()), adj[i].end());
  }
  int numOfCom = 0;
  int numOfOneDeg = 0;
  for(int i = 0; i < n; i++){
    if (vis[i] == 0){
      hasOneDegree = 0;
      dfs(i);
      numOfCom++;
      numOfOneDeg += hasOneDegree;
    }
  }
  printf("%d %d\n", numOfCom - max(0, numOfOneDeg - 1) , numOfCom);
}
int main(){
  int t;
  scanf("%d", &t);
  while (t--){
    solve();
  }
}