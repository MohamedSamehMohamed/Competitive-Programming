// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 9; 
char x[N]; 
int dp[N][N], n;
int solve(int l = 0, int r = n-1)
{
 if (l >= r)return 0;
 int &ret = dp[l][r];
 if (~ret)return ret;
 if (x[l] == x[r])return ret = solve(l+1, r-1); 
 ret = 1 + min(solve(l+1, r), solve(l, r-1)); 
 return ret; 
}
int main()
{
 scanf("%d %s", &n, x); 
 memset(dp, -1, sizeof dp);
 printf("%d\n", solve()); 
}
