#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
 ll n; 
 cin >> n; 
 ll l = 1, r = n, m, ans = 1;
 long long tot = 1LL * n * (n-1)/2ll; 
 while(l <= r)
 {
  m = (l+r)>>1; 
  ll i = n - 1 - m; 
  long long cur = tot - (1LL * i * (i+1))/2;
  if (cur >= tot/2 + (tot&1))
  {
   ans = m; 
   r = m-1; 
   } else 
   l = m+1; 
 }
 cout << ans << '\n';
}
