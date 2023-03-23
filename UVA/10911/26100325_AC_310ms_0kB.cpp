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
const int N = 16;
int n;
char arr[21];
int pos[N][2];
double dp[(1<<N)];
double dist (int i, int j)
{
  return sqrt( pow( pos[i][0] - pos[j][0], 2 ) + pow(pos[i][1] - pos[j][1], 2));
}
double solve(int msk = 0)
{
  if (msk == (1<<n)-1)return 0;
  double &ret = dp[msk];
  if (ret == ret)return ret;
  ret = 1e9;
  for (int i = 0; i < n; i++)
    for (int j = i+1; j < n; j++)
    {
      if ( (msk&(1<<i)) || (msk&(1<<j)))continue;
      int nmsk = msk;
      nmsk |= (1<<i);
      nmsk |= (1<<j);
      ret = min(ret, dist(i, j) + solve(nmsk));
    }
  return ret;
}
int main()
{
  int t = 0;
  while(scanf("%d", &n) && n)
  {
    t++;
    n*=2;
    for (int i = 0; i < n; i++)
    {
      scanf("%s%d%d", arr, pos[i], pos[i]+1);
    }
    memset(dp, -1, sizeof dp);
    printf("Case %d: %.2f\n",t, solve());
  }
}
