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
int t, n, m;
const int N = 1e6+9;
int a[N];
bool can(ll mx)
{
  int tot = 0;
  for (int i = 0; i < n; i++)
  {
    if (a[i] > mx)return 0;
    int E = a[i];
    int tk = 1;
    int j = i+1;
    while(j < n && 1LL * max(E,a[j]) * (tk+1) <= mx)
    {
      E = max(E, a[j]);
      j++;
      tk++;
    }
    tot++;
    i = j-1;
  }
  return tot <= m;
}
int main()
{
  scanf("%d", &t);
  while(t--){
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)scanf("%d", a+i);
    ll l = 1, r = 1e13, mid, ans = -1;
    while(l <= r)
    {
      mid = (l+r)>>1LL;
      if (can(mid))
      {
        ans = mid;
        r = mid - 1;
      }else
      l = mid + 1;
    }
    printf("%lld\n", ans);
  }
}
