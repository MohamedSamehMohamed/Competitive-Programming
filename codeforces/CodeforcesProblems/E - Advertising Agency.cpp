// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 9, M = 1e9 + 7;
int dp[N][N], a[N], n, k;
int solve(int i = 0, int cur = 0)
{
  if (cur == k)return 1;
  if (i == n)return 0;
  int &ret = dp[i][cur];
  if (~ret)return ret;
  ret = solve(i+1, cur) % M;
  if (a[i] == a[cur]) ret = (ret + solve(i+1, cur+1)%M)%M;
  return ret;
}
void init()
{
  for (int i = 0; i < n; i++)
    memset(dp[i], -1, sizeof(a[0]) * n);
}
void test()
{
  scanf("%d%d", &n, &k);
  init();
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  sort(a, a+n);
  for (int i = 0; i < n-i-1; i++)
    swap(a[i], a[n-i-1]);
  printf("%d\n", solve());
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}
