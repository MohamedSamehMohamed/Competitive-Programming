#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 9;
int n, m, a[N];
int dp[N][N][2];
int solve(int i = 0, int rm = 0, bool flag = 0)
{
  rm %= m;
  if (rm == 0 && flag)return 1;
  if (i == N)return 0;
  int &ret = dp[i][rm][flag];
  if (~ret)return ret;
  ret = solve(i+1, rm, flag);
  int tk = 1;
  while(!ret && tk <= a[i])
  {
    ret = solve(i+1, rm + tk * i, 1);
    tk++;
  }
  return ret;
}
int main()
{
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++)
  {
    int x;scanf("%d", &x);
    a[x%m]++;
  }
  memset(dp, -1, sizeof dp);
  if (n > m || solve())
  {
    printf("YES\n");
  }else
  {
    printf("NO\n");
  }
}  
