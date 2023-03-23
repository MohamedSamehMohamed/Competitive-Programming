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
const int N = 21, M = 1e9 + 7;
ll dp[N][(1<<N)];
int n;
int a[N][N];
ll solve(int idx = 0, int msk = 0)
{
  if (idx == n)return 1;
  ll &ret = dp[idx][msk];
  if (~ret)return ret;
  ret = 0;
  for (int i = 0; i < n; i++)
  {
    if ( (msk & (1 << i)) || !a[idx][i])continue ;
    ret = (ret + solve(idx+1, (msk | (1<<i))))%M;
  }
  return ret;
}
int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> a[i][j];
  memset(dp, -1, sizeof dp);
  cout << solve() <<"\n";
}
