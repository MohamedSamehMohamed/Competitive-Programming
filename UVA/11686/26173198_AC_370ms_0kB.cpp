// Author : Mohamed sameh
#include <bits/stdc++.h>
typedef long long ll ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
using namespace std ;
const int N = 1e6+1;
int n, m;
bool vis[N];
int v2[N], id;
vector<int> adj[N];
stack<int> st;
bool ok;
void dfs(int u)
{
  vis[u] = 1;
  for (int i : adj[u])
  {
    if (!vis[i])
    dfs(i);
  }
  st.push(u);
}
// 0 not visted yet
// 1 in the path
// 2 out of the path and visted
void check_cycle(int u)
{
  if (v2[u] == 1){ok = 0;return;}
  v2[u] = 1;
  for (int i : adj[u])
  {
    if (v2[i] != 2)check_cycle(i);
  }
  v2[u] = 2;
}
int main()
{
  //freopen("t.txt", "w", stdout);
  while(scanf("%d%d", &n, &m) && n && m)
  {
    ok = 1;
    for (int i = 1; i <= n; i++)adj[i].clear(), vis[i]=0,v2[i]=0;
    for (int i = 0; i < m; i++)
    {
      int u, v;
      scanf("%d%d", &u, &v);
      adj[u].pb(v);
    }
    for (int i = 0; i < n; i++)
    {
      if (!vis[i+1])dfs(i+1);
    }
    ok =1;
    for (int i = 0; i < n; i++)
    {
      if (v2[i+1] != 2)check_cycle(i+1); 
    }
    if (st.empty() || !ok)
    {
      printf("IMPOSSIBLE\n");
      while(!st.empty())st.pop();
    }
    while(!st.empty())
    {
      printf("%d\n", st.top());
      st.pop();
    }
  }
}
