#include<bits/stdc++.h>
using namespace std;
int n, a[100], p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
int dp[100][1<<17];
int Msk[61];
int getmsk(int x)
{
  int msk = 0;
  for (int i = 0; x != 1 && i < 17; i++)
  {
    while(x % p[i] == 0)
    {
      msk |= (1<<i);
      x/= p[i];
    }
  }
  return msk;
}
int solve(int i = 0, int msk = 0)
{
  if (i == n)return 0;
  int &ret = dp[i][msk];
  if (~ret)return ret;
  ret = 1e9;
  for (int j = 1; j <= 60; j++)
  {
    int curmsk = Msk[j];
    if (msk & curmsk)continue;
    ret = min(ret, abs(a[i] - j) + solve(i+1, msk | curmsk));
  }
  return ret;
}
void build(int i = 0, int msk = 0)
{
  if (i == n)return;
  int ret = dp[i][msk];
  for (int j = 1; j <= 60; j++)
  {
    int curmsk = Msk[j];
    if (msk & curmsk)continue;
    int p1 = abs(a[i] - j) + solve(i+1, msk | curmsk);
    if (ret == p1)
    {
      printf("%d ", j);
      build(i+1, msk | curmsk);
      break;
    }
  }
}
int main()
{
  for (int i = 1; i <= 60; i++)Msk[i] = getmsk(i);
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  memset(dp, -1, sizeof dp);
  solve();
  build();
}
