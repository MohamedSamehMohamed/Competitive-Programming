// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
int a, b, c, M = 1e5;
void solve()
{
  cin >> a >> b >> c;
  int best = 1e9;
  int x, y, z;
  for (int i = 1; i <= M; i++)
    for (int j = i; j <= M; j+=i)
      for (int k = j; k <= M; k+=j)
      {
        int cur = abs(a-i) + abs(b-j) + abs(c-k);
        if (cur < best)
        {
          best = cur;
          x = i;
          y = j;
          z = k;
        }
      }
  cout << best << "\n";
  cout << x <<" " << y <<" " << z <<"\n";
}
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    solve();
  }
}
