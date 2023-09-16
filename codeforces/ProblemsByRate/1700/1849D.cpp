// Author : Mohamed Sameh
// created in: 2:36 AM
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int a[N], n, dp[N][2][2];
int solve(int i = 0, int lst = 1, int prvCan = 0){
  if (i == n)
    return 0;
  if (a[i] == 0 && !lst)
    return n + 5;
  int& ret = dp[i][lst][prvCan];
  if (~ret) return ret;
  ret = n + 2;
  if (a[i] == 0){
    ret = solve(i+1, 1, 0) + !prvCan;
  }else if (a[i] >= 1){
    if (lst)
    {
      ret = !prvCan + solve(i+1, 1, 1);
    }else {
      ret = 1 + solve(i+1, 1, 0);
      if (i + 1 < n && a[i+1] != 0)
        ret = min(ret, solve(i+1, 0, 0));
    }
    if (a[i] == 2)
    {
      ret = min(ret, !prvCan + solve(i+1, 1, 1));
      if (i + 1 < n && a[i+1] != 0)
        ret = min(ret, solve(i+1, 0, 0));
    }
  }
  if (i+1 < n && a[i+1] == 2)
    ret = min(ret, solve(i+1, 0, 0));
  if (i+1 < n && a[i+1] == 1 && lst)
    ret = min(ret, solve(i+1, 0, 0));
  return ret;
}
void test(){
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  memset(dp, -1, sizeof dp);
  printf("%d\n", solve());
}
int main()
{
  test();
}