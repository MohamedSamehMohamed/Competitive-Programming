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
int h, c, t;
int main()
{
  int T;
  cin >> T;
  while(T--)
  {
    cin >> h >> c >> t;
    if (2*t <= h+c)
    {
      cout << 2 <<"\n";
      continue;
    }
    int l = 0, r = 1e9, m, ans = 0, ans1 = 0;
    while (l <= r)
    {
      // decresing ---5 4 3 2 1
      m = (l+r)>>1LL;
      ll cur = 1LL*h * m + 1LL*c * m + h ;
      int sz = 2*m + 1;
      if (cur <= 1LL*t*sz)
      {
        ans = sz;
        r = m-1;
      }else
      l = m+1;
    }
    l = 0, r = 1e9;
    while (l <= r)
    {
      // decresing ---5 4 3 2 1
      m = (l+r)>>1LL;
      ll cur = 1LL*h * m + 1LL*c * m + h ;
      int sz = 2*m + 1;
      if (cur >= 1LL*t*sz)
      {
        ans1 = sz;
        l = m+1;
      }else
      r = m-1;
    }
    if (ans > ans1)swap(ans, ans1);
    ll A = 1LL * h * (ans/2) + 1LL * c * (ans/2) + h;
    ll B = 1LL * h * (ans1/2) + 1LL*c*(ans1/2)+h;
    double A1, A2;
    A1 = 1.0*A/ans;
    A2 = 1.0*B/ans1;
    if (abs(A1 - t) <= abs(A2 - t))
    cout << ans <<"\n";
    else
    cout << ans1 <<"\n";
    }
 
}
