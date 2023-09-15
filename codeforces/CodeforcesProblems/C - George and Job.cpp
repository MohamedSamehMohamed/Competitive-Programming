// Author : Mohamed sameh
#include <bits/stdc++.h>
typedef long long ll ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
using namespace std ;
const int N = 5e3+9;
int n, m, k;
ll pre[N];
ll dp[N][N];
ll solve(int i = 1, int rm = k)
{
 if (i > n)return rm == 0? 0: -1e12;
 ll &ret = dp[i][rm];
 if (~ret)return ret; 
 ret = solve(i+1, rm);
 if (rm > 0 && i + m - 1 <= n)ret = max(ret, pre[i + m - 1] - pre[i-1] + solve(i + m, rm - 1));
 return ret;
}
int main()
{
 memset(dp, -1, sizeof dp);
 cin >> n >> m >> k;
 for (int i = 1; i <= n; i++)
 {
  cin >> pre[i];
  pre[i] += pre[i-1];
 }
 cout << solve() << "\n";
}
