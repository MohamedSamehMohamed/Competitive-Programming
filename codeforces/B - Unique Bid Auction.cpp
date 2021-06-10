// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
const int N = 2e5 + 9;
int a[N], n;
void test()
{
  map<int, int> mp;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", a+i);
    mp[a[i]]++;
  }
  int ans = -1;
  for (int i = 0; i < n; i++)
  {
    if (mp[a[i]] == 1)
    {
      if (ans == -1)ans = i+1;
      if (a[i] < a[ans-1])ans = i + 1;
    }
  }
  printf("%d\n", ans);
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
