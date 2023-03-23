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
const int N = 109;
vector<int> adj[N], rev[N];
stack<int> order;
int n, m, idx, id;
int vis[N];
void dfs(int u)
{
  vis[u] = id;
  for (int i : adj[u])
    if (vis[i] != id)
      dfs(i);
  order.push(u);
}
void dfs2(int u)
{
  vis[u] = id;
  for (int i: rev[u])
    if (vis[i] != id)
      dfs2(i);
}
char arr[N];
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
  {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
      adj[i].clear();
      rev[i].clear();
    }
    for (int i = 0; i < n; i++)
    {
      scanf("%s", arr);
      for (int j = 0; j < n; j++)
        if (arr[j] == 'Y')
          {
            adj[i].pb(j);
            rev[j].pb(i);
          }
    }
    id++;
    for (int i = 0; i < n; i++)
      if (vis[i] != id)
        dfs(i);
    id++;
    idx=0;
    while(!order.empty())
    {
      int cur = order.top();
      order.pop();
      if (vis[cur] == id)continue;
      idx++;
      dfs2(cur);
    }
    printf("%d\n", idx);
  }
}
