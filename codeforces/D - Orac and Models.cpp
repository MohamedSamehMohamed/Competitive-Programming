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
const int N = 1e5+9;
int a[N], n, dp[N];
int solve(int i)
{
  if (i > n)return 0;
  int &ret = dp[i];
  if (~ret)return ret;
  ret = 0;
  for (int j = i+i; j <= n; j+=i)
  {
    if (a[i] < a[j])
    ret = max(ret, 1 + solve(j));
  }
  return ret;
}
int main()
{
  FAST
  int t;
  cin >> t;
  while(t--)
  {
    memset(dp, -1, sizeof dp);
    cin >> n;
    for (int i = 1; i <= n; i++)
      cin >> a[i];
    int ans = 1;
    for (int i = n; i >= 1; i--)
    ans = max(ans, 1 + solve(i));
    cout << ans <<"\n";
  }
}
