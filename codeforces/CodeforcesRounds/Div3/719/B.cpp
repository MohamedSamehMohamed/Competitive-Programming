#include<bits/stdc++.h>
using namespace std;
int n;
vector<long long> v;
void test()
{
  scanf("%d", &n);
  int ans = 0;
  for (int i = 0; i < v.size(); i++)
  {
    if (v[i] > n)break;
    ans++;
  }
  printf("%d\n", ans);
}
int main()
{
  for (int len = 1; len <= 10; len++)
  {
    for (int d = 1; d <= 9; d++)
    {
      long long cur = 0;
      int rm = len;
      while(rm--)
        cur = cur * 10 + d;
      v.push_back(cur);
    }
  }
  sort(v.begin(), v.end());
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}
