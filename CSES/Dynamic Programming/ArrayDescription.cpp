#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9, M = 101, mod = 1e9 + 7;
int a[N], dp[N][M], n, m;
int main()
{
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  if (a[0] == 0)
  {
    for (int i = 1; i <= m; i++)
      dp[0][i] = 1;
  }else
  {
    dp[0][a[0]] = 1;
  }
  for (int i = 1; i < n; i++)
  {
    if (a[i] == 0)
    {
      for (int endwith = 1; endwith <= m; endwith++)
      {
        for (int previous = endwith - 1; previous <= endwith + 1; previous++)
        {
          if (previous >= 1 && previous <= m)
            dp[i][endwith] = (dp[i][endwith] + dp[i-1][previous]) % mod;
        }
      }
    }else
    {
      for (int previous = a[i] - 1; previous <= a[i] + 1; previous++)
      {
        if (previous >= 1 && previous <= m)
        {
          dp[i][a[i]] = (dp[i][a[i]] + dp[i-1][previous]) % mod;
        }
      }
    }
  }
  int ans =0 ;
  for (int i = 1; i <= m; i++)
    ans = (ans + dp[n-1][i]) % mod;
  printf("%d\n", ans);
}
