#include<bits/stdc++.h>
using namespace std;
class BearPlaysDiv2
{
  int dp[501][501][501];
  int solve(int a, int b, int c)
  {
    if (a == b && b == c)return 1;
    int &ret = dp[a][b][c];
    if (~ret)return ret;
    ret = 0;
    int tem[] = {a, b, c};
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
      {
        if (i == j || tem[i] >= tem[j])continue;
        int x = tem[i];
        tem[i] += x;
        tem[j] -= x;
        ret = max(ret, solve(tem[0], tem[1], tem[2]));
        tem[i] -= x;
        tem[j] += x;
      }
    return ret;
  }
  public:
    string equalPiles(int A, int B, int C)
    {
      memset(dp, -1, sizeof dp);
      return solve(A, B, C)? "possible": "impossible";
    }
};
