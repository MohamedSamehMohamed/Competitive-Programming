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
const int N = 5009;
int dp[N][N], a[N], n;
int solve(int i = 0, int lst = n)
{
  if (i == n)return 0;
  int &ret = dp[i][lst];
  if (~ret)return ret;
  if (a[i] > a[lst])
  {
    // make all segment with the same hight
    // fix a[i] to be as a[lst]
    ret = 1 + solve(i + 1, lst);
 
    // stay with a[i] hight and add the cost
    ret = min(ret, a[i] - a[lst] + solve(i + 1, i));
  }else
  {
    // less than previous and previous is calculated
    ret = solve(i + 1, i);
  }
  return ret;
}
int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)cin >> a[i];
  memset(dp, -1, sizeof dp);
  cout << solve() << '\n';
}
