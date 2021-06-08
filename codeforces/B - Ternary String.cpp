// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
const int N = 2e5 + 9;
char x[N];
int n, dp[N][1<<3];
int val(int idx){return 1<<((x[idx]-'0')-1);}
int solve(int i = 0, int msk = 0)
{
  if (i == n)
    return (msk == (1<<3)-1? 0: n+1);
  if (msk == (1<<3)-1)return 0;
  int &ret = dp[i][msk];
  if (~ret)return ret;
  ret = min(1 + solve(i+1, msk|val(i)), solve(i+1, 0));
  return ret;
}
void test()
{
  scanf(" %s", x);
  n = strlen(x);
  for(int i = 0; i < n; i++)for (int j = 0; j < (1<<3); j++)dp[i][j] = -1; 
  int ans = solve();
  if (ans > n)ans = 0;
  printf("%d\n", ans);
}
int main()
{
  int t;scanf("%d", &t);
  while(t--)
    test();
}
