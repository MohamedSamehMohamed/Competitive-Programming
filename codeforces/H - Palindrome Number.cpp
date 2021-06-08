// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
int frq[10];
int n, s, S;
bool can(int o)
{
  s = S;
  memset(frq, 0, sizeof frq);
  int digts = 0, odd = 0;
  for (int i = 9; i > 0; i--)
  {
    int cnt = s / i;
    if (cnt&1)
    {
      if (i != o)
        cnt--;
    }
    odd += (cnt&1);
    s -= cnt * i;
    frq[i] += cnt;
    digts += frq[i];
  }
 
  if (s || digts > n || odd > 1) return 0;
  if ((n%2 == 0)&&odd)return 0;
  if (digts <= 1)return 0;
  frq[0] += n - digts;
  return 1;
}
bool gen(int rm = n, int sum = s)
{
  if (sum < 0)return 0;
  if (rm == 1)return (sum <= 9);
  if (rm == 0)
  {
    return (sum == 0);
  }
  for (int i = 0 + (rm == n); i <= 9; i++)
  {
    if (gen(rm-2, sum-i-i))return 1;
  }
  return 0;
}
void test()
{
  scanf("%d%d", &n, &s);
  if (n == 1)
  {
    if (s <= 9)printf("%d\n", s);
    else printf("-1\n");
    return;
  }
  bool ok = 0;
  S = s;
  for (int i = 1; !ok && i <= 9; i++)
    ok = can(i);
  if (!ok)
  {
    printf("-1\n");
    return;
  }
  int center = -1;
  for (int i = 9; i >= 0; i--)
  {
    int c = frq[i] / 2;
    if (frq[i]&1)center = i;
    while(c--)printf("%d", i);
    frq[i]/=2;
  }
  if (~center)printf("%d", center);
  for (int i = 0; i <= 9; i++)
  {
    while(frq[i]--)printf("%d", i);
  }
  printf("\n");
}
int main()
{
  int t;scanf("%d", &t);
  while(t--)
    test();
}
