// Author : Mohamed Sameh
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
const int N = 3000;
ll dp[N][N][2];
int a[N], n;
ll solve (int l = 0, int r = n-1, int turn = 0)
{
  if (l > r)return 0;
  ll &ret = dp[l][r][turn];
  if (~ret)return ret;
  if (turn)
  {
    ret = min(solve(l+1, r, !turn) - a[l] , solve(l, r-1, !turn) - a[r] );
  }else
  {
    ret = max(solve(l+1, r, !turn) + a[l] , solve(l, r-1, !turn) + a[r] );
  }
  return ret;
}
int main()
{
  memset(dp, -1, sizeof dp);
  cin >> n ;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  cout << solve() <<"\n";
}
