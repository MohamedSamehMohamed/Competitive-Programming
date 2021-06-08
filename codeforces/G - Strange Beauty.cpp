// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int dp[N], n;
void test()
{
  scanf("%d", &n);
  map<int, int> mp;
  memset(dp, 0, sizeof dp);
  for (int i = 0; i < n; i++)
  {
    int x;
    scanf("%d", &x);
    mp[x]++;
  }
  auto solve = [&](int x)
  {
    dp[x] += mp[x];
    for (int i = x+x; i < N; i+=x)
    {
      dp[i] = max(dp[i], dp[x]);
    }
  };
  for (int i = 1; i < N; i++)
    solve(i);
  int ans = 0;
  for (int i = 0; i < N; i++)
    ans = max(ans, dp[i]);
  printf("%d\n", n - ans);
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}
