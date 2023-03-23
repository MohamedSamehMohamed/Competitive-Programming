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
int n, s;
ll dp[70][70][2];
ll solve(int i = n, int rm = s, int loc = 1)
{
  if (i == 0) return rm == 0;
  if (rm < 0) return 0;
  ll &ret = dp[i][rm][loc];
  if (~ret)return ret;
  ret = solve(i-1, rm - loc, 1) + solve(i-1, rm, 0);
  return ret;
}
int main()
{
  memset(dp, -1, sizeof dp);
  while (cin >> n >> s && n > 0 && s >= 0)
  {
    cout << solve() <<"\n";
  }
}
