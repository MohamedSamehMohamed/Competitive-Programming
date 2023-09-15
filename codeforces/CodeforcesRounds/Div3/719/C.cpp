#include<bits/stdc++.h>
using namespace std;
int n;
int a[101][101];
void test()
{
  scanf("%d", &n);
  int cur = 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
    {
      if (cur > n * n)
        cur = 2;
      a[i][j] = cur;
      cur += 2;
    }
  bool ok = 1;
  int dx[] = {1, -1, 0, 0};
  int dy[] = {0, 0, 1, -1};
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
    {
      for (int k = 0; k < 4; k++)
      {
        int nx = dx[k] + i;
        int ny = dy[k] + j;
        if (min(nx, ny) < 0 || max(nx, ny) >= n)continue;
        if (abs(a[i][j] - a[nx][ny]) == 1)ok = 0;
      }
    }
  if (!ok)
  {
    printf("-1\n");
    return;
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
    {
      printf("%d", a[i][j]);
      if (j + 1 < n)printf(" ");
      else
      printf("\n");
    }
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}
