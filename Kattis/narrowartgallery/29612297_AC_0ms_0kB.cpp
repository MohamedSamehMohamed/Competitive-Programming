// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 205, inf = 1e9;
int a[N][2], n, k; 
int dp[N][N][1<<2], vis[N][N][1<<2], vid;
int solve(int i = 0, int rm = k, int msk = 0)
{
 if (rm == 0)return 0;
 if (i == n)return inf;
 int &ret = dp[i][rm][msk];
 if (vis[i][rm][msk] == vid)return ret;
 vis[i][rm][msk] = vid; 
 ret = solve(i+1, rm, 0); 
 for (int j = 0; j < 2; j++)
 {
  int k = (j+1) % 2; 
  if (msk&(1<<k))continue; 
  ret = min(ret, a[i][j] + solve(i+1, rm-1, 1<<j)); 
 }
 return ret; 
} 
int main()
{
 while(scanf("%d%d", &n, &k) && (n||k))
 {
  vid++;
  int sum = 0;
  for (int i = 0; i < n; i++)
   scanf("%d%d", a[i], a[i]+1), sum += a[i][0] + a[i][1]; 
  printf("%d\n", sum - solve()); 
 }
}
