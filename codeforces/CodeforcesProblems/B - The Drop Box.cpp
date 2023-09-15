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
const int N = 1e5 + 9;
int n, factor[3], a[N];
ll dp[N][3], inf = 4e18;
bool vis[N][3];
ll solve(int i = 0, int j = 0)
{
  if (j == 3)return 0;
  if (i == n)return -inf;
  ll &ret = dp[i][j];
  if (vis[i][j])return ret;
  vis[i][j] = 1;
  ret = solve(i+1, j);
  ret = max(ret, 1LL * factor[j] * a[i] + solve(i, j+1));
  return ret;
}
int main()
{
  cin >> n;
  for (int i = 0; i < 3; i++)cin >> factor[i];
  for (int i = 0; i < n; i++)cin >> a[i];
  cout << solve() << '\n';
}
