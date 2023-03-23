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
ll dp[205];
string x;
int n;
ll solve(int i = 0)
{
  if (i == n)return 0;
  ll &ret = dp[i];
  if (~ret)return ret;
  ll cur = x[i] - '0';
  ret = cur + solve(i+1);
  if (cur != 0)
  {
    i++;
    while (i < n && cur * 10 +(x[i] - '0') <= (1<<31)-1)
    {
      cur *= 10;
      cur += (x[i] - '0');
      ret = max(ret, cur + solve(i+1));
      i++;
    }
  }
  return ret;

}
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    memset(dp, -1, sizeof dp);
    cin >> x;
    n = SZ(x);
    cout << solve() <<"\n";
  }
}
