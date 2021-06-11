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
const int N = 3e5+9, M = 998244353;
int n, m;
bool vis[N], seen[N];
ll dp[N][4];
int color[N];
vector<int> adj[N];
void dfs(int u)
{
 vis[u] = 1;
 if (~dp[u][1])return;
 dp[u][1] = dp[u][2] = dp[u][3] = 1;
 for (int v: adj[u])
 {
  if (!vis[v])
  {
  dfs(v);
  dp[u][1] = dp[u][1] * dp[v][2] % M;
  dp[u][2] = dp[u][2] * (dp[v][1] + dp[v][3]) % M;
  dp[u][3] = dp[u][3] * dp[v][2] % M;
  }
 }
}
bool oddCycle(int u)
{
 if (~color[u])return 0;
 queue<int> q;
 q.push(u);
 color[u] = 1;
 bool odd = 0;
 while(!q.empty() && !odd)
 {
  u = q.front();
  q.pop();
  for (int v: adj[u])
  {
   if (color[v] == -1)
   {
    color[v] = 1 - color[u];
    q.push(v);
   }else if (color[v] == color[u])
   {
    odd = 1;break;
   }
  }
 }
 return odd;
}
ll pow(int b, int p)
{
  if (p == 0)return 1;
  if (p&1)return 1LL * b * pow(b, p-1)%M;
  ll cur = pow(b, p/2)%M;
  return cur * cur % M;
}
int main()
{
 int t;
 cin >> t;
 while(t--)
 {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
  {
   adj[i].clear();
   for (int j = 1; j <= 3; j++)dp[i][j] = -1;
   vis[i] = 0;
   color[i] = -1;
  }
  for (int i = 0; i < m; i++)
  {
   int u, v;
   cin >> u >> v;
   adj[u].pb(v);
   adj[v].pb(u);
  }
  bool bad = 0;
  int emptyNodes = 0;
  for (int i = 1; i <= n && !bad; i++)
  {
   if (SZ(adj[i]) == 0)emptyNodes++;
   if (oddCycle(i))bad = 1;
  }
  if (bad)
  {
   cout <<"0\n";
   continue;
  }
  ll ways = (emptyNodes? pow(3, emptyNodes)%M: 1);
  for (int i = 1; i <= n; i++)vis[i] = 0;
  for (int i = 1; i <= n; i++)
  {
   if (SZ(adj[i]) == 0)continue;
   if (!vis[i])
   {
    dfs(i);
    ways = (ways * (dp[i][1] + dp[i][2] + dp[i][3])%M )%M;
   }
  }
  cout << ways << '\n';
 }
}
