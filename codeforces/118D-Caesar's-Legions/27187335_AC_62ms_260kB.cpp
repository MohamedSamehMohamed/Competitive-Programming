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
const int Mod = 1e8;
int n1, n2, k1, k2;
ll dp[101][101][3];
ll solve(int rma = n1, int rmb = n2, int lst = 2)
{
  if (min(rma, rmb) < 0)return 0;
  if (rma == 0 && rmb == 0)return 1;
  ll &ret = dp[rma][rmb][lst];
  if (~ret)return ret;
  ret = 0;
  if (lst != 0)
  {
    int cur = 1;
    while(cur <= k1)
    {
      ret = (ret + solve(rma-cur, rmb, 0)%Mod)%Mod;
      cur++;
    }
  }
  if (lst != 1)
  {
    int cur = 1;
    while(cur <= k2)
    {
      ret = (ret + solve(rma, rmb-cur, 1)%Mod)%Mod;
      cur++;
    }
  }
  return ret;
}
int main()
{
  cin >> n1 >> n2 >> k1 >> k2;
  memset(dp, -1, sizeof dp);
  cout << solve() << '\n';
}
