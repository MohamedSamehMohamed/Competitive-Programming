#include <bits/stdc++.h>
using namespace std;
void read_file()
{
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  #endif
}
int n;
string s; 
int dp[1009][1<<13][13]; 
int mod = 998244353;
int solve(int i = 0, int msk = 0, int lst = 12)
{
 if (i == n)
    return 1;
  int &ret = dp[i][msk][lst];
  if (~ret)return ret; 
  ret = 0; 
  ret = solve(i+1, msk, lst) % mod; 
  int pos = s[i] - 'A';
  if (((msk & (1<<pos)) == 0) || lst == s[i] - 'A')
  {
    int nmsk = msk;
    if (lst != 12)nmsk |= (1<<lst); 
    ret = (ret + solve(i+1, nmsk, s[i] - 'A') % mod) % mod;
  }
  return ret;
}
int main()
{
  read_file();
  memset(dp, -1, sizeof dp);
  cin >> n >> s; 
  cout << (solve()-1+mod)%mod <<"\n";
}
