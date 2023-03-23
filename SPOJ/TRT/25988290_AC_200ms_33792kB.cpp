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
const int N = 2000;
ll dp[N][N];
int a[N], n;
ll solve (int l = 0, int r = n-1, int nu = 1)
{
  if (l > r)return 0;
  ll &ret = dp[l][r];
  if (~ret)return ret;
  ret = max(1LL*a[l] * nu + solve(l+1, r, nu + 1), 1LL*a[r] * nu + solve(l, r-1, nu + 1));
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
