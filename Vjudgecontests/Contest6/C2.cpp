// Author : Mohamed Sameh
// created in: 8:22 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 9, mod = 998244353;
int dp[N][N], ways[N][N], n, m;
int mul(int a, int b){
  return (1LL * a * b) % mod;
}
long long fast(long long b, long long p)
{
  if (p == 0)return 1;
  if (p&1)return mul(b, fast(b, p-1));
  long long cur = fast(b, p/2);
  return mul(cur, cur);
}
int calc(int len){
  if (len == 0)
    return 0;
  int ans = fast(m, len) - fast(m-1, len);
  if (ans < 0) ans += mod;
  return ans;
}
void test(){
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++)
  {
    dp[1][i] = 1;
    ways[1][i] = 1;
  }
  /*
   * 1 1
   * 1 2
   * 2 1
   */
  for (int i = 2; i <= n; i++){
    for (int j = 1; j <= m; j++){
      for (int prv = 1; prv <= m; prv++){
        if (prv < j){
          ways[i][j] = (ways[i][j]+ways[i-1][prv])%mod;
          dp[i][j] = (dp[i][j] + dp[i-1][prv] + 1)%mod;
        }else if (prv == j){
          ways[i][j] = (ways[i][j]+ways[i-1][prv])%mod;
          dp[i][j] = (dp[i][j] + dp[i-1][prv])%mod;
        }else {
          ways[i][j] = (ways[i][j]+ways[i-1][prv])%mod;
          dp[i][j] = (dp[i][j] + dp[i-1][prv] - calc(i-2))%mod;
          if (dp[i][j] < 0) dp[i][j] += mod;
        }
      }
    }
  }
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= m; j++)
      cout << ways[i][j] <<" \n"[j == m];
  }
  cout <<"\n\n";
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= m; j++)
      cout << dp[i][j] <<" \n"[j == m];
  }
  /*
   * 1 1
   * 2 1
   * 3 1
   */
  int ans = 0;
  for (int i = 1; i <= m; i++)
    ans = (1LL * ans + dp[n][i] + ways[n][i]) % mod;
  printf("%d\n", ans);
}
int main()
{
  test();
}
/*
 *
 */