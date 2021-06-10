// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
int main()
{
  int n, s;
  cin >> n >> s;
  int mx = 0;
  for (int i = 0; i < n; i++)
  {
    int x;cin >> x;
    mx = max(mx, x);
  }
  int ans = mx * s;
  ans = ((ans+999)/1000);
  cout << ans << '\n';
 
}
