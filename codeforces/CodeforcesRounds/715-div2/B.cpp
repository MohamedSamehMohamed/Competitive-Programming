#include<bits/stdc++.h>
using namespace std;
char a[100009];
void test()
{
  int n;scanf("%d", &n);
  scanf("%s", a);

  int before = 1, after = 0;
  for (int i = 1; i < n; i++)after += a[i] == 'T';

  if ((after % 2 == 0) || ( n - (after+1) != n / 3) ||a[0] == 'M' || a[n-1] == 'M')
  {
    printf("NO\n");
    return;
  }
  int l = 0;
  for (int i = 1; i < n-1; i++)
  {
    if (a[i] != 'M')continue;
    while(l < i && a[l] != 'T')l++;
    if (l >= i)
    {
      printf("NO\n");
      return;
    }
    l++;
  }
  int r = n-1;
  for (int i = n-2; i > 0; i--)
  {
    if (a[i] != 'M')continue;
    while(r > i && a[r] != 'T')r--;
    if (r <= i)
    {
      printf("NO\n");
      return;
    }
    r--;
  }
  printf("YES\n");
}
int main()
{
  int t;scanf("%d", &t);
  while(t--)test();
}
