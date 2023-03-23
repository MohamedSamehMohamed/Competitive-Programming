// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 9; 
int n; 
char grid[N][N]; 
bool vis[N][N], can = 0; 
long long dp[N][N], mod = (1LL << 31) - 1;
bool valid(int i, int j)
{
 return min(i, j) >= 0 && max(i, j) < n && grid[i][j] == '.'; 
}
long long solve(int i = 0, int j = 0)
{
 if (!valid(i, j))return 0;
 if (i == j && i == n-1)return can = 1; 
 long long &ret = dp[i][j]; 
 if (~ret)return ret; 
 return ret = (solve(i+1, j) + solve(i, j+1))%mod;
} 
bool dfs(int i = 0, int j = 0)
{
 if (!valid(i, j))return 0;
 if (i == j && i == n-1)return 1; 
 if (vis[i][j])return 0;
 vis[i][j] = 1; 
 if (dfs(i,j+1))return 1;
 if (dfs(i+1,j))return 1;
 if (dfs(i-1,j))return 1;
 if (dfs(i,j-1))return 1;
 return 0; 
}
int main()
{
 scanf("%d", &n);
 for (int i = 0; i < n; i++)
  scanf(" %s", grid[i]); 
 memset(dp, -1, sizeof dp); 
 if (!dfs())
  printf("INCONCEIVABLE\n"); 
 else 
 {
  long long ans = solve(); 
  if (can)
   printf("%lld\n", ans); 
  else 
   printf("THE GAME IS A LIE\n"); 
 }
}
