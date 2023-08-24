// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 9;
char a[N][N], b[N][N];
int n;
void test()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf(" %s", a+i);
  for (int i = 0; i < n; i++)
    scanf(" %s", b+i);
  for (int i = 0; i < n; i++)
  {
    if (a[i][0] == '1')
    {
      for (int j = 0; j < n; j++)
        a[i][j] = (a[i][j] == '1'? '0': '1');
    }
    if (b[i][0] == '1')
    {
      for (int j = 0; j < n; j++)
        b[i][j] = (b[i][j] == '1'? '0': '1');
    }
  }
  for (int i = 0; i < n; i++)
  {
    if (a[0][i] == '1')
    {
      for (int j = 0; j < n; j++)
        a[j][i] = (a[j][i] == '1'? '0': '1');
    }
    if (b[0][i] == '1')
    {
      for (int j = 0; j < n; j++)
        b[j][i] = (b[j][i] == '1'? '0': '1');
    }
  }
  bool ok = 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      ok &= (a[i][j] == b[i][j]);
  if (ok)
    printf("Yes\n");
  else
    printf("No\n");
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}
