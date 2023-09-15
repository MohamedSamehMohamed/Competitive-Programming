#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 9;
char x[N];
int n, q;
bool isPalindorm[N][N];
int dp[N][N];
bool isPal(int l, int r)
{
  if (r >= l)return 1;
  if (x[l] != x[r])return 0;
  return isPal(l+1, r-1);
}
int solve(int l, int r)
{
  if(l == r)return 1;
  if (r - l == 1)
    return 2 + isPalindorm[l][r];
  if(l > r)return 0;
  int &ret = dp[l][r];
  if (~ret)return ret;
  ret = 0;
  return ret = isPalindorm[l][r] + solve(l+1, r) + solve(l, r-1) - solve(l+1, r-1);
}
int main()
{
  scanf("%s%d", x, &q);
  memset(dp, -1, sizeof dp);
  n = strlen(x);
  for (int i = 0; i < n; i++)
    for (int j = i; j < n; j++)
      isPalindorm[i][j] = isPal(i, j);
  while(q--)
  {
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%d\n", solve(--l, --r));
  }
}
