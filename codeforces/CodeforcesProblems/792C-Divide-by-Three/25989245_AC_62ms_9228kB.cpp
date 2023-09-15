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
const int N = 1e5+1;
int dp[N][3];
string x;
int n;
int solve(int i = 0, int cur = 0)
{
  cur %= 3;
  if (i == n)
  {
    if (cur == 0)return 0;
    return -1e9;
  }
  int &ret = dp[i][cur];
  if (~ret)return ret;
  ret = solve(i+1, cur);
  ret = max(ret, 1 + solve(i+1, cur + (x[i] - '0')));
  return ret;
}
void build(int i = 0, int cur = 0)
{
  cur %= 3;
  if (i == n){return ;}
  int ret = dp[i][cur];
  int p1 = solve(i+1, cur);
  int p2 = 1 + solve(i+1, cur + (x[i] - '0'));
  if (p1 == ret)
  {
    build(i+1, cur);
  }else
  {
    cout << x[i];
    build(i+1, cur + (x[i] - '0'));
  }
}
int main()
{
  cin >> x;
  n  = SZ(x);
  memset(dp, -1, sizeof dp);
  bool ok = 0;
  for (int i = 0; i < n; i++)
  {

    if (x[i] != '0')
    {
      solve(i+1, x[i] - '0');
    }else ok = 1;
  }
  int mx = 0;
  int id;
  for (int i = 0; i < n; i++)
  {
    if (x[i] != '0')
    {
      int cur = solve(i+1, x[i] -'0');
      if (cur + 1> mx )
      {
        mx = 1 + cur;
        id = i;
      }
    }
  }
  if (mx == 0)
  {
    cout << (ok ? "0\n" : "-1\n");
  }else
  {
    cout << x[id] ;
    build(id+1, x[id] - '0');
  }
}
