// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
const int N = 60;
int n;
int a[N];
int dp[N][N][2];
int solve(int idx, int lst, int st)
{
  if (idx == n)
    return 0;
  int &ret = dp[idx][lst][st];
  if (~ret)return ret;
  ret = solve(idx+1, lst, st);
  if ((a[idx] != a[lst]) && (a[idx] < a[lst]) == st)
    ret = max(ret, 1 + solve(idx+1, idx, !st));
  return ret;
}
int main()
{
  memset(dp, -1, sizeof dp);
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int ans = 1;
  for (int i = 0; i < n; i++)
  {
    for (int j = i+1; j < n; j++)
    {
      if (a[i] != a[j])
      {
        ans = max(ans, 2 + solve(j+1, j, (a[i] < a[j])));
      }
    }
  }
  cout << ans << '\n';
}
