// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
int n, m, k, inf = 1e9; 
int a[1001][3], dp[1001][22][80], vis[1001][22][80], vid; 
int solve(int i = 0, int rm1 = n, int rm2 = m)
{
 rm1 = max(0, rm1);
 rm2 = max(0, rm2);
 if (rm1 + rm2 == 0)return 0;
 if (i == k)return inf;
 int &ret = dp[i][rm1][rm2];
 if (vis[i][rm1][rm2] == vid)return ret;
 vis[i][rm1][rm2] = vid;
 ret = solve(i+1, rm1, rm2);
 ret = min(ret, a[i][2] + solve(i+1, rm1-a[i][0], rm2-a[i][1])); 
 return ret;  
}
void test()
{
 scanf("%d%d%d", &n, &m, &k);
 for (int i = 0; i < k; i++)
  for (int j = 0; j < 3; j++)
   scanf("%d", a[i] + j); 
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
