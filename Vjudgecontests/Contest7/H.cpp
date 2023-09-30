// Author : Mohamed Sameh
// created in: 9:57 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int mp[N], n;
vector<int> adj[N];
int color[N], ans[N], sz;
void dfs(int u, int par){
  if(++mp[color[u]] == 1)
    ans[sz++] = u;
  for (int v: adj[u]){
    if (v == par) continue;
    dfs(v, u);
  }
  mp[color[u]]--;
}
void test(){
  scanf("%d", &n);
  for (int i = 0; i < n; i++){
    scanf("%d", color + i);
  }
  for (int i = 0; i < n - 1; i++){
    int u, v;
    scanf("%d%d", &u, &v);
    u--;v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  sz = 0;
  dfs(0, -1);
  sort(ans, ans + sz);
  for (int i = 0; i < sz; i++)
    printf("%d\n", ans[i] + 1);
}
int main()
{
  test();
}