// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std;
int dp[2][3];
string x;
int main()
{
  cin >> x;
  int p = 0;
  dp[p][0] = dp[p][2] = (x[0] == 'a');
  dp[p][1] = !dp[p][0];
  for (int i = 1; i < x.size(); i++)
  {
    p ^= 1;
    dp[p][0] = dp[p^1][0] + (x[i] == 'a');
    dp[p][1] = max(dp[p^1][0], dp[p^1][1]) + (x[i] == 'b');
    dp[p][2] = max(dp[p^1][1], dp[p^1][2]) + (x[i] == 'a');
  }
  cout << max({dp[p][0],dp[p][1],dp[p][2]}) << '\n';
}
