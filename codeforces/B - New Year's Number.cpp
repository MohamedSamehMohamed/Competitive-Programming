// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
void test()
{
  int n;
  scanf("%d", &n);
  if (n < 2020)
  {
    printf("NO\n");
    return;
  }
  int c = n/2020;
  int nn = n - (2020*c);
  if (nn <= c)
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
