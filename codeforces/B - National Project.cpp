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
int n, g, b, need;
bool ok (ll days)
{
  ll good = 1LL * g * ( days / (g + b) ) + min((ll)g,days % (g+b));
  return good >= need;
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
  {
    scanf("%d%d%d", &n, &g, &b);
    need = (n+1)/2;
    ll l = 1, r = 1e18, m , ans = 1;
    while (l <= r)
    {
      m = (l+r)>>1LL;
      if (ok(m))
      {
        ans = m;
        r = m-1;
      }else
      l = m+1;
    }
    ans = max(ans, (ll)n);
    printf("%lld\n", ans);
  }
}
