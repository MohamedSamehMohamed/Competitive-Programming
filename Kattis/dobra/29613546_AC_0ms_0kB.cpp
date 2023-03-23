// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 102;
char x[N];
int n;
long long dp[N][4][4][2]; 
bool vowal(char c)
{
 for (auto i: "AEIOU")
  if (i == c)return 1;
 return 0; 
}
long long solve(int i = 0, int cn = 0, int vo = 0, int flag = 0)
{
 if (max(cn, vo) > 2)return 0;
 if (i == n)return flag;
 long long &ret = dp[i][cn][vo][flag];
 if (~ret)return ret;
 ret = 0; 
 if (x[i] == '_')
 for (char c = 'A'; c <= 'Z'; c++)
 {
  bool v = vowal(c); 
  ret = (ret + solve(i+1, !v*cn + !v, v*vo + v, flag|(c=='L')));
 }
 else
 {
  bool v = vowal(x[i]);
  ret = solve(i+1, !v*cn + !v, v*vo + v, flag|(x[i]=='L'));
 }
 return ret;
}
int main()
{
 memset(dp, -1, sizeof dp);
 scanf(" %s", x);
 n = strlen(x);
 printf("%lld\n", solve()); 
}
