// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 31;
int n;
long long dp[N], g[N]; 
int main()
{
 dp[0] = 1;
 g[1] = 1;
 for (int i = 2; i < N; i++)
 {
  dp[i] = dp[i-2] + 2LL * g[i-1]; 
  g[i] = dp[i-1] + g[i-2];
 }
 while(scanf("%d", &n) && ~n)
  printf("%lld\n", dp[n]); 
}
