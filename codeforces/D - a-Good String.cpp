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
const int N = 2e5+9;
string x;
int n;
map<array<int,3>,int> dp;
int pre[N][26];
int Pre(int l, int r, int c)
{
  return pre[r][c] - (l-1 >= 0? pre[l-1][c]: 0);
}
int solve(int l = 0, int r = n-1, int c = 0)
{
  if (l > r)return 0;
  if (l == r)
  {
    if (x[l] - 'a' != c)return 1;
    return 0;
  }
  if (dp.find({l, r, c}) != dp.end())return dp[{l, r, c}];
  int L, R, m;
  m = (l+r)>>1;
  int len = (r-l+1)/2;
  int C1, C2;
  C1 = (len)-Pre(l, m, c);
  C2 = (len)-Pre(m+1, r, c);
  L = C1 + solve(m+1, r, c+1);
  R = C2 + solve(l, m, c+1);
  return dp[{l, r, c}] = min(L, R);
}
int main()
{
  FAST
  int t;
  cin >> t;
  while(t--)
  {
    dp.clear();
    cin >> n >> x;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < 26; j++)
        pre[i][j] = 0;
    for (int i = 0; i < n; i++)
    {
      pre[i][x[i]-'a']++;
      for (int j = 0; i && j < 26; j++)
      {
        pre[i][j] += pre[i-1][j];
      }
    }
    cout << solve() <<"\n";
  }
}
