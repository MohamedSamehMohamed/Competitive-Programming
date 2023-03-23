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
const int N = 5009;
int n, k, a[N];
int dp[N][N];
int BS (int idx)
{
  int l = idx, r = n-1, m, ans = idx;
  while (l <= r)
  {
    m = (l+r)>>1;
    if (a[m] - a[idx] <= 5)
    {
      ans = m;
      l = m+1;
    }else
    r = m-1;
  }
  return ans;
}
int solve (int i = 0, int rem = k)
{
  if (i == n || rem == 0)return 0;
  int &ret = dp[i][rem];
  if (~ret)return ret;
  ret = solve(i+1, rem);
  int idx = BS(i);
  ret = max(ret, idx - i + 1 + solve(idx+1, rem - 1));
  return ret;
}
int main()
{
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a+n);
  memset(dp, -1, sizeof dp);
  cout << solve() <<"\n";
}
