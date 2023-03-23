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
string x;
const int N = 100;
ll dp[10009][N+1][2];
int n, sz;
const int M = 1e9 + 7;
ll solve(int idx = 0, int sum = 0, bool fl = 0)
{
  sum%=n;
  if (idx == sz)return sum == 0;
  ll &ret = dp[idx][sum][fl];
  if (~ret)return ret;
  ret = 0;
  int mx = fl ? 9 : x[idx] - '0';
  for (int i = 0; i <= mx; i++)
  {
    ret = (ret + solve(idx + 1, sum + i, (fl | (i < mx))) % M)%M;
  }
  return ret;
}
int main()
{
  memset(dp, -1, sizeof dp);
  cin >> x >> n;
  sz = SZ(x);
  cout << (solve()-1+M)%M <<"\n";
}
