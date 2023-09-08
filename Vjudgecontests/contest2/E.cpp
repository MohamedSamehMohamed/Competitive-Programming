// Author : Mohamed Sameh
// created in: 9:26 PM
#include <bits/stdc++.h>
using namespace std;
long long dp[201][13];
long long solve(int len, int rem){
  if (len == 0 && rem == 0) return 1;
  if (len == 0 || rem == 0) return 0;
  long long& ret = dp[len][rem];
  if (~ret) return ret;
  ret = 0;
  for (int i = 1; i <= len; i++)
    ret += solve(len - i, rem - 1);
  return ret;
}
void test(){
  int n;
  scanf("%d", &n);
  memset(dp, -1, sizeof dp);
  printf("%lld\n", solve(n, 12));
}
int main()
{
  test();
}