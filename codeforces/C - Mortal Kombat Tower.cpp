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
int n, a[N], dp[N][2];
int solve(int i = 0, int lst = 0)
{
  if (i == n)return 0;
  int &ret = dp[i][lst];
  if (~ret)return ret;
  ret = a[i] * !lst + solve(i+1, !lst);
  if (i + 1 < n)
  ret = min(ret, a[i] * !lst + a[i+1] * !lst + solve(i+2, !lst));
  return ret;
}
int main()
{
  FAST
  int t;
  cin >> t;
  while(t--)
  {
    cin >> n;
    for (int i = 0; i < n; i++)cin >> a[i];
    for (int i = 0; i < n; i++)
    {
      dp[i][0] = dp[i][1] = -1;
    }
    cout << solve() <<"\n";
  }
}
