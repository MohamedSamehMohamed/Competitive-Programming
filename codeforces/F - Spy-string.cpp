// Author : Mohamed sameh
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
const int N = 10;
int t, n, m;
string x[N];
int dp[N][(1<<N)];
int solve(int i = 0, int msk = 0)
{
 if (i == m)return 1;
 int &ret = dp[i][msk];
 if (~ret)return ret;
 ret = 0;
 for (char c = 'a'; c <= 'z'; c++)
 {
  bool can = 1;
  int nmsk = 0;
  for (int idx = 0; idx < n; idx++)
  {
   if (x[idx][i] != c)
   {
    nmsk|=(1<<idx);
    if (msk & (1<<idx))can = 0;
   }
  }
  if (can)ret = max(ret, solve(i+1, nmsk | msk));
 }
 return ret;
}
void build(int i = 0, int msk = 0)
{
 if (i == m)return;
 int ret = dp[i][msk];
 for (char c = 'a'; c <= 'z'; c++)
 {
  bool can = 1;
  int nmsk = 0;
  for (int idx = 0; idx < n; idx++)
  {
   if (x[idx][i] != c)
   {
    nmsk|=(1<<idx);
    if (msk & (1<<idx))can = 0;
   }
  }
  if (can)
  {
   int cur = solve(i+1, nmsk | msk);
   if (cur == ret)
   {
    cout << c; 
    build(i+1, nmsk|msk);
    break;
   }
  }
 }
}
int main()
{
 cin >> t;
 while(t--)
 {
  cin >> n >> m;
  for (int i = 0; i < n; i++)cin >> x[i];
  memset(dp, -1, sizeof dp);
  if (solve())build();
  else 
  cout << "-1";
  cout << '\n'; 
 }
}
