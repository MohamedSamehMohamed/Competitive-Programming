// Author : Mohamed Sameh
// created in: 10:08 PM
#include <bits/stdc++.h>
using namespace std;
int r, x, y;
void test(){
  cin >> r >> x >> y;
  long long d = 1LL * x * x + 1LL * y * y;
  long long R = 1LL * r * r;
  if (R == d)
    cout << 1 <<"\n";
  else if (R > d)
    cout << 2 << "\n";
  else
  {
    long long dSq = (d + R - 1) / R;
    long long ans = sqrt(dSq);
    while (ans * ans < dSq)
      ans++;
    cout << ans << "\n";
  }
}
int main()
{
  test();
}