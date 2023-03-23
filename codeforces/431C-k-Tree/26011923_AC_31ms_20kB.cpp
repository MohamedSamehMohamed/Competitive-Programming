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
const int N = 109, M = 1e9 + 7;
ll dp[N][2];
int n, k, d;
ll solve(int rm = n, bool has = 0)
{
  if (rm == 0)return has;
  if (rm < 0)return 0;
  ll &ret = dp[rm][has];
  if (~ret)return ret;
  ret = 0;
  for (int i = 1; i <= k; i++)
  {
    ret = (ret + solve(rm - i, (has | (i >= d)) )%M )%M;
  }
  return ret;
}
int main()
{
  memset(dp, -1, sizeof dp);
  cin >> n >> k >> d;
  cout << solve() % M <<"\n";
}
