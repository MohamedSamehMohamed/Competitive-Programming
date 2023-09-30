// Author : Mohamed Sameh
// created in: 2:26 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 501;
int d[N], a[N], n, l, k;
int dp[N][N];
int solve(int i = 0, int tk = 1){
  if (i == n)
    return tk >= n - k? 0: (int)1e9;
  int& ret = dp[i][tk];
  if (~ret) return ret;
  ret = 2e9;
  for (int j = i + 1; j <= n; j++){
    int len = d[j] - d[i];
    ret = min(ret, a[i] * len + solve(j, tk + (j!=n)));
  }
  return ret;
}
void test(){
  scanf("%d%d%d", &n, &l, &k);
  for (int i = 0; i < n; i++)
    scanf("%d", d+i);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  d[n] = l;
  memset(dp, -1, sizeof dp);
  printf("%d\n", solve());
}
int main()
{
  test();
}