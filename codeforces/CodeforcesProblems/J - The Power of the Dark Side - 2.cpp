// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
const int N = 5e5 + 9;
int n;
vector<array<int, 3>> v;
int a[3];
vector<long long> vec;
int solve(long long tar, long long tk)
{
  int l = 0, r = n-1, m, ans = 0;
  while(l <= r)
  {
    m = (l+r)>>1;
    if (vec[m] <= tar)
    {
      ans = (tk <= vec[m]? m: m+1);
      l = m + 1;
    }else
      r = m - 1;
  }
  return ans;
}
int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < 3; j++)
      scanf("%d", a+j);
    sort(a, a+3);
    v.push_back({a[0], a[1], a[2]});
    vec.push_back(1LL*a[0]+a[1] + 2);
  }
  sort(vec.begin(), vec.end());
  for (int i = 0; i < n; i++)
  {
    long long sum = 0;
    for (int j = 0; j < 3; j++)
      sum += v[i][j];
    printf("%d ", solve(sum, 1LL*v[i][0] + v[i][1] + 2));
  }
}
