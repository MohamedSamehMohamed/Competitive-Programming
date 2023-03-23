// Author : Mohamed Sameh
#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
typedef long long ll ;
using namespace std ;
int n;
const int N = 4e2+9;
int a[N];
ll dp[N][N];
ll pre[N];
ll solve(int l = 0, int r = n-1)
{
  if (l >= r)return 0;
  if (l == r-1)return a[l] + a[r];
  ll &ret = dp[l][r];
  if (~ret)return ret;
  ret = 1e18;
  for (int i = l; i < r; i++)
  {
    ret = min(ret, solve(l, i) + solve(i+1, r) + a[l] + pre[r] - pre[l]);
  }
  return ret;
}
void test ()
{
  memset(dp, -1, sizeof dp);
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  pre[0] = a[0];
  for (int i = 1; i < n; i++)
    pre[i] = pre[i-1] + a[i];
  cout << solve() <<"\n";
}
int main()
{
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  test();
}
