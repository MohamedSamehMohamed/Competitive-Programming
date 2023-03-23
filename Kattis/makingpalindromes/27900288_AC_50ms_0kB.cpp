// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
const int N = 202, mod = 1e9 + 7;
int dp[N][N][N];
int n;
string x;
int solve(int i = 0, int l = 0, int r = n-1)
{
  if (i == n)
    return (l > r? 1: 0);
  int &ret = dp[i][l][r];
  if (~ret)return ret;
  ret = 0;
  if (l>r)
  {
    ret = (1LL * 26 * solve(i+1, l, r))%mod;
    return ret;
  }
  if (x[l] == x[r])
  {
    ret = (1LL * 25 * solve(i+1, l, r))%mod;
    ret = (ret + 1LL * solve(i+1, l+1, r-1))%mod;
  }else
  {
    ret = (1LL * 24 * solve(i+1, l, r))%mod;
    ret = (ret + 1LL * solve(i+1, l+1, r))%mod;
    ret = (ret + 1LL * solve(i+1, l, r-1))%mod;
  }
  return ret;
}
int main()
{
  cin >> n >> x;
  memset(dp, -1, sizeof dp);
  if (n == 0)
  {
    cout <<"1\n";
    return 0;
  }
  int ans = solve();
  cout << ans << '\n';
}
