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
const int N = 3000;
int dp[N][N], n, m;
string x, y;
int solve(int i = 0, int j = 0)
{
  if (i == n || j == m)return 0;
  int &ret = dp[i][j];
  if (~ret)return ret;
  ret = max(solve(i+1, j) , solve(i, j+1));
  if (x[i] == y[j])ret = max(2 + solve(i+1, j+1) , ret);
  return ret;
}
void build(int i = 0, int j = 0)
{
  if (i == n || j == m)return;
  int ret = dp[i][j];
  int p1 = solve(i+1, j);
  int p2 = solve(i, j+1);
  int p3 = 0;
  if (x[i] == x[j])
  p3 = 2 + solve(i+1, j+1);
  if (ret == p1)
  {
    build(i+1, j);
  }else if (ret == p2)
  {
    build(i, j+1);
  }else
  {
    cout << x[i];
    build(i+1, j+1);
  }
}
int main()
{
  cin >> x >> y;
  n = SZ(x);
  m = SZ(y);
  memset(dp, -1, sizeof dp);
  solve();
  build();
}
