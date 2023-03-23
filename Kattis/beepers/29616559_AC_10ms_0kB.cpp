// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
int n, m, k, stx, sty;
int pos[11][2];
int dp[11][1<<11], vis[11][1<<11], vid;
int dist(int i, int j)
{
 return abs(pos[i][0] - pos[j][0]) + abs(pos[i][1]-pos[j][1]); 
}
int solve(int i = 0, int msk = 1)
{
 if (msk == (1<<(k+1))-1)return dist(i, 0); 
 int &ret = dp[i][msk];
 if (vis[i][msk] == vid)return ret; 
 vis[i][msk] = vid;
 ret = 1e9;
 for (int j = 1; j <= k; j++)
  ret = min(ret, dist(i, j) + solve(j, msk|(1<<j))); 
 return ret; 
}
void test()
{
 scanf("%d%d%d%d%d", &n, &m, pos[0], pos[0]+1, &k);
 pos[0][0]--;
 pos[0][1]--; 
 for (int i = 1; i <= k; i++)
  scanf("%d%d", pos[i], pos[i]+1), pos[i][0]--, pos[i][1]--; 
 vid++;
 printf("%d\n", solve()); 
}
int main()
{
 int t; 
 scanf("%d", &t);
 while(t--)
  test(); 
}
