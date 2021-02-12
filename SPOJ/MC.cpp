// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 9;
char x[N], y[N]; 
int n, m;
int dp[N][N], vis[N][N], vid; 
int solve(int i = 0, int j = 0)
{
 if (i == n || j == m)return 15*(n-i) + 30 * (m-j);  
 int &ret = dp[i][j];
 if (vis[i][j] == vid)return ret; 
 vis[i][j] = vid;
 if (x[i] == y[j])return ret = solve(i+1, j+1);
 ret = min(solve(i+1, j) + 15, solve(i, j+1) + 30); 
 return ret;  
}
int main()
{
 while(scanf(" %s", x) && x[0] != '#')
 {
  scanf(" %s", y); 
  n = strlen(x);
  m = strlen(y);
  vid++;
  printf("%d\n", solve());
 }
}
