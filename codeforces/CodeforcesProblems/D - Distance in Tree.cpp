// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 5e4 + 9;
vector<int> adj[N];
int dp[N][505], par[N], n, k; 
void dfs(int u = 0, int p = -1)
{
 par[u] = p;
 dp[u][0] = 1; 
 for (int i: adj[u])
 {
  if (i == p)continue; 
  dfs(i, u); 
  for (int j = 1; j <= k; j++)
   dp[u][j] += dp[i][j-1];
 }
}
int main()
{
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n-1; i++)
  {
   int u, v;
   scanf("%d%d", &u, &v);
   u--;v--;
   adj[u].push_back(v);
   adj[v].push_back(u); 
  }
  dfs();
  long long ans = 0;
  for (int i = 0; i < n; i++)
  {
   ans += 2 * dp[i][k];
   for (int j: adj[i])
   {
    if (j == par[i])continue; 
    for (int len = 1; len < k; len++)
    {
     ans += 1LL*dp[j][len-1] * (dp[i][k-len]-dp[j][k-len-1]);
    }
   }
  }
  printf("%lld\n", (ans>>1LL));  
}
