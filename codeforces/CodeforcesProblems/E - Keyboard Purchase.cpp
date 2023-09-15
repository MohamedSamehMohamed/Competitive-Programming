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
const int N = 1e5+9, M = 1 << 20;
string x;
int rep[20][20];
int dp[M], n, m;
int solve(int msk = 0)
{
  if (msk == (1<<m) - 1)return 0;
  int &ret = dp[msk];
  if (~ret)return ret;
  int cost = 0;
  ret = 2e9;
  for (int i = 0; i < m; i++)
  {
    if (msk & (1<<i))continue;
    ret = min(ret, solve(msk | (1<<i)));
    for (int j = 0; j < m; j++)
    {
      if (msk & (1<<j))cost += rep[i][j] + rep[j][i];
    }
  }
  ret += cost;
  return ret;
}
int main()
{
  memset(dp, -1, sizeof dp);
  cin >> n >> m >> x;
  for (int i = 1; i < n; i++)
  {
    rep[x[i-1] - 'a'][x[i] - 'a']++;
  }
  cout << solve() << '\n';
}
