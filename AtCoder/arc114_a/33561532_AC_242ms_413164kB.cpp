#include <bits/stdc++.h>
using namespace std;
void read_file()
{
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  #endif
}
int P[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
bool v[50][50]; 
long long dp[50][1<<20]; 
int n;
long long solve(int i = 0, int msk = 0)
{
  if (i == n)
    return 1; 
  long long& ret = dp[i][msk];
  if (~ret)return ret; 
  ret = 1e18; 
  for(int j = 0; j < 15; j++)
  {
    if (v[i][P[j]] == 0)continue; 
    if (msk & (1<<j))
      ret = min(ret, solve(i+1, msk)); 
    else 
      ret = min(ret, 1LL * P[j] * solve(i+1, msk | (1<<j)) );
  }
  return ret;
}
int main()
{
  read_file();
  memset(dp, -1, sizeof dp); 
  cin >> n;
  for(int i = 0; i < n; i++)
  {
    int x;cin >> x;
    for(int j = 2; j <= x/j; j++)
    {
      if (x % j == 0)
      {
        v[i][j] = 1;
        while(x % j == 0)x /= j; 
      }
    }
    if (x != 1)v[i][x] = 1; 
  }
  cout << solve() <<"\n";
  
}
