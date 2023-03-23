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
const int N = 2e5+9;
int n;
vector<int> adj[N];
bool vis[N];
stack<int> ans;
void dfs(int u)
{
  vis[u] = 1;
  for (int i : adj[u])
  {
    if (vis[i])continue;
    dfs(i);
  }
  ans.push(u);
}
int main()
{
  scanf("%d", &n);
  vector<pair<int,int>> vec;
  for (int i = 0; i < n; i++)
  {
    int u, v;
    scanf("%d%d", &u, &v);
    u--;v--;
    vec.pb({u, v});
  }
  for (int i = 0; i < n; i++)
  {
    int u = vec[i].f;
    int v = vec[i].s;
    if (vec[u].f == v || vec[u].s == v)
    {
      adj[i].pb(u);
      adj[u].pb(v);
    }else
    {
      adj[i].pb(v);
      adj[v].pb(u);
    }
  }
  for (int i = 0; i < n; i++)
  {
    if (!vis[i])dfs(i);
  }
  while(!ans.empty())
  {
    printf("%d ", ans.top()+1);
    ans.pop();
  }
  printf("\n");
}
