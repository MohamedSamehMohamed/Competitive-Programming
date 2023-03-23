// Author : Mohamed Sameh
#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define FAST ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
typedef long long ll ;
using namespace std ;
const int N = 1e5+9;
vector<int> adj[N], rev[N];
int n, m;
bool vis[N];
stack<int> order;
int ComId[N];
int id;
set<int> reach[N];
int In[N];
void dfs(int u)
{
  vis[u] = 1;
  for (int i: adj[u])
    if (!vis[i])
      dfs(i);
  order.push(u);
}
void SCC(int u)
{
  vis[u] = 1;
  for (int i: rev[u])
    if (!vis[i])
      SCC(i);
  ComId[u] = id;
}
int DFS(int u, int par)
{
  for (int i: rev[u])
  {
    if (i == par)continue;
    if (ComId[i] != ComId[u])
      In[ComId[u]] += DFS(i, u);
  }
  return In[ComId[u]];
}
int main()
{
  FAST
  cin >> n >> m;
  set<pair<int,int>> dup;
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    if (dup.find({u, v}) == dup.end()){
    adj[u].pb(v);
    rev[v].pb(u);
    dup.insert({u, v});
    }
  }
  for (int i = 1; i <= n; i++)
    if (!vis[i])
      dfs(i);
  memset(vis, 0, sizeof vis);
  int cnt = 0;
  id = 0;
  while(!order.empty())
  {
    int cur = order.top();
    order.pop();
    if (vis[cur])continue;
    SCC(cur);
    cnt++;
    id++;
  }
  for (int i = 1; i <= n; i++)
  {
    In[ ComId[i] ]++;
  }
  vector<int> ans;
  for (int i = 1; i <= n; i++)
    if (In[ComId[i]] > 1)ans.pb(i);
  /*
  for (int i = 1; i <= n; i++)
    for (int j: adj[i])
      if (ComId[j]  != ComId[i])
        {
          In[ComId[j]] += DFS(i, j);
        }
  for (int i = 1; i <= n; i++)
  {
    if (In[ComId[i]] == n )ans.pb(i);
  }*/
  sort(all(ans));
  cout << SZ(ans) <<"\n";
  for (int i : ans)
    cout << i <<" ";
  cout <<"\n";

}
