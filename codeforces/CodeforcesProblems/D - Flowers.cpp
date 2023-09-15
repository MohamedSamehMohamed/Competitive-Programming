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
const int M = 1e9 + 7, N = 1e5+9;
ll dp[N];
ll pre[N];
int t, k;
ll solve(int rm)
{
  if (rm == 0 )return 1;
  if (rm < 0)return 0;
  ll &ret = dp[rm];
  if (~ret)return ret;
  ret = 0;
  ret = solve(rm - 1)%M + solve(rm - k)%M;
  return ret%M;
}
int main()
{
  memset(dp, -1, sizeof dp);
  scanf("%d%d", &t, &k);
  for (int i = 1; i < N; i++)
  {
      pre[i] = solve(i);
      pre[i] = (pre[i-1] + pre[i])%M;
  }
  while (t--)
  {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%lld\n", (pre[b] - pre[a] + dp[a] + M)%M );
  }
}
