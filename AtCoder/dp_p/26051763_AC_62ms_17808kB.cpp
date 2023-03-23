// Author : Mohamed Sameh
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
const int N = 1e5, M = 1e9 + 7;
vector<int> adj[N];
int n;
ll dp[N][2];
void solve(int node = 0, int par = 0)
{
  dp[node][0] = dp[node][1] = 1;
  for (int i : adj[node])
  {
    if (i == par)continue;
    solve(i, node);
    dp[node][0] = (dp[node][0] * (dp[i][1] + dp[i][0])%M)%M;
    dp[node][1] = (dp[node][1] * dp[i][0])%M;
  }
}
int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n-1; i++)
  {
    int u, v;
    scanf("%d%d", &u, &v);
    u--;v--;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  solve();
  printf("%d\n", (dp[0][0] + dp[0][1])%M);
}
