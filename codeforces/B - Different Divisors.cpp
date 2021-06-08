// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
bool prime(int x)
{
  for (int i = 2; i <= x/i; i++)
    if (x % i == 0)
      return 0;
  return (x > 1);
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
  {
    int n;
    scanf("%d", &n);
    int ans = 1;
    int x, y;
    for (int i = n+1; ; i++)
    {
      if (prime(i))
      {
        ans = i;
        x = i;
        break;
      }
    }
    for (int i = ans+n; ;i++)
    {
      if (prime(i))
      {
        y = i;
        break;
      }
    }
    printf("%lld\n", 1LL*x*y);
  }
}
