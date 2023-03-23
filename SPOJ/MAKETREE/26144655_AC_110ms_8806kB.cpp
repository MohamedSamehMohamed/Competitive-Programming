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
const int N = 1e5;
int n, k;
vector<int> adj[N];
stack<int> sk;
bool vis[N];
int ans[N];
void dfs(int u)
{
  vis[u] = 1;
  for (int i : adj[u])
    if (!vis[i])dfs(i);
  sk.push(u);
}
int main()
{
  scanf("%d%d", &n, &k);
  for (int i = 0; i < k; i++)
  {
    int w, v;
    scanf("%d", &w);
    while (w--)
    {
      scanf("%d", &v);
      v--;
      if (v < k)
      {
        adj[i].pb(v);
      }
    }
  }
  for (int i = 0; i < k; i++)
  {
    if (!vis[i])dfs(i);
  }
  int lst = -1;

  while (!sk.empty())
  {
    int cur = sk.top();
    sk.pop();
    if (~lst)ans[cur] = lst+1;
    lst = cur;
  }
  for (int i = k; i < n; lst = i, i++)ans[i] = lst+1;
  for (int i = 0; i < n; i++)printf("%d\n", ans[i]);
}
