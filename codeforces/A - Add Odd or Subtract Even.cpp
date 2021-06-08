// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    int a, b;
    cin >> a >> b;
    int need = abs(a-b);
    int ans = 0;
    if (a > b)
    {
      ans++;
      if (need % 2)
        ans++;
    }else if (a < b)
    {
      ans++;
      if (need % 2 == 0)
        ans++;
    }
    cout << ans << "\n";
  }
}
