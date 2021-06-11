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
const ll Mx = 1e18;
int n;
int a[N];
ll test(ll c)
{
  ll cur = 1;
  ll ans = 0;
  for (int i = 0; i < n; i++)
  {
    if (cur > 1e11 || cur < 0)return Mx;
    ans += abs(cur - a[i]);
    cur*=c;
  }
  return ans;
}
int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)cin >> a[i];
  sort(a, a+n);
  ll ans = 0;
  ans = 1e18;
  for (int i = 1; i <= 100000; i++)
  {
    ll cur = test(i);
    ans = min(ans, cur);
    if (cur == Mx)break;
  }
  cout << ans << '\n';
 
}
