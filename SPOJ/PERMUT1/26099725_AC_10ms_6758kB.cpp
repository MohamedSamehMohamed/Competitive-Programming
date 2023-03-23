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
const int N = 12, M = 100;
int n, k, cnt[(1<<N)];
ll dp[(1<<N)][M];
ll solve(int msk = 0, int rm = k)
{
  if (rm < 0)return 0;
  if (!rm && cnt[msk] == n)return 1;
  ll &ret = dp[msk][rm];
  if (~ret)return ret;
  ret = 0;
  int bits = cnt[msk];
  for (int i = 0; i < n; i++)
  {
    if ( (msk &(1<<i)) )
    {
      bits--;
      continue;
    }
    ret = (ret + solve( (msk | (1<<i)) , rm - bits));
  }
  return ret;
}
int main()
{
  for (int i = 0; i < (1<<N); i++)
  {
    int c = 0;
    for (int j = 0; j < N; j++)
    {
      c += ( (i & (1<<j)) != 0 );
    }
    cnt[i] = c;
  }
  int t;
  scanf("%d", &t);
  while(t--)
  {
    scanf("%d%d", &n, &k);
    memset(dp, -1, sizeof dp);
    printf("%lld\n", solve());
  }
}
