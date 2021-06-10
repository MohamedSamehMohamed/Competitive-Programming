#include<bits/stdc++.h>
using namespace std; 
const int N = 102, mod = 1e9 + 7;
int dp[N][N][2*N];
int solve(int rm, int p, int x)
{
 if (rm == 0)
  return (p == 0 && x != 0); 
 int &ret = dp[rm][p][x]; 
 if (~ret)return ret; 
 ret = 0; 
 for (int tk = 1; tk <= rm; tk++)
  ret = (ret + solve(rm - tk, p - 1, (x^tk))%mod )%mod; 
 return ret;  
}  
int main()
{  
 int t; 
 scanf("%d", &t);
 memset(dp, -1, sizeof dp); 
 while(t--)
 {
  int n; 
  scanf("%d", &n);
  int ans = 0; 
  for (int i = 1; i <= n; i++)
  {
   ans = (ans + solve(n, i, 0)%mod)%mod; 
  }
  printf("%d\n", ans); 
 }
}
