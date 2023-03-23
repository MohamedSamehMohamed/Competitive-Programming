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
const int MxP = 3e7+9;
bool siev[MxP];
int primes[MxP], idx;
void Sieve()
{
  for (int i = 2; i < MxP/ i; i++)
  {
    if (siev[i])continue;
    for (int j = i * i; j < MxP; j+=i)siev[j] = 1;
  }
  for (int i = 2; i < MxP; i++)if (!siev[i])primes[idx++] = i;
}
int k, n;
int BS(int mx)
{
  if (mx == 1)return 0;
  int l = 0, r = idx-1, m, ans = 1;
  while(l <= r)
  {
    m = (l+r)>>1;
    if (primes[m] < mx)
    {
      ans = primes[m];
      l = m+1;
    }else r = m-1;
  }
  return ans;
}
const int MX = 3e7, Lg = 26;
int dp[Lg][Lg][2];
int solve(int idx, int rm, int f1)
{
  // cout << idx <<" " << rm <<" " << f1 <<"\n";
  if (idx < 0)return rm == 0;
  if (rm < 0)return 0;
  int &ret = dp[idx][rm][f1];
  if (~ret)return ret;
  ret = 0;
  if (f1)
  {
    ret = solve(idx-1, rm, 1) + solve(idx-1, rm-1, 1);
  }else
  {
    if ((k & (1<<idx)))
    {
      ret = solve(idx-1, rm-1, f1) + solve(idx-1, rm, 1);
    }else
    ret = solve(idx-1, rm, f1);
  }
  return ret;
}
int main()
{
  freopen("monster.in", "r", stdin);
  freopen("monster.out", "w", stdout);
  Sieve();
  scanf("%d%d", &k, &n);
  while(n--)
  {
    int head;
    scanf("%d", &head);
    if (head&1)
    {
      int y = BS(head);
      k--;
      k += y;
      k = min(k, MX);
    }else
    {
      int cnt = 0;
      for (int i = 0; i < Lg; i++)cnt += ((head & (1<<i)) != 0);
      memset(dp, -1, sizeof dp);
      int tot = solve(Lg-1, cnt, 0);
      k-=tot;
    }
  }
  printf("%d\n", k);
}
