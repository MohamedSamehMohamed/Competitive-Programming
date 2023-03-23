// Author : Mohamed Sameh
#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define FAST ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
typedef long long ll ;
using namespace std ;
const int N = 5e3+9;
int n, m, k;
ll a[N];
ll dp[N][N];
ll solve(int i = 1, int rm = k)
{
  if (i == n+1)return (rm == 0? 0: -1e16);
  if (rm == 0)return 0;
  ll &ret = dp[i][rm];
  if (~ret)return ret;
  ret = solve(i+1, rm);
  if (i + m - 1 <= n)ret = max(ret, a[i+m-1] - a[i-1] + solve(i + m, rm - 1));
  return ret;
}
int main()
{
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    a[i] += a[i-1];
  }
  memset(dp, -1, sizeof dp);
  cout << solve() << '\n';

}
