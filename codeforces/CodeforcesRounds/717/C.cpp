#include<bits/stdc++.h>
using namespace std;
int a[101], n;
int dp[101][(2000*100 + 9)/2];
int solve(int i, int rm)
{
  if (rm == 0)return 1;
  if (i == n)return 0;
  int &ret = dp[i][rm];
  if (~ret)return ret;
  return ret = max(solve(i+1, rm), solve(i+1, rm - a[i]));
}
int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  int sum = 0;
  for (int i = 0; i < n; i++)
    sum += a[i];
  memset(dp, -1, sizeof dp);
  if (sum % 2 || solve(0, sum/ 2) == 0)
  {
    printf("0\n");
    return 0;
  }
  for (int i = 0; i < n; i++)
  {
    if (a[i] % 2)
    {
      printf("1\n%d\n", i+1);
      return 0;
    }
  }
  int id = 0;
  for (int i = 0; i < n; i++)if (a[i] < a[id])id = i;
  printf("1\n%d\n", id+1);
}
