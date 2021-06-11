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
const int N = 2e5 + 9;
int n, k, t, a[N];
int main()
{
  scanf("%d", &t);
  while(t--)
  {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
      scanf("%d", a+i);
    sort(a, a+n);
    ll mx = a[n-1];
    for (int i = n-2; i >= 0 && k--; i--)
    {
      mx += a[i];
      a[i] = 0;
    }
    int mn = 1e9;
    for (int i = 0; i < n; i++)mn = min(mn, a[i]);
    printf("%lld\n", mx - mn);
  }
}
