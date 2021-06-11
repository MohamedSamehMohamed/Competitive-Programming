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
const int M = 1e8;
int n, m, k1, k2;
ll dp[101][101][3];
ll solve(int rn = n, int rm = m, int lst = 2)
{
  if (rn == 0 && rm == 0)return 1;
  if (rn < 0 || rm < 0)return 0;
  ll &ret = dp[rn][rm][lst];
  if (~ret)return ret;
  ret = 0;
  int ave = 1;
  if (lst == 0)
  {
    while (ave <= k2)
    {
      ret = (ret + solve(rn, rm - ave, lst ^ 1)%M)%M;
      ave++;
    }
  }else if (lst == 1)
  {
    while (ave <= k1)
    {
      ret = (ret + solve(rn - ave, rm, lst ^ 1)%M)%M;
      ave++;
    }
  }else
  {
    while (ave <= k1)
    {
      ret = (ret + solve(rn - ave, rm, 0)%M)%M;
      ave++;
    }
    ave = 1;
    while (ave <= k2)
    {
      ret = (ret + solve(rn, rm - ave, 1)%M)%M;
      ave++;
    }
  }
  return ret;
 
}
int main()
{
  cin >> n >> m >> k1 >> k2 ;
  memset(dp, -1, sizeof dp);
  cout << solve() % M;
}
