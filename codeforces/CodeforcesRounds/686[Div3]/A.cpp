// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std;
int n;
void test()
{
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
  {
    int x = i + 1;
    if (x > n) x = 1;
    printf("%d ", x);
  }
  printf("\n");
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
  {
    test();
  }
}
