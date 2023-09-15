// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
int main()
{
  int t;cin >> t;
  while(t--)
  {
    int x, y, n;
    cin >> x >> y >> n;
    int ans = y + x * ((n-y)/x);
    cout << ans << "\n";
  }
}
