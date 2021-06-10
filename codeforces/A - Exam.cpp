// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
const int N = 1e3 + 9;
int dp[N][N];
int n, sz;
string x, y;
int solve(int i = 0, int c = 0)
{
  if (i == sz)
    return (c == n? 0: -1e6);
  int &ret = dp[i][c];
  if (~ret)return ret;
  if (c < n)
    ret = (x[i] == y[i]) + solve(i+1, c+1);
  ret = max(ret, (x[i] != y[i]) + solve(i+1, c));
  return ret;
}
int main()
{
  cin >> n;
  cin >> x >> y;
  sz = x.size();
  memset(dp, -1, sizeof dp);
  cout << solve() << '\n';
}
