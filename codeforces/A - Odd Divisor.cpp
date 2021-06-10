// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
void test()
{
  long long x;
  scanf("%lld", &x);
  while(x % 2 == 0)
  {
    x/=2;
  }
  if ((x % 2) && x != 1)
    printf("YES\n");
  else
    printf("NO\n");
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}
