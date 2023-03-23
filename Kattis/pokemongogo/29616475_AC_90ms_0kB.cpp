// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 20;
int a[N+1][3], MSK;
int dp[N+1][1<<N], n;
char x[30];  
int dist(int i, int j)
{
 return abs(a[i][0] - a[j][0]) + abs(a[i][1]-a[j][1]); 
}
int solve(int i = 0, int msk = 0)
{
 if (msk == MSK)return dist(i, 0);
 int &ret = dp[i][msk];
 if (~ret)return ret;
 ret = 1e9;
 for (int j = 1; j <= n; j++)
  ret = min(ret, dist(i, j) + solve(j, msk|(1<<a[j][2]))); 
 return ret; 
}
int main()
{
 memset(dp, -1, sizeof dp); 
 scanf("%d", &n);
 map<string, int> mp;
 for (int i = 1; i <= n; i++)
 {
  scanf("%d%d %s", a[i], a[i]+1, x);
  string str = x;
  if (mp.find(x) == mp.end())
  {
   int sz = mp.size();
   mp[x] = sz; 
  }
  a[i][2] = mp[x];
  MSK = max(MSK, mp[x]+1); 
 }
 MSK = (1<<MSK) - 1;
 printf("%d\n", solve()); 
}
