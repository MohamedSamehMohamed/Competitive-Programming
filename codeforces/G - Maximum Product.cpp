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
string x, y;
int n;
ll dp[20][2][2];
ll solve(int idx = 0, bool f1 = 0, bool f2 = 0)
{
  if (idx == n) return 1;
  ll &ret = dp[idx][f1][f2];
  if (~ret)return ret;
  int mn = f2 ? 1 : x[idx] - '0';
  int mx = f1 ? 9 : y[idx] - '0';
  ret = 0;
  for (int i = mn; i <= mx; i++)
  {
    int j = i;
    if (j == 0 && idx == 0) j = 1;
    ret = max(ret, j * solve(idx+1, (f1 | (i < mx)) , (f2 | (i > mn))));
  }
  return ret;
}
void build (int idx = 0, bool f1 = 0, bool f2 = 0)
{
  if (idx == n) return ;
  ll ret = dp[idx][f1][f2];
  int mn = f2 ? 1 : x[idx] - '0';
  int mx = f1 ? 9 : y[idx] - '0';
  ll p1 = 0;
  for (int i = mn; i <= mx; i++)
  {
    int j = i;
    if (j == 0 && idx == 0) j = 1;
    p1 = j *solve(idx+1, (f1 | (i < mx)) , (f2 | (i > mn)));
    if (p1 == ret)
    {
      if (idx == 0){
      if (i)
      cout << i;
    }else
    {
      cout << i;
    }
      build(idx+1,(f1 | (i < mx)) , (f2 | (i > mn)));
      return;
    }
  }
}
int main()
{
  cin >> x >> y ;
  while (SZ(x) < SZ(y))x = "0" + x;
  n = SZ(x);
  memset(dp, -1, sizeof dp);
  solve();
  build();
}
