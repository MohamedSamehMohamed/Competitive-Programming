#include <bits/stdc++.h>
using namespace std;
void read_file()
{
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  #endif
}
int k, mn, mx;
char x[300];
int dp[300][300], n;
int solve(int len, int rem)
{
  if (len == 0 && rem == 0)
    return 1;
  if (len <= 0 || rem <= 0)
    return 0;
  int &ret = dp[len][rem];
  if (~ret)return ret; 
  ret = 0;
  for(int i = mn; i <= mx; i++)
  {
    if (solve(len - i, rem - 1))
    {
      ret = 1;
      return ret;
    }
  }
  return ret;
}
vector<int> parts;
void build(int len, int rem)
{
  if (len == 0 && rem == 0)
    return;
  if (len <= 0 || rem <= 0)
    return;
  int ret = dp[len][rem];
  for(int i = mn; i <= mx; i++)
  {
    if (solve(len - i, rem - 1))
    {
      parts.push_back(i);
      build(len - i, rem - 1);
      return;
    }
  }
}
void test()
{
  scanf("%d%d%d %s", &k, &mn, &mx, x);
  n = strlen(x);
  memset(dp, -1, sizeof dp);
  if (solve(n, k))
  {
    build(n, k);
    int idx = 0;
    for(int i = 0; i < parts.size(); i++)
    {
      while(parts[i]--)
      {
        printf("%c", x[idx++]);
      }
      printf("\n");
    }
  }else 
  {
    printf("No solution\n");
  }
}
int main()
{
  read_file();
  int t;
  t = 1;
  while(t--)
    test();
}
