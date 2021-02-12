// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 102;
char x[N], y[N];
int dp[N][N], vis[N][N], vid, n, m; 
int solve(int i = 0, int j = 0)
{
 if (i == n || j == m)return n+m-i-j;
 int &ret = dp[i][j];
 if (vis[i][j] == vid)return ret; 
 vis[i][j] = vid;
 if (x[i] == y[j])return ret = 1 + solve(i+1, j+1); 
 ret = 1 + min(solve(i+1, j), solve(i, j+1));
 return ret;
}
void build(int i = 0, int j = 0)
{
 if (i == n || j == m)
 {
  while(i != n)printf("%c", x[i++]); 
  while(j != m)printf("%c", y[j++]);
  return;  
 }
 int best = dp[i][j];
 if (x[i] == y[j])
 {
  printf("%c", x[i]); 
  build(i+1, j+1); 
 }else 
 {
  if (best == 1 + solve(i+1, j))
  {
   printf("%c", x[i]); 
   build(i+1, j);
  }
  else
  {
   printf("%c", y[j]); 
   build(i, j+1); 
  }
 }
}
int main()
{
 while(scanf("%s %s", x, y) == 2)
 {
  n = strlen(x);
  m = strlen(y); 
  vid++;
  solve();
  build(); 
  printf("\n");  
 }
}
