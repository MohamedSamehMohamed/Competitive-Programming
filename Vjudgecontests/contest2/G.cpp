// Author : Mohamed Sameh
// created in: 9:53 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 9;
int dp[N][N];
int n, m;
int a[N], b[N];
/*
 * x number of removed
 * n+m+-taked + y
 */
int solve(int i = 0, int j = 0){
  if (i == n || j == m) return 0;
  int& ret = dp[i][j];
  if (~ret) return ret;
  ret = min(solve(i + 1, j), solve(i, j + 1));
  if (a[i] == b[j])
  {
    ret = min(ret, -2 + solve(i + 1, j + 1));
  }else {
    ret = min(ret, -1 + solve(i + 1, j + 1));
  }
  return ret;
}
void test(){
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", a+i);
  for (int i = 0; i < m; i++) scanf("%d", b+i);
  memset(dp, -1, sizeof dp);
  printf("%d\n", n + m + solve());
}
int main()
{
  test();
}