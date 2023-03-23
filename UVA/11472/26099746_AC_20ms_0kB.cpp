// Author : Mohamed Sameh
#include <bits/stdc++.h>
typedef long long ll ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
using namespace std ;
const int M = 1e9+7, N = 101;
int dp[N][10][(1<<10)];
int vis[N][10][(1<<10)];
int n, m, tar, Id;
int solve(int idx = 0, int lst = 0, int msk = 0)
{
  if (idx == m)return 0;
  int &ret = dp[idx][lst][msk];
  if (vis[idx][lst][msk] == Id)return ret;
  ret = 0;
  vis[idx][lst][msk] = Id;
  if (idx == 0)
  {
    for (int i = 1; i < 10; i++)
    {
      if ((tar&(1<<i)) == 0)continue;
      int nmsk = (msk|(1<<i));
      ret = (ret +(nmsk == tar) + solve(idx+1, i, nmsk))%M;
    }
  }else
  {
    if (lst == 0)
    {
      int nmsk = (msk | (1<<1));
      if ((tar&(1<<1)))
      ret = ((nmsk == tar) + solve(idx+1, 1, nmsk))%M;
    }else if (lst == 9)
    {
      int nmsk = (msk | (1<<8));
      if ((tar&(1<<8)))
      ret = ((nmsk == tar) + solve(idx+1, 8, nmsk))%M;
    }else
    {
      int x = lst - 1;
      int nmsk = (msk | (1<<x));
      if ((tar&(1<<x)))
      ret = ((nmsk == tar) + solve(idx+1, x, nmsk))%M;
      x+=2;
      nmsk = (msk | (1<<x));
      if ((tar&(1<<x)))
      ret = (ret + (nmsk == tar) + solve(idx+1, x, nmsk))%M;
    }
  }
  return ret;
}
int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d%d", &n, &m);
    tar = (1<<n)-1;
    Id++;
    printf("%d\n", solve());
  }
}
