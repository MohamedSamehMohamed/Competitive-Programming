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
int n, m, k;
ll sum(int r)
{
  if (r <= 0)return 0;
  return (1LL * r * (r+1))/2;
}
ll sum1(int l, int r)
{
  if (l < 0)return sum(r) - l;
  if (r >= l) return sum(r) - sum(l);
  return sum(r) + (l - r);
}
bool can(int tk)
{
  int rm = m - tk;
  ll lsum = sum1(tk-k, tk-1);
  ll rsum = sum1(tk-1-n+k, tk-1);
  // cout <<"ST\n";
  // cout << tk - k  <<" " << tk-1 <<"\n";
  // cout << tk-1-n+k <<" " << tk-1 <<"\n";
  // cout << tk <<" " << lsum <<" " << rsum <<"\n";
  // cout <<"EN\n";
  return (rm >= lsum + rsum);
}
int main()
{
  cin >> n >> m >> k;
  int l = 1, r = m, ans = 1;
  while(l <= r)
  {
    int mid = (l+r)>>1;
    if (can(mid))
    {
      ans = mid;
      l = mid+1;
    }else
    r = mid-1;
  }
  cout << ans << '\n';
}
