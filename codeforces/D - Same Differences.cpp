#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int a[N], n;
void test()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  map<int, int> mp;
  long long ans = 0;
  for (int i = 0; i < n; i++)
  {
    ans += mp[a[i] - i];
    mp[a[i] - i]++; 
  }
  printf("%lld\n", ans);
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}
