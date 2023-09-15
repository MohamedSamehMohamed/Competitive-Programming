// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
const int N = 2e5 + 9;
int a[N], n, k;
void solve()
{
  map<int, int> mp;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  for (int i = 0; i < n; i++)
  {
    if (a[i] % k)
      mp[k-a[i]%k]++;
  }
  if (mp.size() == 0)
    printf("0\n");
  else
  {
    long long ans = 0;
    for (auto i: mp)
      ans = max(ans, 1 + i.first + 1LL*(i.second-1) * k);
    printf("%lld\n", ans);
  }
}
int main()
{
  int t;cin >> t;
  while(t--)
  {
    solve();
  }
}
