#include <bits/stdc++.h>
using namespace std;
void read_file(){
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  #endif
}
class LuckyRemainder
{
  int dp[51][10]; 
  int solve(string& s, int i, int rem)
  {
    rem %= 9; 
    if (i == s.size())
      return rem;
    int &ret = dp[i][rem];
    if (~ret)return ret;
    ret = (solve(s, i+1, rem) + solve(s, i+1, rem * 10 + s[i] - '0'))%9;  
    return ret; 
  }
  public:
    int getLuckyRemainder(string s)
    {
      memset(dp, -1, sizeof dp); 
      return solve(s, 0, 0); 
    }
};

