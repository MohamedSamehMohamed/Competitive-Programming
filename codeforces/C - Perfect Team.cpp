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
int main()
{
  FAST
  int t;
  cin >> t;
  while(t--)
  {
    int c, m, x;
    cin >> c >> m >> x ;
    int l = 1, r = min(c, m), ans = 0;
    while(l <= r)
    {
      int mid = (l+r)>>1;
      int na = min({mid, c, m});
      int rm = (c - na) + (m - na) + x;
      ans = max(ans, min(na, rm));
      if (na < rm)
      l = mid + 1;
      else
      r = mid - 1;
    }
    cout << ans <<"\n";
  }
 
}
