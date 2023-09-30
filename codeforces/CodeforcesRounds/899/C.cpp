// Author : Mohamed Sameh
// created in: 5:23 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int a[N], n;
long long dp[N][2];
long long solve(int i = 0, int prv = 0){
  if (i >= n) return 0;
  long long& ret = dp[i][prv];
  if (~ret) return ret;
  ret = 0;
  // is odd
  int odd = (i%2 == 0);
  odd ^= prv;
  if (odd){
    ret = max(ret, 1LL * a[i] + solve(i+1, prv ^ 1));
    ret = max(ret, 1LL * a[i] + solve(i+1, prv));
    ret = max(ret, solve(i+2, prv));
    ret = max(ret, solve(i+3, prv^1));
  }else {
    ret = max(ret, solve(i+1, prv));
    ret = max(ret, solve(i+1, prv^1));
  }
  return ret;
}
void test(){
  scanf("%d", &n);
  for (int i = 0; i < n; i++){
    scanf("%d", a+i);
    dp[i][0] = dp[i][1] = -1;
  }
  printf("%lld\n", solve());
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}