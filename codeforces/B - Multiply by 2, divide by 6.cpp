// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
void solve()
{
  int n;cin >> n;
  // 6 -> 2 * 3
  int two = 0, three = 0;
  while(n % 2 == 0)
    n/= 2, two++;
  while(n % 3 == 0)
    n/= 3, three++;
  if (n == 1 && two <= three)
  {
    cout << 2 * three - two <<"\n";
  }else
    cout <<"-1\n";
}
int main()
{
  int t;cin >> t;
  while(t--)
  {
    solve();
  }
}
