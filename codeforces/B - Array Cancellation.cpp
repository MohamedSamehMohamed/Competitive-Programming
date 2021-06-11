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
ll a[N], n;
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    cin >> n;
    for (int i = 0; i < n; i++)cin >> a[i];
    ll rem = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
      if (a[i] >= 0)
      {
        rem += a[i];
      }else
      {
        a[i] += rem;
        if (a[i] <= 0)
        {
          ans += -a[i];
          rem = 0;
        }else
        rem = a[i];
      }
    }
    cout << ans << '\n';
  }
}
