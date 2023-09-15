// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
int main()
{
  int t;cin >> t;
  while(t--)
  {
    int x, y;cin >> x >> y;
    int ans = min(x, y);
    x -= ans;
    y -= ans;
    ans *= 2;
    x += y;
    if (x)
    ans += x + (x  - 1);
    cout << ans << '\n';
  }
}
