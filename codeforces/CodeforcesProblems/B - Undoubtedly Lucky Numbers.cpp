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
string x;
int dp[20][(1<<11)][2][2], cnt[(1<<11)], n;
int solve(int i = 0, int msk = 0, bool f = 0, bool st = 0)
{
  if (i == n)return cnt[msk] <= 2 && st;
  int &ret = dp[i][msk][f][st];
  if(~ret)return ret;
  ret = 0;
  int mx = f ? 9: x[i] - '0';
  for (int idx = 0; idx <= mx; idx++)
  {
    int nmsk = msk;
    if (idx == 0)nmsk |= st * (1<<idx);
    else
    nmsk |= (1<<idx);
    ret += solve(i+1, nmsk, f | (idx < mx), st | (idx > 0));
  }
  return ret;
}
int main()
{
  for (int i = 1; i < (1<<11); i++)
  {
    int r = 0;
    for (int j = 0; j < 11; j++)r += ((i & (1<<j))!=0);
    cnt[i] = r;
  }
  cin >> x;
  n = SZ(x);
  memset(dp, -1, sizeof dp);
  cout << solve() << '\n';
}
