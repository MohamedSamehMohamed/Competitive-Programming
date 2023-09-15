// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
long long n;
void test()
{
  scanf("%lld", &n);
  map<long long, int> P;
  for (int i = 2; i <= n/i; i++)
  {
    while(n % i == 0)
    {
      P[i]++;
      n/=i;
    }
  }
  if (n != 1)P[n]++;
  vector<long long> ans;
  while(1)
  {
    long long cur = 1;
    for (auto &i: P)
    {
      if (i.second == 0)continue;
      i.second--;
      cur *= i.first;
    }
    if (cur == 1)break;
    ans.push_back(cur);
  }
  sort(ans.begin(), ans.end());
  printf("%d\n", ans.size());
  for(auto i: ans)
    printf("%lld ", i);
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
