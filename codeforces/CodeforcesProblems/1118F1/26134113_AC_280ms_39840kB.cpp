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
const int N = 3e5+1;
int color[N], dep[N], n, R, B;
vector<int> adj[N];
vector<pair<int,int>> edges;
int dp[N][2];
void dfs(int u = 0, int par = 0)
{
  if(color[u])dp[u][ color[u]-1 ]++;
  dep[u] = dep[par]+1;
  for (int i : adj[u])
  {
    if (par == i)continue;
    dfs(i, u);
    dp[u][0] += dp[i][0];
    dp[u][1] += dp[i][1];
  }
}
int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++){
    scanf("%d", color+ i);
    if (color[i] == 1)R++;
    else if (color[i] == 2)B++;
  }
  for (int i = 0 ; i < n-1; i++)
  {
    int u, v;
    scanf("%d%d", &u, &v);
    u--;v--;
    adj[u].pb(v);
    adj[v].pb(u);
    edges.pb({u, v});
  }
  dfs();
  int ans =0;
  for (int i = 0; i < SZ(edges); i++)
  {
    int u = edges[i].f ;
    int v = edges[i].s ;
    if (dep[u] > dep[v])swap(u, v);
    ans+=((dp[v][0] == R && dp[v][1] == 0) ||(dp[v][0] == 0 && dp[v][1] == B) );
  }
  printf("%d\n", ans);

}
