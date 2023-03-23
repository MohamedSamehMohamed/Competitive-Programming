// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 10, mod = 9901; 
int n, k, bad[N][N], dp[N][N][1<<N], vis[N][N][1<<N], vid, Case;
int mypow(int b, int p)
{
 if (p == 0)return 1;
 if (p &1)return (b * mypow(b, p-1))%mod; 
 int cur = mypow(b, p/2); 
 return (cur * cur)%mod; 
}
int inv(int x)
{
 return mypow(2, mod-2); 
}
int solve(int st, int cur, int msk)
{
 if (msk == (1<<n)-1)
  return !bad[cur][st]; 
 int &ret = dp[st][cur][msk];
 if (vis[st][cur][msk] == vid)return ret; 
 vis[st][cur][msk] = vid; 
 ret = 0; 
 for (int i = 0; i < n; i++)
 {
  if (bad[cur][i] || (msk&(1<<i)))continue; 
  ret = (ret + solve(st, i, msk|(1<<i)))%mod; 
 }
 return ret; 
}
void test()
{
 scanf("%d%d", &n, &k);
 memset(bad, 0, sizeof bad); 
 vid++;
 for (int i = 0; i < k; i++)
 {
  int u, v; 
  scanf("%d%d", &u, &v);
  bad[u-1][v-1] = bad[v-1][u-1] = 1;
 }
 int ans = inv(2) * solve(0, 0, 1) % mod;
 printf("Case #%d: %d\n", ++Case, ans); 
}
int main()
{
 int t; 
 scanf("%d", &t);
 while(t--)
  test(); 
}
