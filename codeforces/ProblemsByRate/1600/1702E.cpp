// Author : Mohamed Sameh
// created in: 8:22 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
vector<int> adj[N];
int n, c[N], deg[N];
bool bi(int u){
  c[u] = 0;
  queue<int> q;
  q.push(u);
  while (!q.empty()){
    u = q.front();
    q.pop();
    for (int v: adj[u]){
      if (c[v] == -1){
        c[v] = 1 - c[u];
        q.push(v);
      }else if (c[v] == c[u])
        return 0;
    }
  }
  return 1;
}
void test(){
  scanf("%d", &n);
  for (int i = 0; i < n; i++){
    adj[i].clear();
    c[i] = -1;
    deg[i] = 0;
  }
  bool ok = 1;
  for (int i = 0; i < n; i++){
    int u, v;
    scanf("%d%d", &u, &v);
    u--;v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
    deg[u]++;
    deg[v]++;
    ok &= max(deg[u], deg[v]) <= 2;
  }

  for (int i = 0; i < n; i++){
    if (c[i] == -1)
      ok &= bi(i);
  }
  printf("%s\n", (ok? "yes": "no"));
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}
