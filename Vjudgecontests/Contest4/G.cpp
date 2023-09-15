// Author : Mohamed Sameh
// created in: 12:14 AM
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n, l, r;
int dp[2][3];
void test(){
  scanf("%d%d%d", &n, &l, &r);
  int ways[3] = {0, 0, 0};
  dp[0][0] = dp[0][1] = dp[0][2] = 0;
  for (int i = 0; i < 3 && i + l <= r; i++)
  {
    ways[(i+l)%3] =  1 + (r-l-i)/3;
    dp[0][(i+l)%3] =  ways[(l+i)%3];
  }
  int p = 1;
  for (int i = 1; i < n; i++){
    for (int j = 0; j < 3; j++)
      dp[p][j] = 0;
    for (int j = 0; j < 3; j++){
      for (int k = 0; k < 3; k++){
        dp[p][(j+k)%3] = (1LL * dp[p][(j+k)%3] +
                          1LL * dp[p ^ 1][j] * ways[k] % mod) % mod;
      }
    }
    p ^= 1;
  }
  printf("%d\n", dp[p^1][0]);
}
int main()
{
  test();
}