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
bool dfs()
{
 queue<pair<int,int>> q; 
 q.push({0, 0});
 vis[0][0] = 1; 
 while(!q.empty())
 {
  int i, j;
  tie(i, j) = q.front();
  q.pop(); 
  if (i == j && i == n-1)return 1; 
  for (int dx = -1; dx <= 1; dx++)
    for (int dy = -1; dy <= 1; dy++)
    {
     if (abs(dx) == abs(dy))continue; 
     if (valid(i + dx, j + dy) && !vis[i + dx][j + dy])
     {
      vis[i + dx][j + dy] = 1; 
      q.push({i + dx, j + dy}); 
     }
    }
 }
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
