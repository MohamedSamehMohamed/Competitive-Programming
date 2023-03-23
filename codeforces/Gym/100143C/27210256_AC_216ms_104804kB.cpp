// Author : Mohamed Sameh
#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define FAST ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
typedef long long ll ;
using namespace std ;
const int N = 100, Lg = 18;
ll Space[1<<Lg];
int cost[Lg], curspace[Lg], a[N];
int n, cap, k;
int dp[N][1<<Lg], Mx = 2e9;
vector<int> bb[N];

int solve(int cur = 0, int msk = 0)
{
  if (cur == k)return 0;
  int &ret = dp[cur][msk];
  if (~ret)return ret;
  ret = Mx;
  if (msk & (1<<a[cur]))return ret = solve(cur + 1, msk);
  if (Space[msk] + curspace[ a[cur] ] <= cap)
  {
    int nmsk = msk | (1<<a[cur]);
    ret = cost[ a[cur] ] + solve(cur + 1, nmsk);
    return ret;
  }
  for (int i = 0; i < n; i++)
  {
    if (msk & (1<<i))
    {
      int nmsk = msk & ~(1<<i);
      ret = min(ret, solve(cur, nmsk));
    }
  }
  return ret;
}
void build(int cur = 0, int msk = 0)
{
  if (cur == k)return;
  int ret = dp[cur][msk];
  if (msk & (1<<a[cur]))
  {
    build(cur+1, msk);
    return;
  }
  if (Space[msk] + curspace[ a[cur] ] <= cap)
  {
    int nmsk = msk | (1<<a[cur]);
    build(cur + 1, nmsk);
    return;
  }
  for (int i = 0; i < n; i++)
  {
    if (msk & (1<<i))
    {
      int nmsk = msk & ~(1<<i);
      int sol = solve(cur, nmsk);
      if (sol == ret)
      {
        bb[cur].pb(i);
        build(cur, nmsk);
        break;
      }
    }
  }
}
int main()
{
  freopen("cache.in", "r", stdin);
  freopen("cache.out", "w", stdout);

  memset(dp, -1, sizeof dp);
  scanf("%d%d%d", &n, &cap, &k);
  for (int i = 0; i < n; i++)scanf("%d", curspace+i);
  for (int i = 0; i < n; i++)scanf("%d", cost+i);
  for (int i = 0; i < k; i++)scanf("%d", a+i), a[i]--;

  for (int i = 1; i < (1<<n); i++)
    for (int j = 0; j < n; j++)
      if ((i & (1<<j)))
        Space[i] += curspace[j];

  printf("%d\n", solve());
  build();
  for (int i = 0; i < k; i++)
  {
    printf("%d ", SZ(bb[i]));
    for (int j: bb[i])printf("%d ", j+1);
    printf("\n");
  }
}
