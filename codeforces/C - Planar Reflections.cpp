#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7; 
const int N = 1e3 + 9; 
int n, k; 
long long dp[N][N][2]; 
int vis[N][N][2], vid; 
long long solve(int i, int rm, int dir)
{
 if (rm == 0)return 0;
 if (i == -1|| i == n)return 1;
 long long &ret = dp[i][rm][dir]; 
 if (vis[i][rm][dir] == vid)return ret; 
 vis[i][rm][dir] = vid; 
 ret = (solve(i + (dir? -1: 1), rm - 1, !dir)%mod + solve(i + (dir? 1: -1), rm, dir)%mod)%mod; 
 return ret; 
}
void test()
{
 scanf("%d%d", &n, &k);
 vid++;
 printf("%lld\n", solve(0, k, 1) % mod); 
}
int main()
{
 int t; 
 scanf("%d", &t);
 while(t--)
 test();
}
