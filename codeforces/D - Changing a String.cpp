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
const int N = 1000;
int dp[N][N], n, m;
string x, y;
int solve(int i = 0, int j = 0)
{
  if (i == n && j == m)return 0;
  if (i == n)return m - j;
  if (j == m)return n - i;
  int &ret = dp[i][j];
  if (~ret) return ret;
  ret = 1e9;
  if (x[i] == y[j]) ret = solve(i+1, j+1);
  return ret = min(ret, 1 + min({solve(i+1, j+1) , solve(i+1, j), solve(i, j+1)}));
}
int idx = 1;
void build (int i = 0, int j = 0)
{
  if (i == n && j == m)return;
  if (i == n)
  {
    while (j < m)
    {
      cout <<"INSERT " << idx++ << " " << y[j++] <<"\n";
    }
    return;
  }
  if (j == m)
  {
    while (i < n)
    {
      cout <<"DELETE " << idx <<"\n";
      i++;
    }
    return;
  }
  int ret = dp[i][j];
  int p1, p2, p3, p4;
  p1 = p2 = p3 = p4 = 1e9;
  if (x[i] == y[j]) p1 = solve(i+1, j+1);
  p2 = 1 + solve(i+1, j+1);
  p3 = 1 + solve(i+1, j);
  p4 = 1 + solve(i, j+1);
  if (ret == p1)
  {
    idx++;
    build(i+1, j+1);
  }else if (ret == p2)
  {
    cout << "REPLACE " << idx++ << " " << y[j] <<"\n";
    build(i+1, j+1);
  }else if (ret == p3)
  {
    cout <<"DELETE " << idx <<"\n";
    build(i+1, j);
  }else
  {
    cout << "INSERT " << idx++ << " " << y[j] << "\n";
    build(i, j+1);
  }
}
int main()
{
 
  cin >> x >> y;
  n = SZ(x);
  m = SZ(y);
  memset(dp, -1, sizeof dp);
  cout << solve() <<"\n";
  build();
}
