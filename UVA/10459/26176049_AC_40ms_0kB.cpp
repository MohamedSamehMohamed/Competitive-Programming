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
const int N = 5009;
vector<int> adj[N];
int dp[N][3];
int dp_node[N][2];
int n;
bool vis[N];
void dfs(int u)
{
  vis[u] = 1;
  int &mx1 = dp[u][0];
  int &mx2 = dp[u][1];
  mx1 = mx2 = 0;
  dp_node[u][0] = dp_node[u][1] = -1;
  for (int i : adj[u])
  {
    if (vis[i])continue;
    dfs(i);
    int cur = dp[i][0]+1;
    if (cur > mx1)
    {
      mx2 = mx1;
      dp_node[u][1] = dp_node[u][0];
      mx1 = cur;
      dp_node[u][0] = i;
    }else if (cur > mx2)
    {
      mx2 = cur;
      dp_node[u][1] = i;
    }
  }
}
void dfs2(int u, int mx_p)
{
  vis[u] = 1;
  dp[u][2] = 0;
  int ch1 = dp_node[u][0];
  int ch2 = dp_node[u][1];
  for (int i : adj[u])
  {
    if (vis[i])continue;
    if (i != ch1 && ch1 != -1)
    dfs2(i, max(mx_p, dp[u][0]) + 1);
    else if (i != ch2 && ch2 != -1)
    dfs2(i, max(mx_p, dp[u][1]) + 1);
    else
    dfs2(i, mx_p+1);
  }
  dp[u][2] = mx_p ;
}
int main()
{
  while(scanf("%d", &n) == 1){
  for (int i = 0; i <= n; i++)adj[i].clear();
  for (int i = 0; i < n; i++)
  {
    int w, v;
    scanf("%d", &w);
    while(w--)
    {
      scanf("%d", &v);
      v--;
      adj[i].pb(v);
      adj[v].pb(i);
    }
  }
  memset(vis, 0, sizeof vis);
  dfs(0);
  memset(vis, 0, sizeof vis);
  dfs2(0, 0);
  int mx = -1, mn = 1e9;
  for (int i = 0; i < n; i++)
  {
    int cur = max({dp[i][0] ,dp[i][1], dp[i][2]});
    mx = max(cur, mx);
    mn = min(mn, cur);
  }
  printf("Best Roots  :");
  for (int i = 0; i < n; i++)
  {
    int cur = max({dp[i][0] ,dp[i][1], dp[i][2]});
    if (cur == mn)
    printf(" %d", i+1);
  }
  printf("\nWorst Roots :");
  for (int i = 0; i < n; i++)
  {
    int cur = max({dp[i][0] ,dp[i][1], dp[i][2]});
    if (cur == mx)
    printf(" %d", i+1);
  }
  printf("\n");
}
}
